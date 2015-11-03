/* Chapter 15 Exercise 4
Graph a sine (sin()), a cosine (cos()), the sum of those (sin(x)+cos(x)), and the sum of the squares of those (sin(x)*sin(x)+cos(x)*cos(x)) 
on a single graph. Do provide axes and labels.
*/
#include "../14/14.h"
#include "15.h"

using namespace Graph_lib;

constexpr int x_size = 800;
constexpr int y_size = 600;

constexpr double r1 = -10;
constexpr double r2 = 11;

constexpr Point orig {x_size/2,y_size/2};

constexpr int numbers = 100;

constexpr int xscale = 25;
constexpr int yscale = 25;

int main() {
	Graph_lib::Window win {Point {100,100}, x_size, y_size, "sin(), cos(), sin(x) + cos(x), sin(x)*sin(x) + cos(x)*cos(x)"};
	Funct f1 ([](double x) { return std::sin(x);}, r1, r2, orig, numbers, xscale, yscale);
	win.attach(f1);

	Funct f2 ([](double x) { return std::cos(x);}, r1, r2, orig, numbers, xscale, yscale);
	f2.set_color(Color::blue);
	win.attach(f2);

	Funct f3 ([](double x) { return std::sin(x) + std::cos(x);}, r1, r2, orig, numbers, xscale, yscale);
	f3.set_color(Color::dark_red);
	win.attach(f3);

	Funct f4 ([](double x) { return std::sin(x)*std::sin(x) + std::cos(x)*std::cos(x);}, r1, r2, orig, numbers, xscale, yscale);
	f4.set_color(Color::dark_green);
	win.attach(f4);

	

	gui_main();
}