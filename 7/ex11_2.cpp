/*
	This program collects names and ages, holds them in vectors and allow user to output them by specifying name and value.
	2015
*/

#include "std_lib_facilities.h";
	
	vector<string> names; // Vector to hold names
	vector<int> values; // Vector to hold values
	string name; // Holds name
	int age; // Holds age
	string query; // Name query
	int query_num; // Age query
	int counter = 0; // Counter to use in loops

	int main() try {
		cout << "Welcome to our program. Please, enter the data in following format: Name Value\n";
		while(cin >> name >> age) { // Read name and age
			for (string x : names) {
				if (name == x) { // If vector already contains such name print error
					cout << "Please, enter another name\n";
					break;
				}
			}
			if (name == "NoName") break; // Use NoName with any value to terminate input
			else {
				names.push_back(name); // Add name to vector 'names'
				values.push_back(age); // Add age to vector 'values'
			}
		}
		cout << "Enter the score to search for corresponding names\n";
		while (cin >> query_num) { // Search for names by score
			if (query_num == -1) break; // Use -1 to terminate
			counter = 0; // To get rid of multiple error checks
			for (int i = 0; i < values.size();++i) {
				if (query_num == values[i]) {
					cout << names[i] << "\n"; // Print name if search was successful
					counter = 1; // Update counter
					}
			}
			if (counter == 0) {
				cout << "Name not found\n"; // Print error if nothing was found
			}
		}
		cout << "Enter the name to search for the score\n";
		while (cin >> query) { // Search for scores by name
			counter = 0; // To get rid of multiple error checks
			for (int j = 0; j < names.size();++j) {
				if (query == names[j]) { // If name exists in vector
					cout << values[j] << "\n"; // Print its value
					counter = 1; // Update counter
					}
			}
			if (counter == 0) {
				cout << "Score not found\n"; // Print error if nothing was found
			}
		}
	}
	catch(...) {
		cout << "Uknown error" << "\n";
		return 1;
	}
