#include "std_lib_facilities.h" 

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
	Date(int y, Month m, int d)
	:y{y}, m{m}, d{d}
	{
		if (int(m) < 1 || int(m) > 12) throw Invalid{}; // If month is not valid throw Invalid{}
		if (d < 1 || d > 31) throw Invalid{}; // If day is not valid throw Invalid{}
	}
	void add_day(int n);
	int month() {return int(m);};
	int year() {return y;};
	int day() {return d;};
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

ostream& operator<<(ostream& os, Date& dd)
{
	return os << '(' << dd.year() << ',' << dd.month() << ',' << dd.day() << ')';
}

int main() try{
	Date today {1978, Month::may, 5};
	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << tomorrow;
}
catch (Date::Invalid) {
	error("Invalid date");
}
