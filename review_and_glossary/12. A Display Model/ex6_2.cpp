/* Chapter 12 Exercise 6.2
What happens when you draw a Shape that doesn’t fit inside its window? 
What happens when you draw a Window that doesn’t fit on your screen? Write two programs that illustrate these two phenomena.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{0,0},1480,1324,"Frame"};
	
	Graph_lib::Rectangle r {Point{1000,20},800,600};
	
	win.attach(r);
	win.wait_for_button();
}