/*Chapter 16 Exercise 1
Make a My_window that’s a bit like Simple_window except that it has two buttons, next and quit.
*/

#include "16.h"

namespace Graph_lib {

My_window::My_window(Point xy, int w, int h, const string& label)
:Window{xy,w,h,label}, next_button{Point {w-70,0},70,20,"Next",[](Address, Address pw) {reference_to<My_window>(pw).next();}},
quit_button{Point{w-70,20},70,20,"Quit",[](Address, Address pw) {reference_to<My_window>(pw).quit();}}, is_pressed{false}, b_quit{false}
{
	attach(next_button);
	attach(quit_button);
}

void My_window::wait_for_button() {
	if(1) {
	    while(!is_pressed && !b_quit) Fl::wait();
	    Fl::redraw();
	    is_pressed = false;
	}
}

void My_window::next() {
	is_pressed = true;
}

void My_window::quit() {
	b_quit = true;
	hide();
}

}

using namespace Graph_lib;

/*int main() {
	My_window win {Point{100,100},800,600,"Exercise 1"};
	Line l{Point {200,200}, Point {300,200}};
	win.attach(l);
	win.wait_for_button();
	Line l2{Point {200,400}, Point {300,200}};
	win.attach(l2);
	win.wait_for_button();
}*/