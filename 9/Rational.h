#include "std_lib_facilities.h"

class Rational {
public:
	Rational(int nn, int dd);
	Rational(int nn);
	int numerator() const {return n;};
	int denumerator() const {return d;};
	void operator=(const Rational& b);
private:
	int n; //Numerator
	int d; //Denumerator
};

void operator<<(ostream& os, const Rational& n);
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
bool operator==(Rational a, Rational b);
double to_double(const Rational& a);