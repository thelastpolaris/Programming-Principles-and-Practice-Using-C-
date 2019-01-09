/* Chapter 12 Exercise 3
Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{100,200},600,400,"Initials"};
	Graph_lib::Line a1 {Point{150,250}, Point{200,100}};
	Graph_lib::Line a2 {Point{200,100}, Point{250,250}};
	Graph_lib::Line a3 {Point{175,175}, Point{225,175}};
	a1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
	a2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
	a3.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
	a1.set_color(Graph_lib::Color::dark_blue);
	a2.set_color(Graph_lib::Color::dark_blue);
	a3.set_color(Graph_lib::Color::dark_blue);
	win.attach(a1);
	win.attach(a2);
	win.attach(a3);
	Graph_lib::Line f1 {Point{300,100}, Point{300,250}};
	Graph_lib::Line f2 {Point{300,100}, Point{400,100}};
	Graph_lib::Line f3 {Point{300,175}, Point{350,175}};
	f1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
	f2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
	f3.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
	f1.set_color(Graph_lib::Color::dark_green);
	f2.set_color(Graph_lib::Color::dark_green);
	f3.set_color(Graph_lib::Color::dark_green);
	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.wait_for_button();
}