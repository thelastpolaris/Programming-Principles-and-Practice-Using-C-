#include "std_lib_facilities.h"

class Name_pairs {
public:
	Name_pairs()
	:name{}, age{} 
	{}
	void read_names(); // Read names from cin into vector name
	void read_ages(); // Read ages from cin into vector age
	void print(); // Print all name and age pairs
	void sort(); // Sort names in alphabetical order and change indexes of elements in age vector so they pass to names
private:
	vector<string> name;
	vector<double> age;
};

void Name_pairs::read_names() {
	string s;
	while (cin>>s && s !="NoName") {
		name.push_back(s); // Add string from cin to the vector name
	}
}

void Name_pairs::read_ages() {
	double n;
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << "'s age = "; // Output the name with which age will be associated
		cin >> n;
		age.push_back(n); // Add int from cin to the vector age
	}
}

void Name_pairs::print() {
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << " : " << age[i] << endl; // Print pairs of name and ages in format "Name : Age"
	}
}

void Name_pairs::sort() {
	vector<string> old_name = name; // To hold unsorted version of the vector name
	vector<double> old_age = age; // To hold old version of the vector age
	bool status;
	while (status) { // Sort the vector name
		status = false;
		for (int i = 1; i < name.size(); i++) {
			if (name[i - 1] > name[i]) { swap(name[i-1],name[i]); status = true; }
			if (name[name.size() - i] < name[name.size() - i-1]) { swap(name[name.size() - i-1],name[name.size() - i]); status = true; }
		}
	}
	for (int i = 0; i < name.size(); i++) { // Loop for sorted vector name
		for (int x = 0; x < old_name.size(); x++) { // Loop for unsorted vector name
			if (name[i] == old_name[x]) { // If names are equal use i and x to change the index of age in vector age
				age[i] = old_age[x]; 
			}
		}
	}
}

int main () {
	Name_pairs name_age;
	name_age.read_names();
	name_age.read_ages();
	name_age.print();
	name_age.sort();
	cout << endl;
	name_age.print();
}