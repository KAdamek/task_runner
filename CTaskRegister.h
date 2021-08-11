#pragma once
#include <string>
#include "CTaskMetadata.h"
#include "CTaskRunner.h"

class CTaskRegister {
public:
	static CTaskRunner *getTaskRunner(std::string taskname, CTaskMetadata *metadata);

};

