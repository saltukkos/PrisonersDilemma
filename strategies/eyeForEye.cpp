#include "eyeForEye.h"

#include <string>
#include "creator.h"
#include "factory.h"

namespace {
	bool c = Instance<std::string>().Register(std::string("eyeForEye"), &Creator<EyeForEyeStrategy>);
}

EyeForEyeStrategy::EyeForEyeStrategy(const std::string& directory) :
	Strategy(directory),
	angry(false) {}

EyeForEyeStrategy::~EyeForEyeStrategy() {}

void EyeForEyeStrategy::GetResults(Choice a, Choice b) {
	if (a == defect || b == defect)
		angry = true;
}

Strategy::Choice EyeForEyeStrategy::MakeChoice() {
	if (angry) {
		angry = false;
			return defect;
	}
	return cooperate;
}
