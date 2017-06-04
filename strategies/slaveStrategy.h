#pragma once

#include <string>
#include "angryStrategy.h"
#include "strategy.h"

class SlaveStrategy : public AngryStrategy {
public:

	SlaveStrategy(const std::string& directory);

	~SlaveStrategy();

	Choice MakeChoice() override;

	void GetResults(Choice a, Choice b) override;

private:

	int step;

	bool matchedA;
	bool matchedB;

	int cipher[10];
	int mySteps[10];
};
