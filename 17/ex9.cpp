/* Chapter 17 Exercise 9
Which way does the stack grow: up (toward higher addresses) or down (toward lower addresses)? Which way does the free store initially grow 
(that is, before you use delete)? Write a program to determine the answers.
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <inttypes.h>

void stack_heap() {
	int* i = new int(99);
	int val = 99;
	int* ip = &val;
	int dif = reinterpret_cast<intptr_t>(ip) - reinterpret_cast<intptr_t>(i);
	std::cout << dif << '\n';
	stack_heap();	
}

int main() try {
	stack_heap();
}
catch(std::runtime_error& e) {
	std::cout<< e.what() << '\n';
}
catch(...) {
	std::cout << "Unknown error" << '\n';
}