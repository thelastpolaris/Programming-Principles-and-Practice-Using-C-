#include "std_lib_facilities.h";

	vector<string> words_array = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	vector<int> num_array = {0,1,2,3,4,5,6,7,8,9};
	string number;

	int main() {
		cout << "Enter the number between 0 and 9\n";
		while(cin >> number) {
			for (int x = 0; x < words_array.size(); x++) {
				if (words_array[x] == number) {
					cout << num_array[x] << "\n";
				}
				
			}
			
		}
	}
