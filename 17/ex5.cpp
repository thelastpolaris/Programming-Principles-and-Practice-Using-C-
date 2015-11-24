/* Chapter 17 Exercise 5
Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.
*/
#include <iostream>
#include <stdexcept>
#include <string>

const char* findx(const char*s, const char*x) {
	for (int i = 0; s[i]; ++i) {
		if(s[i] == x[0]) {
			for(int n = 0; x[n]; ++n) {
				if(s[i+n] != x[n]) break;
				if(!(x[n+1])) return &s[i];
				if(!(s[n+1])) return 0;
			}
		}
	}
	return 0;
}

int main() try {
	char s[] = "Hello World!";
	char x[] = "orl";
	const char* f = findx(s,x);
	if (!f) throw std::runtime_error("No occurrence found");
	std::cout << f << std::endl;
}
catch(std::runtime_error& e) {
	std::cout<< e.what() << '\n';
}
catch(...) {
	std::cout << "Unknown error" << '\n';
}