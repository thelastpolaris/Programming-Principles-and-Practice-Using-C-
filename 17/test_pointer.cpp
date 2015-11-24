#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

class A {
public:
	std::string sA;
	A(std::string s) :sA{s} {/* std::cout << "A is created\n"; */}
	~A() { std::cout << "A was deleted\n";}
	std::string get_pA() {std::cout << pA << std::endl;}
	virtual void funct() {std::cout << sA << '\n';};
private:
	std::string pA = "test_private";
};

class B : public A {
public:
	std::string sB;
	std::string* pB;
	B(std::string s) :A{s}, sB{s}, pB{&s} { /*std::cout << "B is created\n"; */}
	~B() {std::cout << "B was deleted\n";}
	std::string get_pB() {return ppB;}
private:
	std::string ppB = "test_private_B";
};

B* get_B(std::string s) {
	B* bp = new B{s};
	return bp;
}

A* funct_A(A* object) {
	std::cout << object->sA << std::endl;
	return object;
}

int main() {
	//A a {"test"};
	//B* b = new B{"test"};
	//B* p = get_B("testTEST");
	//std::cout << p -> sB << std::endl;
	//b->funct();
	int i = 10000000;
	while(i--) {
		A* ap = new B{"test"};
		delete ap;
	}
	/*float* pi = new float(22);
	double* pd = reinterpret_cast<double*>(pi);
	std::cout << *pd << std::endl;*/
}