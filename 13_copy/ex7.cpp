/*
Chapter 13 Exercise 7
Make an RGB color chart (e.g., search the web for “RGB color chart”).
*/

#include "Classes.h"
#include <iostream>

int main() {
	Simple_window win1{x,800,600,"RGB Color Chart"};
	Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;
	int x = 0;
	int y = 0;
	int carriage = 0;
	for (int b = 0; b <= 255; b+=51) {
		for (int g = 0; g <=255; g+=51) {
			for (int r = 0; r <=255; r+=51) {
				vr.push_back(new Graph_lib::Rectangle{Point{x,y},20,20});
				vr[vr.size()-1].set_fill_color(Graph_lib::Color{r,g,b});
				cout << x << " : " << y << " : " << carriage << endl;
				if (carriage == 5) {
					if (y == 100) {
						x+=20;
						y = 0;
					}
					else {
						x-=100;
						y+=20;
					}
					carriage = 0;
				}
				else {
					x+=20;
					carriage++;
				}
				
				/*if (y == 100) {
					x+=20;
					y = 0;
				}
				else y+=20;*/
			}
		}
	}
	for (int i = 0; i < vr.size(); i++) win1.attach(vr[i]);
	win1.wait_for_button();
}
