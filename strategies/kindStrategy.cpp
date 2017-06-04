#include "kindStrategy.h"

#include "creator.h"
#include "factory.h"

namespace {
	bool c = Instance<std::string>().Register(std::string("kind"), &Creator<KindStrategy>);
}

KindStrategy::KindStrategy(const std::string& directory) :
	Strategy(directory) {}

KindStrategy::~KindStrategy() {}

void KindStrategy::GetResults(Choice, Choice) {}

Strategy::Choice KindStrategy::MakeChoice() {
	return cooperate;
}
