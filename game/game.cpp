#include "game.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include "factory.h"
#include "interface.h"
#include "matrix.h"
#include "parser.h"
#include "simulator.h"

int main(const int argc, const char *argv[]) {

	 ParseResult res = Parse(argc, argv);

	 for (VectorCS::iterator i = res.list->begin(); i != res.list->end(); ++i) {
		 std::shared_ptr<Strategy> temp = std::shared_ptr<Strategy>(Instance<std::string>().Create(std::string(i->first.first), res.dir));
		 
		 if (!temp) {
			 Interface::NotFound(i->first.first);
			 --i;
			 res.list->erase(i+1);
		 }
		 else
			 i->second = temp;
	 }

	if (res.list->size() < 3) {

		Interface::ShowHelp();
		Instance<std::string>().ShowRegistred();
		return -1;
	}

	if (res.mode == Mode::none) {
		if (3 == res.list->size())
			res.mode = Mode::detailed;
		else
			res.mode = Mode::tournament;
	}

	if (res.mode != Mode::detailed && res.steps < 1) {
		Interface::IncorrectSteps();
		return -1;
	}

	Matrix matrix;

	if (!matrix.LoadFromFile(res.fileName))
		Interface::DefaultTable();

	Simulator run(res.list, res.steps, res.mode, matrix, res.dir);
	run.Run();
}