/* Chapter 14 Exercise 12
Modify Binary_tree to draw its nodes using a virtual function. Then, derive a new class from Binary_tree that overrides that virtual 
function to use a different representation for a node (e.g., a triangle).
*/
#include "14.h"

namespace Graph_lib {

void Binary_tree_triangle::draw_lines() const {
	for (int i = 0; i < number_of_points(); ++i) {
		Regular_polygon tri {point(i), 3, radius()};
		tri.draw();
		labels[i].draw();
	}
	for (int i = 0; i < lines.size(); ++i) {
		lines[i].draw();
	}
	
}

}

int main() {
	Simple_window win {x,800,600,"Binary Tree with Triangles"};
	Graph_lib::Binary_tree_triangle btt {Point{400,50}, 5, 20, "ad", Graph_lib::Color::Color_type::red};
	win.attach(btt);
	btt.set_label("Test","rlll");
	btt.set_label("Test1","");
	btt.set_label("Test2","lrr");
	win.wait_for_button();
}