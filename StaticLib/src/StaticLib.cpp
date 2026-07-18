#include "StaticLib/StaticLib.h"

namespace StaticLib {

std::string greet(const std::string& name) {
    return "Hello, " + name + "!";
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

} // namespace StaticLib
