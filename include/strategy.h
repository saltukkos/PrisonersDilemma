#pragma once

#include <string>

class Strategy{
public:

	enum Choice { defect = 0, cooperate };

	struct Result {
		Choice a;
		Choice b;
		Choice c;
	};

	Strategy(const std::string& directory);

	virtual void GetResults(Choice a, Choice b) = 0;

	virtual Choice MakeChoice() = 0;

	virtual ~Strategy();

protected:
	std::string dir;

};
