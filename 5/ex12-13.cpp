#include "std_lib_facilities.h"

	vector<int> numbers(4);
	int rand_num = 0;
	int win = 0;
	int guess = 0;
	int bull = 0;
	int cow = 0;
	char game = 'y';

	int main() {
		while (game == 'y') {
			srand(time(0));
			rand_num = 1 + rand() % 6;
						
			for (int i = 0; i < 4; i++) {
					numbers[i] = rand_num;
					rand_num++;
				}
			cout << "Let's start Bulls and Cows! Enter 4 digits\n";

			while (win == 0) {
				for (int i = 0; i < 4; i++) {
					cin >> guess;
					if (guess == numbers[i]) bull += 1;
					else {
						for (int x: numbers) {
							if (guess == x) cow += 1;
						}
					}
				}
				cout << bull <<" bull and " << cow << " cow\n";
				if (bull == 4) {
						win = 1;
				}
				bull = 0;
				cow = 0;
			}

			cout << "Congratulations! You have won! The right combination was: ";
			for (int x: numbers) cout << x << " ";
			cout << "\nDo you want to start a new game? (yes or no)\n";
			cin >> game;
			if (game == 'n') {
				cout << "See you later alligator!\n";
				return 0;
			}
			else if (game == 'y') {
				win = 0;
			}
			else  {
				cerr << "Wrong answer entered\n";
				return 0;
			}
		}	
	}