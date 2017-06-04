#pragma once

#include <random>
#include <string>
#include "strategy.h"

class RndStrategy : public Strategy {
public:

	RndStrategy(const std::string& directory);

	~RndStrategy();

	Choice MakeChoice() override;

	void GetResults(Choice a, Choice b) override;

private:

	std::random_device rnd;

};
