/* Chapter 11 Exercise 7
Modify the program from the previous exercise so that it replaces don't with do not, can't with cannot, etc.; 
leaves hyphens within words intact (so that we get “ do not use the as-if rule ”); and converts all characters to lower case.
*/

//"- don't use the as-if rule."

#include <iostream>
#include <string>
#include <sstream>

using std::string;

string change_to_whitespace(string s) {
	string r, p;
	bool quote = false;
		for (char& ch : s) {
			if (ch == '"') quote = quote ? false : true;
			if (!quote) {
				switch(ch) {
					case '.': case ';': case ',': case '?': // Change . ; , - and ? to whitespace
					ch = ' ';
				}
			}
			r += ch;
		}
		std::istringstream is {r};
		string o;
		while (is >> o) { //Check i
			if (o == "don't") o = "do not";
			else if (o == "can't") o = "cannot";

			for (char& ch : o) ch = tolower(ch); // Coverts all characters of string to lowercase one
			p += o + " ";
		}
		return p;
}

int main() {
	string s;
	std::ostringstream os;
	while (getline(std::cin, s)) {
		os << change_to_whitespace(s);
	}
	std::cout << os.str() << std::endl;
}
