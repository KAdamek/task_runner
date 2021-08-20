#pragma once
#include <string>
#include "CTaskMetadata.h"
#include "CTaskRunner.h"

// Supplies scheduler with instance of a task.
class CTaskRegister {
public:
	static CTaskRunner *getTaskRunner(std::string taskname, CTaskMetadata *metadata);

};

