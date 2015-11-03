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

} 
