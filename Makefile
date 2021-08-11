INC := -I${CUDA_HOME}/include
LIB := -L${CUDA_HOME}/lib64 -lcudart -lcuda -lfftw3f -lgsl -lgslcblas

GCC = g++
NVCC = ${CUDA_HOME}/bin/nvcc


NVCCFLAGS = -O3 -arch=sm_60 --ptxas-options=-v -Xcompiler -Wextra -lineinfo
GCC_OPTS =-O3 -Wall -Wextra $(INC)

TSKRUNNEREXE = taskrunner.exe

ifdef reglim
NVCCFLAGS += --maxrregcount=$(reglim)
endif

ifdef fastmath
NVCCFLAGS += --use_fast_math
endif

all: clean tskrunner

tskrunner: ITask.o IExecutionEnvelope.o CTaskRunner.o CTaskRegister.o CHardwareConfiguration.o CTaskData.o CTaskFFTExample.o CTaskMetadata.o task_runner_prototype.o Makefile
	$(GCC) -o $(TSKRUNNEREXE) ITask.o IExecutionEnvelope.o CTaskRunner.o CTaskRegister.o CHardwareConfiguration.o CTaskData.o CTaskFFTExample.o CTaskMetadata.o task_runner_prototype.o $(GCC_OPTS)

CHardwareConfiguration.o:
	$(GCC) -c CHardwareConfiguration.cpp

CTaskData.o:
	$(GCC) -c CTaskData.cpp

CTaskFFTExample.o:
	$(GCC) -c CTaskFFTExample.cpp

CTaskMetadata.o:
	$(GCC) -c CTaskMetadata.cpp

CTaskRegister.o:
	$(GCC) -c CTaskRegister.cpp

CTaskRunner.o:
	$(GCC) -c CTaskRunner.cpp

IExecutionEnvelope.o:
	$(GCC) -c IExecutionEnvelope.cpp

ITask.o:
	$(GCC) -c ITask.cpp

task_runner_prototype.o:
	$(GCC) -c task_runner_prototype.cpp


clean:	
	rm -f *.o *.~ $(TSKRUNNEREXE)
	



