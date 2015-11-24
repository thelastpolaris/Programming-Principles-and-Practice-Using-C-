#include <iostream>
int i = 1;

int main() {
	int* pArray = new int[5];
	int size = 1;
	int* s = &size;
	std::cout << s << std::endl;
}