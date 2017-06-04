#pragma once

#include <string>

namespace Interface {

	int GetSteps(std::string& input);

	void IncorrectSteps();

	void CountTooBig();

	void DefaultTable();

	void InvalidConfig(const char* name);

	void ShowName(const std::string& name);

	void GetComand();

	void FinishTournament();

	void NotFound(const std::string& strategy);

	void NoConfig(const std::string& dir);

	void NoMode(const std::string& mode);

	void IncorrectArg(const char* arg);

	void IncorrectCommand(const std::string& command);

	void ShowHelp();

	void Match(const char* a, const char* b, const char* c);

	void TableHeader();

	void Ending();

	void ShowStep(const char* name, bool defeat, int up, int score);

	void ShowResult(int place, const char* name, int score);

	static const int QUIT = -1;

	static const int ERROR = 0;

}