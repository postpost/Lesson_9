#pragma once


class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction();
	Fraction(int numerator, int denominator);
	//Constructor of copy
	Fraction(const Fraction& fr);

	int get_numerator();
	int get_denominator();
	//reduce
	void reduce(int new_numerator_, int new_denominator_);
	//overloads
	// 1. Sum
	Fraction operator+ (const Fraction& right);
	// 2. Substruct
	Fraction operator-(const Fraction& right);
	// 3. Multiply
	Fraction operator*(const Fraction& right);
	Fraction operator*(int a);
	// 4. Division
	Fraction operator/(const Fraction& right);
	// 5. Unary minus
	Fraction operator-();
	// 6.1 Increment prefix
	Fraction operator++();
	// 6.2 Increment postfix
	Fraction operator++ (int);
	// 7.1 Decrement prefix
	Fraction operator -- ();
	// 7.1 Decrement postfix
	Fraction operator -- (int);

	void print();
};