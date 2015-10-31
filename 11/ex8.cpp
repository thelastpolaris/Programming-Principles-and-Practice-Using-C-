/* Chapter 11 Exercise 8
Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question mark), 
- (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). 
For example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::string;
using std::vector;

class Punct_stream {
public:
	Punct_stream(std::istream& s)
	:source{s} { }
	void add_whitespace(string s) {white += s;}
	string whitespace() {return white;}
	bool is_whitespace(char ch);
	Punct_stream& operator>>(string& s);
	operator bool();
private:
	std::istream& source;
	std::istringstream buffer;
	string white;
};

Punct_stream::operator bool() {
	return !(source.bad()||source.fail()) && source.good();
}

bool Punct_stream::is_whitespace(char ch) {
	for (char c : white) if (c == ch) return true;
	return false;
}

Punct_stream& Punct_stream::operator>>(string& s) {
	while(!(buffer >> s)) {
		if(buffer.bad() || !source.good()) return *this;
		buffer.clear();
		string line;
		getline(source, line);
		bool quote = false;
		for (char& ch : line) {
			if (ch == '"') quote = quote ? false : true; /* If there is a quote (") the characters won't be
														 	affected while there won't be a closing quote */
			if (!quote) {
				if(is_whitespace(ch)) ch = ' '; // Change the symbol to whitespace
				else (tolower(ch)); // Covert all letters of string to lowercase one
			}
		}
		std::istringstream is {line};
		string x, r;
		while (is >> r) { //Check if the word has to be changed
			if (r == "don't") r = "do not";
			else if (r == "can't") r = "cannot";
			x += r + ' '; // Add whitespace between words
		}
		buffer.str(x);
	}
	return *this;
}

int main() {
	vector<string> dictionary;
	Punct_stream ps {std::cin};
	ps.add_whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
	string s;
	while (ps >> s) dictionary.push_back(s);
	std::sort(dictionary.begin(), dictionary.end());
	std::ofstream ofs {"ex8.txt"};
	for (string x : dictionary) ofs << x << std::endl;
}