/**
Exercise 3
Write a function, int strcmp(const char* s1, const char* s2) , that compares C-style strings. Let it 
lexicographically after s2 . Do not use any standard library functions. Do not use subscripting; use the 
dereference operator * instead.
**/

#include <iostream>
using namespace std;

int strcmp(const char* s1, const char* s2) {
	while(*s1 && *s2) {
		if(*s1 > *s2) return -1;
		else if(*s1 < *s2) return 1;
		++s1;
		++s2;
	}

	if(*s1 && !*s2) return 1;
	else if(!*s1 && !s2) return -1;
	return 0;
}

int main() {
	cout << strcmp("helloworld", "hello") << endl;
}