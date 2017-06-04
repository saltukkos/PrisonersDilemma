#include "strategy.h"

Strategy::Strategy(const std::string& directory):
	dir(directory) {
	if ((0 != dir.length()) && (dir[dir.length() - 1] != '/') && (dir[dir.length() - 1] != '\\'))
		dir += '/';
}

Strategy::~Strategy() {}
