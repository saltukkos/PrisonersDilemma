#pragma once

#include <string>
#include "strategy.h"

class EyeForEyeStrategy : public Strategy {
public:

	EyeForEyeStrategy(const std::string& directory);

	~EyeForEyeStrategy();

	Choice MakeChoice() override;

	void GetResults(Choice a, Choice b) override;

private:

	bool angry;

};
