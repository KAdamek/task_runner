#pragma once
#include "IExecutionEnvelope.h"
#include "CTaskMetadata.h"
#include "CTaskData.h"

class ITask {
public:
	virtual void preProcessing() = 0;

	virtual void setup(CHardwareConfiguration *hardwareConfiguration, CTaskMetadata *metadata) = 0;

	virtual void start(CTaskData *data) = 0;

	virtual void teardown() = 0;

	virtual void postProcessing() = 0;

	virtual CTaskMetadata *getEmptyMetadata() = 0;

	virtual IExecutionEnvelope *executionEnvelope(CTaskMetadata *metadata) = 0;
};

