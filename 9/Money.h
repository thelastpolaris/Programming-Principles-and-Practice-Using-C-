#include "std_lib_facilities.h"

class Money {
public:
	Money (string cu, double a);
	string write_cur() const {return cur;};
	long int write_cents() const {return cents;};
	double write_double() const { return cents*0.01;};
	class Invalid{};
private:
	long int cents;
	string cur; // Currency
};
void operator>>(ostream& os, const Money& a);
void operator<<(ostream& os, const Money& a);
void operator*(const Money&a, const Money&b);
void operator/(const Money&a, const Money&b);
Money operator+(const Money&a, const Money&b);
Money operator-(const Money&a, const Money&b);

class Currency {
public:
	Currency(string c_a, string c_b, int r)
	:cur_a{c_a}, cur_b{c_b}, ratio{r}
	{
	}
	string write_cur_a() {return cur_a;};
	string write_cur_b() {return cur_b;};
	int write_ratio() {return ratio;};
private:
	string cur_a;
	string cur_b;
	int ratio;
};