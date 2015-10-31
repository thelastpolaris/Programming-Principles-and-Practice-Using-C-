/*Chapter 13 Exercise 5
Define the functions from exercise 4 for a Circle and an Ellipse. Place the connection points on or outside the shape 
but not outside the bounding rectangle.
*/
#include "13.h"
#include <iostream>
#include <cmath>

//Circle functions
Point n(const Graph_lib::Circle &c) {
	return Point{c.point(0).x+c.radius(),c.point(0).y};
}

Point w(const Graph_lib::Circle &c) {
	return Point{c.point(0).x,c.point(0).y+c.radius()};
}

Point s(const Graph_lib::Circle &c) {
	return Point{c.point(0).x+c.radius(),c.point(0).y+c.radius()*2};
}

Point e(const Graph_lib::Circle &c) {
	return Point{c.point(0).x+c.radius()*2,c.point(0).y+c.radius()};
}

Point center(const Graph_lib::Circle &c) {
	return c.center();
}

Point nw(const Graph_lib::Circle &c) {
	return Point{c.center().x + c.radius()*cos(get_radian(225)),c.center().y + c.radius()*sin(get_radian(225))};
}

Point ne(const Graph_lib::Circle &c) {
	return Point{c.center().x + c.radius()*cos(get_radian(315)),c.center().y + c.radius()*sin(get_radian(315))};
}

Point se(const Graph_lib::Circle &c) {
	return Point{c.center().x + c.radius()*cos(get_radian(45)),c.center().y + c.radius()*sin(get_radian(45))};
}

Point sw(const Graph_lib::Circle &c) {
	return Point{c.center().x + c.radius()*cos(get_radian(135)),c.center().y + c.radius()*sin(get_radian(135))};
}

//Ellipse functions
Point n(const Graph_lib::Ellipse &e) {
	return Point{e.point(0).x+e.major(),e.point(0).y};
}

Point w(const Graph_lib::Ellipse &e) {
	return Point{e.point(0).x+e.major()*2,e.point(0).y+e.minor()};
}

Point s(const Graph_lib::Ellipse &e) {
	return Point{e.point(0).x+e.major(),e.point(0).y+e.minor()*2};
}

Point e(const Graph_lib::Ellipse &e) {
	return Point{e.point(0).x,e.point(0).y+e.minor()};
}

Point center(const Graph_lib::Ellipse &e) {
	return e.center();
}

Point nw(const Graph_lib::Ellipse &e) {
	return Point{e.center().x + e.major()*cos(get_radian(225)),e.center().y + e.minor()*sin(get_radian(225))};
}

Point ne(const Graph_lib::Ellipse &e) {
	return Point{e.center().x + e.major()*cos(get_radian(315)),e.center().y + e.minor()*sin(get_radian(315))};
}

Point se(const Graph_lib::Ellipse &e) {
	return Point{e.center().x + e.major()*cos(get_radian(45)),e.center().y + e.minor()*sin(get_radian(45))};
}

Point sw(const Graph_lib::Ellipse &e) {
	return Point{e.center().x + e.major()*cos(get_radian(135)),e.center().y + e.minor()*sin(get_radian(135))};
}

/*int main() {
	Simple_window win1{x,800,600,"Circle and Ellipse functions"};
	Graph_lib::Circle c{Point {200,200},50};
	Graph_lib::Marks m_c{"x"};
	m_c.add(n(c));
	m_c.add(w(c));
	m_c.add(s(c));
	m_c.add(e(c));
	m_c.add(center(c));
	m_c.add(nw(c));
	m_c.add(ne(c));
	m_c.add(sw(c));
	m_c.add(se(c));
	win1.attach(c);
	win1.attach(m_c);

	Graph_lib::Ellipse ee{Point {500,200},50,150};
	Graph_lib::Marks m_e{"x"};
	m_e.add(n(ee));
	m_e.add(w(ee));
	m_e.add(s(ee));
	m_e.add(e(ee));
	m_e.add(center(ee));
	m_e.add(nw(ee));
	m_e.add(ne(ee));
	m_e.add(sw(ee));
	m_e.add(se(ee));
	win1.attach(ee);
	win1.attach(m_e);
	
	win1.wait_for_button();
}*/
