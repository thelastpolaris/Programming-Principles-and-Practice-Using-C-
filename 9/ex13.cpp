#include "Rational.h"

Rational::Rational(int nn, int dd)
	:n{nn}, d{dd}
	{
	}
Rational::Rational(int nn)
	:n{nn}, d{1}
	{
	}

void Rational::operator=(const Rational& b) {
	n = b.n; // Assign numerator
	d = b.d; // Assign denumerator
}

Rational operator+(const Rational& a, const Rational& b) {
	int n = (a.denumerator() * b.numerator()) + (a.numerator() * b.denumerator());
	int d = a.denumerator() * b.denumerator();
	return Rational {n,d};
}

Rational operator-(const Rational& a, const Rational& b) {
	int n = ((a.numerator() * b.denumerator() - a.denumerator() * b.numerator()));
	int d = a.denumerator() * b.denumerator();
	return Rational {n,d};
}

Rational operator/(const Rational& a, const Rational& b) {
	int n = a.numerator()*b.denumerator();
	int d = a.denumerator()*b.numerator();
	return Rational {n,d};
}

Rational operator*(const Rational& a, const Rational& b) {
	int n = a.numerator()*b.numerator();
	int d = a.denumerator()*b.denumerator();
	return Rational {n,d};
}

bool operator==(Rational a, Rational b) {
	if (b.numerator() == a.numerator() && b.denumerator() == a.denumerator()) return true;
	return false;
}

void operator<<(ostream& os, const Rational& n) {
	os << n.numerator() << "/" << n.denumerator() << endl;
}

double to_double(const Rational& a) {
	return double(a.numerator())/double(a.denumerator());
}

/*int main() {
	Rational d1 {10,12};
	Rational d2 {5,6};
	Rational d3 = d2*d1;
	bool d4 = d1 == d2;
	cout << d4;
	double d5 = to_double(d2);
	cout << d5;
}*/