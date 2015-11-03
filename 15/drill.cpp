#include "../14/14.h"

using namespace Graph_lib;

constexpr int xmax = 600;
constexpr int ymax = 600;
constexpr Point orig {xmax/2,ymax/2};

constexpr int x_offset = 100;
constexpr int y_offset = 100;

constexpr int r_min = -10;
constexpr int r_max = 11;

constexpr int x_scale = 40;
constexpr int y_scale = 40;

double one(double) {return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};
double sloping_cos(double x) {return cos(x) + slope(x);};

int main() {
	Graph_lib::Window win {Point {100,100},xmax,ymax,"Function graphs"};
	Axis x {Axis::x,Point{x_offset,ymax/2},400,400/20,"1 == 20 pixels"};
	Axis y {Axis::y,Point{xmax/2,400+y_offset},400,400/20,"1 == 20 pixels"};
	x.set_color(Color::red);
	y.set_color(Color::red);
	Mark m {orig,'X'};
	win.attach(m);
	win.attach(x);
	win.attach(y);
	Function f1 {one,r_min,r_max,orig,400,x_scale,y_scale};
	win.attach(f1);
	Function f2 {slope,r_min,r_max,orig,400,x_scale,y_scale};
	win.attach(f2);
	Text t2 {Point {f2.point(0).x,f2.point(0).y+30},"x/2"};
	win.attach(t2);
	Function f3 {square,r_min,r_max,orig,400,x_scale,y_scale};
	Function f4 {cos,r_min,r_max,orig,400,x_scale,y_scale};
	f4.set_color(Color::blue);
	Function f5 {sloping_cos,r_min,r_max,orig,400,x_scale,y_scale};
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);
	gui_main();
}