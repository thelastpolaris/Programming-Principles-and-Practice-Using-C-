/* Chapter 11 Exercise 4
Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal, decimal, 
or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and converts them to decimal form. 
Then your program should output the values in properly spaced columns like this:
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
#include <sstream>
#include <stdexcept>

using std::string;

void error(string s) {
	throw std::runtime_error(s);
}

struct Number_base {
	int num;
	char base;
};

void write(Number_base i) {
	std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	std::cout.setf(std::ios_base::showbase);
	switch(i.base) {
		case 'h':
			std::cout << std::hex << std::setw(4) << i.num << std::setw(12) << " hexadecimal" << " converts to " << std::dec << i.num << " decimal" << std::endl;
		break;
		case 'o':
			std::cout << std::oct << std::setw(4) << i.num << std::setw(12) << " octal" << " converts to " << std::dec << i.num << " decimal" << std::endl;
		break;
		case 'd':
			std::cout << std::dec << std::setw(4) << i.num << std::setw(12) << " decimal" << " converts to " << std::dec << i.num << " decimal" << std::endl;
		break;
	}
}

int main() try{
	char ch;
	string s;
	std::vector<Number_base> values;
	std::cout << "Enter several integers with prefix '0x' for hexadecimal value and '0' for octal one" << std::endl;
	int i;
	while (std::cin.get(ch)) {
		Number_base a;
		if (!isdigit(ch)) {
			if(isalpha(ch)) error("Not integer is provided");
			continue;
		}
		if (ch == '0') {
			std::cin.get(ch);
			if (ch == 'x') {
				std::cin >> std::hex >> a.num;
				a.base = 'h'; // H for hex
			}
			else if(isdigit(ch)) {
				std::cin.unget();
				std::cin >> std::oct >> a.num;
				a.base = 'o'; // O for octal
			}
			else {
				std::cin.unget();
				a.num = 0;
				a.base = 'o';
			}
		}
		else {
			std::cin.unget();
			std::cin >> a.num;
			a.base = 'd';
		}
		values.push_back(a);
	}
	for (Number_base i : values) write(i);
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}