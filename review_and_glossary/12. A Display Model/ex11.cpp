/* Chapter 12 Exercise 11
Draw a series of regular polygons, one inside the other. The innermost should be an equilateral triangle, enclosed by a square, 
enclosed by a pentagon, etc. For the mathematically adept only: let all the points of each N-polygon touch sides of the (N+1)-polygon. 
Hint: The trigonometric functions are found in <cmath> (§24.8, §B.9.2).
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities
#include <cmath>

const double pi = 3.14159265359;

int get_x(int p, int r, int a) {return p + int(r*cos(a*pi/180.0));}
int get_y(int p, int r, int a) {return p + int(r*sin(a*pi/180.0));}

int main()
{
	Simple_window win {Point{100,100},800,600,"Polygons"};
	//Circle
	//Graph_lib::Circle c {Point{400,300},145};
	//win.attach(c);
	//Equilateral Triangle
	// 0 - (300,100,300)
	Graph_lib::Polygon tri;
	tri.add(Point{get_x(400,150,270),get_y(345,150,270)});
	tri.add(Point{get_x(400,150,45),get_y(300,150,45)});
	tri.add(Point{get_x(400,150,135),get_y(300,150,135)});
	win.attach(tri);
	//Square
	Graph_lib::Polygon sqr;
	sqr.add(Point{get_x(400,150,45),get_y(300,150,45)});
	sqr.add(Point{get_x(400,150,135),get_y(300,150,135)});
	sqr.add(Point{get_x(400,150,225),get_y(300,150,225)});
	sqr.add(Point{get_x(400,150,315),get_y(300,150,315)});
	win.attach(sqr);
	//Pentagon
	Graph_lib::Polygon pen;
	pen.add(Point{get_x(410,175,0),get_y(300,175,0)});
	pen.add(Point{get_x(410,175,72),get_y(300,175,72)});
	pen.add(Point{get_x(410,175,144),get_y(300,175,144)});
	pen.add(Point{get_x(410,175,216),get_y(300,175,216)});
	pen.add(Point{get_x(410,175,288),get_y(300,175,288)});
	win.attach(pen);
	//Hexagon
	Graph_lib::Polygon hex;
	hex.add(Point{get_x(400,195,0),get_y(300,195,0)});
	hex.add(Point{get_x(400,195,60),get_y(300,195,60)});
	hex.add(Point{get_x(400,195,120),get_y(300,195,120)});
	hex.add(Point{get_x(400,195,180),get_y(300,195,180)});
	hex.add(Point{get_x(400,195,240),get_y(300,195,240)});
	hex.add(Point{get_x(400,195,300),get_y(300,195,300)});
	win.attach(hex);
	//Heptagon
	Graph_lib::Polygon hep;
	hep.add(Point{get_x(390,210,0),get_y(300,210,0)});
	hep.add(Point{get_x(390,210,51.43),get_y(300,210,51.43)});
	hep.add(Point{get_x(390,210,102.86),get_y(300,210,102.86)});
	hep.add(Point{get_x(390,210,154.29),get_y(300,210,154.29)});
	hep.add(Point{get_x(390,210,210.72),get_y(300,210,210.72)});
	hep.add(Point{get_x(390,210,257.15),get_y(300,210,257.15)});
	hep.add(Point{get_x(390,210,308.58),get_y(300,210,308.58)});
	win.attach(hep);
	//Octagon
	Graph_lib::Polygon oct;
	oct.add(Point{get_x(390,225,0),get_y(300,225,0)});
	oct.add(Point{get_x(390,225,45),get_y(300,225,45)});
	oct.add(Point{get_x(390,225,90),get_y(300,225,90)});
	oct.add(Point{get_x(390,225,135),get_y(300,225,135)});
	oct.add(Point{get_x(390,225,180),get_y(300,225,180)});
	oct.add(Point{get_x(390,225,225),get_y(300,225,225)});
	oct.add(Point{get_x(390,225,270),get_y(300,225,270)});
	oct.add(Point{get_x(390,225,315),get_y(300,225,315)});
	win.attach(oct);
	//Nonagon
	Graph_lib::Polygon non;
	non.add(Point{get_x(390,240,0),get_y(300,240,0)});
	non.add(Point{get_x(390,240,40),get_y(300,240,40)});
	non.add(Point{get_x(390,240,80),get_y(300,240,80)});
	non.add(Point{get_x(390,240,120),get_y(300,240,120)});
	non.add(Point{get_x(390,240,160),get_y(300,240,160)});
	non.add(Point{get_x(390,240,200),get_y(300,240,200)});
	non.add(Point{get_x(390,240,240),get_y(300,240,240)});
	non.add(Point{get_x(390,240,280),get_y(300,240,280)});
	non.add(Point{get_x(390,240,320),get_y(300,240,320)});
	win.attach(non);
	//Nonagon
	Graph_lib::Polygon dec;
	dec.add(Point{get_x(390,260,0),get_y(300,260,0)});
	dec.add(Point{get_x(390,260,36),get_y(300,260,36)});
	dec.add(Point{get_x(390,260,72),get_y(300,260,72)});
	dec.add(Point{get_x(390,260,108),get_y(300,260,108)});
	dec.add(Point{get_x(390,260,144),get_y(300,260,144)});
	dec.add(Point{get_x(390,260,180),get_y(300,260,180)});
	dec.add(Point{get_x(390,260,216),get_y(300,260,216)});
	dec.add(Point{get_x(390,260,252),get_y(300,260,252)});
	dec.add(Point{get_x(390,260,288),get_y(300,260,288)});
	dec.add(Point{get_x(390,260,324),get_y(300,260,324)});
	win.attach(dec);

	win.wait_for_button();
}