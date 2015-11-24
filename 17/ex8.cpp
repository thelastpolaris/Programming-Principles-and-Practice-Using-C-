/* Chapter 17 Exercise 8
Do exercise 7 again, but this time read into a std::string 
rather than to memory you put on the free store (string knows how to use the free store for you).
*/
#include <iostream>
#include <stdexcept>
#include <string>

int main() try {
	std::string s;
	char c;
	while(std::cin.get(c) && c != '!') {
		s += c;
	}
	std::cout << s << '\n';
}
catch(std::runtime_error& e) {
	std::cout<< e.what() << '\n';
}
catch(...) {
	std::cout << "Unknown error" << '\n';
}