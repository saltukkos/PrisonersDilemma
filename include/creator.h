#pragma once

#include <string>
#include "strategy.h"

template<class T>
Strategy* Creator(const std::string& dir) {
	return new T(dir);
}