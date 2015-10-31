#include "std_lib_facilities.h";

	vector<string> values = {"Rock", "Paper", "Scissors"};
	char user_value;
	int x = 0;

	int main() {
		while (cin >> user_value) {
				switch (user_value) {
				case 'R':
					if (values[x] == "Rock") cout << "Rock vs. Rock - Draw\n";
					else if (values[x] == "Paper") cout <<  "Rock vs. Paper - You loose\n";
					else if (values[x] == "Scissors") cout << "Rock vs. Scissors - You win\n";
				break;
				case 'P':
					if (values[x] == "Rock") cout << "Paper vs. Rock - You win\n";
					else if (values[x] == "Paper") cout <<  "Paper vs. Paper - Draw\n";
					else if (values[x] == "Scissors") cout << "Paper vs. Scissors - You loose\n";
				break;
				case 'S':
					if (values[x] == "Rock") cout << "Scissors vs. Rock - You loose\n";
					else if (values[x] == "Paper") cout <<  "Scissors vs. Paper - You win\n";
					else if (values[x] == "Scissors") cout << "Scissors vs. Scissors - Draw\n";
				break;
				}
				x++;
				if (x == 3) x = 0;
			}
		}
	
	