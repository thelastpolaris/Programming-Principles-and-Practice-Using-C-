#include <string>
#include <iostream>

using std::string;

class A {
public:
	A(string s1, string s2);
	A(const string &A);
	string str() {return str2;}
private:
	string str1;
	string str2;
};

A::A(string s1, string s2)
:str1{s1}, str2{s2}
{
}

class B {
public:
	B(int x, string s1, string s2);
	string str11() {return a1.str();}
private:
	int i;
	A a1;
};

B::B(int x, string s1, string s2)
:i{x}, a1{s1,s2}
{
}

int main() {
	A k {"S","B"};
	B o {5,"S","B"};
	std::cout << k.str() << " " << o.str11() << std::endl;
}
