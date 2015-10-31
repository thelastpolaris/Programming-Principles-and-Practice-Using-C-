/*
Chapter 13 Exercise 14
Define a right triangle class. Make an octagonal shape out of eight right triangles of different colors.
*/

#include "13.h"
#include <iostream>

Right_triangle::Right_triangle(Point rr, int ww, int hh)
:r{rr}, w{ww}, h{hh}
{
	add(rr);
	add(Point {rr.x+ww,rr.y});
	add(Point {rr.x,rr.y-hh});
}

Right_triangle::Right_triangle(const Right_triangle &rt)
:r{rt.right_angle()}, w{rt.width()}, h{rt.height()}
{
	add(r);
	add(Point {r.x+w,r.y});
	add(Point {r.x,r.y-h});
}

void Right_triangle::rotate(Point c, int angle) {
	set_point(0,rotate_point(c,point(0),angle));
	set_point(2,rotate_point(c,point(2),angle));
	r = point(0);
}

Right_triangle Right_triangle::operator=(const Right_triangle &rt) {
	return Right_triangle {rt.right_angle(), rt.width(), rt.height()};
}

/*int main() {
	Simple_window win1 {x,800,600,"Right triangle"};
	int a = 100;
	Graph_lib::Vector_ref<Right_triangle> octagonal_shape;
	octagonal_shape.push_back(new Right_triangle {Point {200,200},-a,-a});

	for(int i = 1; i < 8; ++i) {
		octagonal_shape.push_back(new Right_triangle {Point {octagonal_shape[i-1].right_angle().x+a,octagonal_shape[i-1].right_angle().y},-a,-a});
		 octagonal_shape[i].rotate(octagonal_shape[i-1].right_angle(),45*i);
	}
	for(int i = 0; i < octagonal_shape.size(); ++i) win1.attach(octagonal_shape[i]);
	win1.wait_for_button(); 
}*/
