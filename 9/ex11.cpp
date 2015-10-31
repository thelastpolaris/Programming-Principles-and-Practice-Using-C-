#include "Chrono.h"

using namespace Chrono;

int main() try {
	Date d1 = Date();
	Date d2 = Date{2015, Month::Jul, 1};
	Date d3 = next_workday(d2);

	cout << int(what_dow(d2)) << endl;
	cout << d3;
	long int d4 = days_since_0(d2);
	cout << d4;
	
}
catch(Date::Invalid) {
	error("ERROR!");
}