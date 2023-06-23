#include <iostream>
#include "fraction.h"
#include "errorDivisionByZero.h"
#include "lcm.h"
#include "gcd.h"

// 1. Constructor realization
Fraction::Fraction(int numerator, int denominator)
{
	try {
		if (denominator > 0)
		numerator_ = numerator;
		denominator_ = denominator;
	}
	catch (ErrorDivisonByZero& ex) {
		throw ErrorDivisonByZero("Error...Division by zero!");
	}
	catch (...) {
		std::cout << "Unknown behavior...";
	}
}
//Constructor of copy
	Fraction::Fraction(const Fraction& fr) {
	numerator_ = fr.numerator_;
	denominator_ = fr.denominator_;
	};

	int Fraction:: get_numerator() {
		return numerator_;
	}

	int Fraction:: get_denominator() {
		return denominator_;
	}
//reduce

void Fraction::reduce(int new_numerator_, int new_denominator_) {
	int gcd = GCD(abs(new_numerator_), new_denominator_);
	if (gcd != 1) {
		numerator_ = new_numerator_ / gcd;
		denominator_ = new_denominator_ / gcd;
	}
};

// 1. Sum
  Fraction Fraction::operator+ (const Fraction& right) {
	int lcm = LCM(denominator_, right.denominator_);
	if (lcm != 1) {
		int left_num = numerator_ * right.denominator_;
		int right_num = right.numerator_ * denominator_;
		int new_numerator_ = left_num + right_num;
		int new_denominator_ = lcm;
		reduce(new_numerator_, new_denominator_);
		return Fraction(new_numerator_, new_denominator_);
	}
	
	else {
		int new_num = numerator_ + right.numerator_;
		return Fraction(new_num, denominator_);
	}
	
	//return *this;
};

// 2. Substruct
  Fraction Fraction::operator-(const Fraction& right) {
	  int lcm = LCM(denominator_, right.denominator_);
	  if (lcm != 1) {
		  int left_num = numerator_ * right.denominator_;
		  int right_num = right.numerator_ * denominator_;
		  int new_numerator_ = left_num - right_num;
		  int new_denominator_ = lcm;
		  reduce(new_numerator_, new_denominator_);
		  return Fraction(new_numerator_, new_denominator_);
	  }

	  else {
		  int new_num = numerator_ - right.numerator_;
		  return Fraction(new_num, denominator_);
	  }

};
// 3. Multiply
Fraction Fraction::operator*(const Fraction& right) {
	int new_num = numerator_ * right.numerator_;
	int new_denom = denominator_ * right.denominator_;
	reduce(new_num, new_denom);
	return Fraction(numerator_, denominator_);
};

Fraction Fraction::operator*(int a) {
	int new_num = numerator_ * a;
	int new_denom = denominator_;
	reduce(new_num, new_denom);
	return Fraction(new_num, new_denom);
};
// 4. Division
Fraction Fraction::operator/(const Fraction& right) {
	int new_num = numerator_ * right.denominator_;
	int new_denom = denominator_ * right.numerator_;
	reduce(new_num, new_denom);
	return Fraction(new_num, new_denom);
};
 //5. Unary minus
Fraction Fraction::operator-() {
	int new_num = -numerator_;
	return Fraction (new_num, denominator_);
};

// 6.1 Increment prefix
Fraction Fraction:: operator++() {
	this->numerator_ = numerator_ + denominator_;
	return *this;	
};
// 6.2 Increment postfix
Fraction Fraction:: operator++ (int) {
	Fraction duplicate(*this);
	this->numerator_ = numerator_+ denominator_;
	return duplicate;
};
// 7.1 Decrement prefix
Fraction Fraction::operator -- () {
	this->numerator_ = numerator_ - denominator_;
	return *this;
};
// 7.1 Decrement postfix
Fraction Fraction:: operator -- (int) {
	Fraction duplicate(*this);
	this->numerator_ = numerator_ - denominator_;
	return duplicate;
};

//print
void Fraction::print() {
	std::cout << numerator_ << "/" << denominator_ << std:: endl;
}



