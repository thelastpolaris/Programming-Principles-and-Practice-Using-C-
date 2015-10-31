/*
Chapter 13 Exercise 15
“Tile” a window with small right triangles.
*/

#include "13.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Graph_lib::Vector_ref<Right_triangle> triangle_tile(Point ra, int w, int h, int n_y, int n_x) {
	Graph_lib::Vector_ref<Right_triangle> r;
	r.push_back(new Right_triangle{ra,w,h});
	for (int i = 0; i < n_y; ++i) {
		int bias = 0;
		if ((i%2)) bias = w;
		else bias = -w;
		if (i!=0) r.push_back(new Right_triangle {Point {r[r.size()-n_x*4].right_angle().x+bias,r[r.size()-n_x*4].right_angle().y+h},w,h});
		for (int a = 0; a < n_x; ++a) {
			if (a!=0) r.push_back(new Right_triangle {Point {r[r.size()-1].right_angle().x+w*2,r[r.size()-1].right_angle().y},w,h});
			r.push_back(new Right_triangle {r[r.size()-1].right_angle(),w,-h});
			r.push_back(new Right_triangle {r[r.size()-1].right_angle(),-w,-h});
			r.push_back(new Right_triangle {r[r.size()-1].right_angle(),-w,h});
		}
	}
	return r;
}

/*int main() {
	Simple_window win1{x,800,600,"Arrow"};
	Graph_lib::Vector_ref<Right_triangle> vr = triangle_tile(Point{-50,-50},50,50,50,50);
	srand(time(0));
	for (int i = 0; i < vr.size(); i++)	{
		vr[i].set_fill_color(1 + rand()%255);
		win1.attach(vr[i]);
		
	}
	cout << vr.size() << endl;
	win1.wait_for_button();
}*/
