/* Chapter 14 Exercise 8
Define a class Octagon to be a regular octagon. Write a test that exercises all of 
its functions (as defined by you or inherited from Shape).
*/
#include "14.h"

Graph_lib::Octagon::Octagon(Point cc, int rr)
:c{cc}, r{rr}
{	
	for (int a = 0; a <= 360; a += 45) {
		add(rotate_point(c,Point{c.x+r,c.y},a));
	}
}

void Graph_lib::Octagon::draw_lines() const {
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		for (int i = 0; i < number_of_points(); ++i) {
			fl_vertex(point(i).x, point(i).y);
		}
		fl_end_complex_polygon();
		fl_color(color().as_int());
	}
	if (color().visibility()) Shape::draw_lines();
}

void Graph_lib::Octagon::set_center(Point nc) {
	move((c.x - nc.x)*(-1), (c.y - nc.y)*(-1));
	c = nc;
}

void Graph_lib::Octagon::set_radius(int nr) {
	int i, d;
	for (struct {int i; int d;} v {0, 0}; v.i < number_of_points(); ++v.i, v.d += 45) {
		set_point(v.i, rotate_point(c,Point{c.x+nr,c.y},v.d));
	}
	r = nr;
}

int main() {
	Simple_window win {x,800,600,"Test of regular octagon"};
	Graph_lib::Octagon oct {Point{100,100},50};
	win.attach(oct);
	win.wait_for_button();

	// set_center
	oct.set_center(Point{350,300});
	cout << oct.center().x << " : " << oct.center().y << endl;
	win.wait_for_button();

	// set_radius
	oct.set_radius(200);
	cout << oct.radius() << endl;
	win.wait_for_button();

	// move
	oct.move(50, 50); // move the shape +=dx and +=dy
	win.wait_for_button();

	// set_color
    oct.set_color(Graph_lib::Color::Color_type::red);
    cout << oct.color().as_int() << endl;
    win.wait_for_button();

    // set_style
    oct.set_style(Graph_lib::Line_style(Graph_lib::Line_style::Line_style_type::solid,10));
    cout << oct.style().width() << " " << oct.style().style() << endl;
    win.wait_for_button();

    // set_fill_color
    oct.set_fill_color(Graph_lib::Color::Color_type::black);
    cout << oct.fill_color().as_int() << endl;
    win.wait_for_button();

    // points
    cout << "Points of octagon(" << oct.number_of_points() << "):" << endl;
    for (int i = 0; i < oct.number_of_points(); ++i) {
    	cout << i << endl;
    }
    win.wait_for_button();
}