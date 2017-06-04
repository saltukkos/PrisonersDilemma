#include "interface.h"

#include <iomanip>
#include <iostream>

int Interface::GetSteps(std::string& input) {
	
	size_t found = std::string::npos;

	std::getline(std::cin, input);
	int steps = 1;

	if ((found = input.find("tick")) != std::string::npos) {
		if (input.length() > found + 4) {
			try {
				steps = std::stoi(input.substr(5));

				if (steps < 1) {
					std::cerr << "Incorrect steps number" << std::endl;
					return ERROR;
				}

			}
			catch (...) {
				std::cerr << "Incorrect steps number" << std::endl;
				return ERROR;
			}
		}

		return steps;
	}

	else if ((found = input.find("quit")) != std::string::npos) {
		return QUIT;
	}

	return 0;
}

void Interface::IncorrectSteps() {

	std::cerr << "Incorrecrt steps count" << std::endl;

}

void Interface::CountTooBig() {
	std::cerr << "Steps count is not in int range" << std::endl;
}

void Interface::DefaultTable() {

        std::cerr << "Using default score table" << std::endl;

}

void Interface::InvalidConfig(const char* name) {

	std::cerr << "Invalid config file \"" << name << '"' << std::endl;

}

void Interface::NotFound(const std::string& strategy) {

	std::cerr << "Warning! Strategy " << strategy
		<< " isn't found" << std::endl;

}

void Interface::NoConfig(const std::string& dir) {

	std::cerr << "Warning! Config file symbiosys.cfg is"
		" not found in directory " << dir << std::endl;
}

void Interface::NoMode(const std::string& mode) {

	std::cerr << "'" << mode << "' is not a mode" << std::endl;

}

void Interface::IncorrectArg(const char* arg) {

	std::cerr << "Incorrect argument " << arg << std::endl;

}

void Interface::IncorrectCommand(const std::string& command) {

	std::cerr << '"' << command << "\" is unknown command" << std::endl;

}

void Interface::ShowHelp() {

	std::cout << "List of avaliable strategies:" << std::endl;

}

void Interface::GetComand() {

	std::cerr << "Type \"tick\" or \"tick <n>\" :" << std::endl;

}

void Interface::Match(const char* a, const char* b, const char* c) {

	std::cout << "Match between " << a << ", "
		<< b << " and " << c << std::endl;

}

void Interface::ShowName(const std::string& name) {

	std::cout << name << std::endl;

}

void Interface::TableHeader() {

	std::cout.setf(std::ios::left);
	std::cout << std::endl << std::setw(20) << "name"
		<< std::setw(15) << "action"
		<< std::setw(10) << "got"
		<< std::setw(10) << "score" << std::endl << std::endl;
}

void Interface::Ending() {
	std::cout << std::endl;
}

void Interface::FinishTournament() {

        std::cout << "\nTournament is finished, the results are in:" << std::endl;

}

void Interface::ShowStep(const char* name, bool defect, int up, int score) {

	std::cout << std::setw(20) << name
		<< std::setw(15) << (defect ? "defeats" : "cooperates")
		<< std::setw(10) << up
		<< std::setw(10) << score << std::endl;

}

void Interface::ShowResult(int place, const char* name, int score) {

	std::cout << '#' << place << " "
		<< name << " - " << score << std::endl;

}
