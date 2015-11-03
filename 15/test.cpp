#include "../14/14.h"
#include <iostream>
#include <iomanip>

using namespace Graph_lib;

constexpr int xmax = 800;                 // window size
constexpr int ymax = 600;

constexpr int x_orig = xmax/2;         // position of (0,0) is center of window
constexpr int y_orig = ymax/2;
constexpr Point orig {x_orig,y_orig};

constexpr int r_min = -10;                // range [–10:11)
constexpr int r_max = 11;

constexpr int n_points = 100;           // number of points used in range

constexpr int x_scale = 30;                // scaling factors
constexpr int y_scale = 30;

constexpr int xlength = xmax-40;
constexpr int ylength = ymax-40;

double one(double x) {return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};
double sloping_cos(double x) {return cos(x) + x/2;};
double fac(int n) {return (n > 1) ? fac(n-1)*n : 1;};

double term(double x, int n) {return pow(x,n)/fac(n);};
double expe(double x, int n) {return (n > 0) ? term(x,n) + expe(x,n-1) : 1;};

int main() {
	Simple_window win(Point{100,100},xmax,ymax,"Function graphing");
	/*Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};

	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	//win.wait_for_button();

	Text t {Point{100,y_orig-40},"one"};
	Text t2 {Point{100,y_orig+y_orig/2-20},"x/2"};
	Text t3 {Point{x_orig-120,20},"x*x"};
	win.set_label("Function graphing: label functions");
	win.attach(t);
	win.attach(t2);
	win.attach(t3);
	//win.wait_for_button();*/

	Axis x {Axis::x, Point{20,y_orig},xlength,xlength/x_scale,"one notch == 1"};
	Axis y {Axis::y, Point{x_orig,ylength+20},ylength,ylength/y_scale,"one notch == 1"};
	win.attach(x);
	win.attach(y);
	//win.wait_for_button();

	x.set_color(Color::red);
	y.set_color(Color::red);
	//win.wait_for_button();

	/*Function s4 {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s5 {cos,r_min,r_max,orig,n_points,x_scale,y_scale};
	win.attach(s4);
	win.attach(s5);
	x.label.move(-100,0);
	x.notches.set_color(Color::dark_red);
	s5.set_color(Color::blue);
	//win.wait_for_button();

	Function f1 {log,0.000001,r_max,orig,200,x_scale,y_scale};
	Function f2 {sin,r_min,r_max,orig,200,x_scale,y_scale};
	Function f3 {exp,r_min,7,orig,200,30,30};
	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	f1.set_color(Color::dark_red);
	f2.set_color(Color::magenta);
	f3.set_color(Color::dark_yellow);
	//win.wait_for_button();

	Function fl3 {[](double x) {return x/3;},r_min,r_max,orig,200,x_scale,y_scale};
	Function fl4 {[](double x) {return x/4;},r_min,r_max,orig,200,x_scale,y_scale};
	Function fl5 {[](double x) {return x/5;},r_min,r_max,orig,200,x_scale,y_scale};
	Function fl6 {[](double x) {return x/6;},r_min,r_max,orig,200,x_scale,y_scale};
	Function fl7 {[](double x) -> double {return x/7;},r_min,r_max,orig,200,x_scale,y_scale};
	win.attach(fl3);
	win.attach(fl4);
	win.attach(fl5);
	win.attach(fl6);
	win.attach(fl7);*/
	cout << setprecision(64) << expe(1,33) << endl;
	Function real_exp {exp,r_min,7,orig,200,x_scale,y_scale};
	real_exp.set_color(Color::blue);
	win.attach(real_exp);

	for (int n = 0; n < 50; ++n) {
		ostringstream ss;
		ss << "exp approximation, n ==" << n << " exp == " << setprecision(32) << expe(1,n);
		win.set_label(ss.str());
		Function e {[n](double x){return expe(x,n);},r_min,r_max,orig,200,x_scale,y_scale};
		win.attach(e);
		win.wait_for_button();
		win.detach(e);
	}
	win.wait_for_button();
}