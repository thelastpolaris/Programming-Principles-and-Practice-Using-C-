#include "Money.h"

Money::Money(string cu, double a)
:cur{cu}
{
	double c = a*100; // Convert to cents
	cents = c;
	double r = cents%10; // Check if the number should be rounded up or down
	if (r > 5) cents += 10 - r;
	else if (r < 5) cents -= r;
}

void operator>>(istream& is, Money& a) {
	double cents = 0;
	string cur;
	is >> cur >> cents;
	a = Money{cur, cents}; // Update the value
}

void operator<<(ostream& os, const Money& a) {
	double c = a.write_cents()*0.01; // Convert cents to double
	os << a.write_cur() << c << endl;
}

void operator*(const Money&a, const Money&b) {
	throw(Money::Invalid());
}

void operator/(const Money&a, const Money&b) {
	throw(Money::Invalid());
}

Money operator+(const Money&a, const Money&b) { 
	vector<Currency> cur {{"USD","DKK",3},{"USD","KZT",187}}; // Conversion rates
	for (Currency x : cur) { // convert the second figure and sum them
		if (a.write_cur() == x.write_cur_a() && b.write_cur() == x.write_cur_b()) return Money {a.write_cur(), a.write_double() + b.write_double()/x.write_ratio()};
		}
		throw(Money::Invalid{});
	}

Money operator-(const Money&a, const Money&b) { 
	vector<Currency> cur {{"USD","DKK",3},{"USD","KZT",187}}; // Conversion rates
	for (Currency x : cur) { // convert the second figure and sum them
		if (a.write_cur() == x.write_cur_a() && b.write_cur() == x.write_cur_b()) {
			
			double i = a.write_double() - b.write_double()/x.write_ratio();

			if (i < 0) throw(Money::Invalid{});
			return Money {a.write_cur(), i};
		}
	}
	throw(Money::Invalid{});
}

/*int main() try {
	Money usd = Money{"USD", 120.20};
	Money dkk = Money{"KZT", 10010000};

	Money usd_dkk = usd-dkk;

	cout << usd_dkk;
}

catch(Money::Invalid) {
	cerr << "Error\n";
}*/