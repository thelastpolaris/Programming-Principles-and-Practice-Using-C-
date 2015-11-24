#include <iostream>
#include <string>
#include <vector>

class first_vector {
	int sz;
	double * elem;
public:
	first_vector(int s) :sz{s}, elem{new double[s]}
	{
		for (int i = 0; i < s; ++i) {
			elem[i] = 0;
		}
	}
	int size() const { return sz; }
	
	~first_vector() {delete[] elem;}
};

void sizes(char ch, int i, int* p, bool b, bool* bp, double d, double* dp, std::string s, std::string* sp)
{
	std::cout << "the size of char is " << sizeof(char) << ' ' << sizeof (ch) << '\n';
	std::cout << "the size of int is " << sizeof(int) << ' ' << sizeof (i) << '\n';
	std::cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof (p) << '\n';
	std::cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof (b) << '\n';
	std::cout << "the size of bool* is " << sizeof(bool*) << ' ' << sizeof (bp) << '\n';
	std::cout << "the size of double is " << sizeof(double) << ' ' << sizeof (d) << '\n';
	std::cout << "the size of double* is " << sizeof(double*) << ' ' << sizeof (dp) << '\n';
	std::cout << "the size of std::string* is " << sizeof(std::string*) << ' ' << sizeof (sp) << '\n';
	std::cout << "the size of std::string is " << sizeof(std::string) << ' ' << sizeof (s) << '\n';
	std::vector<int> v(10);
	std::cout << "the size of vector<int>(1000) is " << sizeof (v) << '\n';
}

double* calc(int res_size, int max) {
	double* p = new double[max];
	double* res = new double[res_size];
	delete[] p;
	return res;
}

int main() {
	/*int i = 1;
	int* p = &i;
	bool b = true;
	bool* bp = &b;
	double d = 3.14;
	double* dp = &d;
	std::string s = "sdsadsadsadasstring";
	std::string* sp = &s;
	sizes('2',i, p, b, bp, d, dp, s, sp);*/
	double* pointer = new double(5.5);
	pointer[1000] = 4.4;
	//std::cout << &pointer << std::endl;
	for (int i = 0; i < 10000; ++i) {
		double* dd = calc(100,1000000000);
	}
}
