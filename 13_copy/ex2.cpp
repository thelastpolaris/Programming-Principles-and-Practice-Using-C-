/*Chapter 13 Exercise 2
Draw a box with rounded corners. Define a class Box, consisting of four lines and four arcs.
*/
#include "Classes.h"
#include <iostream>

void Box::add_points(Point p, int w, int h)  {
	double wp = (double(w)/100)*10;
	double hp = (double(h)/100)*10;
	/* Sides without rounded corners
	Top side */
	add(Point{p.x+wp,p.y});
	add(Point{(p.x+w)-wp,p.y});
	//Right side
	add(Point{p.x+w,p.y+hp});
	add(Point{p.x+w,(p.y+h)-hp});
	//Bottom side
	add(Point{p.x+wp,p.y+h});
	add(Point{(p.x+w)-wp,p.y+h});
	//Left side
	add(Point{p.x,p.y+hp});
	add(Point{p.x,(p.y+h)-hp});
}

Point n(const Box &b) {
	return Point{b.point(0).x+b.width()/2,b.point(0).y};
}

Point w(const Box &b) {
	return Point{b.point(0).x,b.point(0).y+b.height()/2};
}

Point s(const Box &b) {
	return Point{b.point(0).x+b.width()/2,b.point(0).y+b.height()};
}

Point e(const Box &b) {
	return Point{b.point(0).x+b.width(),b.point(0).y+b.height()/2};
}

Point nw(const Box &b) {
	return Point{b.point(0).x,b.point(0).y};
}

Point ne(const Box &b) {
	return Point{b.point(0).x+b.width(),b.point(0).y};
}

Point se(const Box &b) {
	return Point{b.point(0).x+b.width(),b.point(0).y+b.height()};
}

Point sw(const Box &b) {
	return Point{b.point(0).x,b.point(0).y+b.height()};
}

Box::Box(Point p, int ww, int hh) // Top leftmost point of box, width, height
:w{ww}, h{hh}
{
	add(p);
	add_points(p,w,h);
}

Box::Box(Point p1, Point p2) // Top leftmost point of box and Bottom rightmost point of box
:w{p2.x - p1.x}, h{p2.y - p1.y}
{
	add(p1);
	add_points(p1,w,h);
}

Box::Box(const Box &b)
:w{b.w}, h{b.h}
{
	add(b.point(0));
	add_points(point(0),w,h);

}

void Box::operator=(const Box &other) {
	w = other.width();
	h = other.height();
	for (int i = 0; i < number_of_points(); ++i) set_point(i,other.point(i));
}

Point Box::center() {
	return Point{point(0).x+width()/2,point(0).y+height()/2};
}

void Box::draw_lines() const {
	for (int i=2; i<number_of_points(); i+=2) fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
	double we = ((double(w)/100)*10)*2;
	double he = ((double(h)/100)*10)*2;
	
	fl_arc(point(0).x,point(0).y,we,he,180,90); // Top leftmost corner
	fl_arc((point(0).x+w)-we,point(0).y,we,he,0,90); // Top rightmost corner
	fl_arc((point(0).x+w)-we,(point(0).y+h)-he,we,he,270,360); // Bottom rightmost corner
	fl_arc(point(0).x,(point(0).y+h)-he,we,he,180,270); // Bottom leftmost corner
}

/*int main() {
	Simple_window win1{x,800,600,"Box"};
	Box a {x,150,150};
	Box b {Point{300,300},188,100};
	Box c {Point{400,400},250,150};

	win1.attach(a);
	win1.attach(b);
	win1.attach(c);
	win1.wait_for_button();
}*/