#include "std_lib_facilities.h"

void print(string label, const vector<string>& numbers){ // Prints name and values of the vector
	cout << "Name: " << label << " | Size: " << numbers.size() << "\n";
	for (int i = 0; i < numbers.size();i++) {
		cout << numbers[i]; // Print values
		if (numbers.size() - i != 1) cout << ", "; // Print comma
		else cout << "\n"; // Print new line symbol
	}
}

vector<string> reverse_vector_1(vector<string>v) { // Reverses order of values in vector
	vector<string> v2; // New vector to hold reversed values
	for (int i = v.size() - 1; 0 <= i; --i) { // Start with the last value of the vector
		v2.push_back(v[i]); // Add values to the new vector
	}
	return v2;
}

void reverse_vector_2(vector<string>& v) { // Reverses order of values in vector
	for (int i = 0; i < v.size()/2; i++) swap(v[i],v[v.size()-1-i]); // Swap values of vector (Note that v.size() must be divided by 2)
}

vector<string> strings; // Holds values

int main() try {
	string label;
	string n;
	cout << "Enter the name of the vector\n";
	cin >> label;
	cout << "Enter the values to add into the vector (enter 'exit' to terminate the input)\n";
	while (cin >> n) {
		if(n == "exit") break;
		strings.push_back(n); // Add values to the vector
	}
	cout << "Reversing № 1\n";
	print(label,reverse_vector_1(strings));
	cout << "Reversing № 2\n";
	reverse_vector_2(strings);
	print(label,strings); // Print reversed by the function 'reverse_vector_2' values
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
}