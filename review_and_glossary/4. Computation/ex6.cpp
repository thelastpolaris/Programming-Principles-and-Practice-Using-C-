#include "std_lib_facilities.h";

	vector<string> array = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	int number;

	int main() {
		cout << "Enter the number between 0 and 9\n";
		while(cin >> number) {
			if (number >= 0 && number <= 9) {
				cout << array[number] << "\n";	
			}
			else cout << "Wrong number!\n";
		}
	}
