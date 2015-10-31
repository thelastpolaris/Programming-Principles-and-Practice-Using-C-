/* Chapter 14 Exercise 5
Define a Striped_rectangle where instead of fill, the rectangle is “filled” by drawing one-pixel-wide horizontal lines across 
the inside of the rectangle (say, draw every second line like that). You may have to play with the width 
of lines and the line spacing to get a pattern you like.
*/
#include "14.h"

void Graph_lib::Striped_rectangle::draw_lines() const {
	Rectangle::draw_lines();
	for (int i = point(0).y; i < point(0).y+height()-1; i += 2) {
		Graph_lib::Line l {Point{point(0).x,i},Point{point(0).x-1+width(),i}};
		l.draw();
	}
}

int main() {
	Simple_window win1{x,800,600,"Striped Rectangle"};
	Graph_lib::Striped_rectangle sr {Point{100,25}, Point{600,400}};
	win1.attach(sr);
	win1.wait_for_button();
}