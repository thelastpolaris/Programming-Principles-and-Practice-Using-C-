/**
Exercise 1
Write a function, char* strdup(const char*) , that copies a C-style string into memory it allocates on the 
free store. Do not use any standard library functions. Do not use subscripting; use the dereference operator * 
instead.
**/

#include <iostream>
using namespace std;

char* strdup(const char* s, int len) {
	char* dup = new char[len];
	while(*s) *dup++ = *s++;
	
	dup -= len;
	return dup;
}

int main() {
	const char* s = "hello world!";
	cout << strdup(s, 12) << endl;
}