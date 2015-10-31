#include "std_lib_facilities.h" 

struct Date {
	int y; // Year
	int m; // Month
	int d; // Day
	Date(int y, int m, int d)
	:y{y}, m{m}, d{d}
	{}
};

struct Invalid {};

void init_day (Date& dd, int y, int m, int d) {
	if (m < 1 || m > 12) throw Invalid{}; // If month is not valid throw Invalid{}
	if (d < 1 || d > 31) throw Invalid{}; // If day is not valid throw Invalid{}

	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n) {
	if (n+dd.d < 1 || n+dd.d > 31) throw Invalid{};
	dd.d += n;
}

ostream& operator<<(ostream& os, const Date& dd)
{
	return os << '(' << dd.y << ',' << dd.m << ',' << dd.d << ')';
}

int main() try{
	Date today {1978, 4, 5};
	//init_day(today, 1978, 6, 25);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	cout << tomorrow;
}
catch (Invalid) {
	error("Invalid date");
}
