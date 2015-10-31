/* Chapter 12 Exercise 2
Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{100,200},600,400,"Rectangle"};
	Graph_lib::Rectangle r {Point{250,185},100, 30};
	Graph_lib::Text t {Point{280, 205}, "Howdy!"};
	win.attach(r);
	win.attach(t);
	win.wait_for_button();
}