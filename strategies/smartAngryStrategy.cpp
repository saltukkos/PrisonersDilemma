#include "smartAngryStrategy.h"

#include "creator.h"
#include "factory.h"

namespace {
	bool c = Instance<std::string>().Register(std::string("smartAngry"), &Creator<SmartAngryStrategy>);
}

SmartAngryStrategy::SmartAngryStrategy(const std::string& directory) :
	Strategy(directory),
	angry(false)
{}

SmartAngryStrategy::~SmartAngryStrategy() {}

void SmartAngryStrategy::GetResults(Choice a, Choice b) {
	if (a == defect || b == defect)
		angry = true;
}

Strategy::Choice SmartAngryStrategy::MakeChoice() {
	if (angry)
		return defect;
	return cooperate;
}
