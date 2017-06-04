#pragma once

#include <string>
#include "strategy.h"

class SmartAngryStrategy : public Strategy {
public:

	SmartAngryStrategy(const std::string& directory);

	~SmartAngryStrategy();

	Choice MakeChoice() override;

	void GetResults(Choice a, Choice b) override;

private:

	bool angry;
};
