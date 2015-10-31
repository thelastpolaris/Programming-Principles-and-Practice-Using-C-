/* Chapter 10 Exercise 11
Write a program that produces the sum of all the whitespace-separated integers in a text file. 
For example, bears: 17 elephants 9 end should output 26.
*/

#include <cmath>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

int file_sum(ifstream& ifs) {
	int i = 0;
	int sum = 0;
	while (true) {
		ifs >> i;
		sum+= i;
		if (ifs.eof() || ifs.bad()) {
			return sum;
		}
		else if (ifs.fail()) {
			ifs.clear();
			char ch;
			string s;
			if (ifs >> ch && !isdigit(ch)) {
				ifs.unget();
				ifs >> s;
				continue;
			}
		}
	}
}

int main() {
	ifstream ifs{"ex11.txt"};
	cout << file_sum(ifs) << endl;
}