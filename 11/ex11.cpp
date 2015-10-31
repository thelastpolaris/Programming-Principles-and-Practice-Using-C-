/* Chapter 11 Exercise 11
Write a function vector<string> split(const string& s, const string& w) that returns a vector of whitespace-separated substrings 
from the argument s, where whitespace is defined as “ordinary whitespace” plus the characters in w.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> split(const string& s, const string& w) { // String for processing and string that holds separators
	string b = s;
	for (char& ch : b) {
		for (char c : w) {
			if (ch == c) ch = ' ';
		}
	}
	std::istringstream is {b};
	vector<string> str;
	string x;
	while (is >> x) str.push_back(x);
	return str;
}

int main() {
	string s;
	string w = ";:,.?!()\"{}<>/&$@#%^*|~";
	vector<string> str;
	std::getline(std::cin,s);
	str = split(s,w);
	for (string i : str) std::cout << i << std::endl;
}