#include "gcd.h"


int GCD(int a, int b) {
	return (a == 0) ? b : GCD(b % a, a);

	/*while (b > 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;*/

	/*if (a%b == 0) {
		return a;
	}
	if (b % a == 0) {
		return b;
	}
	if (a > b) {
		return GCD(a % b, b);
		return GCD(a, b % a);
	}*/
}