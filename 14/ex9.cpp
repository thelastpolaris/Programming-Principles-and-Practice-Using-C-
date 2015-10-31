/* Chapter 14 Exercise 9
Define a Group to be a container of Shapes with suitable operations applied to the various members of the Group. 
Hint: Vector_ref. Use a Group to define a checkers (draughts) board where pieces can be moved under program control.
*/
#include "14.h"

namespace Graph_lib {

void Group::move(int dx, int dy) {
	for (int i = 0; i < number_of_shapes(); ++i) {
		shapes[i].move(dx,dy);
	}
}

void Group::set_color(Color col) {
	for (int i = 0; i < number_of_shapes(); ++i) {
		shapes[i].set_color(col);
	}
}

void Group::set_style(Line_style ls) {
	for (int i = 0; i < number_of_shapes(); ++i) {
		shapes[i].set_style(ls);
	}
}

void Group::set_fill_color(Color fc) {
	for (int i = 0; i < number_of_shapes(); ++i) {
		shapes[i].set_fill_color(fc);
	}
}

void Group::draw_lines() const {
	for (int i = 0; i < number_of_shapes(); ++i) {
		shapes[i].draw();
	}	
}
}


int main() {
	Simple_window win {x,800,600,"Group of Shapes"};
	Graph_lib::Group grp;
	win.attach(grp);

	grp.add_shape(new Graph_lib::Circle{Point{100,100},30});
	win.wait_for_button();

	grp.add_shape(new Graph_lib::Circle{Point{100,190},30});
	win.wait_for_button();

	grp.add_shape(new Graph_lib::Circle{Point{100,190},30});
	win.wait_for_button();

	grp.set_style(Graph_lib::Line_style {Graph_lib::Line_style::Line_style_type::solid,5});
	win.wait_for_button();

	grp.move(50,200);
	win.wait_for_button();
}