/* Chapter 11 Exercise 13
Reverse the order of words (defined as whitespace-separated strings) in a file. For example, Norwegian Blue parrotasd becomes parrot Blue Norwegian. 
You are allowed to assume that all the strings from the file will fit into memory at once.
*/

#include <iostream>
#include <fstream>
#include <sstream>
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
		vector<string> buf;
		string b, buffer;
		std::istringstream is {str[i]};
		while(is >> b) buf.push_back(b);
		for (int x = buf.size() - 1; x >= 0; x--) buffer += buf[x] + " ";		
		ofs << buffer << std::endl; // Add line from buffer to file
	}
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}