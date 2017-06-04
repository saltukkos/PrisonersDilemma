#include "masterStrategy.h"

#include <fstream>
#include <iostream>
#include "creator.h"
#include "factory.h"
#include "interface.h"

namespace {
	bool c = Instance<std::string>().Register(std::string("master"), &Creator<MasterStrategy>);
}

MasterStrategy::MasterStrategy(const std::string& directory) :
	SmartAngryStrategy(directory),
	step(0),
	matchedA(false),
	matchedB(false) {

	std::ifstream source;
	
	source.exceptions(
		std::ifstream::failbit |
		std::ifstream::badbit);

	try {
		source.open(dir + std::string("symbiosys.cfg"), std::ifstream::in);
	}
	catch (std::ifstream::failure) {
		Interface::NoConfig(dir);
		return;
	}

	for (int i = 0; i < 10; ++i) {
		try {
			source >> mySteps[i];
			source >> cipher[i];
		}

		catch (std::ifstream::failure) {
			Interface::InvalidConfig("symbiosys.cfg");
			return;
		}
	}

	matchedA = true;
	matchedB = true;
}

void MasterStrategy::GetResults(Choice a, Choice b) {
	
        SmartAngryStrategy::GetResults(a, b);

	if (step >= 10)
		return;

	if (matchedA) {
                if (a != static_cast<Choice>(cipher[step]))
			matchedA = false;
	}
	
	if (matchedB) {
                if (b != static_cast<Choice>(cipher[step]))
			matchedB = false;
	}
	
	++step;
}

Strategy::Choice MasterStrategy::MakeChoice() {
	
	if (!matchedA && !matchedB)
                return SmartAngryStrategy::MakeChoice();

	else {
		if (step < 10)
                        return static_cast<Choice>(mySteps[step]);
		else
			return defect;
	}
}

MasterStrategy::~MasterStrategy() {}
