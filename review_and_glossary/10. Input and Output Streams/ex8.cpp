/* Chapter 10 Exercise 8
Write a program that accepts two file names and produces a new file that is the contents of the first file followed 
by the contents of the second; that is, the program concatenates the two files.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;
void merge_files(const string& f1, const string& f2, const string& out) { // two files and the name of output file are required
	ifstream file1 {f1};
	ifstream file2 {f2};
	ofstream fout {out};
	vector <string> s;
	string b;
	while (getline(file1, b)) s.push_back(b);
	while (getline(file2, b)) s.push_back(b);
	for (string i : s) fout << i << endl;
}

int main() try {
	string f1, f2, out;
	cout << "Please enter the name of 2 files and a file to hold merged data" << endl;
	cin >> f1 >> f2 >> out;
	merge_files(f1, f2, out);
}

catch(runtime_error& e) {
	cout << e.what() << endl;
}
