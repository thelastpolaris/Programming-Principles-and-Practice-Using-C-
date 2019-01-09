/* Chapter 10 Exercise 1
Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.
*/

#include <iostream>
#include <fstream>

int main() {
	using namespace std;
	string file;
	cout << "Please enter the name of file" << endl;
	cin >> file;
	ifstream ifs {file};
	int number = 0;
	int sum = 0;
	while (ifs >> number) sum += number;
	cout << sum << endl;
}


