/* Chapter 16 Exercise 7
Using the techniques developed in the previous exercises, make an image of an airplane “fly around” in a window.
Have a “Start” and a “Stop” button.
*/

#include "16.h"
#include "../13/13.h"
#include <chrono>
#include <ctime>

namespace Graph_lib {
	using namespace std::chrono;
	Airplane::Airplane(Point xy, int x, int y, string label, string image, int x_step, int y_step)
	:Window{xy,x,y,label}, start{Point{0,0},80,20,"Start",[](Address, Address pw){reference_to<Airplane>(pw).is_flying = true;}}, 
	stop{Point{0,20},80,20,"Stop",[](Address, Address pw){reference_to<Airplane>(pw).is_flying = false;}}, plane{Point{0,60},image}
	{	
		plane.set_point(0,Point{0,y-plane.height()});
		attach(plane);
		attach(start);
		attach(stop);
		step.x_step = x_step;
		step.y_step = y_step;
		step.x_orig = x_step;
		step.y_orig = x_step;
	}

	void Airplane::cb_fly(void* p) {
		Airplane* a = (Airplane*)p;
		a->fly();
		Fl::repeat_timeout(0.1, cb_fly, a);
	}

	void Airplane::fly() {
		if (is_flying) {
			plane.move(step.x_step, step.y_step);
			step.x_step++;
			step.y_step--;
			redraw();
		}
		if (plane.point(0).x > x_max()) {
			step.reset_step();
			plane.set_point(0,Point{0,y_max()-plane.height()});
		}
	}
}

using namespace Graph_lib;

int main() {
	Airplane* a = new Airplane {Point{100,100},800,600,"Flying airplane","airplane.gif",1,-1};
	Fl::add_timeout(1.0, Airplane::cb_fly, a);
	gui_main();
} 
