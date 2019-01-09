#include "std_lib_facilities.h"

	int num = 0;
	vector<int> fibonacci;
		
	int main() {

			fibonacci.push_back(1);
			fibonacci.push_back(1);

			cout <<"How much Fibonacci numbers do you want to output?\n";

			cin >> num;

			for (int j = 0; j < num; j++) {
				fibonacci.push_back(fibonacci[j+1] + fibonacci[j]);
				cout << fibonacci[j] << " ";
			}

		}