/*
Chapter 13 Exercise 8
Define a class Regular_hexagon (a regular hexagon is a six-sided polygon with all sides of equal length). 
Use the center and the distance from the center to a corner point as constructor arguments.
*/

#include "13.h"
#include <iostream>

Regular_hexagon::Regular_hexagon(Point cc, int dd)
:c{cc}, d{dd}
{
	add(Point{cc.x+dd,cc.y});
	for (int a = 60; a < 360; a += 60) {
		Point p = rotate_point(c,point(0),a);
		add(p);
	}
}

/*int main() {
	Simple_window win1{x,800,600,"Arrow"};
	Regular_hexagon r (Point{300,300},100);
	win1.attach(r);
	
	win1.wait_for_button();
}*/
