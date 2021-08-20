#pragma once
#include <map>
#include <string>
#include <iostream>

// A placeholder for task (processing function) parameters. This needs to be specified more in the future. Metadata contained in this class should not be related to data, that is how to access them, size of the data etc. It should only contain task specific parameters. For example, a number of FFTs to perform, length of the FFT. The exact scope needs to be specified further.
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
		std::cout << "CTaskMetadata destructor" << std::endl;
	}
};

