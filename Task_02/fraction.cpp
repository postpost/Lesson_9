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
//Fraction::Fraction(const Fraction& fr) {
//	numerator_ = fr.numerator_;
//	denominator_ = fr.denominator_;
//};


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
// 4. Division
Fraction Fraction::operator/(const Fraction& right) {
	int new_num = numerator_ * right.denominator_;
	int new_denom = denominator_ * right.numerator_;
	reduce(new_num, new_denom);
	return Fraction(numerator_, denominator_);
};
// 5. Unary minus
//Fraction Fraction::operator-(const Fraction& right) {
//
//	int new_num = -right.numerator_;
//	int new_denom = -right.denominator_;
//	return *this;
//};
// 6.1 Increment prefix
Fraction& Fraction:: operator++() {

	int whole_num = denominator_, whole_denom = denominator_;
	Fraction f1(whole_num, whole_denom);
	Fraction f2(numerator_, denominator_);
	Fraction f3 = (f1 + f2);
	//reduce(f3.numerator_, f3.denominator_);
	numerator_ = f3.numerator_;
	denominator_ = f3.denominator_;
	return *this;
	
	/*int new_num = numerator_ + 1;
	int new_denom = denominator_ + 1;*/
};
// 6.2 Increment postfix
Fraction Fraction:: operator++ (int) {
	int whole_num = denominator_, whole_denom = denominator_;
	Fraction f1(whole_num, whole_denom);
	Fraction f2(numerator_, denominator_);
	Fraction f3 = (f2 + f1);
	//reduce(f3.numerator_, f3.denominator_);
	numerator_ = f3.numerator_;
	denominator_ = f3.denominator_;
	return *this;
};
// 7.1 Decrement prefix
Fraction Fraction::operator -- () {
	int whole_num = denominator_, whole_denom = denominator_;
	Fraction f1(whole_num, whole_denom);
	Fraction f2(numerator_, denominator_);
	Fraction f3 = (f1 - f2);
	//reduce(f3.numerator_, f3.denominator_);
	numerator_ = f3.numerator_;
	denominator_ = f3.denominator_;
	return *this;
};
// 7.1 Decrement prefix
Fraction Fraction:: operator -- (int) {
	int whole_num = denominator_, whole_denom = denominator_;
	Fraction f1(whole_num, whole_denom);
	Fraction f2(numerator_, denominator_);
	Fraction f3 = (f2 - f1);
	//reduce(f3.numerator_, f3.denominator_);
	numerator_ = f3.numerator_;
	denominator_ = f3.denominator_;
	return *this;

};

//print
void Fraction::print() {
	std::cout << numerator_ << "/" << denominator_ << std:: endl;
}



