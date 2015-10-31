#include "std_lib_facilities.h";

	vector<int> numbers;
	int maximal;

	int main() {
		cout << "Enter the max number\n";
		cin >> maximal;
		for (int i = 2; i <= maximal; i++) {
			numbers.push_back(i);
		}
		for (int c = 0; c < numbers.size(); c++) {
			for (int x = 2; x < c - 1; x++) {
					if (numbers[c]%x == 0) numbers[c] = 0;
				}
			}
		for (int n: numbers) {
			cout << n << " ";
		}

	}