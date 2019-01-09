#include "std_lib_facilities.h"

	int num = 0;
	vector<double> numbers;
	vector<double> diff_numbers;
	double number = 0;
	double result = 0;
	
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
			for (int j = 0; j < numbers.size(); j++) {
				if (numbers[j] == numbers[numbers.size() - 1]) {
					if(numbers[j] - numbers[j-1] == (num - 1) || numbers[j] - numbers[j-1] == -1*(num - 1))
					diff_numbers.push_back(numbers[j]);	
				}
				else if(numbers[j] - numbers[j+1] == (num - 1) || numbers[j] - numbers[j+1] == -1*(num - 1))
					diff_numbers.push_back(numbers[j]);
			}

			if (narrow_cast<double>(result)) cout << "Your result is " << result << "\n";
			else cerr << "The result is too big for double\n";
			cout << "The numbers with difference " << num - 1 << " between them are: ";
			for (double x: diff_numbers) {
				cout << x << " ";
			}
		}

	}	