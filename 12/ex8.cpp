/* Chapter 12 Exercise 8
Draw the Olympic five rings. If you can’t remember the colors, look them up.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{100,100},800,600,"Olympic symbol"};
	//Circle 1
	Graph_lib::Circle o1 {Point{150,150},50};
	o1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid,2));
	o1.set_color(Graph_lib::Color::blue);
	win.attach(o1);
	//Circle 2
	Graph_lib::Circle o2 {Point{255,150},50};
	o2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid,2));
	o2.set_color(Graph_lib::Color::black);
	win.attach(o2);
	//Circle 3
	Graph_lib::Circle o3 {Point{360,150},50};
	o3.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid,2));
	o3.set_color(Graph_lib::Color::red);
	win.attach(o3);
	//Circle 4
	Graph_lib::Circle o4 {Point{200,200},50};
	o4.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid,2));
	o4.set_color(Graph_lib::Color::yellow);
	win.attach(o4);
	//Circle 5
	Graph_lib::Circle o5 {Point{305,200},50};
	o5.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid,2));
	o5.set_color(Graph_lib::Color::green);
	win.attach(o5);

	win.wait_for_button();
}