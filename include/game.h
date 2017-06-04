#pragma once

#include <memory>
#include <vector>
#include "strategy.h"

using CS = std::pair< std::pair<const char*, int>, std::shared_ptr<Strategy> >;
using VectorCS = std::vector<CS>;

enum class Mode {none, detailed, fast, tournament };