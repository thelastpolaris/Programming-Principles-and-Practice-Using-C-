/* Chapter 16 Exercise 9
Modify the calculator from Chapter 7 to get its input from an input box and return its results in an output box.
*/

#include "16.h"
#include "../13/13.h"
#include <chrono>
#include <ctime>
#include "calculator/calculator.h"

//------------------------------------------------------------------------------

namespace Graph_lib {

	constexpr int x_scale = 30;                // scaling factors
	constexpr int y_scale = 30;

	Graph_window::Graph_window(Point xy, int x, int y, string label)
	:Window{xy,x,y,label},x_axis{Axis::Orientation::x, Point{30,y/2}, x-60, x/x_scale, "x"},
	y_axis{Axis::Orientation::y, Point{x/2,y-30}, y-70, y/y_scale, "y"},
	r1{Point{x-160,0},80,20,"r1"}, r2{Point{x-160,20},80,20,"r2"},
	sin{Point{x-80,0},80,20,"sin()",[](Address, Address pw){reference_to<Graph_window>(pw).sin_g()	;}},
	cos{Point{x-80,20},80,20,"cos()",[](Address, Address pw){reference_to<Graph_window>(pw);}},
	tg{Point{x-80,40},80,20,"tg()",[](Address, Address pw){reference_to<Graph_window>(pw);}},
	ctg{Point{x-80,60},80,20,"ctg()",[](Address, Address pw){reference_to<Graph_window>(pw);}},
	sqr{Point{x-80,80},80,20,"sqr()",[](Address, Address pw){reference_to<Graph_window>(pw);}},
	cube{Point{x-80,100},80,20,"cube()",[](Address, Address pw){reference_to<Graph_window>(pw);}},
	four{Point{x-80,120},80,20,"four()",[](Address, Address pw){reference_to<Graph_window>(pw);}},
	five{Point{x-80,140},80,20,"five()",[](Address, Address pw){reference_to<Graph_window>(pw);}}
	{
		attach(x_axis);
		attach(y_axis);
		attach(r1);
		attach(r2);
		attach(sin);
		attach(cos);
		attach(tg);
		attach(ctg);
		attach(sqr);
		attach(cube);
		attach(four);
		attach(five);
	}

	void Graph_window::sin_g() {
		if(r1.is_empty() || r2.is_empty()) error("Enter the range of values");
		else {
			Function f ([](double x) {return std::sin(x);}, r1.get_int(), r2.get_int(), Point {x_max()/2,y_max()/2}, 100, x_scale, y_scale);
			attach(f);
			redraw();
		}
	}
}

using namespace Graph_lib;

int main() try {
	Graph_window gw {Point{100,100},800,600,"Graphs"};
	gui_main();
} 
catch(runtime_error& e) {
	std::cerr << e.what() << std::endl;
}
catch (...) { // Throws an exception
	std::cerr << "error\n";
}
