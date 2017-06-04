#pragma once

#include <string>
#include "smartAngryStrategy.h"
#include "strategy.h"

class MasterStrategy : public SmartAngryStrategy {
public:

	MasterStrategy(const std::string& directory);

	~MasterStrategy();

	Choice MakeChoice() override;

	void GetResults(Choice a, Choice b) override;

private:
	int step;

	bool matchedA;
	bool matchedB;

	int cipher[10];
	int mySteps[10];
};
