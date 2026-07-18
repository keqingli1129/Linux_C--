#include <iostream>
#include "StaticLib/StaticLib.h"
#include "DynamicLib/DynamicLib.h"
int main(int, char**){
    std::cout << "Hello, from Linux_C++!\n";
    std::cout << StaticLib::greet("Alice") << std::endl;
    std::cout << "Factorial of 5: " << StaticLib::factorial(5) << std::endl;
    std::cout << "Addition of 3 and 4: " << DynamicLib::add(3, 4) << std::endl;
    std::cout << "Multiplication of 3 and 4: " << DynamicLib::multiply(3, 4) << std::endl;
}
