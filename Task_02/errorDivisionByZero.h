#pragma once
#include <iostream>

class ErrorDivisonByZero : public std::exception {
public:
	ErrorDivisonByZero(const char* msg);
};
