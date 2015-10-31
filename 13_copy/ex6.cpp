/*Chapter 13 Exercise 6
Write a program that draws a class diagram like the one in §12.6. It will simplify matters if you start by defining 
a Box class that is a rectangle with a text label.
*/
#include "Classes.h"
#include <iostream>
#include <sstream>

Point Box_arr::arrow_side(const Point &arr2) {
	Point center = b.center();
	Point topleft = b.point(0);
	if (arr2.y > n(b).y && arr2.y < s(b).y && arr2.x > w(b).x && arr2.x < e(b).x) error("Arrow within the area of box");
	if (arr2.x < topleft.x) return w(b);
	else if(arr2.x > topleft.x && arr2.x < topleft.x+b.width()) {
		if (arr2.y < center.y) return n(b);
		else if(arr2.y > center.y) return s(b);
	}
	else if (arr2.x > topleft.x+b.width()) return e(b);
}

Box_arr::Box_arr(Point p, string l, Point arr2)
:t{p,l}, b{x,10,10}
{
	t.set_font_size(8);
	Point box_1 {t.point(0).x-30,t.point(0).y-20};
	Point box_2 {t.point(0).x+t.width()+0,t.point(0).y+t.font_size()+10};
	b = Box {box_1,box_2};
	arr.push_back(Arrow{arrow_side(arr2),arr2});
}

/*Box_arr::Box_arr(Point p, string l)
:t{p,l}//, b{box_text(tt)}
{
	
}*/

void Box_arr::draw_lines() const {
	for (Arrow a : arr) a.draw_lines();
	t.draw_lines();
	b.draw_lines();
	
}

void Box_arr::add_arrow(Point arr2) {
	arr.push_back(Arrow{arrow_side(arr2),arr2});
}

int main() try {
	Simple_window win1 {x,800,600,"Class diagram"};
	//Box b = box_text(Graph_lib::Text{x,"Test"});
	//win1.attach(b);
	Box_arr box_arr1{Point{400,200},"Test2Test2Test2Test",Point {100,300}};
	win1.attach(box_arr1);
	box_arr1.add_arrow(Point {600,300});
	box_arr1.add_arrow(Point {600,200});
	box_arr1.add_arrow(Point {600,400});
	Graph_lib::Text t {x,"Test2Test"};
	t.set_font_size(20);
	std::cout << t.length() << " " << t.width() << " " << t.font_size() << std::endl;
	win1.attach(t);
	win1.wait_for_button();
}
catch (runtime_error&e) {
	std::cout << e.what() << std::endl;
}