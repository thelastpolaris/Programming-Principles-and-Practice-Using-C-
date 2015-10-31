#include "std_lib_facilities.h"

int f(int h) {
	int x = 1;
	for (int i = 1; i <= h; i++) {
		x *=i;
	}
	return x;
}

int p(int a, int b) {
	return f(a)/f(a-b);
}

int c(int a, int b) {
	return p(a, b)/f(b);
}

int a = 0;
int b = 0;
char ch;

int main()
	try{
		cout << "Please choose an operation - 'p' for permutation and 'c' for combination\n";
		cin >> ch;
		if (ch != 'p' && ch !='c') error("Wrong character entered\n");
		else {
			cout << "Enter 'a' and 'b' both in range between 0 and 100\n";
			cin >> a >> b;
				if (a < 0 || a > 100) error("Please, enter a correct number");
				if (b < 0 || b > 100) error("Please, enter a correct number");
				if (a < b) error("'a' can't be smaller than 'b'");
				if (!a && !b) error("Oops! Something went wrong");
			}
		switch(ch) {
			case('p'):
				cout << "There are " << p(a,b) << " possible permutations in the set that consists of " << a << " numbers\n";
				break;
			case('c'):
				cout << "There are " << c(a,b) << " possible combinations in the set that consists of " << a << " numbers\n";
				break;
		}
	}
	catch(exception& e){
		cerr << e.what() << "\n";
	}