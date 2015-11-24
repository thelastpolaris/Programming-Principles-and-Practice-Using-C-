/* Chapter 17 Exercise 6
This chapter does not say what happens when you run out of memory using new. That’s called memory exhaustion. Find out what happens. 
You have two obvious alternatives: look for documentation, or write a program with an infinite loop that allocates but never deallocates. 
Try both. Approximately how much memory did you manage to allocate before failing?
*/
#include <iostream>
#include <stdexcept>
#include <string>

int main() try {
	int i = 0;
	while(true)	{
		double* ch = new double(1);
		std::cout << i << '\n';
		i++;
	}
}
catch(std::runtime_error& e) {
	std::cout<< e.what() << '\n';
}
catch(...) {
	std::cout << "Unknown error" << '\n';
}