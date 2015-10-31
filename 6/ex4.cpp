#include "std_lib_facilities.h"
	
	class Name_value {
	public:
		string name;
		int age;
		Name_value(int age, string name )
        :age(age), name(name) { }
	};

	Name_value get_token() {
		int val;
		string str;
	    cin>>val>>str;
	    return Name_value(val,str);
	}

	vector<Name_value> values;
	string query_str;
	int query_int;
	
	int main() {
		while(cin) {
			Name_value t = get_token();
			for (Name_value x: values) {
				if (t.name == x.name) {
					cout << "Please, consider entering another name\n";
					break;
				}
			}
			if (t.name == "NoName" || t.age == 0) break;
			else {
				values.push_back(t);
			}
		}
		cout << "Enter the score to search for corresponding names\n";
		while (cin >> query_int) {
			int p = 0;
			for (Name_value i : values) {
				if (query_int == i.age) {
					cout << i.name << "\n";
					p = 1;
				}
			}
			if (p == 0) {
				cout << "Name not found\n";
				break;
			}
		}
		cout << "Enter the name to search for the score\n";
		while (cin >> query_str) {
			int p = 0;
			for (Name_value j : values) {
				if (query_str == j.name) {
					cout << j.age << "\n";

					p = 1;
				}
			}
			if (p == 0) {
				cout << "Score not found\n";
				break;
			}
		}
}
