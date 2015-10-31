/* Chapter 14 Exercise 16
Define a class Controller with four virtual functions on(), off(), set_level(int), and show(). Derive at least two classes from 
Controller. One should be a simple test class where show() prints out whether the class is set to on or off and what is the current 
level. The second derived class should somehow control the line color of a Shape; the exact meaning of “level” is up to you. Try to 
find a third “thing” to control with such a Controller class.
*/
#include "14.h"
namespace Graph_lib {

}

int main() {
	Graph_lib::Controller_show cs {0, 245};
	cs.show();
	Graph_lib::Controller_color cc {1, 120};
	cc.control_color(Graph_lib::Color::Color_type::red);
	cout << cc.color().as_int() << endl;
	Graph_lib::Controller_visibility cv {1, 130};
	cv.control_visibility(Graph_lib::Color::Transparency::visible);
	cout << cv.color().visibility() << endl;
}