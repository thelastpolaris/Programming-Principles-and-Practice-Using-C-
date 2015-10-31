#include "Chrono.h"

namespace Chrono {

	Date::Date(int yy, Month mm, int dd)
	:y{yy}, m{mm}, d{dd}
	{
		if(!is_date(yy,mm,dd)) throw Invalid{};
	}

	Day what_dow(Date d) {
	return Day((d - default_date() + 1)%7);
	}

	const Date& default_date(){
		static Date dd {1970, Month::Jan, 1}; // 2001.01.01 is Tuesday
		return dd;
	}

	Date::Date()
	:y{default_date().year()},
	m{default_date().month()},
	d{default_date().day()}
	{
	}

	void Date::add_day(int n) {
		int max = days_in_month(m, y);
		if ((d + n) <= 0) throw Date::Invalid{};
		if ((d + n) > max) {
			add_month(1);
		}
		d += n;
	}

	void Date::add_month(int n) {
		if ((int(m)+n) < 1 || (int(m) + n) > (int(Month::Dec) + 1)) throw Date::Invalid{};
		m = (m == Month::Dec) ? Month::Jan : Month(int(m) + n);
	}

	void Date::add_year(int n) {
		if (m == Month::Feb && d == 29 && (!leapyear(y+n))) {

			m = Month::Mar;
			d = 1;

		}
		y += n;
	}

	int days_in_month(Month m, int y) {
		switch (m){
			case Month::Feb: // If the month is February and it is a leap year then return 29 days
			return (leapyear(y)) ? 29:28;
			case Month::Apr: case Month::Jun: case Month::Sep: case Month::Nov:
			return 30;
		}
		return 31;
	}

	int days_in_year(int y) {
		if (leapyear(y)) return 366;
		return 365;
	}

	bool is_date(int y, Month m, int d) {
		if (y < 1970) return false;
		if (m < Month::Jan || Month::Dec < m) return false;
		if (d <= 0 || days_in_month(m, y) < d) return false;
		return true;
	}

	bool leapyear(int n) {
		if (n%4) return false;
		else if (n%100) return true;
		else if (n%400) return false;
		return true;
	}

	Date next_workday(const Date& d) {
		Date p = d;
		Day dow = what_dow(p);
		switch (dow){
			case Day::Fr: case Day::Sa:
				p.add_day(7-int(dow)+1);
			break;
			default:
			p.add_day(1);
		}
		return p;
	}

	long int days_since_0(const Date& d) {
		return d - default_date();
	}

	int week_of_the_year(const Date& d) {
		Date p = Date {d.year(), Month::Jan, 1};
		return (d - p)/7;
	}

	bool operator==(const Date& a, const Date& b) {
		if (a.year() == b.year() &&
			a.month() == b.month() &&
			a.day() == a.day()) return true;
			return false;
	}

	bool operator!=(const Date& a, const Date& b) {
		return !(a == b);
	}

	int operator-(Date a, Date b) { // Returns the difference betwee two dates
		int x = days_in_year(b.year());
		
		for (int i = int(Month::Jan); i < int(b.month()); i++) {

			x -= days_in_month(Month(i), b.year());

		}

		x -= b.day();
		
		for (int i = b.year(); i < a.year(); i++) {
			x += days_in_year(i);
		}
		
		for (int i = (int(a.month()) + 1); i <= int(Month::Dec); i++) {
			x -= days_in_month(Month(i), a.year());
		}

		x -= days_in_month(a.month(), a.year()) - a.day();

		return x;
	}

	ostream& operator<<(ostream& os, Date& a) {
		os << "(" << a.year() << ", " << int(a.month()) << ", " << a.day() << ")" << endl;
		return os;
	}

	istream& operator>>(istream& is, Date& a) {
		int y, m, d; // Year, Month, Day
		char ch1, ch2, ch3, ch4; // To check the format
		if (!is) return is;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (ch1 != '(' || ch2 != ',' || ch3 !=',' || ch4 !=')') { // Format error
			is.clear(ios_base::failbit); // Set the fail bit
			return is;
		}
		a = Date{y, Month(m), d};
		return is;
	}
}


