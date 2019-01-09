/* Chapter 12 Exercise 9
Display an image on the screen, e.g., a photo of a friend. 
Label the image both with a title on the window and with a caption in the window.
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
	Simple_window win {Point{100,100},800,600,"Photo"};
	Graph_lib::Image photo{Point{200,200}, "y.jpg"};
	Graph_lib::Text t{Point{320,530}, "Autumn Plains"};

	win.attach(photo);
	win.attach(t);
	win.wait_for_button();
}