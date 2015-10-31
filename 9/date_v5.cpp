#include "std_lib_facilities.h" 

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec

};

Month operator++(Month& m) {
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

class Date {
public:
	Date(int y, Month m, int d)
	:y{y}, m{m}, d{d}
	{
		if (int(m) < 1 || int(m) > 12) throw Invalid{}; // If month is not valid throw Invalid{}
		if (d < 1 || d > 31) throw Invalid{}; // If day is not valid throw Invalid{}
	}
	Date()
	:y{1992}, m{Month::dec}, d{27}
	{

	}
	void add_day(int n);
	void add_month();
	int month() const {return int(m);};
	int year() const {return y;};
	int day() const {return d;};
	class Invalid {}; // To throw when the error was found
private:
	int y; // Year
	Month m;
	int d; // Day

};

void Date::add_day(int n) {
	if (n+d < 1 || n+d > 31) throw Invalid{};
	d += n;
}

void Date::add_month() {
	++m;
}

ostream& operator<<(ostream& os, Date& dd)
{
	return os << '(' << dd.year() << ',' << dd.month() << ',' << dd.day() << ')';
}

void some_function(Date& d, const Date& b) {
	cout << d.day();
	cout << b.day();
	d.add_day(1);
}

int main() try{
	//Date today {1978, Month::jun, 5};
	Date today;
	Date tomorrow = today;
	tomorrow.add_day(1);
	tomorrow.add_month();
	cout << tomorrow;
}
catch (Date::Invalid) {
	error("Invalid date");
}
