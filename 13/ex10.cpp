/*
Chapter 13 Exercise 10
Define a class Regular_polygon. Use the center, the number of sides (>2), and the distance from the center 
to a corner as constructor arguments.
*/

#include "13.h"
#include <iostream>

Regular_polygon::Regular_polygon(Point cc, int ss, int dd)
:c{cc}, s{ss}, d{dd}
{
	if (ss == 4) add(Point{c.x+d,c.y-d});
	else add(Point{c.x,c.y-d});
	for (int a = 360/s; a < 360; a += 360/s) {
		Point p = rotate_point(c,point(0),a);
		add(p);
	}
}

void Regular_polygon::rotate(int angle) {
	for (int i = 1; i < number_of_points(); ++i) set_point(i, rotate_point(point(0), point(i), angle));
}

/*int main() {
	Simple_window win1{x,800,600,"Regular Polygon"};
	Regular_polygon rp_3 {Point{100,200},3,50};
	Regular_polygon rp_4 {Point{250,200},4,50};
	Regular_polygon rp_5 {Point{400,200},5,50};
	Regular_polygon rp_6 {Point{550,200},6,50};
	Regular_polygon rp_7 {Point{100,400},7,50};
	Regular_polygon rp_8 {Point{300,400},8,50};
	Regular_polygon rp_9 {Point{500,400},9,50};
	Regular_polygon rp_10 {Point{650,400},10,50};
	win1.attach(rp_3);
	win1.attach(rp_4);
	win1.attach(rp_5);
	win1.attach(rp_6);
	win1.attach(rp_7);
	win1.attach(rp_8);
	win1.attach(rp_9);
	win1.attach(rp_10);

	win1.wait_for_button();
}*/
