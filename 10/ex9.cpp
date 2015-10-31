/* Chapter 10 Exercise 9
Write a program that takes two files containing sorted whitespace-separated words and merges them, preserving order.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

void file_sort(const string& f) {
	ofstream file {f};
	vector<string> words;
	string s;
	while (cin >> s) {
		if (s == "888") {
			cin.clear(ios_base::failbit);
			break;
		}
		words.push_back(s);
	}
	sort(words.begin(), words.end());
	for (string x : words) file << x << endl;
}

void error(string s) {
	throw runtime_error(s);
}

int main() try{
	string f1, f2, out;
	cout << "Please enter the names of two files to merge and a file for output" << endl;
	cin >> f1 >> f2 >> out;
	ifstream file1 {f1};
	if (!file1) error("Error: first file name is wrong");
	ifstream file2 {f2};
	if (!file2) error("Error: second file name is wrong");
	ofstream fout {out};
	if (!fout) error("Error: output file name is wrong");
	string s1, s2;
	file1 >> s1;
	file2 >> s2;
	while(true) {
		if (s1 < s2) {
			fout << s1 << endl;
			file1 >> s1;
		}
		if (s1 >= s2) {
			fout << s2 << endl;
			file2 >> s2;
		}
		if (file1.eof() || file2.eof()) break;
	}
	while(file1 >> s1) fout << s1;
	while(file2 >> s2) fout << s2;
}

catch (runtime_error& e) {
	cout << e.what() << endl;
}

catch (...) {
	cout << "Unexpected error" << endl;
}