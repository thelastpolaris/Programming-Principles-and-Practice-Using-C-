/*
Chapter 13 Exercise 18
Define a class Poly that represents a polygon but checks that its points really do make a polygon in its constructor. 
Hint: You’ll have to supply the points to the constructor.
*/

#include "Classes.h"
#include <iostream>

int main() {
	Simple_window win1{x,800,600,"Arrow"};
	Graph_lib::Vector_ref<Point> p;
	p.push_back(new Point {100,100});
	p.push_back(new Point {200,200});
	p.push_back(new Point {100,300});
	Poly tri {p};
	win1.attach(tri);
	win1.wait_for_button();
}