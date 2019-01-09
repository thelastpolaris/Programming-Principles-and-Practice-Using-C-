#include "std_lib_facilities.h"

void print(string label, const vector<int>& numbers){ // Prints name and values of the vector
	cout << "Name: " << label << " | Size: " << numbers.size() << "\n";
	for (int i = 0; i < numbers.size();i++) {
		cout << numbers[i]; // Print values
		if (numbers.size() - i != 1) cout << ", "; // Print comma
		else cout << "\n"; // Print new line symbol
	}
}

vector<int> reverse_vector_1(vector<int>v) { // Reverses order of values in vector
	vector<int> v2; // New vector to hold reversed values
	for (int i = v.size() - 1; 0 <= i; --i) { // Start with the last value of the vector
		v2.push_back(v[i]); // Add values to the new vector
	}
	return v2;
}

void reverse_vector_2(vector<int>& v) { // Reverses order of values in vector
	for (int i = 0; i < v.size()/2; i++) swap(v[i],v[v.size()-1-i]); // Swap values of vector (Note that v.size() must be divided by 2)
}

vector<int> numbers; // Holds values

int main() try {
	string label;
	int n;
	cout << "Enter the name of the vector\n";
	cin >> label;
	cout << "Enter the values to add into the vector\n";
	while (cin >> n) numbers.push_back(n); // Add values to the vector
	cout << "Reversing № 1\n";
	print(label,reverse_vector_1(numbers));
	cout << "Reversing № 2\n";
	reverse_vector_2(numbers);
	print(label,numbers); // Print reversed by function 'reverse_vector_2' values
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
}