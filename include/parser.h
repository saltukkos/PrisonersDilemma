#pragma once

#include <string>
#include "game.h"

struct ParseResult
{
	Mode mode;
	int steps;
	std::shared_ptr<VectorCS> list;
	std::string fileName;
	std::string dir;

	ParseResult() : 
		mode(Mode::none),
		steps(0),
		list(new VectorCS)
		{}
};

ParseResult Parse(int argc, const char *argv[]);

bool KeyWord(ParseResult& res, const char* arg);