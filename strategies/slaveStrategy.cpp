#include "slaveStrategy.h"

#include <fstream>
#include "creator.h"
#include "factory.h"

namespace {
	bool c = Instance<std::string>().Register(std::string("slave"), &Creator<SlaveStrategy>);
}

SlaveStrategy::SlaveStrategy(const std::string& directory) :
	AngryStrategy(directory),
	step(0),
	matchedA(false),
	matchedB(false) {

	std::ifstream source;
		
	source.exceptions(
		std::ifstream::failbit |
		std::ifstream::badbit);

        try {
		source.open(dir + std::string("symbiosys.cfg"), std::ifstream::in);

		for (int i = 0; i < 10; ++i) {
			source >> cipher[i];
			source >> mySteps[i];
		}
	}
	catch (std::ifstream::failure) {
		return;
	}

	source.close();
	matchedA = true;
	matchedB = true;
}

SlaveStrategy::~SlaveStrategy() {}

void SlaveStrategy::GetResults(Choice a, Choice b) {
	
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

Strategy::Choice SlaveStrategy::MakeChoice() {
	
	if (!matchedA && !matchedB)
                return AngryStrategy::MakeChoice();

	else {
		if (step < 10)
                        return static_cast<Choice>(mySteps[step]);
		else
			return cooperate;
	}
}
