/* Chapter 14 Exercise 15
Most class hierarchies have nothing to do with graphics. Define a class Iterator with a pure virtual function next() that returns 
a double* (see Chapter 17). Now derive Vector_iterator and List_iterator from Iterator so that next() for a Vector_iterator yields 
a pointer to the next element of a vector<double> and List_iterator does the same for a list<double>. You initialize a 
Vector_iterator with a vector<double> and the first call of next() yields a pointer to its first element, if any. If there is 
no next element, return 0. Test this by using a function void print(Iterator&) to print the elements of a vector<double> and 
a list<double>.
*/
#include "14.h"

namespace Graph_lib {
double* Vector_iterator::next() {
		double* pd;
		if (i != v.size()) {
			pd = &v[i];
			i++;
			return pd;
		}
		else {
			i = 0;
			return 0;
		}
	}

double* List_iterator::next() {
		double* pd;
		if (i != l.size()) {
			std::list<double>::iterator it = std::next(l.begin(),i);
			pd = &(*it);
			i++;
			return pd;
		}
		else {
			i = 0;
			return 0;
		}
	}

void print(Iterator& it) {
	for (int i = 0; i < it.size(); ++i) cout << *it.next() << endl;
}

}

int main() {
	vector<double> vec{5,6,3,4,2,5,6,1,2,2};
	Graph_lib::Vector_iterator v {vec};
	Graph_lib::print(v);
	cout << endl;
	list<double> ll{50,60,30,40,20,50,60,10,20,20};
	Graph_lib::List_iterator l {ll};
	Graph_lib::print(l);
}