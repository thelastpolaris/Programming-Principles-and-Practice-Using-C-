/* Chapter 11 Exercise 14
Write a program that reads a text file and writes out how many characters of each character classification (§11.6) are in the file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::string;
using std::vector;

void error(string s) {
	throw std::runtime_error(s);
}

int main() try {

	//Open file for reading
	std::cout << "Please enter the file name\n";
	string iname;
	std::cin >> iname;
	std::ifstream ifs {iname};
	int space = 0, letter = 0, digit = 0, punct = 0, cntrl = 0, upper = 0, lower = 0;
	char ch;
	if (!ifs) error("Wrong file name");
	std::cout << "File '" << iname << "' contains:" << std::endl;
	while (ifs.get(ch)) {
		if (std::isspace(ch)) space++;
		else if (std::isalpha(ch)) {
			letter++;
			if (std::isupper(ch)) upper++;
			else lower++;
		}
		else if (std::isdigit(ch)) digit++;
		else if (std::ispunct(ch)) punct++;
		else if (std::iscntrl(ch)) cntrl++;
	}
	std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	std::cout << std::setw(6) << space << " whitespaces\n";
	std::cout << std::setw(6) << letter << " letters (";
	std::cout << upper << " of them are/is uppercase and ";
	std::cout << lower << " of them are/is lowercase)\n";
	std::cout << std::setw(6) << digit << " digits\n";
	std::cout << std::setw(6) << punct << " punctuation marks\n";
	std::cout << std::setw(6) << cntrl << " control char.\n";
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}