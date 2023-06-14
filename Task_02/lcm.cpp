#include "lcm.h"
#include "gcd.h"

int LCM(int denom_1, int denom_2) {
	if (denom_1 == denom_2) {
		return 1;
	}
	else {
		return (denom_1 * denom_2) / GCD(denom_1, denom_2);
	}
	
}
