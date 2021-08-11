#pragma once
#include "ITask.h"
#include "CHardwareConfiguration.h"
#include "IExecutionEnvelope.h"
#include "CTaskMetadata.h"
#include "CTaskData.h"

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

