#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Roman_sym {
		int num;
		string s;
};

struct Roman_dig {
		int num;
		char ch;
};

void error(string s);
bool is_valid(string r);
bool is_valid(char ch);
int conv_to_int(string r);
string conv_to_rom(int n);
int sym_to_int(string ch);

class Roman_int {
public:
	Roman_int(string rr);
	Roman_int(int n);
	Roman_int();
	int as_int() const {return n;};
	string as_roman() const {return r;};
private:
	int n; // Integer numeral
	string r; // Roman numeral
};

istream& operator>>(istream& is, Roman_int& r);
ostream& operator<<(ostream& os, const Roman_int& r);