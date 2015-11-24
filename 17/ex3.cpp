/* Chapter 17 Exercise 3
Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their lowercase equivalents. 
For example, Hello, World! becomes hello, world!. Do not use any standard library functions. A C-style string is a zero-terminated array of 
characters, so if you find a char with the value 0 you are at the end.
*/
#include <iostream>


void to_lower(char* s) {
	do if(*s >= 65 && *s <= 90) *s += 32;
	while(*s++);
}

int main() {
	char c_string[] = "HELLO WORLD!";
	std::cout << c_string << '\n';
	to_lower(c_string);
	std::cout << c_string << '\n';
}