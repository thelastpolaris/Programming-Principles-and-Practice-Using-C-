#include "std_lib_facilities.h"

struct X {
	void f(int x) { // Member function of struct X
		struct Y { // Nested struct of struct X
			int f() { // Member function of struct Y
				return 1; 
			} 
			int m; // Data member of struct Y
		};
		int m; // A variable initialized within f();
		m=x; // Value assignment
		Y m2; // Declaration of object m2 of type Y
		return f(m2.f()); // Return the result of executing Y's a member function
	}
	int m; // Data member of X
	void g(int m) { // Member function of X
		if (m) f(m+2); // If m is 'true' execute f()
		else {
			g(m+2); // Else g executes g
		}
	}
	X() // X's constructor 
	{ } 
	void m3() { // Member function of X
	}

void main() { // Member function of X
	X a; // Initialization of object a of type X
	a.f(2); // Executing member function of object a
	}
};