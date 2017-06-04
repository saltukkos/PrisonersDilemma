#include "rndStrategy.h"

#include "creator.h"
#include "factory.h"

namespace {
	bool c = Instance<std::string>().Register(std::string("fifty-fifty"), &Creator<RndStrategy>);
}

RndStrategy::RndStrategy(const std::string& directory) :
	Strategy(directory) {}

RndStrategy::~RndStrategy() {}

void RndStrategy::GetResults(Choice, Choice) {}

Strategy::Choice RndStrategy::MakeChoice() {
	if (rnd() % 2)
		return cooperate;
	return defect;
}
