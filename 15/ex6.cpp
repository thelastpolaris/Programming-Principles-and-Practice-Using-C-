/* Chapter 15 Exercise 6
Design and implement a bar graph class. Its basic data is a vector<double> holding N values, and each value should be represented by a “bar” 
that is a rectangles where the height represents the value.
*/
#include "../14/14.h"
#include "15.h"
#include <ctime>

namespace Graph_lib {

class Bar : public Shape {
public:
	Bar(Point xy, int x, int y) :xsize{x}, ysize{y} { add(xy); }
	void add_value(double v);
	void remove_value(int i);
	void draw_lines() const;
	void set_bar_color(Color c, int i) { rectangles[i].set_color(c); };
	void set_bar_fill_color(Color c, int i) { rectangles[i].set_fill_color(c); };
	void set_bar_label(string t, int i) { labels[i].set_label(t); };
private:
	int xsize;
	int ysize;
	vector<double> values;
	Vector_ref<Text> labels;
	Vector_ref<Rectangle> rectangles;
};

class Scale {
	double max;
	double size;
public:
	Scale(double m, double s) :max{m}, size{s} { }
	int operator()(double value) { return ((value)/max)*size; };
};

void Bar::add_value(double v) {
	values.push_back(v);
	labels.push_back(new Text{Point{0,0}," "});
	int bar_width = xsize/values.size();

	Vector_ref<Text> labels_c;
	for (int i = 0; i < labels.size(); ++i) labels_c.push_back(labels[i]);

	vector<Color> colors;
	vector<Color> fill_colors;
	double max_val = 0;
	for (int i = 0; i <= rectangles.size(); ++i) {
		if (i != rectangles.size()) {
			colors.push_back(rectangles[i].color());
			fill_colors.push_back(rectangles[i].fill_color());
		}
		if (values[i] > max_val) max_val = values[i];
	}

	Scale ys {max_val, ysize};

	labels.clear();
	rectangles.clear();
	for (int i = 0; i < values.size(); ++i) {
		rectangles.push_back(new Rectangle {Point {point(0).x+bar_width*i+bar_width*0.2, point(0).y - ys(values[i])}, bar_width-bar_width*0.2, ys(values[i])});
		labels.push_back(new Text {Point {rectangles[i].point(0).x, point(0).y + ysize*0.1}, labels_c[i].label()});
	}
	for (int i = 0; i < colors.size(); ++i) {
		rectangles[i].set_color(colors[i]);
		rectangles[i].set_fill_color(fill_colors[i]);
	}
}

void Bar::draw_lines() const {
	for (int i = 0; i < rectangles.size(); ++i) {
		rectangles[i].draw_lines();
		Line l {Point {point(0).x,rectangles[i].point(0).y},Point {point(0).x*0.8,rectangles[i].point(0).y}};
		l.set_style(Line_style::dash);
		l.draw();
		Text v {Point {point(0).x*0.5,rectangles[i].point(0).y}, to_string(values[i])};
		v.draw_lines();
		if (labels[i].label() != " ") {
			labels[i].draw();
		}
	}
	Axis x {Axis::x, point(0), xsize, 0, ""};
	Axis y {Axis::y, point(0), ysize, 0, ""};
	x.draw_lines();
	y.draw_lines();
}

constexpr int x_size = 800;
constexpr int y_size = 600;

constexpr int xoffset = 25;
constexpr int yoffset = 25;

}

using namespace Graph_lib;

int main() {
	srand(time(0));
	Simple_window win {Point {100,100}, x_size, y_size, "Bar chart"};
	Bar b {Point{100,500}, 500, 300};
	for (int i = 10; i <= 100; i+=10) {
		b.add_value(1 + rand()%4000);
	}
	b.add_value(400);
	b.set_bar_fill_color(Color::red, 4);
	b.set_bar_label("Third",3);
	win.attach(b);
	win.wait_for_button();
}

