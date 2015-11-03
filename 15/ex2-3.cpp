/* Chapter 15 Exercise 2
2. Define a class Fct that is just like Function except that it stores its constructor arguments.
Provide Fct with “reset” operations, so that you can use it repeatedly for different ranges, different functions, etc.
3. Modify Fct from the previous exercise to take an extra argument to control precision or whatever. 
Make the type of that argument a template parameter for extra flexibility.
*/

#include "../14/14.h"
#include "15.h"

using namespace Graph_lib;

namespace Graph_lib {

void Funct::reset() {
	if (r2-r1<=0) error("bad graphing range");
    if (count <=0) error("non-positive graphing count");
    double dist = (r2-r1)/count;
    double r = r1;
    clear_points();
    for (int i = 0; i<count; ++i) {
       	add(Point(orig.x+round(int(int(r*xscale)/prec)*prec),orig.y-round(int(int(f(r)*yscale)/prec)*prec)));
    	r += dist;
   	}
}

Funct::Funct(Fct_Capture ff, double rr1, double rr2, Point orig1, int c, int x, int y, double precision)
	:f{ff}, r1{rr1}, r2{rr2}, orig{orig1}, count{c}, xscale{x}, yscale{y}, prec{precision}
	{
		reset();
	}

}

/*int main() {
	Graph_lib::Window win {Point{100,100},800,600,"Funct"};
	Funct f{[](double x) { return x*x;}, -10, 11, Point {400,500}, 100, 10, 10};
	win.attach(f);
	f.reset_fct([](double x) { return x*x*x;});
	gui_main();
}*/