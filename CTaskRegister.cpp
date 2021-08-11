#include "CTaskRegister.h"
#include "CTaskFFTExample.h"

CTaskRunner *CTaskRegister::getTaskRunner(std::string taskname, CTaskMetadata *metadata) {
	ITask *task;
	if (taskname == "FFTExample") task = (ITask *) new CTaskFFTExample;
	else {
		task = nullptr;
		throw new std::exception;
	}
	return new CTaskRunner(task, metadata);
}