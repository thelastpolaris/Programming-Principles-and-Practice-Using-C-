/* Chapter 12 Exercise 12
A superellipse is a two-dimensional shape defined by the equation
Look up superellipse on the web to get a better idea of what such shapes look like. 
Write a program that draws “starlike” patterns by connecting points on a superellipse. Take a, b, m, n, and N as arguments. 
Select N points on the superellipse defined by a, b, m, and n. Make the points equally spaced for some definition of “equal.” 
Connect each of those N points to one or more other points (if you like you can make the number of points to which 
to connect a point another argument or just use N–1, i.e., all the other points).
*/

#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities
#include <cmath>
#include <iostream>

int sgn(double d) {

    if (d < 0)
        return -1;
    if (d == 0)
        return 0;
    if (d > 0)
        return 1;
    // exception
    error("sgn: something gone wrong\n");
}

const double m_pi = 3.14159265359;

vector<Point> superellipse(double a, double b, double m, double n, double precision = 0.01, int xCenter = 300, int yCenter = 300) {
    if (precision < 0.01 || precision > 1) error("Wrong precision");

    vector<Point> points;
    Point temp;
    Point point;
    for (double d = -1.0; d < 1.0; d += precision ) {
        double t = d*m_pi;
        int x = a * pow(abs(cos(t)),2.0/m) * sgn(cos(t));
        int y = b * pow(abs(sin(t)),2.0/n) * sgn(sin(t));
        
        point = Point {x + xCenter, y + yCenter};
        if (temp != point) points.push_back(point); // Check for duplicates
        temp = point;
    }
    return points;
}

/*vector<Point> polygon_in_superellipse (vector<Point> se, int N) {
    vector<Point> points;
    for (int i = 0; i < se.size(); i++) {
        for (int j = i + 1; j < se.size(); j++) {
            for (int s = j + 1; s < se.size(); s++){
                for (int a = 0; a < se.size(); a++) {
                    if (N < 4) {
                        if (abs(se[i].y - se[i].x) == abs(se[j].y - se[j].x) && abs(se[j].y - se[j].x) == abs(se[s].y - se[s].x)) {
                            points.push_back(se[i]);
                            points.push_back(se[j]);
                            points.push_back(se[s]);
                            return points;
                       }
                    }
                    for (int b = 0; b < se.size(); b ++) {
                        if (N < 5) {
                            if (sqrt(pow(abs(se[i].y - se[i].x),2) + pow(abs(se[j].y - se[j].x),2)) == sqrt(pow(abs(se[j].y - se[j].x),2) + pow(abs(se[s].y - se[s].x),2))
                             && sqrt(pow(abs(se[s].y - se[s].x),2) + pow(abs(se[b].y - se[b].x),2)) == sqrt(pow(abs(se[b].y - se[b].x),2) + pow(abs(se[i].y - se[i].x),2))) {
                                points.push_back(se[i]);
                                points.push_back(se[j]);
                                points.push_back(se[s]);
                                points.push_back(se[b]);
                                return points;
                            }
                        }
                        for (int c = 0; c < se.size(); c++) {
                            if (N < 6) {
                                if (abs(se[i].y - se[i].x) == abs(se[j].y - se[j].x) && abs(se[j].y - se[j].x) == abs(se[s].y - se[s].x)) {
                                    points.push_back(se[i]);
                                    points.push_back(se[j]);
                                    points.push_back(se[s]);
                                    return points;
                            }
                        }
                                        if (N > 6) {
                                            for (int q = 0; q < se.size(); q++) {
                                                if (N > 7) {
                                                    for (int w = 0; w < se.size(); w++) {
                                                        if (N > 8) {
                                                            for (int e = 0; e < se.size(); e++) {
                                                                if (N > 9) {
                                                                    for (int h = 0; h < se.size(); h++) {

                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                return points;
            }*/

int main() try {
	Simple_window win {Point{100,100},800,600,"Superellipse"};
	Graph_lib::Open_polyline op;
	vector<Point> points = superellipse(250,250,0.5,0.5);
    for (Point p : points) op.add(p);
	win.attach(op);
    /*Rectangle in Superellipse
    Graph_lib::Polygon rec;
    vector<Point> rectangle = polygon_in_superellipse(points, 3);
    for (Point p : rectangle) cout << p.x << " : " << p.y << endl;
    win.attach(rec);*/
	win.wait_for_button();
}

catch(runtime_error& e) {
    cout << e.what() << endl;
}