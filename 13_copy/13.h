#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities 

const Point x {100,100};
const double pi = 3.14159265359;

//Chapter 13 Exercise 1
struct Arc : Graph_lib::Shape {
	Arc(Point x, int ww, int hh, double ss, double ee) // Center of Ellipse, Width, Height, Start of Arc, End of Arc
	:w{ww}, h{hh}, start{ss}, end{ee} {
		add(x);
	}
	void draw_lines() const;
private:
	int w;
	int h;
	double start;
	double end;
};

//Chapter 13 Exercise 2
struct Box : Graph_lib::Shape {
	Box(Point p, int ww, int hh);
	Box(Point p1, Point p2);
	Box(const Box &b);
	void draw_lines() const;
	void add_points(Point p, int w, int h) ;
	Point center();
	void operator=(const Box &other);
	int width() const {return w;};
	int height() const {return h;};
private:
	int w;
	int h;
};

Point n(const Box &b);
Point e(const Box &b);
Point s(const Box &b);
Point w(const Box &b);
Point center(const Box &b);
Point nw(const Box &b); //North-west (top-left corner of rectangle)
Point ne(const Box &b); //North-east (top-right corner of rectangle)
Point sw(const Box &b); //South-west (bottom-left corner of rectangle)
Point se(const Box &b); //South-east (bottom-right corner of rectangle)

//Chapter 13 Exercise 3
struct Arrow : Graph_lib::Line {
	using Line::Line;
	Arrow(const Arrow &other);
	void draw_lines() const;
};

double get_radian(double d);
Point rotate_point(Point c, Point p, int angle);
Point find_distance(Point p1, Point p2, int d);

//Chapter 13 Exercise 4
Point n(const Graph_lib::Rectangle &r);
Point e(const Graph_lib::Rectangle &r);
Point s(const Graph_lib::Rectangle &r);
Point w(const Graph_lib::Rectangle &r);
Point center(const Graph_lib::Rectangle &r);
Point nw(const Graph_lib::Rectangle &r); //North-west (top-left corner of rectangle)
Point ne(const Graph_lib::Rectangle &r); //North-east (top-right corner of rectangle)
Point sw(const Graph_lib::Rectangle &r); //South-west (bottom-left corner of rectangle)
Point se(const Graph_lib::Rectangle &r); //South-east (bottom-right corner of rectangle)

//Chapter 13 Exercise 5
Point n(const Graph_lib::Circle &c);
Point e(const Graph_lib::Circle &c);
Point s(const Graph_lib::Circle &c);
Point w(const Graph_lib::Circle &c);
Point center(const Graph_lib::Circle &c);
Point nw(const Graph_lib::Circle &c); //North-west (top-left corner of rectangle)
Point ne(const Graph_lib::Circle &c); //North-east (top-right corner of rectangle)
Point sw(const Graph_lib::Circle &c); //South-west (bottom-left corner of rectangle)
Point se(const Graph_lib::Circle &c); //South-east (bottom-right corner of rectangle)

Point n(const Graph_lib::Ellipse &e);
Point e(const Graph_lib::Ellipse &e);
Point s(const Graph_lib::Ellipse &e);
Point w(const Graph_lib::Ellipse &e);
Point center(const Graph_lib::Ellipse &e);
Point nw(const Graph_lib::Ellipse &e); //North-west (top-left corner of rectangle)
Point ne(const Graph_lib::Ellipse &e); //North-east (top-right corner of rectangle)
Point sw(const Graph_lib::Ellipse &e); //South-west (bottom-left corner of rectangle)
Point se(const Graph_lib::Ellipse &e); //South-east (bottom-right corner of rectangle)

//Chapter 13 Exercise 6
struct Box_arr : Graph_lib::Shape {
	Box_arr(Point p, string l, Point arr2);
	Box_arr(Point p, string l);
	void draw_lines() const;
	string text(){return t.label();}
	void set_font_size(int i){t.set_font_size(i);}
	Point center() {return b.center();}
	void add_arrow(Point arr2);
	Point arrow_side(const Point &arr2);
private:
	Box b;
	Graph_lib::Text t;
	vector<Arrow> arr;
};

//Chapter 13 Exercise 8
struct Regular_hexagon : Graph_lib::Polygon {
	Regular_hexagon(Point c, int d);
private:
	Point c; // Center
	int d; // Distance from center to the corner of hexagon
};

//Chapter 13 Exercise 9
Graph_lib::Vector_ref <Regular_hexagon> hexagon_tile(Point c, int d, int n_y, int n_x); /* Center of first hexagon, distance to the corner, 
																		 number of hexagons per x axis and per y axis */	

//Chapter 13 Exercise 10
struct Regular_polygon : Graph_lib::Polygon {
	Regular_polygon(Point cc, int ss, int dd);
	void rotate(int angle);
private:
	Point c; // Center of polygon
	int s; // Number of sides
	int d; // Distance from center to the corner
};

//Chapter 13 Exercise 14
struct Right_triangle : Graph_lib::Polygon {
	Right_triangle(Point r, int a, int b);
	Right_triangle(const Right_triangle &rt);
	void rotate(Point c, int angle);
	Point right_angle() const { return r;};
	int width() const { return w; };
	int height() const { return h; };
	Right_triangle operator=(const Right_triangle &rt);
private:
	Point r; // Right angle point
	int w; // Width
	int h; // Height
};

//Chapter 13 Exercise 18
struct Poly : Graph_lib::Polygon {
	Poly(Graph_lib::Vector_ref<Point> p) { for(int i = 0; i < p.size(); ++i) add(p[i]);};
};

//Chapter 13 Exercise 19
struct Star : Graph_lib::Polygon {
	Star(Point c, int p, int r); // Center, number of points, radius
	void rotate(int angle);
private:
	Point c; // Center
	int r; // Radius
	int p; // Number of points
};