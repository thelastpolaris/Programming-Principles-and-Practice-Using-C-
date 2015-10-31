#include "std_lib_facilities.h"

void print(string label, const vector<int>& numbers){
	cout << "Name: " << label << " | Size: " << numbers.size() << "\n";
	for (int i = 0; i < numbers.size();i++) {
		cout << numbers[i];
		if (numbers.size() - i != 1) cout << ", ";
		else cout << "\n";
	}
}

void fibonacci(int x, int y, vector<int>& v, int n) { // Prints a sequence of fibonacci numbers
	if (n <= 1) return; // If the number of values to add in vector is less than 1 then return
	v.push_back(x); // Add x into vector
	v.push_back(y); // Add y into vector

	int z = 0;

	for (int i = 2; i < n; i++) {
		z = v[i-2] + v[i-1];
		v.push_back(z);
	}
}

vector<int> numbers;

int main() try {
	string label;
	int n = 0;
	int x = 0;
	int y = 0;
	vector<int> v;
	cout << "Enter the name of the vector, the number of elements, the first and the second value\n";
	while(cin >> label >> n >> x >> y) {
		fibonacci(x, y, v, n);
		print(label, v);
		x = n = y = 0;
		v = {};
	}
}
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
}