#include "std_lib_facilities.h"

	vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int rand_num = 0;
	int win = 0;
	char guess = 0;
	int bull = 0;
	int cow = 0;
	char game = 'y';

	int main() {
		while (game == 'y') {

			srand(time(0));
			rand_num = rand() % 21;
			
			cout << "Let's start Bulls and Cows! Enter 4 letters (with space between each of them)\n";

			while (win == 0) {
				for (int i = rand_num; i < rand_num + 4; i++) {
					cin >> guess;
					if (guess == letters[i]) bull += 1;
					else {
						for (int x = rand_num; x < rand_num + 4; x++) {
							if (letters[x] == guess) cow += 1;
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
			for (int i = rand_num; i < rand_num + 4; i++) cout << letters[i] << " ";
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