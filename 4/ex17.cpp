#include "std_lib_facilities.h";

	vector<string> sequence;
	string max_str;
	string min_str;
	int modeCount = 1;
	string mode;
	string lastStr;
	int counter = 0;
	
	int main() {
		for (string x; cin >> x;) {
			sequence.push_back(x);
		}

		sort(sequence.begin(), sequence.end());

		lastStr = sequence[0];

		min_str = sequence[0];

		max_str = sequence[sequence.size() - 1];

		for (int c = 0; c < sequence.size(); c++) {
			if (lastStr == sequence[c]) {
				counter++;
			}
			else {
				lastStr = sequence[c];
				if (counter > modeCount) {
					modeCount = counter;
					mode = sequence[c-1];
					}
				counter = 0;
			}
		}
		for (string i: sequence) {
			cout << i << " ";
		}
		cout << "\nMode: " << mode << "\nMin: " << min_str << "\nMax: " << max_str << "\n";
	}