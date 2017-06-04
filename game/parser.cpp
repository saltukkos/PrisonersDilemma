#include "parser.h"

#include <memory>
#include <string>
#include "interface.h"

bool KeyWord(ParseResult& res, const char* arg) {
	std::string str(arg);
	std::size_t found = str.find("mode=");

	if (0 == found) {

		if (str.find("detailed", 5) != std::string::npos)
			res.mode = Mode::detailed;

		else if (str.find("fast", 5) != std::string::npos)
			res.mode = Mode::fast;

		else if (str.find("tournament", 5) != std::string::npos)
			res.mode = Mode::tournament;

		else
			Interface::NoMode(str.substr(5));

		return true;
	}

	else if (0 == (found = str.find("steps="))) {

		int temp = 0;

		try {
			temp = std::stoi(str.substr(6));
		}

		catch (std::invalid_argument) {
			Interface::IncorrectSteps();
			return true;
		}

		catch (std::out_of_range) {
			Interface::CountTooBig();
			return true;
		}

		res.steps = temp;
		return true;
	}

	else if (0 == (found = str.find("matrix="))) {
		res.fileName = arg + 7;
		return true;
	}

	else if (0 == (found = str.find("configs="))) {
		res.dir = (str.substr(8));
		return true;
	}

	return false;
}

ParseResult Parse(int argc, const char *argv[]) {
	
	ParseResult res;

	for (int i = 1; i < argc; ++i) {

		if (argv[i][0] == '-' && argv[i][1] == '-') {
			if (!KeyWord(res, argv[i] + 2)) {
				Interface::IncorrectArg(argv[i]);
			}
		}

		else
			res.list->push_back(CS(std::pair<const char*, int>(argv[i], 0), nullptr));
	}

	return res;
}