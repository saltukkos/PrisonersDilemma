#pragma once

#include <string>
#include "strategy.h"

class Matrix{
public:

	struct stepScore {
		int a;
		int b;
		int c;
	};

	Matrix();
	
	bool LoadFromFile(const std::string&);

	stepScore GetScore(Strategy::Result&) const;

	~Matrix();

private:
        static const int size = 16;

        int matrix[size];
};
