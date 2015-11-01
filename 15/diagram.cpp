#include "../14/14.h"
using namespace Graph_lib;

struct Distribution {
	int year, young, middle, old;
};

istream& operator >>(istream& is, Distribution& d) {
	Distribution dd;
	char c1;
	char c2;
	char c3;
	if(is >> c1 >> dd.year >> c2 >> dd.young >> dd.middle >> dd.old >> c3) {
		if (c1 != '(' || c2 != ':' || c3 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
		else d = dd;
	}
	return is;
}

class Scale {
	int cbase; // offset
	int vbase; // base of values
	double scale;
public:
	Scale(int b, int v, double s) :cbase{b}, vbase{v}, scale{s} {}
	int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

constexpr int xmax = 600;     // window size
constexpr int ymax = 400;

constexpr int xoffset = 100;  // distance from left-hand side of window to y axis
constexpr int yoffset = 60;  // distance from bottom of window to x axis

constexpr int xspace = 40;  // space beyond axis
constexpr int yspace = 40;

constexpr int xlength = xmax-xoffset-xspace;          // length of axes
constexpr int ylength = ymax-yoffset-yspace;

constexpr int base_year = 1960;
constexpr int end_year = 2040;

constexpr double xscale = double(xlength)/(end_year-base_year);
constexpr double yscale = double(ylength)/100;

Scale xs {xoffset,base_year,xscale};
Scale ys {ymax-yoffset,0,-yscale};

int main() {
	Graph_lib::Window win {Point{100,100},xmax,ymax,"Aging Japan"};
	Axis x {Axis::x,Point{xoffset,ymax-yoffset},xlength,(end_year-base_year)/10, "year     1960     1970     1980     1990      "
    "2000      2010      2020      2030      2040"};
    x.label.move(-110,0);
    Axis y {Axis::y,Point{xoffset,ymax-yoffset},ylength,10,"% of population"};
    Line current_year {Point{xs(2015),ys(0)},Point{xs(2015),ys(100)}};
    current_year.set_style(Line_style::dash);

    Open_polyline young;
    Open_polyline middle;
    Open_polyline old;
    string file_name = "japanese_age_groups.txt";
	ifstream ifs {file_name};
	if (!ifs) error("can't open" + file_name);
	for (Distribution d; ifs >> d;) {
		if (d.year < base_year || d.year > end_year) {
			error("Incorrect year");
		}
		if (d.young+d.middle+d.old != 100) {
			error("Incorrect percentage");
		}
		const int x = xs(d.year);
		young.add(Point{x,ys(d.young)});
		middle.add(Point{x,ys(d.middle)});
		old.add(Point{x,ys(d.old)});
	}
	Text young_label {Point{20,young.point(0).y},"age 0-14"};
	young.set_color(Color::red);
	young_label.set_color(Color::red);

	Text middle_label {Point{20,middle.point(0).y},"age 15-64"};
	middle.set_color(Color::blue);
	middle_label.set_color(Color::blue);

	Text old_label {Point{20,old.point(0).y},"age 65+"};
	old.set_color(Color::dark_green);
	old_label.set_color(Color::dark_green);

	win.attach(young);
	win.attach(middle);
	win.attach(old);
	win.attach(young_label);
	win.attach(middle_label);
	win.attach(old_label);
    win.attach(x);
    win.attach(y);
    win.attach(current_year);
    gui_main();
}