#include <iostream>
#define enter '\n'


class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	//overload for comparison, spaceship

	auto operator<=>(const Fraction& fr) const 
	{
		double fr_01 = static_cast<double>(numerator_) / static_cast<double>(denominator_);
		double fr_02 = static_cast<double>(fr.numerator_) / static_cast<double>(fr.denominator_);
		return fr_01 <=> fr_02;
	};

	//overload for assignment

	bool operator== (const Fraction& fr) const = default;
};

int main(int argc, char** argv) {
	
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return 0;
}