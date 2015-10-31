#include "std_lib_facilities.h";

	vector<int> squares(64);
	int desired_grains;

	int main() {
		cout << "Enter the number of grains\n";
		while(cin >> desired_grains) {
		for (int x = 0; x < 64; x++) {
			if (x == 0) squares[x] = 1;
			else
			{
				squares[x] = squares[x-1]*2;
				if (desired_grains < squares [x]) break;
			}
				cout << x << ":" << squares[x] << "\n";		
			}
		}
	}