//#include "../fltk/Simple_window.h"   // get access to our window library
//#include "../fltk/Graph.h"                    // get access to our graphics library facilities 
#include "../13/13.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

// Exercise 1
namespace Graph_lib {

struct Smiley : Circle {
	Smiley(Point center, int radius);
	void draw_lines() const;
protected:
	Smiley() {}
};

struct Frowny : Circle {
	Frowny(Point center, int radius);
	void draw_lines() const;
protected:
	Frowny() {}
};

struct Smiley_hat : Smiley {
	using Smiley::Smiley;
	void draw_lines() const;	
};

struct Frowny_hat : Frowny {
	using Frowny::Frowny;
	void draw_lines() const;	
};

// Exercise 4
struct Immobile_Circle : Circle {
	using Circle::Circle;
	void move(int dx, int dy) { cout << "Moving is forbidden" << endl; };
};

// Exercise 5
struct Striped_rectangle : Rectangle {
	using Rectangle::Rectangle;
	void draw_lines() const;
};

// Exercise 6
struct Striped_circle : Circle {
	using Circle::Circle;
	void draw_lines() const;
};

// Exercise 7
struct Striped_closed_polyline : Closed_polyline {
	Striped_closed_polyline(int d);
	void draw_lines() const;
private:
	int density;
};

bool lie_on_line(Point p1, Point p2, Point current); // Checks if the point lies on the given line

// Exercise 8
struct Octagon : Shape {
	Octagon(Point cc, int rr);
	//Octagon_test();
	void rotate(int degree);
	Point center() { return c; };
	void set_center(Point nc);
	int radius() { return r; };
	void set_radius(int nr);
	void draw_lines() const;
private:
	Point c; // Center of the octagon 
	int r; // Distance from the center to each corner
};

// Exercise 9
struct Group : Shape {
	Group(){};
	void add_shape(Shape* s) { shapes.push_back(s); };
	void move(int dx, int dy);
	int number_of_shapes() const { return shapes.size(); };
	void set_color(Color col);
    void set_style(Line_style sty);
    void set_fill_color(Color col);
    void draw_lines() const;
private:
	Vector_ref<Shape> shapes;
};

// Exercise 10
struct Pseudo_window : Box {
	Pseudo_window(Point pp, int ww, int hh, string str, string img_file);
	
	//void set_image(Image i) { img = i; };
	void draw_lines() const;
private:
	Point p; // top left-most point
	int w; // Width
	int h; // Height
	Text lab; // Label
	Box window;
	Box minimize;
	Box maximize;
	Box close;
	Image img;
};

// Exercise 11 && 13
struct Binary_tree : Shape {
	Binary_tree(Point cc, int ll, int rr, string line_style, Color line_c = Color::Color_type::black);
	virtual void draw_lines() const;
	int radius() const { return r; };
	Point top_node() const { return point(0); };
	int levels() const { return level; };
	void set_line_color(Color c) { line_color = c; };
	void set_label(string text, string p);
protected:
	int r; // Radius of nodes
	int level; // Tree's levels
	int node_d; // Distance between nodes
	Color line_color =  Color::Color_type::black;
	Vector_ref<Shape> lines;
	Vector_ref<Text> labels;
};

// Exercise 12
struct Binary_tree_triangle : Binary_tree {
	using Binary_tree::Binary_tree;
	void draw_lines() const;
};

// Exercise 15
struct Iterator {
	virtual double* next() =0;
	virtual int size() const =0;
};

struct Vector_iterator : Iterator {
	double* next();
	Vector_iterator(vector<double> vv) :v{vv.begin(), vv.end()} { }
	vector<double> v;
	int size() const { return v.size(); };
	int i = 0;
};

struct List_iterator : Iterator {
	double* next();
	List_iterator(list<double> ll) :l{ll.begin(), ll.end()} { }
	list<double> l;
	int size() const { return l.size(); };
	int i = 0;
};

void print(Iterator& it);

// Exercise 16

struct Controller : Shape {
	Controller(bool ss, int ll)
	:status{ss}, level{ll} {}
	virtual void on() { status = true; };
	virtual void off() { status = false; };
	virtual void set_level(int l) {level = l; };
	virtual void const show(){};
protected:
	bool status;
	int level;
};

struct Controller_show : Controller{
	using Controller::Controller;
	void show() const { cout << status << endl << level << endl; };
};

struct Controller_color : Controller{
	using Controller::Controller;
	void control_color(Color col) { set_color(col); };
};

struct Controller_visibility : Controller{
	using Controller::Controller;
	void control_visibility(Color::Transparency v) { set_color(Color {color().as_int(), v}); };
};

} // end of Graph_lib
