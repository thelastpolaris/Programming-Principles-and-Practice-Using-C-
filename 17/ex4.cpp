/* Chapter 17 Exercise 4
Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. 
Do not use any standard library functions.
*/
#include <iostream>
#include <string>

char* strdup(const char* s) {
	int i = 0;
	while(s[i]) ++i;
	char* p = new char[i+1];
	for (int n = 0; s[n]; ++n) p[n] = s[n];
	p[i] = '\0';
	return p;
}

int main() {
	const char c_string[]{"Hello World!"};
	std::cout << c_string << '\n';
	char* sp = strdup(c_string);
	std::cout << sp << '\n';
	delete[] sp;
}