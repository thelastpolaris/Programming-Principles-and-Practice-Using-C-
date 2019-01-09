/* Chapter 12 Exercise 7
Draw a two-dimensional house seen from the front, the way a child would: with a door, two windows, and a roof with a chimney. 
Feel free to add details; maybe have “smoke” come out of the chimney.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{100,100},800,600,"House"};
	//Home
	Graph_lib::Rectangle home {Point{100,100},500,400};
	//Window 1
	Graph_lib::Polygon window_1;
	window_1.add(Point{150,150});
	window_1.add(Point{150,300});
	window_1.add(Point{250,300});
	window_1.add(Point{250,150});
	//Window 2
	Graph_lib::Polygon window_2;
	window_2.add(Point{300,150});
	window_2.add(Point{300,300});
	window_2.add(Point{400,300});
	window_2.add(Point{400,150});
	//Door
	Graph_lib::Line door_1(Point{525,300}, Point{600,300});
	Graph_lib::Line door_2(Point{525,300}, Point{525,500});
	//Roof
	Graph_lib::Polygon roof;
	roof.add(Point{300,20});
	roof.add(Point{650,100});
	roof.add(Point{50,100});
	
	win.attach(home);
	win.attach(window_1);
	win.attach(window_2);
	win.attach(door_1);
	win.attach(door_2);
	win.attach(roof);
	win.wait_for_button();
}