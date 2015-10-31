/* Chapter 14 Exercise 3
Define an abstract class and try to define an object of that type. What happens?
Answer: class A - compiler throws an error because the class is abstract and pure virtual function wasn't overriden.
class B - compiler throws an error because default constructor of class is protected.
*/
#include "14.h"

struct A {
	virtual void test() const =0;
};

struct Ab : A {
	virtual void test() const { cout << "Ab" << endl;};
};

struct B {
	virtual void test() const {};
protected:
	B(){}
};

struct Bb : B {
	virtual void test() const { cout << "Bb" << endl;};
};

struct C {
	C(int aa ){ a = aa;};
	int get_a() { return a; };
private:
	int a;
};

int factorial(int n) {
	if (n <= 1) return 1;
	return n*factorial(n-1);
}

int main() {
	//A a;
	Ab ab;
	ab.test();
	Bb bb;
	bb.test();
	C d {32};
	cout << d.get_a() << endl;

	double f = 65.505;
	double* ptr = &f;

	cout << ptr << endl;

	char ch1 = 'a';
	char ch2 = 'b';
	char ch3 = 'c';
	char ch4 = 'd';

	/*char * pi = "sd";
	char * ps = pi;
	pi = "Frederick";
	char* chp = &ch;
	cout << pi << endl;
	cout << ps << endl;*/
	cout << "int: " << sizeof(int) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "char: " << sizeof(char) << endl;

	cout << factorial(5) << endl;

	//B b;
}