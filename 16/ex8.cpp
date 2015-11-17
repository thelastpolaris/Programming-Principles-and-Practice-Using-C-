/* Chapter 16 Exercise 8
Provide a currency converter. Read the conversion rates from a file on startup. Enter an amount in an input window and 
provide a way of selecting currencies to convert to and from (e.g., a pair of menus).
*/

#include "16.h"
#include "../13/13.h"
#include <chrono>
#include <ctime>

namespace Graph_lib {
	Currency_converter::Currency_converter(Point xy, int x, int y, string label, string file)
	:Window{xy, x, y, label}, from{Point {40,0},80,20,Menu::vertical,"From"}, to{Point{200,0},80,20,Menu::vertical,"To"},
	in_cur{Point{40,0},80,20,"From:"}, out_cur{Point{200,0},80,20,""}, convert{Point{120,0},80,20,"Convert",[](Address, Address pw) {reference_to<Currency_converter>(pw).convert_cur();}},
	current_from{Point{0,0},0}, current_to{Point{0,0},0}
	{
		ifstream ifs {file};
		int count = 0;
		string line;
		while(std::getline(ifs, line)) {
			if (line.empty()) {
				continue;
			}
			else {
				istringstream is {line};
				Cur_pair p;
				is >> p.from >> p.value;
				if(!is) error("Wrong currency format");
				pairs.push_back(p);
			}
		}
		//KZT
		from.attach(new Button{Point{from.loc.x,from.loc.y+from.height*1},from.width,from.height,"KZT",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_from(0);}});
		to.attach(new Button{Point{to.loc.x,to.loc.y+to.height*1},to.width,to.height,"KZT",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_to(0);}});
		//USD
		from.attach(new Button{Point{from.loc.x,from.loc.y+from.height*1},from.width,from.height,"USD",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_from(1);}});
		to.attach(new Button{Point{to.loc.x,to.loc.y+to.height*1},to.width,to.height,"USD",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_to(1);}});
		//EUR
		from.attach(new Button{Point{from.loc.x,from.loc.y+from.height*2},from.width,from.height,"EUR",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_from(2);}});
		to.attach(new Button{Point{to.loc.x,to.loc.y+to.height*2},to.width,to.height,"EUR",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_to(2);}});
		//RUR
		from.attach(new Button{Point{from.loc.x,from.loc.y+from.height*3},from.width,from.height,"RUR",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_from(3);}});
		to.attach(new Button{Point{to.loc.x,to.loc.y+to.height*3},to.width,to.height,"RUR",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_to(3);}});
		//KGS
		from.attach(new Button{Point{from.loc.x,from.loc.y+from.height*4},from.width,from.height,"KGS",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_from(4);}});
		to.attach(new Button{Point{to.loc.x,to.loc.y+to.height*4},to.width,to.height,"KGS",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_to(4);}});
		//UZS
		from.attach(new Button{Point{from.loc.x,from.loc.y+from.height*5},from.width,from.height,"UZS",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_from(5);}});
		to.attach(new Button{Point{to.loc.x,to.loc.y+to.height*5},to.width,to.height,"UZS",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_to(5);}});
		//BYR
		from.attach(new Button{Point{from.loc.x,from.loc.y+from.height*6},from.width,from.height,"BYR",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_from(6);}});
		to.attach(new Button{Point{to.loc.x,to.loc.y+to.height*6},to.width,to.height,"BYR",[](Address, Address pw){reference_to<Currency_converter>(pw).cb_to(6);}});

		attach(from);
		attach(to);
		in_cur.loc = Point{in_cur.loc.x,7*20};
		attach(in_cur);
		out_cur.loc = Point{out_cur.loc.x,7*20};
		attach(out_cur);
		convert.loc = Point{convert.loc.x,7*20};
		attach(convert);
		current_from.set_fill_color(Color::green);
		attach(current_from);
		current_to.set_fill_color(Color::red);
		attach(current_to);
	}

	void Currency_converter::cb_from(int n) {
		int r = from.selection[n].height/2;
		cur_from = from.selection[n].label;
		current_from.set_point(0,Point{from.selection[n].loc.x-r*2,from.selection[n].loc.y});
		current_from.set_radius(r);
		redraw();
	}

	void Currency_converter::cb_to(int n) {
		cur_to = to.selection[n].label;
		int r = to.selection[n].height/2;
		current_to.set_point(0,Point{to.selection[n].loc.x-r*2,to.selection[n].loc.y});
		current_to.set_radius(r);
		redraw();
	}

	void Currency_converter::convert_cur() {

		if (cur_from.empty() || cur_to.empty()) {
			out_cur.put("Choose the currencies");
		}
		else if (in_cur.is_empty()) out_cur.put("Enter the value");
		else {
			if(cur_from == "KZT" || cur_to == "KZT") {
				for (int i = 0; i < pairs.size(); ++i) {
					if (pairs[i].from == cur_to) {
						out_cur.put(std::to_string(in_cur.get_double()/pairs[i].value));
						break;
					}
					if (pairs[i].from == cur_from) {
						out_cur.put(std::to_string(pairs[i].value*in_cur.get_double()));
						break;
					}
				}	
			}
			else {
				double c = 0;
				double t = 0;
				for (int i = 0; i < pairs.size(); ++i) {
					if (pairs[i].from == cur_from) c = pairs[i].value;
					if (pairs[i].from == cur_to) t = pairs[i].value;
				}
				out_cur.put(std::to_string(in_cur.get_double()/(t/c)));
			}
		}
	}
}

using namespace Graph_lib;

int main() {
	Currency_converter cc {Point{100,100},290,170,"Currency_converter","currencies.txt"};
	gui_main();
} 
