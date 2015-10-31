/*
Chapter 13 Exercise 19
Define a class Star. One parameter should be the number of points. 
Draw a few stars with differing numbers of points, differing line colors, and differing fill colors.
*/

#include "13.h"
#include <iostream>

Star::Star (Point cc, int pp, int rr)
:c{cc}, r{rr}, p{pp}
{	
	add(Point{c.x,c.y-r});
	add(find_distance(rotate_point(c,point(0),180/p), c, r));
	for (int a = 360/p; a < 360; a += 360/p) {
		add(rotate_point(c,point(0),a));
		Point rp = rotate_point(c,point(number_of_points()-1),180/p);
		add(find_distance(rp, c, r));
	}
	/*if(p <= 4) {
		if (p == 3) polygon.rotate(180);
		for (int i = 0; i < 360; i+=360/p) {
			for (int a = 1; a <= p*2; a += 2) {
				add(polygon.point(a));
				add(rotate_point(c,Point {c.x,c.y-r},i));
				add(polygon.point(a+1));
			}
		}
	}*/
}

void Star::rotate(int angle) {
	for (int i = 1; i < number_of_points(); ++i) set_point(i, rotate_point(point(0), point(i), angle));
}

/*int main() {
	Simple_window win1{x,1000,600,"Star"};
	Star rp1 {Point {200,300}, 3, 50};
	Star rp2 {Point {550,200}, 4, 50};
	Star rp3 {Point {800,250}, 5, 50};
	//3-sided star
	rp1.set_fill_color(44);
	rp1.set_color(12);
	rp1.set_style(Graph_lib::Line_style {Graph_lib::Line_style::Line_style_type::solid,5});
	rp1.rotate(180);
	win1.attach(rp1);
	//4-sided star
	rp2.set_fill_color(88);
	rp2.set_color(32);
	rp2.set_style(Graph_lib::Line_style {Graph_lib::Line_style::Line_style_type::solid,5});
	rp2.rotate(45);
	win1.attach(rp2);
	//pentagram
	rp3.rotate(180);
	rp3.set_fill_color(132);
	rp3.set_color(52);
	rp3.set_style(Graph_lib::Line_style {Graph_lib::Line_style::Line_style_type::solid,5});
	win1.attach(rp3);
	
	win1.wait_for_button();
}*/
