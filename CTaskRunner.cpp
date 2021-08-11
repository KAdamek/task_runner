#include "CTaskRunner.h"

CTaskRunner::CTaskRunner(ITask *task, CTaskMetadata *metadata) {
	this->task = task;
	// metadata could be cloned or stored as a pointer
	this->metadata = *metadata;
}

void CTaskRunner::run(CHardwareConfiguration *hardwareConfiguration, CTaskData *data) {
	task->setup(hardwareConfiguration, &metadata);
	task->preProcessing();
	task->start(data);
	task->postProcessing();
	task->teardown();
}

IExecutionEnvelope* CTaskRunner::executionEnvelope() {
	if(envelope == nullptr) envelope = task->executionEnvelope(&metadata);
	return envelope;
}
