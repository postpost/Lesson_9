#include <iostream>
#include "gcd.h"
#include "lcm.h"
#include "fraction.h"
#include "errorDivisionByZero.h"
#define enter '\n'


int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	int num , denom = 0;
	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> num;
	const int n_num = num;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> denom;
	const int n_denom = denom;
	Fraction f1 (n_num, n_denom);
	
	int num_2 = 0, denom_2 = 0;
	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> num_2;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> denom_2;
	Fraction f2 (num_2, denom_2);
	

	Fraction f3 =f1 + f2;
	std::cout << num << "/" << denom << " + " << num_2 << "/" << denom_2 << "= ";
	f3.print(); 
	
	Fraction f4 = f1 - f2;
	std::cout << num << "/" << denom << " - " << num_2 << "/" << denom_2 << "= ";
	f4.print();

	Fraction f5 = f1 * f2;
	std::cout << num << "/" << denom << " * " << num_2 << "/" << denom_2 << "= ";
	f5.print();

	Fraction f6(num, denom);
	f6 = f6 / f2;
	std::cout << num << "/" << denom << " / " << num_2 << "/" << denom_2 << "= ";
	f6.print();

	Fraction f7(num, denom);
	Fraction f7_old = ++f7;
	//f7.print();
	
	Fraction f8 = f7 * f2;

	std::cout << "++" << num << "/" << denom << " * " << num_2 << "/" << denom_2 << "= ";
	f8.print();
	std::cout << "«начение дроби 1 = ";
	f7_old.print();

	Fraction f9 = f7_old--;
	Fraction f9_old = f9;
	Fraction f10 = f9 * f2;
	

	std::cout << f9_old.get_numerator() << "/" << f9_old.get_denominator() <<"--"<<" * " << num_2 << "/" << denom_2 << "= ";
	f10.print();
	std::cout << "«начение дроби 1 = ";
	f7_old.print();

	//std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	

	return 0;
}