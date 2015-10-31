/* Chapter 14 Exercise 10
Define a class Pseudo_window that looks as much like a Window as you can make it without heroic efforts. 
It should have rounded corners, a label, and control icons. Maybe you could add some fake “contents,” such as an image. 
It need not actually do anything. It is acceptable (and indeed recommended) to have it appear within a Simple_window.
*/
#include "14.h"

namespace Graph_lib {
Pseudo_window::Pseudo_window(Point pp, int ww, int hh, string str, string img_file) 
:p{pp}, w{ww}, h{hh}, lab{Point{p.x+w*0.04,p.y+w*0.04},str}, 
window{p, w, h}, 
minimize{Point{p.x+w*0.74,p.y+h*0.02}, (w+h)/2*0.04, (w+h)/2*0.04}, 
maximize{Point{p.x+w*0.82,p.y+h*0.02}, (w+h)/2*0.04, (w+h)/2*0.04}, 
close{Point{p.x+w*0.90,p.y+h*0.02}, (w+h)/2*0.04, (w+h)/2*0.04},
img{window.point(7), img_file} // window.point(7) is the point of window where the first arc (top leftmost) begins
{	
	int iw = 0;
	int ih = 0;
	if (img.width() > w) iw = w;
	else iw = 0;
	if (img.height() > h) ih = window.point(you).8-window.point(7).y;
	else ih = 0;
	img.set_mask(Point{0,0}, iw, ih);
	cout << iw << " : " << ih << endl;	
	lab.set_font(Font::helvetica_bold);
	lab.set_font_size(5);
}

void Pseudo_window::draw_lines() const {
	window.draw();
	lab.draw();
	minimize.draw();
	maximize.draw();
	close.draw();
	//int y = p.y+minimize.height()+minimize.height()*0.5;
	int y = window.point(7).y;
	Line l {Point{p.x,y}, Point{p.x+w,y}};
	l.draw();
	img.draw();
}

}

int main() {
	Simple_window win {x,800,600,"Pseudo Window"};
	Graph_lib::Pseudo_window pw {Point {100,100}, 600, 400, "Pseudo one","../13/rita2.jpg"};
	win.attach(pw);
	win.wait_for_button();

	Simple_window win1 {x,800,600,"Pseudo Window"};
	Graph_lib::Pseudo_window pw1 {Point {100,100}, 600, 400, "The second one","../13/1.gif"};
	win1.attach(pw1);
	win1.wait_for_button();
}