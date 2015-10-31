/*
Chapter 13 Exercise 12
Draw a circle. Move a mark around on the circle (let it move a bit each time you hit the “Next” button).
*/

#include "Classes.h"
#include <iostream>

int main() {
	Simple_window win1 {x,800,600,"Exercise 12"};
	Graph_lib::Circle c {Point{200,200},30};
	Graph_lib::Mark m {Point{0,0},'x'};
	win1.attach(c);
	win1.attach(m);
	for(int i = 0; i < 360; i+=10) {
		m.set_point(0,rotate_point(c.center(),Point{c.center().x,c.center().y-c.radius()},i));
		win1.wait_for_button();
	}
}
