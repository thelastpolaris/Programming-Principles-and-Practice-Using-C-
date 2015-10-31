/* Chapter 12 Exercise 5
Draw a red ¼-inch frame around a rectangle that is three-quarters the height of your screen and two-thirds the width.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{0,0},1280,1024,"Frame"};
	
	Graph_lib::Rectangle r {Point{150,20},853,923};
	r.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));

	win.attach(r);

	Graph_lib::Polygon frame;
	frame.add(Point{145,15});
	frame.add(Point{1006,15});
	frame.add(Point{1006,946});
	frame.add(Point{145,946});
	frame.set_color(Graph_lib::Color::dark_red);
	//frame.set_style(Graph_lib::Line_style(0.25));

	win.attach(frame);
	win.wait_for_button();
}