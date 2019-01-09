/* Chapter 12 Exercise 1
Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle blue.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{100,200},600,400,"Rectangle"};
	Graph_lib::Rectangle r {Point{320,150},150, 100};
	r.set_color(Graph_lib::Color::blue);
	Graph_lib::Polygon p;
	p.set_color(Graph_lib::Color::red);
	p.add(Point{20,150});
	p.add(Point{170,150});
	p.add(Point{170,250});
	p.add(Point{20,250});
	win.attach(r);
	win.attach(p);
	win.wait_for_button();
}