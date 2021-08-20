#pragma once

// This is intended to describe hardware on which the task will run. The task needs to plan its computational strategy according to that. This should contain available memory, number of cores, GPUs etc.
class CHardwareConfiguration {
public:
	int nNodes;
	int nGPUs;
};

