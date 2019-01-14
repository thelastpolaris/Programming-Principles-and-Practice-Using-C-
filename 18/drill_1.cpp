#include <iostream>

using namespace std;

// int ga[10] = {1,2,4,8,16,32,64,128,256,512};

// void f(int arr[], int len) {
// 	int la[10] = {};
// 	cout << "la(on stack): ";
// 	for(int i = 0; i < len; ++i) {
// 		la[i] = arr[i];
// 		cout << la[i] << ", ";
// 	}
// 	cout << endl;

// 	int* p = new int[len];
// 	cout << "p(on heap): ";	
// 	for(int i = 0; i < len; ++i) {
// 		p[i] = la[i];
// 		cout << p[i] << ", ";
// 	}
// 	cout << endl;

// 	delete p;
// }
	// f(ga, 10);
	// int aa[] = {1, 2*1, 3*2, 4*3, 5*4, 6*5, 7*6, 8*7, 9*8, 10*9};
	// f(aa, 10);

int main() {
	int len = 0;
	cin >> len;
	int ga[len] = {};

	for(int i = 0; i < len; ++i) cout << ga[i] << " ";
	cout << endl;
}
