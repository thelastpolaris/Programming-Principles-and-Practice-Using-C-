/**
Exercsie 5
Write a function, string cat_dot(const string& s1, const string& s2) , that concatenates two strings with a dot in 
between. For example, cat_dot("Niels", "Bohr") will return a string containing Niels.Bohr.
**/

#include <string>
#include <iostream>

using namespace std;

string cat_dot(const string& s1, const string& s2) {
	string s = s1 + "." + s2;
	return s;
}

int main() {
	cout << cat_dot("Niels", "Bohr") << endl;
}