/*
Chapter 13 Exercise 9
Tile a part of a window with Regular_hexagons (use at least eight hexagons).
*/

#include "13.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

/*int main() {
	Simple_window win1{x,800,600,"Arrow"};
	Graph_lib::Vector_ref<Regular_hexagon> hexagon_tile(Point c, int d, int n_y, int n_x) {
	Graph_lib::Vector_ref<Regular_hexagon> r;
	for (int i = 0; i < n_y; i++) {
		if (i == 0 ) r.push_back(new Regular_hexagon{c,d});
		else if (!(i%2)) r.push_back(new Regular_hexagon{Point{r[r.size()-n_x].point(1).x+d,r[r.size()-n_x].point(1).y},d});
		else if (i%2) r.push_back(new Regular_hexagon{Point{r[r.size()-n_x].point(1).x-d*2,r[r.size()-n_x].point(1).y},d});
		for (int a = 0; a < n_x-1; a++) {
			r.push_back(new Regular_hexagon{Point{r[r.size()-1].point(5).x+d,r[r.size()-1].point(5).y},d});
		}
	}
	return r;
}	
	Graph_lib::Vector_ref<Regular_hexagon> vr = hexagon_tile(Point{200,200},40,10,5);
	srand(time(0));
	for (int i = 0; i < vr.size(); i++)	{
		vr[i].set_fill_color(1 + rand()%255);
		win1.attach(vr[i]);
	}
	win1.wait_for_button();
}*/
