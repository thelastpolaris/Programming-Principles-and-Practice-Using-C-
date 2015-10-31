#include "std_lib_facilities.h"

//vector<double> numbers {3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23};
vector<string> strings;

string quit = "quit";

void print_until_s(const vector<string>& v, string quit) {
	for (string x: v) {
		if (x == quit) {
			cout << x << '\n';
			return;
		}
	}
}

void print_until_ss(const vector<string>& v, string quit) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == quit && v[i-1] == quit) {
			cout << v[i] << '\n';
			return;
		}
	}
}

int main() try {
	string s;
	while (cin >> s && s != "NoName") strings.push_back(s);
	print_until_ss(strings, quit);
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
} 
