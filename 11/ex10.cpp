/* Chapter 11 Exercise 10
Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated substrings from the argument s.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> split(const string& s) {
	std::istringstream is {s};
	vector<string> str;
	string x;
	while (is >> x) str.push_back(x);
	return str;
}

int main() {
	string s;
	vector<string> str;
	std::getline(std::cin,s);
	str = split(s);
	for (string i : str) std::cout << i << std::endl;
}