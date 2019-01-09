#include "std_lib_facilities.h"

void swap_v(int a, int b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

/*void swap_cr(const int& a,const int& b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}*/

int main() {
	double dx = 7.7;
	double dy = 9.9;
	swap_r(dx,dy);
	//swap_?(7.7,9.9);
	cout << dx << endl << dy << endl;
}