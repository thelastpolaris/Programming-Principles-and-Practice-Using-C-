/* Chapter 11 Exercise 9
Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary text file into binary and 
one program that reads binary and converts it to text. Test these programs by comparing a text file with what you get 
by converting it to binary and back.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::string;

void error(string s) {
	throw runtime_error(s);
}

int main() try {
	std::cout << "Please input the name of file\n";
	string iname;
	std:: >> iname;
	std::ifstream ifs {iname, std::ios_base::binary};
	if (!ifs) error("Wrong filename");
	
}
catch (runtime_error& e) {
	std::cout << e.what() << std::endl;
}