#include "std_lib_facilities.h"

class Name_pairs {
public:
	Name_pairs()
	:name{}, age{} 
	{}
	void read_names(); // Reads names from cin into vector name
	void read_ages(); // Reads ages from cin into vector age
	void sort(); // Sorts names in alphabetical order and change indexes of elements in age vector so they pass to names
	string write_names(int i); // Returns value of names vector element with index i
	double write_ages(int i); // Returns value of ages vector element with index i
	int names_size(); // Returns size of the vector names (implemented in order functions outside the class could get the size of names)
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

string Name_pairs::write_names(int i) {
	return name[i];
}

double Name_pairs::write_ages(int i) {
	return age[i];
}

int Name_pairs::names_size() {
	return name.size();
}

void operator<<(ostream& os, Name_pairs& n) {
	for (int i = 0; i < n.names_size(); i++) {
		os << n.write_names(i) << " : " << n.write_ages(i) << endl; // Print pairs of name and ages in format "Name : Age"
	}
}

bool operator==(Name_pairs&a, Name_pairs&b) {
	if (a.names_size() != b.names_size()) return false; // If sizes of vector are not equal return false
	for (int i = 0; i < a.names_size(); i++) {
		if (a.write_names(i) != b.write_names(i)) return false; // If elements are not equal return false
	}
	return true;
}

bool operator!=(Name_pairs& a, Name_pairs& b) {
	return !(a==b);
}

int main () try {
	Name_pairs name_age;
	Name_pairs name_age_1 = name_age;
	name_age.read_names();
	name_age.read_ages();
	cout << name_age;
	name_age.sort();
	cout << endl;
	cout << name_age;
	Name_pairs name_age_2 = name_age;
	if(name_age == name_age_2) cout << "1";
	if (name_age != name_age_1) cout << "2";
}
catch (exception& e) {
	cout << e.what() << endl;
}
catch (...) {
	cout << "Unknown exception" << endl;
}