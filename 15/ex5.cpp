/* Chapter 15 Exercise 5
“Animate” (as in §15.5) the series 1–1/3+1/5–1/7+1/9–1/11+ . . . . It is known as Leibniz’s series and converges to pi/4.
*/
#include "../14/14.h"
#include "15.h"

using namespace Graph_lib;

constexpr int x_size = 800;
constexpr int y_size = 600;

constexpr double r1 = 0;
constexpr double r2 = 100;

constexpr Point orig {x_size/2,y_size/2};

constexpr int numbers = 100;

constexpr int xscale = 3;
constexpr int yscale = 200;

constexpr int xoffset = 25;
constexpr int yoffset = 25;

double leibniz_series(double t) { return (t > 1) ? ((int(t)%2) ? 1.0/(t*2-1) : -1.0/(t*2-1)) + leibniz_series(t-1) : 1;}

int main() {
	Simple_window win {Point {100,100}, x_size, y_size, "Leibniz’s series"};

	Axis x_axis (Axis::x, Point{xoffset,y_size/2},x_size-2*xoffset,(x_size-2*xoffset)/xscale, "x axis");
	x_axis.set_color(Color::red);
	win.attach(x_axis);

	Axis y_axis (Axis::y, Point{x_size/2,y_size-yoffset},y_size-2*yoffset,(y_size-2*yoffset)/yscale, "y axis");
	y_axis.set_color(Color::red);
	win.attach(y_axis);

	for (int i = 1; i < r2; ++i) {
		Funct f1 (leibniz_series, r1, i, orig, i, xscale, yscale);
		win.attach(f1);
		win.wait_for_button();
	}
}