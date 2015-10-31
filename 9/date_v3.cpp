#include "std_lib_facilities.h" 

class Date {
	int y, m, d; // Year, Month, Day
public:
	Date(int y, int m, int d)
	:y{y}, m{m}, d{d}
	{
		if (m < 1 || m > 12) throw Invalid{}; // If month is not valid throw Invalid{}
		if (d < 1 || d > 31) throw Invalid{}; // If day is not valid throw Invalid{}
	}
	void add_day(int n);
	int month() {return m;};
	int year() {return y;};
	int day() {return d;};
	class Invalid {}; // To throw when the error was found
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
	Date today {1978, 4, 5};
	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << tomorrow;
}
catch (Date::Invalid) {
	error("Invalid date");
}
