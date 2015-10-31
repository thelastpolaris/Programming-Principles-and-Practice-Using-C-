#include "Money.h"
#include "Rational.h"

int main() {
	Money m {"USD",1/3.0};
	cout << m;
	Rational r {1,8};
	double d = to_double(r);
	cout << endl << d;
}