/* Chapter 16 Exercise 6
Make an “analog clock,” that is, a clock with hands that move. You get the time of day from the operating system through a library call. 
A major part of this exercise is to find the functions that give you the time of day and a way of waiting for a short period of time 
(e.g., a second for a clock tick) and to learn to use them based on the documentation you found. Hint: clock(), sleep().
*/

#include "16.h"
#include "../13/13.h"
#include <chrono>
#include <ctime>

namespace Graph_lib {
	using namespace std::chrono;

	Triangle::Triangle(Point xy, int x, int y)
	:w{x}, h{y}
	{
		add(xy);
		add(Point{xy.x-w,xy.y+h});
		add(Point{xy.x+w,xy.y+h});
	}

	void Triangle::rotate(Point center, int degree) {
		set_point(0,rotate_point(center,point(0),degree));
		set_point(1,rotate_point(center,point(1),degree));
		set_point(2,rotate_point(center,point(2),degree));
	}

	Clock::Clock(Point xy, int x, int y, string label) :Window{xy, x, y, label}, cl{Point {x/2,y/2},x*0.2}, 
	center{Point {x/2,y/2}, x*0.015}, big{Point{x/2,y/2-x*0.2}, x*0.015, x*0.2},
	small{Point{x/2,(y/2)-(x*0.2)/2}, x*0.015, x*0.1}, seconds{Point{x/2,y/2}, Point{x/2,y/2-x*0.2}}
	{
		Point pcenter {x/2,y/2};
		//Get current time
		tm* local_tm = get_time();
		cl.set_style(Line_style {Line_style::Line_style_type::solid,6});
		cl.set_fill_color(Color::white);
		attach(cl);
		center.set_fill_color(Color::black);
		attach(center);
		big.set_fill_color(Color::black);
		big.rotate(pcenter,6*(local_tm->tm_min));
		current_min = local_tm->tm_min;
		attach(big);
		small.set_fill_color(Color::black);
		small.rotate(pcenter,30*local_tm->tm_hour);
		small.rotate(pcenter,5*(local_tm->tm_min/12));
		attach(small);
		seconds.set_point(1,rotate_point(seconds.point(0),Point{x_max()/2,y_max()/2-x_max()*0.2},6*(local_tm->tm_sec)));
		attach(seconds);
		for (int i = 0; i <= 60; ++i) {
			if (i == 0 || !(i%5)) {
				big_notches.add(Point {rotate_point(pcenter,Point{x/2,y/2-x*0.2},6*(i))}, rotate_point(pcenter,Point{x/2,y/2-x*0.17},6*(i)));
			}
			else {
				small_notches.add(Point {rotate_point(pcenter,Point{x/2,y/2-x*0.2},6*(i))}, rotate_point(pcenter,Point{x/2,y/2-x*0.18},6*(i)));	
			}
		}
		attach(big_notches);
		attach(small_notches);
		for (int i = 1; i <= 12; ++i) {
			Point p_r = Point {rotate_point(pcenter,Point{x/2,y/2-x*0.16},30*(i))};
			digits.push_back(new Text {p_r, to_string(i)});
			attach(digits[digits.size()-1]);
		}
	}

	tm* Clock::get_time() {
		system_clock::time_point today = system_clock::now();
		std::time_t tt = system_clock::to_time_t(today);
		tm* local_tm = localtime(&tt);
		return local_tm;
	}

	void Clock::cb_runClock(void* p) {
		Clock* c = (Clock*)p;
		c -> runClock();
		Fl::repeat_timeout(1.0, Clock::cb_runClock, p);
	}

	void Clock::runClock() {
		tm* local_tm = get_time();
		// Calculate the current time
		int hour = (local_tm->tm_hour >= 12) ? (local_tm->tm_hour - 12) : local_tm->tm_hour;
		//Move seconds line
		seconds.set_point(1,rotate_point(seconds.point(0),Point{x_max()/2,y_max()/2-x_max()*0.2},6*(local_tm->tm_sec)));
		//Move minutes line
		if (local_tm->tm_min != current_min) {
			big.rotate(Point{x_max()/2,y_max()/2},6);
		}
		current_min = local_tm->tm_min;
		if ((current_min == 0 || !(current_min%12)) && local_tm->tm_sec == 0) {
			small.rotate(Point{x_max()/2,y_max()/2},12);
		}
		redraw();
	}
}

using namespace Graph_lib;

int main() {
	Clock* s = new Clock {Point{100,100},800,600,"Shape window"};
	Fl::add_timeout(1.0, Clock::cb_runClock, s);
	gui_main();
}