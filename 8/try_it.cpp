#include "std_lib_facilities.h"

const double& date() {
	static const double dd = 5;
	return dd;
}

int main() {
	double dd = 32;
	date();
	cout << dd << "\n";
}