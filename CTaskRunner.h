#pragma once
#include "ITask.h"
#include "CHardwareConfiguration.h"
#include "IExecutionEnvelope.h"
#include "CTaskMetadata.h"
#include "CTaskData.h"

// This is a wrapper which provides unified interface for the scheduler.
class CTaskRunner {
private:
	ITask *task;
	CTaskMetadata metadata;
	IExecutionEnvelope *envelope;
	
public:
	CTaskRunner(ITask *task, CTaskMetadata *metadata);

	void run(CHardwareConfiguration *hardwareConfiguration, CTaskData *data);

	IExecutionEnvelope* executionEnvelope();

	~CTaskRunner() {
		delete task;
		delete envelope;
	}
};

