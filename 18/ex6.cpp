/**
Exercsie 6
Modify cat_dot() from the previous exercise to take a string to be used as the separator (rather than dot) as
 its third argument.
**/

#include <string>
#include <iostream>

using namespace std;

string cat_dot(const string& s1, const string& s2, const string& sep) {
	string s = s1 + sep + s2;
	return s;
}

int main() {
	cout << cat_dot("Niels", "Bohr", ",") << endl;
}