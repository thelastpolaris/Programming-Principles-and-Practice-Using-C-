#include "std_lib_facilities.h";
	
	int maximal;
	int n;
	int counter = 0;

	int main() {
		cout << "Enter the max number\n";
		cin >> maximal;
		cout << "Enter the number of primes\n";
		cin >> n;
		vector<int> numbers(maximal);
		for (int b = 0; b <= maximal; b++) {
			numbers[b] = 1;
		}

		for (int i = 2; i < maximal; i++) {
			if (numbers[i] == 1) {
				for (int c = i*i; c < maximal; c+=i) {
					numbers[c] = 0;
				}
			}
			if (counter > n) break;
			
		}
		cout << counter;
		for (int x = 0; x < numbers.size(); x++) {
			if (numbers[x] == 1) cout << x << " | ";
		}
	}