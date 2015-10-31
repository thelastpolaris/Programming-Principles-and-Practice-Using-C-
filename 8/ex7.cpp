#include "std_lib_facilities.h"

void read_pairs(vector<string>& n, vector<int>& a) {
	string name; // Holds names
	int age = 0; // Holds ages
	cout << "Please enter names and ages\n";
	while (cin >> name >> age && name!="NoName") {
		for (int i = 0; i < n.size(); i++) if (name == n[i]) error("duplicate: ", name); // Check if the name has been already inserted into the vector
		n.push_back(name); // Add name
		a.push_back(age); // Add age
	}
}

int find_index(const vector<string>& n, const vector<string>& a, int index) {
	for (int x = 0; x < a.size(); x++) {
		if (n[index] == a[x]) return x;
	}
}

int main() try {
	vector<string> names;
	vector<int> ages;

	read_pairs(names, ages);
	vector<string> names_copy = names;

	sort(names.begin(),names.end());
	
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " : " << ages[find_index(names, names_copy, i)] << endl;

	}
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
}