#include "std_lib_facilities.h"

vector<string> strings;

const int unit = 10;

int f() {
	return unit;
}

int main() try {
	
	cout << f() << endl;
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
/*catch (...) {
	cerr << "Unknown exception\n";
} */
