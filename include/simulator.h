#pragma once

#include <memory>
#include <string>
#include "game.h"
#include "matrix.h"
#include "strategy.h"

class Simulator {
public:
	Simulator(std::shared_ptr<VectorCS> list, const int &n, const Mode &mode, const Matrix& matrix, const std::string& dir);
	
	void Run();
	
	~Simulator();

	class Less {
	public:
		bool operator()(CS&a, CS&b) {
			return (a.first.second > b.first.second);
		}
	};

private:
	void Detailed( CS& a, CS& b, CS& c);
	void Fast(CS& a, CS& b, CS& c);
	void Tournament();
	Strategy::Result MakeStep(std::shared_ptr<Strategy> a, std::shared_ptr<Strategy> b, std::shared_ptr<Strategy> c);

	std::string directory;
	const Matrix& table;
	const Mode mode;
	std::shared_ptr<VectorCS> players;
	int steps;
};