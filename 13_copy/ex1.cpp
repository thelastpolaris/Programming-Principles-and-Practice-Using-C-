/*Chapter 13 Exercise 1
Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
*/

#include "Classes.h"

void Arc::draw_lines() const
{
	if (color().visibility()) fl_arc(point(0).x, point(0).y, w, h, start, end);
}

int main() {
	Simple_window win1 {x,800,600,"Arc"};

	Arc a {Point{100,100},200,250,140,270};
	Arc b {Point{150,150},210,85,40,160};
	Arc c {Point{300,50},50,50,90,180};
	
	win1.attach(a);
	win1.attach(b);
	win1.attach(c);
	
	win1.wait_for_button();
}