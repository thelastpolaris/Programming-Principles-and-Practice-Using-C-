/* Chapter 11 Exercise 16
Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first), one value per line. 
Write a value only once, and if it occurs more than once write the count of its occurrences on its line. 
For example, 7 5 5 7 3 117 5 should give
3
5     3
7     2
117
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

void error(string s) {
	throw std::runtime_error(s);
}

struct Number { // To hold numbers with the count of their occurence
	float num;
	int count;
};

void sort(vector<Number>& n) { // Sort numbers
	bool end = false;
	while (!end) {
		end = true;
		for (int i = 0; i < n.size() - 1; i++) { // Bubble sort
			if (n[i].num > n[i+1].num) {
				Number a;
				a = n[i+1];
				n[i+1] = n[i];
				n[i] = a;
				end = false;
			}
		}
	}
}

void count_duplicates(vector<Number>& n) { // Set duplicates of number to null and count their occurence
	for (int i = 0; i < n.size(); i++) { // Get a number
		for (int x = 0; x < n.size(); x++) { // Compare it with others in vector but not with itself
			if (i != x) {
				if (n[i].num == n[x].num) {
					n[i].count++;
					n[x].num = 0;
				}
			}
		}
	}
}

int main() try {

	//Open file for reading
	std::cout << "Please enter the file name\n";
	string iname;
	std::cin >> iname;
	std::ifstream ifs {iname};
	if (!ifs) error("Wrong file name");

	Number n {0,0};
	vector<Number> numbers;
	while (ifs >> n.num) numbers.push_back(n);

	sort(numbers);
	count_duplicates(numbers);

	for (Number x : numbers) if (x.num != 0) std::cout << x.num << '\t' << x.count << std::endl;
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}