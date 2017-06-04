#include "angryStrategy.h"

#include <string>
#include "creator.h"
#include "factory.h"

namespace {
	bool c = Instance<std::string>().Register(std::string("angry"), &Creator<AngryStrategy>);
}

AngryStrategy::AngryStrategy(const std::string& directory) :
Strategy(directory) {}

AngryStrategy::~AngryStrategy() {}

void AngryStrategy::GetResults(Choice, Choice) {}

Strategy::Choice AngryStrategy::MakeChoice() {
	return defect;
}
