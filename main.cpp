#include <iostream>
#include <cmath>
#include <string>
#include <mpreal.h>



#define TOP 4
#define BOTTOM 12
#define HEIGHT 12
#define MAX_ITER 375000
#define DEC_POINTS 275000

using namespace std;
using centFloat = mpfr::mpreal;

centFloat aTrap(centFloat baseOne, centFloat baseTwo, centFloat high) {
	return (high*((baseOne+baseTwo)/2));
}
centFloat tLen(centFloat baseOne, centFloat baseTwo, centFloat high, centFloat partHigh) {
	return (max(baseOne,baseTwo)-((abs(baseOne-baseTwo)/high)*partHigh));

}
int main() {
	mpfr::mpreal::set_default_prec(mpfr::digits2bits(DEC_POINTS));
	std::cout.precision(DEC_POINTS);
	centFloat x = 0;
	centFloat currentJump = HEIGHT;

	for (unsigned long int i = 1; i <= MAX_ITER; i++) {
		
		currentJump /= 2;
		centFloat curLen = tLen(TOP,BOTTOM,HEIGHT,x);
		centFloat aOne = aTrap(BOTTOM,curLen,x);	
		centFloat aTwo = aTrap(TOP,curLen,12-x);
		cout << to_string(i) << endl;
		if (currentJump == 0) {
			cout << "Needed (by zero): " << to_string(i) << " loops" << endl;
			
			break;
		}
		else if (aOne > aTwo) {
			x -= currentJump;
		} else if (aOne < aTwo) {
			x+= currentJump;
			
		} else {
			cout << "Needed: " << to_string(i) << " loops" << endl;
			
			break;
		}
		
		
	}

	cout << "Got: " << x << endl;
}
