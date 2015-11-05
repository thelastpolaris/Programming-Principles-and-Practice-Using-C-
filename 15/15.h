#include <iomanip>

namespace Graph_lib {

class Funct : public Shape {
public:
	Funct(Fct_Capture ff, double rr1, double rr2, Point orig1, int c = 100, int x = 25, int y = 25, double precision = 1);
	void reset_fct(Fct_Capture ff) { f = ff;reset();};
	void reset_r1(double rr1) {r1 = rr1;reset();}; 
	void reset_r2(double rr2) {r2 = rr2;reset();};
	void reset_orig(Point orig1) {orig = orig1;reset();};
	void reset_xscale(int x) {xscale = x;reset();};
	void reset_yscale(int y) {yscale = y;reset();};
	void reset_prec(double precision) {prec = precision;reset();};
private:
	void reset();
	Fct_Capture f;
	double r1;
	double r2;
	Point orig;
	int count;
	int xscale;
	int yscale;
	double prec;
};

// Exercise 6, 7

class Bar : public Shape {
public:
	Bar(Point xy, int x, int y) :xsize{x}, ysize{y} { add(xy); }
	void add_value(double v);
	void remove_value(int i);
	void draw_lines() const;
	void set_bar_color(Color c, int i) { rectangles[i].set_color(c); };
	void set_bar_fill_color(Color c, int i) { rectangles[i].set_fill_color(c); };
	void set_bar_label(string t, int i) { labels[i].set_label(t); };
	int values_num() const { return values.size(); };
private:
	int xsize;
	int ysize;
	vector<double> values;
	Vector_ref<Text> labels;
	Vector_ref<Rectangle> rectangles;
};

class Scale_bar {
	double max;
	double size;
public:
	Scale_bar(double m, double s) :max{m}, size{s} { }
	int operator()(double value) { return ((value)/max)*size; };
};

// Exercise 8

struct Height
{
	int height, people;
};

struct Height_country
{
	string country;
	double height;
};

struct less_than_height {
	inline bool operator() (const Height& h1, const Height& h2) {
		return (h1.height < h2.height);
	}
	inline bool operator() (const Height_country& h1, const Height_country& h2) {
		return (h1.height < h2.height);
	}
};

} 
