/* Chapter 16 Exercise 5
Write a program that draws a shape of your choice and moves it to a new point each time you click “Next.” 
The new point should be determined by a coordinate pair read from an input stream.
*/

#include "16.h"
#include "../13/13.h"

namespace Graph_lib {
	Single_window::Single_window(Point xy, int x, int y, string label)
	:Window{xy, x, y, label}, coor{Point{0,0},80,20,"Current coord."}, buttons{Point{x-80,0},80,20,Menu::vertical,"Shapes"}
, next{Point{x-80,0},80,20,"Next",[](Address, Address pw) {reference_to<Single_window>(pw).nextShape();}}
	{
		buttons.attach(new Button{Point{x-80,0},80,20,"Circle",[](Address, Address pw) {reference_to<Single_window>(pw).draw_shape("circle");}});
		buttons.attach(new Button{Point{x-80,20},80,20,"Square",[](Address, Address pw) {reference_to<Single_window>(pw).draw_shape("square");}});
		buttons.attach(new Button{Point{x-80,40},80,20,"Triangle",[](Address, Address pw) {reference_to<Single_window>(pw).draw_shape("tri");}});
		buttons.attach(new Button{Point{x-80,60},80,20,"Hexagon",[](Address, Address pw) {reference_to<Single_window>(pw).draw_shape("hex");}});
		attach(buttons);
		attach(coor);
	}

	void Single_window::draw_shape(string s) {
		buttons.hide();
		Point p = getCoordinates();
		shape = s;
		if (s == "circle") {
			shapes.push_back(new Circle {p,int(x_max()*0.1)});
		}
		else if (s == "square") {
			shapes.push_back(new Rectangle {p,int(x_max()*0.2),int(x_max()*0.2)});
		}
		else if (s == "tri") {
			shapes.push_back(new Regular_polygon{p,3,int(x_max()*0.1)});
		}
		else if (s == "hex") {
			shapes.push_back(new Regular_polygon{p,6,int(x_max()*0.1)});	
		}
		attach(shapes[shapes.size()-1]);
		redraw();
		attach(next);
	}

	Point Single_window::getCoordinates() {
		Point p;
		std::cout << "Enter the coordinates:\n";
		std::cin >> p.x >> p.y;
		ostringstream os;
		os << p.x << ", " << p.y;
		coor.put(os.str());
		return p;
	}

	void Single_window::nextShape() {
		int x = 0;
		int y = 0;
		p = Point {x,y};
		detach(shapes[shapes.size()-1]);
		shapes.clear();
		draw_shape(shape);
		redraw();
	}
}

using namespace Graph_lib;

int main() {
	Single_window s_win {Point{100,100},800,600,"Shape window"};
	return gui_main();
} 
