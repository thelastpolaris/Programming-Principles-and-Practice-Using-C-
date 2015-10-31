/* Chapter 14 Exercise 7
Define a Striped_closed_polyline using the technique from Striped_rectangle (this requires some algorithmic inventiveness).
*/
#include "14.h"

bool Graph_lib::lie_on_line(Point p1, Point p2, Point current) {
	int dxc = current.x - p1.x;
	int dyc = current.y - p1.y;

	int dx1 = p2.x - p1.x;
	int dy1 = p2.y - p1.y;

	if (!(dxc*dy1 - dx1*dyc)) {
		if(abs(dx1) > abs(dy1)) {
			return dx1 > 0 ? p1.x <= current.x && current.x <= p2.x : p2.x <= current.x && current.x <= p1.x;
		}
		else return dy1 > 0 ? p1.y <= current.y && current.y <= p2.y : p2.y <= current.y && current.y <= p1.y;
	}
	return false;	
}

bool line_segment_intersection(Point p1, Point p2, Point p3, Point p4, Point &intersect) {
	double y1 = p1.y;
	double y2 = p2.y;
	double y3 = p3.y;
	double y4 = p4.y;
	double x1 = p1.x;
	double x2 = p2.x;
	double x3 = p3.x;
	double x4 = p4.x;
	
	double denom = (y4-y3)*(x2-x1) - (x4-x3)*(y2-y1);
	double u1 = (x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3);
	double u2 = (x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3);

	if (denom == 0 && u1 != 0 && u2 !=0) return false;

	u1 = u1/denom;
	u2 = u2/denom;

	if (u1 < 0 || u1 > 1 || u2 < 0 || u2 > 1) return false;

	intersect.x = x1 + u1*(x2 - x1);
	intersect.y = y1 + u1*(y2 - y1);
	return true;
}

Graph_lib::Striped_closed_polyline::Striped_closed_polyline(int d) :density{d} { }

void Graph_lib::Striped_closed_polyline::draw_lines() const {
	Closed_polyline::draw_lines();
	int min_x = point(0).x; // top left-most point's x
	int min_y = point(0).y; // top left-most point's y
	int max_x = point(0).x; // right-most point's x
	int max_y = point(0).y; // bottom point's y
	vector<Point> lines; // to hold lines
	for (int i = 1; i < number_of_points(); ++i) {
		if(point(i).x < min_x) min_x = point(i).x;
		if(point(i).y < min_x) min_y = point(i).y;
		if(point(i).x > max_x) max_x = point(i).x;
		if(point(i).y > max_y) max_y = point(i).y;
	}
	// Search for intersections of polyline and horizontal lines
	for (int y = min_y + density; y < max_y; y += density) {
		Point intersect;
		for (int i = 1; i < number_of_points(); ++i) {
			if (line_segment_intersection(Point{min_x,y},Point{max_x,y},point(i-1),point(i),intersect)) { 
				lines.push_back(intersect); // find an intersection of polyline and horizontal lines
				}
			}

		if (line_segment_intersection(Point{min_x,y},Point{max_x,y},point(number_of_points()-1),point(0),intersect)) { 
				lines.push_back(intersect); // last line of polyline (starting in the last point and ending in the first one)
			}
		}
	
	for (int i = 1; i < lines.size(); i+=2 ) {
		Line l {lines[i],lines[i-1]}; // draw lines
		l.draw();
	}
}

int main() {
	Simple_window win1{x,800,600,"Striped Circle"};
	Graph_lib::Striped_closed_polyline scp {2};
	scp.add(Point {100,100});
	scp.add(Point {300,280});
	scp.add(Point {200,280});
	scp.add(Point {50,200});
	scp.add(Point {90,150});
	win1.attach(scp);
	win1.wait_for_button();
}