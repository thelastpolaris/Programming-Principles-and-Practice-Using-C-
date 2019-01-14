/**
Exercsie 8
Rewrite all the functions in § 18.7 to use the approach of making a backward copy of the string and then comparing; 
for example, take "home" , generate "emoh" , and compare those two strings to see that they are different, so home 
isn’t a palindrome.
**/

#include <string>
#include <iostream>
#include <cstring>

using namespace std;

// 18.7.1 Palindromes using string

bool is_palindrome(const string& s) {
	// Reverse string
	string reverse = "";
	for(int i = 1; i <= s.size(); ++i) {
		reverse += s[s.size() - i];
	}

	return s == reverse;
}

// 18.7.2 Palindromes using arrays

bool is_palindrome(const char s[], int n) {
	char reverse[6] = {};

	for(int i = 0; i < n; ++i) {
		reverse[i] = s[n - i - 1];
	}
	// cout << s << "|||" << reverse << endl;

	return !strcmp(s, reverse);
}

istream& read_word(istream& is, char* buffer, int max) {
	is.width(max);
	is >> buffer;
	return is;
}

// 18.7.3 Palindromes using pointers

bool is_palindrome(const char* first, const char* last) {
	while(first < last) {
		if(*first != *last) return false;
		++first;
		--last;
	}

	char* reverse = new char[n];
	s += n;
	for(int i = 0; i <= n; ++i) {
		*reverse = *s;

		if(i != n) {
			reverse++;
			s--;
		}
	}

	while

	return true;
}

int main() {
	// 18.7.1 Palindromes using string
	// for(string s; cin >> s;) {
	// 	cout << s << " is";
	// 	if(!is_palindrome(s)) cout << " not";
	// 	cout << " a palindrome\n";
	// }

	// 18.7.2 Palindromes using arrays
	// constexpr int max = 128;
	// for(char s[max]; read_word(cin, s, max);) {
	// 	cout << s << " is";
	// 	if(!is_palindrome(s, strlen(s))) cout << " not";
	// 	cout << " a palindrome\n";
	// }

	// 18.7.3 Palindromes using pointers
	const int max = 128;
	for(char s[max]; read_word(cin, s, max);) {
		cout << s << " is";
		int s_len = strlen(s);
		if(!is_palindrome_recursive(&s[0], &s[s_len - 1])) cout << " not";
		cout << " a palindrome\n";
	}
}