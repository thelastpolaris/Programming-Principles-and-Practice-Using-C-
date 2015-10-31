/* Chapter 11 Exercise 3
Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc pn tm!. 
Surprisingly often, the result is still readable; try it on your friends.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

using std::string;

void error(string s) {
	throw std::runtime_error(s);
}

int main() try{
	string filename, s; // A name of file and a string to hold line
	char ch;
	string vowel = "aeiouy"; // A list of all vowels in English
	std::cout << "Please enter the name of file where all vowels have to be deleted\n";
	std::cin >> filename;
	std::ifstream ifs {filename};
	if (!ifs) error("Wrong filename");
	std::ostringstream str;
	while(ifs) {
		ifs.get(ch);
		bool i = false;
		for (char x : vowel) if (ch == x) i = true;
		if (!i) str << ch;
	}
	
	std::ofstream ofs {filename};
	if (!ofs) error("Wrong filename");
	ofs << str.str();
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}