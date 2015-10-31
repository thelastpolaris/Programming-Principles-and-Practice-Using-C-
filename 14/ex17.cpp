/* Chapter 14 Exercise 17
The exceptions defined in the C++ standard library, such as exception, runtime_error, and out_of_range (§5.6.3), 
are organized into a class hierarchy (with a useful virtual function what() returning a string supposedly explaining what went wrong). 
Search your information sources for the C++ standard exception class hierarchy and draw a class hierarchy diagram of it.
*/
#include "14.h"

int main() {
	Simple_window win {x,1200,600,"Exception class hierarchy"};
	Box_arr exception{Point {400,50}, "exception"};
	win.attach(exception);
	Box_arr bad_al {Point {50,200}, "bad_alloc", Point{365,50}};
	win.attach(bad_al);

	Box_arr bad_a_n_l {Point {50,300}, "bad_array_new_length", Point {75,225}};
	win.attach(bad_a_n_l);

	Box_arr bad_c {Point {185,200}, "bad_cast", Point{368,63}};
	win.attach(bad_c);
	Box_arr bad_e {Point {300,200}, "bad_exception", Point {380,70}};
	win.attach(bad_e);
	Box_arr bad_f_c {Point {450,200}, "bad_function_call(C++11)", Point {430,75}};
	win.attach(bad_f_c);
	Box_arr bad_ti {Point {700,200}, "bad_typeid", Point {480,75}};
	win.attach(bad_ti);
	Box_arr bad_w_p {Point {840,200}, "bad_weak_ptr(C++11)", Point {480,55}};
	win.attach(bad_w_p);
	// logic_error
	Box_arr logic_err {Point {270,300}, "logic_error", Point {395,70}};
	win.attach(logic_err);
	Box_arr domain_err {Point {50,400}, "domain_error", Point {235,310}};
	win.attach(domain_err);
	Box_arr inv_arg {Point {200,400}, "invalid_argument", Point {270,320}};
	win.attach(inv_arg);
	Box_arr len_err {Point {370,400}, "length_error", Point {320,320}};
	win.attach(len_err);
	Box_arr out_of_r {Point {100,450}, "out_of_range", Point {250,320}};
	win.attach(out_of_r);
	Box_arr future_err {Point {300,450}, "future_error", Point {300,320}};
	win.attach(future_err);
	// runtime_error
	Box_arr runtime_err {Point {800,300}, "runtime_error", Point {460,75}};
	win.attach(runtime_err);
	Box_arr range_err {Point {550,400}, "range_error", Point {780,320}};
	win.attach(range_err);
	Box_arr overflow_err {Point {700,400}, "overflow_error", Point {810,320}};
	win.attach(overflow_err);
	Box_arr underflow_err {Point {850,400}, "underflow_error", Point {850,320}};
	win.attach(underflow_err);
	Box_arr sys_err {Point {1010,400}, "system_error", Point {905,315}};
	win.attach(sys_err);

	Box_arr ios_fail {Point {1020,500}, "ios_base::failure", Point {1040,420}};
	win.attach(ios_fail);

	win.wait_for_button();
}