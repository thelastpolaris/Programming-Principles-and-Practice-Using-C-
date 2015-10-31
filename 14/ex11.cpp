/* Chapter 14 Exercise 11
Define a Binary_tree class derived from Shape. Give the number of levels as a parameter 
(levels==0 means no nodes, levels==1 means one node, levels==2 means one top node with two sub-nodes, levels==3 means one top node 
with two sub-nodes each with two sub-nodes, etc.). Let a node be represented by a small circle. 
Connect the nodes by lines (as is conventional). P.S. In computer science, trees grow downward from a top node 
(amusingly, but logically, often called the root).
Exercise 13
Modify Binary_tree to take a parameter (or parameters) to indicate what kind of line to use to connect the nodes (e.g., an arrow 
pointing down or a red arrow pointing up). Note how this exercise and the last use two alternative ways of making a class hierarchy 
more flexible and useful.
Exercise 14
Add an operation to Binary_tree that adds text to a node. You may have to modify the design of Binary_tree to implement this 
elegantly. Choose a way to identify a node; for example, you might give a string "lrrlr" for navigating left, right, right, 
left, and right down a binary tree (the root node would match both an initial l and an initial r).
*/
#include "14.h"

namespace Graph_lib {

Binary_tree::Binary_tree(Point cc, int ll, int rr, string line_style, Color line_color)
:level{ll}, r{rr}, node_d{r*20}
{	
	if (ll < 0) error("The minimum level is 0");
	int dx = node_d;
	int dy = node_d/5;
	for (int i = 0; i < level; ++i) {
		if(i == 0) add(cc);
		else {
			dx /=2;
			vector<Point> points;
			for (int a = pow(2,i-1)-1; a < pow(2,i)-1; ++a) {
				points.push_back(Point {point(a).x-dx,point(a).y+dy});
				points.push_back(Point {point(a).x+dx,point(a).y+dy});

			}
			for (Point s : points) add(s);
		}
	}
	for (int i = 0; i < number_of_points(); ++i) {
		labels.push_back(new Text{Point {point(i).x,point(i).y},""}); // Add empty labels to all nodes
		if (i < pow(2, level-1)-1) {
				if (line_style == "au") { // If line_style is "Arrow up"
					lines.push_back(new Arrow {point(2*i+1),point(i),line_color});
					lines.push_back(new Arrow {point(2*i+2),point(i),line_color});
				}
				else if (line_style == "ad") { // If line_style is "Arrow down"
					lines.push_back(new Arrow {point(i),point(2*i+1),line_color});
					lines.push_back(new Arrow {point(i),point(2*i+2),line_color});	
				}
				else {
					lines.push_back(new Line {point(i),point(2*i+1)});
					lines.push_back(new Line {point(i),point(2*i+2)});
				}
		}
	}
}

void Binary_tree::draw_lines() const {
	for (int i = 0; i < lines.size(); ++i) {
		lines[i].draw();
	}

	for (int i = 0; i < number_of_points(); ++i) {
		labels[i].draw();
		Circle c {point(i), r};
		c.set_fill_color(Color(192,192,192));
		c.draw();
	}

}

void Binary_tree::set_label(string text, string p) {
	if (p.length() > levels()-1) error("False coordinate(more commands than levels)");
	else {
		int n = 0;
		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == 'l') {
				if (i == 0) n = 1;
				else n = 2*n + 1;
			}
			else if (p[i] == 'r') {
				if (i == 0) n = 2;
				else n = 2*n + 2;
			}
			else error("Wrong character");
		}
		labels[n].set_label(text);
	}
}

}

int main() try {
	Simple_window win {x,800,600,"Binary Tree"};
	Graph_lib::Binary_tree bt {Point{400,50}, 3, 15, "", Graph_lib::Color::Color_type::black};
	bt.set_label("0","");
	bt.set_label("1","l");
	bt.set_label("2","r");
	bt.set_label("3","ll");
	bt.set_label("4","lr");
	bt.set_label("6","rr");
	bt.set_label("5","rl");
	win.attach(bt);
	win.wait_for_button();
}

catch (runtime_error& e) {
	cout << e.what() << endl;
}

catch (...) {
	cout << "Unknown error" << endl;
}
