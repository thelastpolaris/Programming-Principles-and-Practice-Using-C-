/**
Exercsie 7
Write versions of the cat_dot() s from the previous exercises to take C-style strings as arguments and return a 
free-store-allocated C-style this exercise with the effort involved for exercises 5 and 6.
**/

#include <iostream>

using namespace std;

int stringlen(const char* s) {
	int i = 0;
	while(*s) {
		++i;
		++s;
	}
	return i;
}

char* strcopy(const char* source, char* dest) {
	while(*source) {
		*dest = *source;
		++dest;
		++source;
	}

	return dest;
}

char* cat_dot(const char* s1, const char* s2, const char* sep) {
	int len = stringlen(s1) + stringlen(s2) + stringlen(sep);
	char* s = new char[len];

	s = strcopy(s1, s);
	s = strcopy(sep, s);
	s = strcopy(s2, s);

	s -= len;
	return s;
}

int main() {
	cout << cat_dot("Niels", "Bohr", ",") << endl;
}