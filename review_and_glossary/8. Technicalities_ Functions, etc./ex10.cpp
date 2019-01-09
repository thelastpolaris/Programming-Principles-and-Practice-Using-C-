#include "std_lib_facilities.h"

vector<double> numbers {2, 10, 42, 3, 53, 8, 19, 25, 37, 1, 4, 63};

double maxv(const vector<double>& v) {
	double max = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > max) max = v[i];
	}
	return max;
}

int main() try {
	cout << maxv(numbers) << endl;
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
} 
