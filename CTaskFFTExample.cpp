#include "CTaskFFTExample.h"

void CTaskFFTExample::preProcessing() {
	std::cout << "FFT preprocessing" << std::endl;
}

void CTaskFFTExample::setup(CHardwareConfiguration *hardwareConfiguration, CTaskMetadata *metadata) {
	this->hardwareConfiguration = hardwareConfiguration;
	size  = metadata->getParameter("size");
	nFFTs = metadata->getParameter("nFFTs");
	std::cout << "FFT setup: size: " << size << "; nFFTs: " << nFFTs << std::endl;
}

void CTaskFFTExample::start(CTaskData *data) {
	std::cout << "FFT start" << std::endl;
	for (int f = 0; f<size; f++) {
		std::cout << f << " - " << data->data[f] << std::endl;
	}
}

void CTaskFFTExample::teardown() {
	this->hardwareConfiguration = nullptr;
	std::cout << "FFT teardown" << std::endl;
}

void CTaskFFTExample::postProcessing() {
	std::cout << "FFT postProcessing" << std::endl;
}

CTaskMetadata *CTaskFFTExample::getEmptyMetadata() {
	CTaskMetadata *metadata = new CTaskMetadata();
	metadata->addParameter("size", 20);
	metadata->addParameter("nFFTs", 2);
	return metadata;
}

IExecutionEnvelope *CTaskFFTExample::executionEnvelope(CTaskMetadata *metadata) {
	return (IExecutionEnvelope*) new CExecutionEnvelopeFFTExample(metadata);
}



//----------------------------------------------------------
CExecutionEnvelopeFFTExample::CExecutionEnvelopeFFTExample(CTaskMetadata *metadata) {
	minNodes = 1;
	maxNodes = (int) ceil(metadata->getParameter("size")/1024.0);
}

int CExecutionEnvelopeFFTExample::getMinNodes() {
	return 1;
}

int CExecutionEnvelopeFFTExample::getMaxNodes() {
	return 1;
}

double CExecutionEnvelopeFFTExample::estimateTime(CHardwareConfiguration *hardwareConfiguration, CTaskMetadata *metadata) {
	if (hardwareConfiguration->nNodes >= minNodes && hardwareConfiguration->nNodes <= maxNodes) {
		double time = (100.0*metadata->getParameter("size"))/hardwareConfiguration->nNodes;
		return time;
	}
}
