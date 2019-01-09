/* Chapter 12 Exercise 4
Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{100,200},600,400,"Tic-Tac-Toe"};
	//Line 1
	Graph_lib::Rectangle r1_1 {Point{200,100},50,50};
	r1_1.set_fill_color(Graph_lib::Color::white);
	Graph_lib::Rectangle r1_2 {Point{250,100},50,50};
	r1_2.set_fill_color(Graph_lib::Color::red);
	Graph_lib::Rectangle r1_3 {Point{300,100},50,50};
	r1_3.set_fill_color(Graph_lib::Color::white);
	win.attach(r1_1);
	win.attach(r1_2);
	win.attach(r1_3);
	//Line 2
	Graph_lib::Rectangle r2_1 {Point{200,150},50,50};
	r2_1.set_fill_color(Graph_lib::Color::red);
	Graph_lib::Rectangle r2_2 {Point{250,150},50,50};
	r2_2.set_fill_color(Graph_lib::Color::white);
	Graph_lib::Rectangle r2_3 {Point{300,150},50,50};
	r2_3.set_fill_color(Graph_lib::Color::red);
	win.attach(r2_1);
	win.attach(r2_2);
	win.attach(r2_3);
	//Line 3
	Graph_lib::Rectangle r3_1 {Point{200,200},50,50};
	r3_1.set_fill_color(Graph_lib::Color::white);
	Graph_lib::Rectangle r3_2 {Point{250,200},50,50};
	r3_2.set_fill_color(Graph_lib::Color::red);
	Graph_lib::Rectangle r3_3 {Point{300,200},50,50};
	r3_3.set_fill_color(Graph_lib::Color::white);
	win.attach(r3_1);
	win.attach(r3_2);
	win.attach(r3_3);

	win.wait_for_button();
}