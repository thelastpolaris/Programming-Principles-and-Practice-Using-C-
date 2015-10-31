/* Chapter 11 Exercise 6
Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question mark), 
- (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). 
For example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”.
*/

//"- don't use the as-if rule."

#include <iostream>
#include <string>
#include <sstream>

using std::string;

string change_to_whitespace(string s) {
	string r;
	bool quote = false;
		for (char& ch : s) {
			if (ch == '"') quote = quote ? false : true;
			if (!quote) {
				switch(ch) {
					case '.': case ';': case ',': case '-': case '?': // Change . ; , - and ? to whitespace
					ch = ' ';
				}
			}
			r += ch;
		}
	return r;
}

int main() {
	string s;
	std::ostringstream os;
	while (getline(std::cin, s)) {
		os << change_to_whitespace(s);
	}
	std::cout << os.str() << std::endl;
}

