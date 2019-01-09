/* Chapter 11 Exercise 5
Write a program that reads strings and for each string outputs the character classification of each character, as 
defined by the character classification functions presented in §11.6. Note that a character can have several classifications 
(e.g., x is both a letter and an alphanumeric).
*/

#include <iostream>
#include <string>

using std::string;

void write(string s) {
	for (char ch : s) {
		if (std::isalpha(ch)) {
			if (std::isupper(ch)) std::cout << ch << " : " << "letter(uppercase)" << std::endl;
			else if(std::islower(ch)) std::cout << ch << " : " << "letter(lowercase)" << std::endl;
		}
		else if (std::isdigit(ch)) std::cout << ch << " : " << "digit" << std::endl;
		else if (std::iscntrl(ch)) std::cout << ch << " : " << "control character" << std::endl;
		else if (std::ispunct(ch)) std::cout << ch << " : " << "punctuation" << std::endl;
	}
}

int main() {
	string s;
	while (std::cin >> s) write(s);
}