#pragma once
#include "ITask.h"
#include <math.h> 

class CTaskFFTExample : ITask {
private:
	CHardwareConfiguration *hardwareConfiguration;
	int size;
	int nFFTs;

public:
	virtual void preProcessing() override;
	virtual void setup(CHardwareConfiguration *hardwareConfiguration, CTaskMetadata *metadata) override;
	virtual void start(CTaskData *data) override;
	virtual void teardown() override;
	virtual void postProcessing() override;
	virtual CTaskMetadata *getEmptyMetadata() override;
	virtual IExecutionEnvelope *executionEnvelope(CTaskMetadata *metadata) override;
};

class CExecutionEnvelopeFFTExample : IExecutionEnvelope {
private:
	int minNodes;
	int maxNodes;
public:
	CExecutionEnvelopeFFTExample(CTaskMetadata *metadata);

	int getMinNodes() override;
	int getMaxNodes() override;
	double estimateTime(CHardwareConfiguration *configuration, CTaskMetadata *metadata) override;
};