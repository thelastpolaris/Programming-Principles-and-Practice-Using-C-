#include "std_lib_facilities.h";

	vector<int> sequence;
	int max_int;
	int min_int;
	int modeCount = 1;
	int mode;
	int lastNumber;
	int counter = 0;
	
	int main() {
		for (int x; cin >> x;) {
			sequence.push_back(x);
		}

		sort(sequence.begin(), sequence.end());

		lastNumber = sequence[0];

		min_int = sequence[0];

		max_int = sequence[sequence.size() - 1];

		for (int c = 0; c < sequence.size(); c++) {
			if (lastNumber == sequence[c]) {
				counter++;
			}
			else {
				lastNumber = sequence[c];
				if (counter > modeCount) {
					modeCount = counter;
					mode = sequence[c-1];
					}
				counter = 0;
			}
		}
		for (int i: sequence) {
			cout << i << " ";
		}
		cout << "\nMode: " << mode << "\nMin: " << min_int << "\nMax: " << max_int << "\n";
	}