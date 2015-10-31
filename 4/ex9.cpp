#include "std_lib_facilities.h";

	vector<double> squares(64);
	
	int main() {
		for (int x = 0; x < 64; x++) {
			if (x == 0) squares[x] = 1;
			else
			{
				squares[x] = squares[x-1]*2;
			}
				cout << x << ":" << squares[x] << "\n";
			}
		}
	