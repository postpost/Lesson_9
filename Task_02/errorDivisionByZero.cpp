#include "errorDivisionByZero.h"
#include <iostream>

ErrorDivisonByZero::ErrorDivisonByZero(const char* msg) :std::exception(msg) {
	std::cout << msg << std::endl;
}