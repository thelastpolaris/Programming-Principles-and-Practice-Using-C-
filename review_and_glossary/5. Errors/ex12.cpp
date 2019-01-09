#include "std_lib_facilities.h"

	vector<int> numbers;
	int rand_num = 0;
	int end_of_vector = 0;
	vector<int> guess_numbers(4);
	int win = false;
	double guess = 0;
	int bull = 0;
	int cow = 0;

	int main() {
		srand(time(0));
		rand_num = 1 + rand() % 6;
		end_of_vector = rand_num + 4;
		
		for (rand_num; rand_num < end_of_vector; rand_num++) {
			numbers.push_back(rand_num);
			}

		while (win == 0) {
			for (int i = 0; i < 4; i++) {
				cin >> guess;
				guess_numbers[i] = guess;
				if (guess_numbers[i] == numbers[i]) bull += 1;
				else if (numbers[0] == guess_numbers[i] || numbers[1] == guess_numbers[i] || numbers[2] == guess_numbers[i] || numbers[3] == guess_numbers[i]) cow += 1;
				if (i == 3) cout << bull <<" bull and " << cow << " cow\n";
			}
			if (bull == 4) {
					win = 1;
			}
			else {
				bull = 0;
				cow = 0;
			}
		}

		cout << "Congratulations! You have won! The right combination was: ";
		for (int x: numbers) cout << x << " ";
		cout << "\n";
	}