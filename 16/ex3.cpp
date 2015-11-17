#include "16.h"

namespace Graph_lib {

Button_image::Button_image(Point xy, Point bxy, int w, int h, string img_name)
:My_window{xy, w, h, img_name}, i{Point {bxy.x+5,bxy.y+5},img_name}, mb{bxy, 0, 0,Menu::vertical, ""}
{
	vb.push_back(new Button {bxy,i.width() + 10,i.height() + 10,"",[](Address, Address pw){reference_to<Button_image>(pw).rand_move();}});
	attach(i);
	attach(vb[0]);
	attach(mb);	
}

void Button_image::rand_move() {
	Point x {rand_int(0,x_max()-i.width()),rand_int(0,y_max()-i.height())};
	vb.push_back(new Button {Point {x.x-5,x.y-5}, vb[0].width, vb[0].height, vb[0].label, vb[0].do_it});
	for (int i = 0; i < vb.size(); ++i) {
		if (i == vb.size()-1) attach(vb[i]);
		else detach(vb[i]);
	}
	i.set_point(0,x);
	Fl::redraw();
}

inline int rand_int(int min, int max) {
	static default_random_engine ran;
	return uniform_int_distribution<>{min,max}(ran);
}

}

using namespace Graph_lib;

int main() 
	try {
		Button_image bi {Point {200,200}, Point{80,80}, 800, 600, "1.jpg"};
		return gui_main();
	}
	catch(exception& e) {
		cerr << "error: " << e.what() << endl;	
	}
	catch(...) {
		cerr << "undefined error\n";
	}