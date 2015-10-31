/*
Chapter 13 Exercise 13
Draw the color matrix from §13.10, but without lines around each color.
*/

#include "Classes.h"
#include <iostream>

int main() {
	Simple_window win6 {x,800,600,"16x16 color matrix"};
	Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;

	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Graph_lib::Rectangle{Point{i*20,j*20},20,20});
			vr[vr.size()-1].set_fill_color(i*16+j);
			vr[vr.size()-1].set_color(Graph_lib::Color::invisible);
			win6.attach(vr[vr.size()-1]);
		}
	}

	win6.wait_for_button(); 
}