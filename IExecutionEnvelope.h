#pragma once
#include "CHardwareConfiguration.h"
#include "CTaskMetadata.h"

// This class declares possible hardware configuration the algorithm is compatible with. 
// For example platforms supported (CPUs, GPUs, ...), number of nodes supported, etc.
// The class also estimates execution time for given hardware configuration and 
// metadata. For example by calculating number of operations and memory transfers and
// then estimating the execution time based on memory bandwidth and FLOPS of the platform.
class IExecutionEnvelope {
public:
	virtual int getMinNodes() = 0;
	virtual int getMaxNodes() = 0;
	virtual double estimateTime(CHardwareConfiguration *configuration, CTaskMetadata *metadata) = 0;
};

