/*
Chapter 13 Exercise 11
Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a 300-pixel-long y axis through the center of the ellipse. 
Mark the foci. Mark a point on the ellipse that is not on one of the axes. Draw the two lines from the foci to the point.
*/
#include "13.h"
#include <iostream>

/*int main() {
	Simple_window win1 {x,800,600,"Ellipse"};
	Graph_lib::Ellipse e {Point {400,300},300,200};
	win1.attach(e);
	Graph_lib::Axis x {Graph_lib::Axis::Orientation::x, Point {e.center().x-350,e.center().y} ,700,0,"x"};
	Graph_lib::Axis y {Graph_lib::Axis::Orientation::y, Point {e.center().x,e.center().y+250},500,0,"y"};
	win1.attach(x);
	win1.attach(y);

	Graph_lib::Mark f1 {e.focus1(),'1'};
	Graph_lib::Mark f2 {e.focus2(),'2'};

	win1.attach(f1);
	win1.attach(f2);

	Graph_lib::Marks m_t {"."};
	Graph_lib::Marks m_b {"."};
	
	for (int x = e.point(0).x; x <= e.point(0).x+e.major()*2; ++x) {
		for (int y = e.point(0).y; y <= e.point(0).y+e.minor()*2; ++y) {
			int fw1 = x - e.focus1().x;
			//cout << fw1 << endl;
			int fh1 = y - e.focus1().y;
			int fp1 = sqrt(pow(fw1,2)+pow(fh1,2));
			int fw2 = x - e.focus2().x;
			int fh2 = y - e.focus2().y;
			int fp2 = sqrt(pow(fw2,2)+pow(fh2,2));
			if (fp1+fp2 == 2*e.major()) {
				if (y < e.center().y) m_t.add(Point{x,y});
				else m_b.add(Point{x,y});
			}			
		}
	}

	Graph_lib::Line l1_t {e.focus1(), m_t.point(451)};
	Graph_lib::Line l2_t {e.focus2(), m_t.point(451)};
	cout << m_t.number_of_points() << " : " << m_b.number_of_points()<< endl;

	win1.attach(l1_t);
	win1.attach(l2_t);

	Graph_lib::Line l1_b {e.focus1(), m_b.point(451)};
	Graph_lib::Line l2_b {e.focus2(), m_b.point(451)};

	win1.attach(l1_b);
	win1.attach(l2_b);

	win1.wait_for_button();
} */
