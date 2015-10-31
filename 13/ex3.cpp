/*Chapter 13 Exercise 3
Define a class Arrow, which draws a line with an arrowhead.
*/
#include "13.h"
#include <iostream>
#include <cmath>

double get_radian(double d) {
	return d*(pi/180);
}

Point rotate_point(Point c, Point p, int angle) {
	double x = (p.x - c.x)*cos(get_radian(angle)) - (p.y - c.y)*sin(get_radian(angle)) + c.x;
	double y = (p.y - c.y)*cos(get_radian(angle)) + (p.x - c.x)*sin(get_radian(angle)) + c.y;
	return Point{x,y};
}

Point find_distance(Point p1, Point p2, int d) {
	double vx = p1.x - p2.x; // Vector towards second point
	double vy = p1.y - p2.y;
	double mag = sqrt(vx*vx + vy*vy); // Length of vector
	vx /= mag;
	vy /= mag;
	int px = int(double(p1.x) + vx*(mag+double(d))); // A.x (A point that lies on a line within a given distance)
	int py = int(double(p1.y) + vy*(mag+double(d))); // A.y
	return Point {px,py};
}

/*Arrow::Arrow(const Arrow &other)
:Line{other.point(0),other.point(1)}
{

}*/

Arrow::Arrow(Point p1, Point p2, Graph_lib::Color c) {
	add(p1);
	add(p2);
	set_color(c);
}

Arrow::Arrow(Point p1, Point p2) {
	add(p1);
	add(p2);
}

void Arrow::draw_lines() const {
	Shape::draw_lines(); //Draw line
	double rotation_rad_l = get_radian(45); // Left line of arrow
	double rotation_rad_r = get_radian(315); // Right line of arrow
	double distance = 10; // Size of arrow
	double vx = point(1).x - point(0).x; // Vector towards second point
	double vy = point(1).y - point(0).y;

	double mag = sqrt(vx*vx + vy*vy); // Length of vector
	//Normalization of vectors
	vx /= mag;
	vy /= mag;
	
	int px = int(double(point(0).x) + vx*(mag-distance)); // A.x (A point that lies on a line within a given distance)
	int py = int(double(point(0).y) + vy*(mag-distance)); // A.y
	
	//Left line of arrow	
	double rx_l = (px - point(1).x)*cos(rotation_rad_l) - (py - point(1).y)*sin(rotation_rad_l) + point(1).x;
	double ry_l = (py - point(1).y)*cos(rotation_rad_l) + (px - point(1).x)*sin(rotation_rad_l) + point(1).y;

	//Right line of arrow	
	double rx_r = (px - point(1).x)*cos(rotation_rad_r) - (py - point(1).y)*sin(rotation_rad_r) + point(1).x;
	double ry_r = (py - point(1).y)*cos(rotation_rad_r) + (px - point(1).x)*sin(rotation_rad_r) + point(1).y;
	
	//Draw arrow
	fl_line(point(1).x,point(1).y,rx_l,ry_l);
	fl_line(point(1).x,point(1).y,rx_r,ry_r);
	
}

/*int main() {
	Simple_window win1{x,800,600,"Arrow"};
	Arrow ar1{Point{400,20},Point{400,255}};
	Arrow ar2{Point{50,450},Point{395,260}};
	Arrow ar3{Point{750,450},Point{405,260}};
	win1.attach(ar1);
	win1.attach(ar2);
	win1.attach(ar3);
	
	win1.wait_for_button();
}*/
