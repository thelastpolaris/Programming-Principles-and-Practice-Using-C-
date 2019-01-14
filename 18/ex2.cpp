/**
Exercise 2
Write a function, char* findx(const char* s, const char* x) , that finds the first occurrence of the C-style string 
x in s . Do not use any standard library functions. Do not use subscripting; use the dereference operator * 
instead.
**/


#include <iostream>
using namespace std;

const char* findx(const char* s, const char* x) {
	const char* x_orig = x;
	const char* starting_pointer = nullptr;
	while(*s) {
		if(!*x) {
			return s;
		}
		if(*x == *s) {
			if(!starting_pointer) starting_pointer = s;
			++x;
		} else {
			x = x_orig;
			starting_pointer = nullptr;
		}
		++s;
	}
	
	return starting_pointer;
}

int main() {
	cout << findx("helloworld", "hello") << endl;
}