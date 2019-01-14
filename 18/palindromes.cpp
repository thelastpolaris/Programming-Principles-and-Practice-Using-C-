#include <string>
#include <iostream>
#include <cstring>

using namespace std;

// 18.7.1 Palindromes using string

bool is_palindrome(const string& s) {
	int first = 0;
	int last = s.length() - 1;

	while(first < last) {
		if(s[first] != s[last]) return false;
		++first;
		--last;
	}
	return true;
}

// 18.7.2 Palindromes using arrays

bool is_palindrome(const char s[], int n) {
	int first = 0;
	int last = n - 1;

	while(first < last) {
		if(s[first] != s[last]) return false;
		++first;
		--last;
	}
	return true;
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
	return true;
}

// 18.7.3 Just for fun (recursion)
bool is_palindrome_recursive(const char* first, const char* last) {
	if(first < last) {
		if(*first != *last) return false;
		return is_palindrome_recursive(first + 1, last - 1);
	}
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
	for(char s[max]; read_word(cin, s, max);){
		cout << s << " is";
		int s_len = strlen(s);
		if(!is_palindrome_recursive(&s[0], &s[s_len - 1])) cout << " not";
		cout << " a palindrome\n";
	}
}