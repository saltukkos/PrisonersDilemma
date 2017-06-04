#pragma once

#include <string>
#include "strategy.h"

class AngryStrategy : public Strategy {
public:

	AngryStrategy(const std::string& directory);

	~AngryStrategy();

	Choice MakeChoice() override;

	void GetResults(Choice a, Choice b) override;

};
