/* Chapter 17 Exercise 1
What is the output format of pointer values on your implementation? Hint: Don’t read the documentation.
*/

#include <iostream>

int main() {
	int* pi = new int(1);
	double* pd = new double(1);
	bool* pb = new bool(true);
	bool** pbb = &pb;
	bool*** pbbb = &pbb;
	std::cout << pi << " : " << pd << " : " << pb << " : " << pbb << " : " << pbbb << '\n';
	delete pi;
	delete pd;
	delete pb;
}

