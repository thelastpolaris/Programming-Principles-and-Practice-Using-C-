#include "16.h"
using namespace Graph_lib;

const int x_maxl = 800;
const int y_maxl = 600;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point p, int w, int h, const string& title);
	Open_polyline lines;
private:
	Button next_button;
	Button quit_button;
	Menu color_menu;
	Menu style_menu;
	Button menu_button_color;
	Button menu_button_style;
	In_box next_y;
	In_box next_x;
	Out_box xy_out;
	void next();
	void quit();
	//Color menu
	void hide_menu_color() { color_menu.hide(); menu_button_color.show(); menu_button_style.show();};
	void menu_color_pressed() { color_menu.show(); menu_button_color.hide(); menu_button_style.hide();};
	void red_pressed() {change_color(Color::red);hide_menu_color();};
	void blue_pressed() {change_color(Color::blue);hide_menu_color();};
	void black_pressed() {change_color(Color::black);hide_menu_color();};
	void change_color(Color c) {lines.set_color(c);redraw();};
	static void cb_menu_color(Address, Address pw) {reference_to<Lines_window>(pw).menu_color_pressed();};
	//Style menu
	void hide_menu_style() { style_menu.hide(); menu_button_style.show(); menu_button_color.show();};
	void menu_style_pressed() { style_menu.show(); menu_button_style.hide(); menu_button_color.hide();};
	void solid_pressed() {change_style(Line_style::solid);hide_menu_style();};
	void dash_pressed() {change_style(Line_style::dash);hide_menu_style();};
	void dot_pressed() {change_style(Line_style::dot);hide_menu_style();};
	void dashdot_pressed() {change_style(Line_style::dashdot);hide_menu_style();};
	void dashdotdot_pressed() {change_style(Line_style::dashdotdot);hide_menu_style();};
	void change_style(Line_style l) {lines.set_style(l);redraw();};
	static void cb_menu_style(Address, Address pw) {reference_to<Lines_window>(pw).menu_style_pressed();};
};

Lines_window::Lines_window(Point p, int w, int h, const string& title) :Graph_lib::Window{p,w,h,title},
next_button{Point{w-150,0},70,20,"Next point",[](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
quit_button{Point{w-70,0},70,20,"Quit",[](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
next_x{Point{w-310,0},50,20,"next x:"}, next_y{Point{w-210,0},50,20,"next y:"},xy_out{Point{100,0},70,20,"current (x,y):"},
color_menu{Point{w-70,40},70,20,Menu::vertical,"Color"}, menu_button_color{Point{w-70,40},70,20,"Color", cb_menu_color},
style_menu{Point{w-70,60},70,20,Menu::vertical,"Style"}, menu_button_style{Point{w-70,60},70,20,"Style", cb_menu_style}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	color_menu.attach(new Button{Point{0,0},0,0,"Red",[](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"Blue",[](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"Black",[](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}});
	attach(color_menu);
	color_menu.hide();
	attach(menu_button_color);
	attach(menu_button_style);
	style_menu.attach(new Button{Point{0,0},0,0,"Dot",[](Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"Dash",[](Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"Solid",[](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"Dashdot",[](Address, Address pw) {reference_to<Lines_window>(pw).dashdot_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"Dashdotdot",[](Address, Address pw) {reference_to<Lines_window>(pw).dashdotdot_pressed();}});
	attach(style_menu);
	style_menu.hide();
	attach(lines);
}

void Lines_window::quit() {
	hide();
}

void Lines_window::next() {
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x,y});
	ostringstream os;
	os << '(' << x << ',' << y << ')';
	xy_out.put(os.str());
	redraw();
}

int main()
	try{
		Lines_window win {Point{100,100},x_maxl,y_maxl,"lines"};
		gui_main();
	}
	catch(exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}
	catch(...) {
		cerr << "Uknown exception\n";
		return 2; 
	}

