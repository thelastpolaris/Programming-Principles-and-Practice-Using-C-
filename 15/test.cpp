#include "../14/14.h"
#include <iostream>
using namespace Graph_lib;

constexpr int xmax = 800;                 // window size
constexpr int ymax = 600;

constexpr int x_orig = xmax/2;         // position of (0,0) is center of window
constexpr int y_orig = ymax/2;
constexpr Point orig {x_orig,y_orig};

constexpr int r_min = -10;                // range [–10:11)
constexpr int r_max = 11;

constexpr int n_points = 999999999;           // number of points used in range

constexpr int x_scale = 30;                // scaling factors
constexpr int y_scale = 30;

constexpr int xlength = xmax-40;
constexpr int ylength = ymax-40;

double one(double x) {return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};

int main() {
	Simple_window win(Point{100,100},xmax,ymax,"Function graphing");
	Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};

	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.wait_for_button();

	Text t {Point{100,y_orig-40},"one"};
	Text t2 {Point{100,y_orig+y_orig/2-20},"x/2"};
	Text t3 {Point{x_orig-120,20},"x*x"};
	win.set_label("Function graphing: label functions");
	win.attach(t);
	win.attach(t2);
	win.attach(t3);
	win.wait_for_button();

	Axis x {Axis::x, Point{20,y_orig},xlength,xlength/x_scale,"one notch == 1"};
	Axis y {Axis::y, Point{x_orig,ylength+20},ylength,ylength/y_scale,"one notch == 1"};
	win.attach(x);
	win.attach(y);
	win.wait_for_button();

	x.set_color(Color::red);
	y.set_color(Color::red);
	win.wait_for_button();
}