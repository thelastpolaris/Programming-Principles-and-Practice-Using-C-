#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include<stdexcept>
using namespace std;

const int not_a_reading = -7777;
const int not_a_month = -1;
const string year_keyword = "year";
const string month_keyword = "month";
const string left_bracket = "{ ";
const string right_bracket = " }";
const string left_parenthesis = " ( ";
const string right_parenthesis = " ) ";

void error(string s) {
	throw runtime_error(s);
}

struct Day {
	vector<double> hour {vector<double> (24, not_a_reading)};
};

struct Month {
	int month {not_a_month};
	vector<Day> day {32};
};

struct Year {
	int year;
	vector<Month> month {12};
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

vector<string> month_input_tbl = {
           "jan", "feb", "mar", "apr", "may", "jun", "jul",
           "aug", "sep", "oct", "nov", "dec"
};

int month_to_int(string s)
// is s the name of a month? If so return its index [0:11] otherwise –1
{
        for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
        return -1;
}

void end_of_loop(istream& ist, char term, const string& message) {
	if(ist.fail()) {
		ist.clear();
		char ch;
		if(ist >> ch && ch==term) return;
		error(message);
	}
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r)
// a rough test
{
    if (r.day<1 || 31<r.day) return false;
    if (r.hour<0 || 23<r.hour) return false;
    if (r.temperature<implausible_min|| implausible_max<r.temperature) return false;
    return true;
}

istream& operator>>(istream& is, Reading& r) {
    char ch1;
	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	char ch2;
	int d; // Day
	int h; // Hour
	double t; // Temperature
	is >> d >> h >> t >> ch2;
    if (ch2 != ')') error("Something wrong with input format");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

istream& operator>>(istream& is, Month& m) {
    char ch = 0;
    if (is >> ch && ch!='{') {
        is.unget();
        is.clear(ios_base::failbit); // we failed to read a Month
        return is;
    }
    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month") error("Bad start of month");
    m.month = month_to_int(mm);
    int duplicates = 0;
    int invalids = 0;
    for (Reading r; is >> r;) {
        if(is_valid(r)) {
            if(m.day[r.day].hour[r.hour] != not_a_reading) ++duplicates;
    		m.day[r.day].hour[r.hour] = r.temperature;
    	}
    	else ++invalids;
    }
    if (invalids) error("invalid readings in month");
    if (duplicates) error("duplicate readings in month");
    end_of_loop(is,'}',"bad end of month");
    return is;
}

istream& operator>>(istream& is, Year& y) {
	char ch = 0;
    is >> ch;
    if (ch!='{') {
        is.unget();
        is.clear(ios_base::failbit); // we failed to read a Month
        return is;
    }
    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != year_keyword) {
        error("Bad start of year");
        }
    y.year = yy;
    while(true) {
    	Month m;
    	if(!(is >> m)) break;
    	y.month[m.month] = m;
    }
    end_of_loop(is,'}',"bad end of year");
    return is;
}

ostream& operator<<(ostream& os, const Month& m) {
    os << left_bracket << month_keyword << " " << month_input_tbl[m.month];
    for (int i = 1; i < m.day.size(); i++) {
        for (int b = 0; b < m.day[b].hour.size(); b++) {
            if (m.day[i].hour[b] != not_a_reading) os << left_parenthesis << i << " " << b << " " << m.day[i].hour[b] << right_parenthesis;
        }
    }
    os << right_bracket;
    return os;
}

ostream& operator<<(ostream& os, const Year& y) {
    os << left_bracket << year_keyword << " " << y.year << " ";
    for (Month m : y.month) if (m.month != not_a_month) os << m;
    os << right_bracket << endl;
    return os;
}

void print_year(ostream& os, Year y) {
    os << y;
}

int main() try {
	cout <<"Please enter the name of file\n";
	string iname;    
	cin >> iname;
	ifstream ist {iname};
	if (!ist) error("can't open input file");
	ist.exceptions(ist.exceptions()|ios_base::badbit);
	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ost {oname};
	if (!ost) error("can't open output file");
	vector<Year> ys;
	while(true) {
          Year y;                  // get a freshly initialized Year each time around
          if (!(ist>>y)) break;
          ys.push_back(y);
}
	cout << "read " << ys.size() << " years of readings\n";
    for (Year y : ys) print_year(ost, y);
}

catch (exception& e)
{
    cerr << "Exception catched : " << e.what() << endl;
}