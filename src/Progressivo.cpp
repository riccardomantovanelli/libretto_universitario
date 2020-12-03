#include "Progressivo.hpp"
#include <iostream>
#include <string>

namespace ProgSpace {

static int prog;

int Progressivo::getProg() { return prog++; }
} // namespace ProgSpace
