#pragma once

#include <string>
#include "strategy.h"

class KindStrategy : public Strategy {
public:

	KindStrategy(const std::string& directory);

	~KindStrategy();

	Choice MakeChoice() override;

	void GetResults(Choice a, Choice b) override;

};
