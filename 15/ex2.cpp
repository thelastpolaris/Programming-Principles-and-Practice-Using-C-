/* Chapter 15 Exercise 2
2. Define a class Fct that is just like Function except that it stores its constructor arguments.
Provide Fct with “reset” operations, so that you can use it repeatedly for different ranges, different functions, etc.
*/

#include "../14/14.h"

using namespace Graph_lib;

namespace Graph_lib {

class Funct : public Shape {
public:
	Funct(Fct_Capture ff, double rr1, double rr2, Point orig1, int c, int x, int y);
	void reset(Fct_Capture ff, double rr1, double rr2 , Point orig1, int c, int x, int y);
private:
	Fct_Capture f;
	double r1;
	double r2;
	Point orig;
	int count = 100;
	int xscale = 25;
	int yscale = 25;
};

Funct::Funct(Fct_Capture ff, double rr1, double rr2, Point orig1, int c, int x, int y)
	:f{ff}, r1{rr1}, r2{rr2}, orig{orig1}, count{c}, xscale{x}, yscale{y}
	{
		if (r2-r1<=0) error("bad graphing range");
    	if (count <=0) error("non-positive graphing count");
    	double dist = (r2-r1)/count;
    	double r = r1;
    	for (int i = 0; i<count; ++i) {
        	add(Point(orig.x+int(r*xscale),orig.y-int(f(r)*yscale)));
    		r += dist;
    	}
	}

void Funct::reset(Fct_Capture ff, double rr1, double rr2 , Point orig1, int c, int x, int y) {
	f = ff;
	r1 = rr1;
	r2 = rr2;
	orig = orig1;
	count = c;
	xscale = x;
	yscale = y;
	resize_points(count);
	if (r2-r1<=0) error("bad graphing range");
    if (count <=0) error("non-positive graphing count");
    double dist = (r2-r1)/count;
    double r = r1;
    for (int i = 0; i<count; ++i) {
       	set_point(i,Point(orig.x+int(r*xscale),orig.y-int(f(r)*yscale)));
    	r += dist;
    }
}

}

int main() {
	Graph_lib::Window win {Point{100,100},800,600,"Funct"};
	Funct f{[](double x) { return x*x;}, -10, 11, Point {400,500}, 200, 10, 10};
	win.attach(f);
	f.reset([](double x) { return std::cos(x) - x/2;}, -10, 11, Point {400,200}, 200, 30, 30);
	gui_main();
}