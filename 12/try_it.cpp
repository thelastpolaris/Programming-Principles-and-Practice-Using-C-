#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities

int main()
{
          using namespace Graph_lib;    // our graphics facilities are in Graph_lib

          Point tl {100,100};              // top left corner of our window

          Simple_window win {tl,600,400,"Canvas"};
               // screen coordinate tl for top left corner
               // window size(600*400)
               // title: Canvas
          win.wait_for_button();   // display!
          Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
          win.attach(xa);
          win.set_label("Canvas #2");
          win.wait_for_button();   // display!
          Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
          ya.set_color(Color::cyan);
          ya.label.set_color(Color::dark_red);
          win.attach(ya);
          win.set_label("Canvas #3");
          win.wait_for_button();
          Function sine {sin,0,100,Point{20,150},1000,50,50};
          sine.set_color(Color::blue);
          win.attach(sine);
          win.set_label("Canvas #4");
          win.wait_for_button();
          Polygon poly;
          poly.add(Point{300,200});
          poly.add(Point{350,100});
          poly.add(Point{400,200});
          poly.set_color(Color::red);
          poly.set_style(Line_style::dash);
          win.attach(poly);
          win.set_label("Canvas #5");
          win.wait_for_button();
          Rectangle r{Point{200,200}, 100, 50};
          win.attach(r);
          Closed_polyline poly_rect;
          poly_rect.add(Point{100,50});
          poly_rect.add(Point{200,50});
          poly_rect.add(Point{200,100});
          poly_rect.add(Point{100,100});
          poly_rect.add(Point{50,75});
          win.attach(poly_rect);
          win.set_label("Canvas #6");
          win.wait_for_button();
          r.set_fill_color(Color::yellow);
          poly.set_style(Line_style(Line_style::dash,4));
          poly_rect.set_style(Line_style(Line_style::dash,2));
          poly_rect.set_fill_color(Color::green);
          win.set_label("Canvas #7");
          win.wait_for_button();
          Text t {Point{150,150}, "Hello, graphical world!"};
          win.attach(t);
          win.set_label("Canvas #8");
          win.wait_for_button();
          t.set_font_size(20);
          t.set_font(Graph_lib::Font::times_bold);
          win.set_label("Canvas #9");
          win.wait_for_button();
          Image ii {Point{100,200}, "2.jpeg"};
          win.attach(ii);
          win.set_label("Canvas #10");
          win.wait_for_button();
          Circle c {Point{100,200},50};
          Ellipse e {Point{100,200},75,25};
          e.set_color(Color::dark_red);
          Mark m {Point{100,200},'x'};
          ostringstream oss;
          oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" <<win.y_max();
          Text sizes {Point{100,20}, oss.str()};
          Image cal {Point{225,225}, "y.jpg"};
          cal.set_mask(Point{1,1},400,350);
          win.attach(c);
          win.attach(e);
          win.attach(m);
          win.attach(sizes);
          win.attach(cal);
          win.set_label("Canvas #11");
          win.wait_for_button();
     }