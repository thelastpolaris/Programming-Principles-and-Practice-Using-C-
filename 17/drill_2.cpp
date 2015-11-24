#include <iostream>
#include <vector>

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
	int* p1 = new int(7);
	std::cout << p1 << " : " << *p1 << std::endl;
	int* p2 = new int[7] {1,2,4,8,16,32,64};
	std::cout << p2 << " : ";
	for (int i = 0; i < 7; ++i) {
		std::cout << p2[i];
		if (i == 6) std::cout << '\n';
		else std::cout << ", ";
	}
	int* p3 = p2;
	p2 = p1;
	std::cout << p3 << " : ";
	for (int i = 0; i < 7; ++i) {
		std::cout << p3[i];
		if (i == 6) std::cout << '\n';
		else std::cout << ", ";
	}
	delete p3;
	p3 = p2;
	std::cout << p3 << " : ";
	for (int i = 0; i < 7; ++i) {
		std::cout << p3[i];
		if (i == 6) std::cout << '\n';
		else std::cout << ", ";
	}
	std::cout << p1 << " : " << *p1 << std::endl;
	std::cout << p2 << " : " << *p2 << std::endl;
	delete p1;
	//delete p3;
	p1 = new int[10] {1,2,4,8,16,32,64,128,256,512};
	p2 = new int[10] {512,256,128,64,32,16,8,4,2,1};
	for (int i = 0; i < 10; ++i) {
		p2[i] = p1[i];
	}
	print_array(std::cout, p2, 10);

	std::vector<int> v1 {1,2,4,8,16,32,64,128,256,512};
	std::vector<int> v2 {512,256,128,64,32,16,8,4,2,1};

	for (int i = 0; i < v1.size(); ++i) {
		v2[i] = v1[i];
	}

	print_vector(std::cout, v2);

}