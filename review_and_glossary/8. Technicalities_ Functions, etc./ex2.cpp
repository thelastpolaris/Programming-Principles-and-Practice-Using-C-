#include "std_lib_facilities.h"

void print(string label, const vector<int>& numbers){
	cout << "Name: " << label << " | Size: " << numbers.size() << "\n";
	for (int i = 0; i < numbers.size();i++) {
		cout << numbers[i];
		if (numbers.size() - i != 1) cout << ", ";
		else cout << "\n";
	}
}

vector<int> numbers;

int main() try {
	cout << "Enter the name of the vector\n";
	string label;
	cin >> label;
	cout << "Now enter the values please\n";
	int number = 0;
	while(cin >> number) {
		numbers.push_back(number);
	}
	print(label, numbers);
}
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
}