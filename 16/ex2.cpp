/*Chapter 16 Exercise 2
Make a window (based on My_window) with a 4-by-4 checkerboard of square buttons. When pressed, a button performs a simple action, 
such as printing its coordinates in an output box, or turns a slightly different color (until another button is pressed).
*/
#include "16.h"

namespace Graph_lib {

	int xb = 300;
	int yb = 200;

	Button_window::Button_window(Point xy, int x, int w, const string& label, int xn, int yn)
	:My_window{xy,x,w,label}, out_xy{Point{100,0},70,20,"Button's (x,y): "}, v1{Point{xb,yb},50,50,Menu::vertical,"1"}, 
	v2{Point{xb+50,yb},50,50,Menu::vertical,"2"}, v3{Point{xb+100,yb},50,50,Menu::vertical,"3"}, v4{Point{xb+150,yb},50,50,Menu::vertical,"4"}
	{	
		//First vertical
		v1.attach(new Button{Point {xb,yb},50,50,"1-1",[](Address, Address pw){reference_to<Button_window>(pw).b11();}});
		v1.attach(new Button{Point {xb,yb+50},50,50,"1-2",[](Address, Address pw){reference_to<Button_window>(pw).b12();}});
		v1.attach(new Button{Point {xb,yb+100},50,50,"1-3",[](Address, Address pw){reference_to<Button_window>(pw).b13();}});
		v1.attach(new Button{Point {xb,yb+150},50,50,"1-4",[](Address, Address pw){reference_to<Button_window>(pw).b14();}});
		//Second vertical
		v2.attach(new Button{Point {xb+50,yb},50,50,"2-1",[](Address, Address pw){reference_to<Button_window>(pw).b21();}});
		v2.attach(new Button{Point {xb+50,yb+50},50,50,"2-2",[](Address, Address pw){reference_to<Button_window>(pw).b22();}});
		v2.attach(new Button{Point {xb+50,yb+100},50,50,"2-3",[](Address, Address pw){reference_to<Button_window>(pw).b23();}});
		v2.attach(new Button{Point {xb+50,yb+150},50,50,"2-4",[](Address, Address pw){reference_to<Button_window>(pw).b24();}});
		//Third vertical
		v3.attach(new Button{Point {xb+100,yb},50,50,"3-1",[](Address, Address pw){reference_to<Button_window>(pw).b31();}});
		v3.attach(new Button{Point {xb+100,yb+50},50,50,"3-2",[](Address, Address pw){reference_to<Button_window>(pw).b32();}});
		v3.attach(new Button{Point {xb+100,yb+100},50,50,"3-3",[](Address, Address pw){reference_to<Button_window>(pw).b33();}});
		v3.attach(new Button{Point {xb+100,yb+150},50,50,"3-4",[](Address, Address pw){reference_to<Button_window>(pw).b34();}});
		//Four vertical
		v4.attach(new Button{Point {xb+150,yb},50,50,"4-1",[](Address, Address pw){reference_to<Button_window>(pw).b41();}});
		v4.attach(new Button{Point {xb+150,yb+50},50,50,"4-2",[](Address, Address pw){reference_to<Button_window>(pw).b42();}});
		v4.attach(new Button{Point {xb+150,yb+100},50,50,"4-3",[](Address, Address pw){reference_to<Button_window>(pw).b43();}});
		v4.attach(new Button{Point {xb+150,yb+150},50,50,"4-4",[](Address, Address pw){reference_to<Button_window>(pw).b44();}});
		attach(out_xy);
		attach(v1);
		attach(v2);
		attach(v3);
		attach(v4);
	}

	//Callback. First menu
	void Button_window::b11() {get_xy(v1.selection[0].loc);}
	void Button_window::b12() {get_xy(v1.selection[1].loc);}
	void Button_window::b13() {get_xy(v1.selection[2].loc);}
	void Button_window::b14() {get_xy(v1.selection[3].loc);}

	//Callback. Second menu
	void Button_window::b21() {get_xy(v2.selection[0].loc);}
	void Button_window::b22() {get_xy(v2.selection[1].loc);}
	void Button_window::b23() {get_xy(v2.selection[2].loc);}
	void Button_window::b24() {get_xy(v2.selection[3].loc);}

	//Callback. Third menu
	void Button_window::b31() {get_xy(v3.selection[0].loc);}
	void Button_window::b32() {get_xy(v3.selection[1].loc);}
	void Button_window::b33() {get_xy(v3.selection[2].loc);}
	void Button_window::b34() {get_xy(v3.selection[3].loc);}

	//Callback. Fourth menu
	void Button_window::b41() {get_xy(v4.selection[0].loc);}
	void Button_window::b42() {get_xy(v4.selection[1].loc);}
	void Button_window::b43() {get_xy(v4.selection[2].loc);}
	void Button_window::b44() {get_xy(v4.selection[3].loc);}

	void Button_window::get_xy(Point p) {
		ostringstream os;
		os << '(' << p.x << ',' << p.y << ')';
		out_xy.put(os.str());
		redraw();
	}
}

using namespace Graph_lib;

int main() {
	Button_window b_win {Point {100,100}, 800, 600, "Exercise 2", 4, 4};
	
	return gui_main();
}
