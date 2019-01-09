 /* Chapter 10
 Exercise 6
 Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. 
 Provide Roman_int with an as_int() member that returns the int value, so that if r is a Roman_int, 
 we can write cout << "Roman" << r << " equals " << r.as_int() << '\n';.
 */

#include "ex6.h"

void error(string s) {
	throw runtime_error(s);
}

vector<Roman_sym> symbols {
		   {1000, "M"},
	        {900, "CM"},
	        {500, "D"},
	        {400, "CD"},
	        {100, "C"},
	         {90, "XC"},
	         {50, "L"},
	         {40, "XL"},
	         {10, "X"},
	          {9, "IX"},
	          {5, "V"},
	          {4, "IV"},
	          {1, "I"}
};

vector<Roman_dig> rom_chars {
		   {1000, 'M'},
	        {500, 'D'},
	        {100, 'C'},
	         {50, 'L'},
	         {10, 'X'},
	          {5, 'V'},
	          {1, 'I'}
};

Roman_int::Roman_int(string rr)
:r{rr}
{
	if(!is_valid(rr)) error("Wrong format of numeral");
	n = conv_to_int(rr);
}

Roman_int::Roman_int(int nn)
:n{nn}
{
	if (nn <= 0) error("Wrong number");
	r = conv_to_rom(nn);
}

Roman_int::Roman_int() :r{"I"}, n{1} { }

bool is_valid(string r) {
	bool status;
	for (int i = 0; i < r.size(); i++) {
		status = false;
		for (Roman_dig ch : rom_chars) if (r[i] == ch.ch) status = true;
		}
	if (status != true) return false;
	return true;
}

bool is_valid(char r) {
	bool status;
	for (Roman_dig ch : rom_chars) if (r == ch.ch) return true;
	return false;
}

int sym_to_int(char ch) {
	for(Roman_dig s : rom_chars) {
		if (s.ch == ch) return s.num;
	}
	return 0;
}

int conv_to_int(string r) {
	int num = 0;
	for (int i = r.size() - 1; i >= 0; i--) {
		int s1 = sym_to_int(r[i]);
		int s2 = sym_to_int(r[i-1]);
		if (s1 > s2) {
			num += s1-s2;
			i--;
		}
		else num += s1;
	}
	return num;
}

string conv_to_rom(int n) {
	string r;
	while (n!=0) {
		for (int i = 0; i < symbols.size(); i++) {
			if (n >= symbols[i].num) {
				r += symbols[i].s;
				n -=symbols[i].num;
				break;
			}
		}
	}
	return r;
}

istream& operator>>(istream& is, Roman_int& r) {
	char ch;
	string s;
	while(is >> ch) {
		if (is_valid(ch)) {
			s += ch;
		}
		else {
			is.unget();
			break;
		}
	}
	cout << s << endl;
	r = Roman_int{s};
	return is;
}

ostream& operator<<(ostream& os, const Roman_int& r) {
	os << r.as_roman();
	return os;
}

/*int main() {
	Roman_int n {1954};
	cout << n.as_roman();
}*/
