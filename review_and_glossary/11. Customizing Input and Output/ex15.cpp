/* Chapter 11 Exercise 15
Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers using scientific format 
and precision 8 in four fields of 20 characters per line.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>

using std::string;

void error(string s) {
	throw std::runtime_error(s);
}

int main() try {

	//Open file for reading
	std::cout << "Please enter the file name\n";
	string iname;
	std::cin >> iname;
	std::ifstream ifs {iname};
	if (!ifs) error("Wrong file name");

	//Open file for writing
	std::cout << "Please enter output file name\n";
	string oname;
	std::cin >> oname;
	std::ofstream ofs {oname};
	if (!ofs) error("Wrong file name");

	double i, i1, i2, i3;

	ofs.setf(std::ios_base::left, std::ios_base::adjustfield);
	while (ifs >> i >> i1 >> i2 >> i3) {
		ofs << std::setprecision(8) << std::scientific << std::setw(20) << i << std::setw(20) << i1 << std::setw(20) << i2 << std::setw(20) << i3 << std::endl;
	}

}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}