#include "simulator.h"

#include <algorithm>
#include <stdexcept>
#include "factory.h"
#include "interface.h"

Simulator::Simulator(std::shared_ptr<VectorCS> list, const int& n, const Mode& _mode, const Matrix& matrix, const std::string& dir) :
	players(list),
	steps(n),
	table(matrix),
	directory(dir),
	mode(_mode)
{}

void Simulator::Run() {

	if (mode == Mode::detailed)
		Detailed(players->at(0), players->at(1), players->at(2));

	else if (mode == Mode::fast)
		Fast(players->at(0), players->at(1), players->at(2));

	else if (mode == Mode::tournament)
		Tournament();

	else
		throw std::range_error("incorrect mode");

}

Simulator::~Simulator() {}

void Simulator::Detailed(CS& a, CS& b, CS& c) {

	Interface::Match(a.first.first, b.first.first, c.first.first);
	Interface::GetComand();

	for (;;) { 
		std::string buff;
		steps = Interface::GetSteps(buff);

		switch (steps){
		
		case Interface::QUIT:
			Simulator::Less less;
			std::sort(players->begin(), players->begin() + 3, less);

			for (int i = 0; i < 3; ++i) {
				Interface::ShowResult(i + 1, players->at(i).first.first, players->at(i).first.second);
			}

			return;
		
		case Interface::ERROR:
			Interface::IncorrectCommand(buff);
			break;

		default:
			Interface::TableHeader();

			for (int i = 0; i < steps; ++i) {
				Strategy::Result res = MakeStep(a.second, b.second, c.second);
				Matrix::stepScore score = table.GetScore(res);

				a.first.second += score.a;
				b.first.second += score.b;
				c.first.second += score.c;

				Interface::ShowStep(a.first.first, (res.a == Strategy::defect), score.a, a.first.second);

				Interface::ShowStep(b.first.first, (res.b == Strategy::defect), score.b, b.first.second);

				Interface::ShowStep(c.first.first, (res.c == Strategy::defect), score.c, c.first.second);

				Interface::Ending();
			}

		}
	}

}

void Simulator::Fast(CS& a, CS& b, CS& c) {
	int aWin = 0;
	int bWin = 0;
	int cWin = 0;

	for (int i = 0; i < steps; ++i) {
		Strategy::Result step = MakeStep(a.second, b.second, c.second);
		Matrix::stepScore score = table.GetScore(step);

		a.first.second += score.a;
		b.first.second += score.b;
		c.first.second += score.c;

		aWin += score.a;
		bWin += score.b;
		cWin += score.c;
	}

	Interface::ShowResult(1, a.first.first, aWin);
	Interface::ShowResult(2, b.first.first, bWin);
	Interface::ShowResult(3, c.first.first, cWin);
}

void Simulator::Tournament() {
	for (int i = 0; i < players->size() - 2; ++i) {
		for (int j = i + 1; j < players->size() - 1; ++j) {
			for (int k = j + 1; k < players->size(); ++k) {

				Interface::Match(players->at(i).first.first, players->at(j).first.first, players->at(k).first.first);
				
				Fast(players->at(i), players->at(j), players->at(k));
				
				players->at(i).second.reset(Instance<std::string>().Create(std::string(players->at(i).first.first), directory));
				players->at(j).second.reset(Instance<std::string>().Create(std::string(players->at(j).first.first), directory));
				players->at(k).second.reset(Instance<std::string>().Create(std::string(players->at(k).first.first), directory));
			}
		}
	}

	Simulator::Less less;
	
	Interface::FinishTournament();
	std::sort(players->begin(), players->end(), less);

	for (int i = 0; i < players->size(); ++i) {
		Interface::ShowResult(i + 1, players->at(i).first.first, players->at(i).first.second);
	}
}

Strategy::Result Simulator::MakeStep(std::shared_ptr<Strategy> a, std::shared_ptr<Strategy> b, std::shared_ptr<Strategy> c) {
	Strategy::Result result;

        result.a = a->MakeChoice();
        result.b = b->MakeChoice();
        result.c = c->MakeChoice();

        a->GetResults(result.b, result.c);
        b->GetResults(result.a, result.c);
        c->GetResults(result.a, result.b);

	return result;
}
