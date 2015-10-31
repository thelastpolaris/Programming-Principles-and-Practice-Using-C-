/* Chapter 14 Exercise 1
Define two classes Smiley and Frowny, which are both derived from class Circle and have two eyes and a mouth. 
Next, derive classes from Smiley and Frowny which add an appropriate hat to each.
*/
#include "14.h"

Graph_lib::Smiley::Smiley(Point center, int radius){
	add(center);
	set_radius(radius);
}

void Graph_lib::Smiley::draw_lines() const {
	Graph_lib::Circle::draw_lines();
	Graph_lib::Circle eye1 {Point {center().x-radius()/2,center().y-radius()/2},radius()/4};
	eye1.draw_lines();
	Graph_lib::Circle eye2 {Point {center().x+radius()/2,center().y-radius()/2},radius()/4};
	eye2.draw_lines();
	Arc smile (center(), radius()*1.2, radius()/1.4, 180, 360);
	smile.draw_lines();
}

Graph_lib::Frowny::Frowny(Point center, int radius){
	add(center);
	set_radius(radius);
}

void Graph_lib::Frowny::draw_lines() const {
	Graph_lib::Circle::draw_lines();
	Graph_lib::Circle eye1 {Point {center().x-radius()/2,center().y-radius()/2},radius()/4};
	eye1.draw_lines();
	Graph_lib::Circle eye2 {Point {center().x+radius()/2,center().y-radius()/2},radius()/4};
	eye2.draw_lines();
	Arc smile (Point {center().x, center().y*1.1}, radius()*1.2, radius()/1.4, 0, 180);
	smile.draw_lines();
}

void Graph_lib::Smiley_hat::draw_lines() const {
	Graph_lib::Polygon hat;
	hat.add(Point{center().x-radius(),center().y-radius()});
	hat.add(Point{center().x-radius(),center().y-radius()*1.5});
	hat.add(Point{center().x-radius()/2,center().y-radius()*1.5});
	hat.add(Point{center().x-radius()/2,center().y-radius()*2});
	hat.add(Point{center().x+radius()/2,center().y-radius()*2});
	hat.add(Point{center().x+radius()/2,center().y-radius()*1.5});
	hat.add(Point{center().x+radius(),center().y-radius()*1.5});
	hat.add(Point{center().x+radius(),center().y-radius()});
	hat.draw_lines();
}

void Graph_lib::Frowny_hat::draw_lines() const {
	Graph_lib::Polygon hat;
	hat.add(Point{center().x-radius(),center().y-radius()});
	hat.add(Point{center().x-radius(),center().y-radius()*1.5});
	hat.add(Point{center().x-radius()/2,center().y-radius()*1.5});
	hat.add(Point{center().x-radius()/2,center().y-radius()*2});
	hat.add(Point{center().x+radius()/2,center().y-radius()*2});
	hat.add(Point{center().x+radius()/2,center().y-radius()*1.5});
	hat.add(Point{center().x+radius(),center().y-radius()*1.5});
	hat.add(Point{center().x+radius(),center().y-radius()});
	hat.draw_lines();
}

int main() {
	Simple_window win1{x,800,600,"Smiley and Frowny"};
	Graph_lib::Smiley s {Point{200,200},100};
	win1.attach(s);
	Graph_lib::Frowny f {Point{500,200},100};
	win1.attach(f);
	Graph_lib::Smiley_hat sh {Point{200,200},100};
	win1.attach(sh);
	Graph_lib::Frowny_hat fh {Point{500,200},100};
	win1.attach(fh);
	win1.wait_for_button();
}
