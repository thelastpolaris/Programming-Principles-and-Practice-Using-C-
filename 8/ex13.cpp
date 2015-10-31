#include "std_lib_facilities.h"

vector<string> strings; // Holds strings
vector<int> numbers; // Holds sizes of each string in strings

void read_strings(vector<string>& v) { // Reads strings from cin to the given vector (pass-by-reference)
	cout << "Please enter the values. When you have finished, enter 'NoName'" << endl;
	string s;
	while (cin >> s && s != "NoName") {
		v.push_back(s); // Add values to the vector
	}
}

vector<int> get_size(const vector<string>& v) { // Gets size of each element of the given vector
	if (v.size()==0) error("get_size(): empty vector");

	vector<int> size;
	for (string x: v) size.push_back(x.size());
	return size;
}

double get_the_longest(const vector<int>& s) {
	int maximal = 0;
	for (int i = 0; i < s.size(); i++) {
		 if (s[i] > s[maximal]) {
		 	maximal = i;
		 }
	}
	return maximal;
}

double get_the_shortest(const vector<int>& s) {
	int minimal = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < s[minimal]) minimal = i;
	}
	return minimal;
}

double lex_first(const vector<string>& s) {
	int first = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > s[first]) first = i;
	}
	return first;	
}

double lex_last(const vector<string>& s) {
	int last = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < s[last]) last = i;
	}
	return last;	
}

int main() try {
	read_strings(strings);
	numbers = get_size(strings);
	cout << "The longest string is: " << strings[get_the_longest(numbers)] << endl;
	cout << "The shortest string is: " << strings[get_the_shortest(numbers)] << endl;
	cout << "Lexically first string is: " << strings[lex_first(strings)] << endl;
	cout << "Lexically last string is: " << strings[lex_last(strings)] << endl;
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
/*catch (...) {
	cerr << "Unknown exception\n";
} */
