#pragma once
#include <map>
#include <string>
#include <iostream>

class CTaskMetadata {
private:
	std::map<std::string, int> metadata;

public:

	void setParameter(std::string name, int value) {
		if (metadata.count(name) > 0) {
			metadata[name] = value;
		}
		else {
			throw new std::exception;
		}
	}

	int getParameter(std::string name) {
		if (metadata.count(name) > 0) {
			return(metadata[name]);
		}
		else {
			throw new std::exception;
		}
	}
	
	// Use builder instead
	void addParameter(std::string name, int value) {
		metadata[name] = value;
	}

	~CTaskMetadata() {
		metadata.clear();
		std::cout << "CTaskMetadata destruktor" << std::endl;
	}
};

