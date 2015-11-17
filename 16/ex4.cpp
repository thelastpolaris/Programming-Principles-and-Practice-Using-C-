/* Chapter 16 Exercise 4
Make a menu with items that make a circle, a square, an equilateral triangle, and a hexagon, respectively. 
Make an input box (or two) for giving a coordinate pair, and place the shape made by pressing a menu item at that coordinate. 
Sorry, no drag and drop.
*/

#include "16.h"
#include "../13/13.h"

namespace Graph_lib {
	void Shape_window::draw_shape(string s) {
		int x = coor_x.get_int();
		int y = coor_y.get_int();
		if (s == "circle") {
			shapes.push_back(new Circle {Point{x,y},int(x_max()*0.1)});
		}
		else if (s == "square") {
			shapes.push_back(new Rectangle {Point{x,y},int(x_max()*0.2),int(x_max()*0.2)});
		}
		else if (s == "tri") {
			shapes.push_back(new Regular_polygon{Point{x,y},3,int(x_max()*0.1)});
		}
		else if (s == "hex") {
			shapes.push_back(new Regular_polygon{Point{x,y},6,int(x_max()*0.1)});	
		}
		attach(shapes[shapes.size()-1]);
		redraw();
	}
	
	Shape_window::Shape_window(Point xy, int x, int y, string label)
	:Window{xy, x, y, label}, coor_x{Point{20,0},80,20,"x"}, coor_y{Point{110,0},80,20,"y"}, buttons{Point{x-80,0},80,20,Menu::vertical,"Shapes"}
	{	
		attach(coor_x);
		attach(coor_y);
		buttons.attach(new Button{Point{x-80,0},80,20,"Circle",[](Address, Address pw) {reference_to<Shape_window>(pw).draw_shape("circle");}});
		buttons.attach(new Button{Point{x-80,20},80,20,"Square",[](Address, Address pw) {reference_to<Shape_window>(pw).draw_shape("square");}});
		buttons.attach(new Button{Point{x-80,40},80,20,"Triangle",[](Address, Address pw) {reference_to<Shape_window>(pw).draw_shape("tri");}});
		buttons.attach(new Button{Point{x-80,60},80,20,"Hexagon",[](Address, Address pw) {reference_to<Shape_window>(pw).draw_shape("hex");}});
		attach(buttons);
	}
}

using namespace Graph_lib;

/*int main() {
	Shape_window s_win {Point{100,100},800,600,"Shape window"};
	return gui_main();
}*/
