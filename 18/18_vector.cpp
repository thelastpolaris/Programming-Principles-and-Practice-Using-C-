#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

class vector {
	int sz;
	double* elem;
public:
	explicit vector(int size);
	vector(std::initializer_list<double> lst);
	vector(const vector& arg);
	vector(vector && arg);

	friend ostream & operator << (ostream &out, const vector &c);
	vector& operator= (const vector& arg);
	vector& operator= (vector&& arg);
	double& operator[] (int n) { return elem[n]; }
	double operator[] (int n) const { return elem[n]; }

	void set(int n, double v) { elem[n] = v; }

	~vector();
};

vector::vector(int size) : sz{size}, elem{new double[sz]} {
	for(int i = 0; i < size; ++i) {
		elem[i] = 0.0;
	}
}

vector::vector(std::initializer_list<double>lst) : sz{lst.size()}, elem{new double[sz]} {
	cout << "init_list constructor" << endl;
	copy(lst.begin(), lst.end(), elem);
}

vector::vector(const vector& arg) :sz{arg.sz}, elem{new double[arg.sz]} {
	cout << "copy" << endl;
	copy(arg.elem, arg.elem + sz, elem);
}

vector::vector(vector && arg) :sz{arg.sz}, elem{arg.elem} {
	cout << "move constructor";
	arg.sz = 0;
	arg.elem = nullptr;
}

vector& vector::operator=(const vector& arg) {
	cout << "assignment" << endl;

	double* p = new double[arg.sz];
	copy(arg.elem, arg.elem + sz, p);
	delete[] elem;

	elem = p;
	sz = arg.sz;

	return *this;
}

vector& vector::operator= (vector&& arg) {
	delete[] elem;
	
	elem = arg.elem;
	sz = arg.sz;

	arg.elem = nullptr;
	arg.sz = 0;

	return *this;
}

ostream& operator << (ostream& out, const vector& c) {
	for (int i = 0; i < c.sz; ++i) {
		out << c.elem[i] << " ";
	}
	out << endl;
	return out;
}

// vector::vector()

vector fill(int numbers) {
	vector res(numbers);
	return res;
}

vector::~vector() {
	delete[] elem;
}

int main() {
	vector v1{1,2,3};
	cout << v1[0] << endl;
	v1[0] = 1;

	const vector v2{4,5,6};
	cout << v2[0] << endl;
}