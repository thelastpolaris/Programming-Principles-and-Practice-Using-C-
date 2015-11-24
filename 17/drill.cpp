#include <iostream>
#include <vector>

void print_array10(std::ostream& os, int* arr) {
	for (int i = 0; i < 10; ++i) {
		os << arr[i];
		if (i != 9) os << ", ";
		else os << "\n";
	}
}

void print_array(std::ostream& os, int* arr, int n) {// n - numer of elements in array
	for (int i = 0; i < n; ++i) {
		os << arr[i];
		if (i != n-1) os << ", ";
		else os << "\n";
	}	
}

void print_vector(std::ostream& os, std::vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size()-1) os << ", ";
		else os << "\n";
	}

}

int main() {
	int* p = new int[10]{100,101,102,103,104,105,106,107,108,109};
	print_array10(std::cout, p);
	delete[] p;
	int* p1 = new int[11]{100,101,102,103,104,105,106,107,108,109,110};
	delete[] p1;
	print_array(std::cout, p1, 11);
	int* p2 = new int[20]{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
	print_array(std::cout, p2, 20);
	delete[] p2;
	std::vector<int> v {100,101,102,103,104,105,106,107,108,109};
	print_vector(std::cout, v);
	std::vector<int> v1 {100,101,102,103,104,105,106,107,108,109,110};
	print_vector(std::cout, v1);
	std::vector<int> v2 {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
	print_vector(std::cout, v2);
}
