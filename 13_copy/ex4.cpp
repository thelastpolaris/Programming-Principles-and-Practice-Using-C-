/*Chapter 13 Exercise 4
Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). Each takes a Rectangle argument and returns a Point. 
These functions define “connection points” on and in the rectangle. 
For example, nw(r) is the northwest (top left) corner of a Rectangle called r.
*/
#include "Classes.h"
#include <iostream>

Point n(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x+r.width()/2,r.point(0).y};
}

Point w(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x,r.point(0).y+r.height()/2};
}

Point s(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x+r.width()/2,r.point(0).y+r.height()};
}

Point e(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x+r.width(),r.point(0).y+r.height()/2};
}

Point center(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x+r.width()/2,r.point(0).y+r.height()/2};
}

Point nw(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x,r.point(0).y};
}

Point ne(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x+r.width(),r.point(0).y};
}

Point se(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x+r.width(),r.point(0).y+r.height()};
}

Point sw(const Graph_lib::Rectangle &r) {
	return Point{r.point(0).x,r.point(0).y+r.height()};
}

int main() {
	Simple_window win1{x,800,600,"Rectangle functions"};
	Graph_lib::Rectangle r{Point {200,200},150,250};
	Graph_lib::Marks m{"x"};
	m.add(n(r));
	m.add(w(r));
	m.add(s(r));
	m.add(e(r));
	m.add(center(r));
	m.add(nw(r));
	m.add(ne(r));
	m.add(sw(r));
	m.add(se(r));
	win1.attach(r);
	win1.attach(m);
	win1.wait_for_button();
}