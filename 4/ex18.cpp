#include "std_lib_facilities.h";

	double a;
	double b;
	double c;
	double x1;
	double x2;
	double d;
	
	int main() {
		cout << "Please, enter a, b, c\n";
		cin >> a >> b >> c;
		d = b*b - 4*a*c;
		if (d > 0) {
			x1 = (-b + sqrt(d)) / (2*a);
			x2 = (-b - sqrt(d)) / (2*a);
			cout << "X1: " << x1 << "\nX2: " << x2 << "\n";
		}
		else if (d == 0) {
			x1 = -b / 2*a;
			cout << "X: " << x1;
		}
		else if (d < 0) cout << "Sorry, there are no real roots\n";
	}	