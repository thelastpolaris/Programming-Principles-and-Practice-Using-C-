/* Chapter 17 Exercise 2
How many bytes are there in an int? In a double? In a bool? Do not use sizeof except to verify your answer.
*/

#include <iostream>

int main() {
	std::cout << "int: " << sizeof(int) << '\n';
	std::cout << "double: " << sizeof(double) << '\n';
	std::cout << "bool: " << sizeof(bool) << '\n';
	std::cout << "char: " << sizeof(char) << '\n';
	std::cout << "long int: " << sizeof(long) << '\n';
	std::cout << "short int: " << sizeof(short) << '\n';
}