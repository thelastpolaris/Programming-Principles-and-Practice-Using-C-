/* Chapter 11 Exercise 12
Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa. 
Warning: There is no really good, portable, and efficient way of reading a file backward.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

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
	if (!ifs) error("Wrong file name");

	vector<string> str;
	string s;
	while (getline(ifs,s)) str.push_back(s); // Push all line from file to vector
	//Open file for writing
	std::cout << "Please enter output file name\n";
	string oname;
	std::cin >> oname;
	std::ofstream ofs {oname};
	if (!ofs) error("Wrong file name");

	for (int i = str.size() - 1; i >= 0; i--) { // Start reversing the lines from the last element of vector
		string buffer;
		for (int x = str[i].size(); x >= 0; x--) {
			if (isgraph(str[i][x])) buffer += str[i][x]; // Start reversing the line from its last character
			else buffer += " "; // Add to buffer
		}
		ofs << buffer << std::endl; // Add line from buffer to file
	}
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}