// task_runner_prototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "ITask.h"
#include "CTaskFFTExample.h"
#include "CTaskRunner.h"
#include "CTaskRegister.h"



int main() {
    CTaskMetadata *metadata = new CTaskMetadata;
    metadata->addParameter("size", 20);
    metadata->addParameter("nFFTs", 2);

    CTaskRunner *runner = CTaskRegister::getTaskRunner("FFTExample", metadata);
    
    CHardwareConfiguration hardwareConfiguration;
    hardwareConfiguration.nGPUs = 0;
    hardwareConfiguration.nNodes = 1;
    IExecutionEnvelope *taskFFTExecutionEnvelope = runner->executionEnvelope();
    double estimatedTime = taskFFTExecutionEnvelope->estimateTime(&hardwareConfiguration, metadata);
    std::cout << "Estimated time: " << estimatedTime << "\n";

    CTaskData FFTdata;
    FFTdata.data = new float[20];
    for (int f = 0; f<20; f++) {
        FFTdata.data[f] = (float)f;
    }

    runner->run(&hardwareConfiguration, &FFTdata);

    delete[] FFTdata.data;
    delete metadata;
}
