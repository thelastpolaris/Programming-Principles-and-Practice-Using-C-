/* Chapter 11 Exercise 8
Write a program that given a file name and a word outputs each line that contains that word together with the line number. 
Hint: getline().
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

using std::string;

void error(string s) {
	throw std::runtime_error(s);
}

int main() try{
	string filename, word, s; // A name of file and a word to search for and a string to hold lines from file
	int counter = 0; // To count lines
	std::cout << "Please enter the name of file and a word to search for\n";
	std::cin >> filename >> word;
	std::ifstream ifs {filename};
	if (!ifs) error("Wrong filename");
	while(ifs) {
		counter++;
		std::getline(ifs, s);
		std::istringstream str {s};
		string b;
		while (str >> b) if (b == word) std::cout << counter << " : " << word << std::endl;
	}
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}