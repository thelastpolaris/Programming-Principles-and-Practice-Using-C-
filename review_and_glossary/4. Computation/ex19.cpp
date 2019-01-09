#include "std_lib_facilities.h";
	

	class Name_value {
	public:
		string name;
		int age;
	};

	string name_str;
	int age_int;
	int loop_count = 0;
	string query_str;
	int query_int;
	int counter = 0;

	int main() {
		while(cin >> name_str >> age_int) {
			for (string x : name) {
				if (name_str == x) {
					loop_count = 1;
				}
			}
			if (loop_count == 1) {
				cout << "Please, enter another name\n";
				break;
			}
			else if (name_str == "NoName") break;
			else {
				name.push_back(name_str);
				age.push_back(age_int);
			}
		}
		cout << "Enter the score to search for corresponding names\n";
		while (cin >> query_int) {
			if (query_int == -1) break;
			counter = 0;
			for (int i = 0; i < age.size();++i) {
				if (query_int == age[i]) {
					cout << name[i] << "\n";
					counter = 1;
					}
			}
			if (counter == 0) {
				cout << "Name not found\n";
			}
		}
		cout << "Enter the name to search for the score\n";
		while (cin >> query_str) {
			counter = 0;
			for (int j = 0; j < name.size();++j) {
				if (query_str == name[j]) {
					cout << age[j] << "\n";
					counter = 1;
					}
			}
			if (counter == 0) {
				cout << "Score not found\n";
			}
		}
}
