/* Chapter 14 Exercise 6
Define a Striped_circle using the technique from Striped_rectangle.
*/
#include "14.h"

void Graph_lib::Striped_circle::draw_lines() const {
	Circle::draw_lines();
	Point p {center().x,center().y-radius()};
	int degree = 360;
	for (int i = 0; i < 180; i += 2) {
		Graph_lib::Line l {rotate_point(center(),p,i), rotate_point(center(),p,degree-i)};
		l.draw();
	}
}

int main() {
	Simple_window win1{x,800,600,"Striped Circle"};
	Graph_lib::Striped_circle sc {Point{300,200}, 100};
	win1.attach(sc);
	win1.wait_for_button();
}