#include "std_lib_facilities.h"

	int num = 0;
	vector<int> numbers;
	int number = 0;
	int result = 0;
	
	int main() {
		cout << "Please, enter the number of values you want to sum\n";
		cin >> num;
		cout << "Now enter some integers (enter '|' to exit)\n";
		while (cin >> number) {
			numbers.push_back(number);
		}
		if (numbers.size() < num) cerr << "Error, the number of integers to sum is bigger than the numbers of integers\n";
		else {
			for (int i = 0; i < num; i++) {
				result+=numbers[i];
			}

			cout << "You result is " << result << "\n";
		}
	}	