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
			if ((x1*x1)*a+x1*b+c >= -0.5 && (x1*x1)*a+x1*b+c <= 0.5 && (x2*x2)*a+x2*b+c >= -0.5 && (x1*x1)*a+x1*b+c <= 0.5) cout << "X1: " << x1 << "\nX2: " << x2 << "\n";
			else cerr << "Sorry, we are unable to provide the result\n";
		}
		else if (d == 0) {
			x1 = -b / 2*a;
			if ((x1*x1)*a+x1*b+c >= -0.5 && (x1*x1)*a+x1*b+c <= 0.5) cout << "X: " << x1;
			else cerr << "Sorry, we are unable to provide the result\n";
		}
		else if (d < 0) cerr << "Sorry, there are no real roots\n";
	}	