/* Chapter 14 Exercise 2
Try to copy a Graph_lib::Shape. What happens?
Answer: Compiler throws an error because copy constructor as well as assignment operator of Shape are both declared as private.
*/
#include "14.h"

int main() {
	Simple_window win1{x,800,600,"Copying the Shape"};
	Graph_lib::Closed_polyline op;
	op.add(Point{100,100});
	op.add(Point{200,200});
	op.add(Point{100,200});
	Graph_lib::Shape copy = op;
	copy = op;
	
	win1.attach(copy);
	win1.attach(op);
	win1.wait_for_button();
}