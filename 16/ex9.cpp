/* Chapter 16 Exercise 9
Modify the calculator from Chapter 7 to get its input from an input box and return its results in an output box.
*/

#include "16.h"
#include "../13/13.h"
#include <chrono>
#include <ctime>
#include "calculator/calculator.h"

//------------------------------------------------------------------------------

namespace Graph_lib {
	Calculator::Calculator(Point xy, int x, int y, string label)
	:Window{xy,x,y,label},
	//Numbers
	zero{Point{40,200},40,20,"0",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("0");}},

	one{Point{40,170},40,20,"1",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("1");}}, 
	two{Point{90,170},40,20,"2",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("2");}},
	three{Point{140,170},40,20,"3",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("3");}},

	four{Point{40,140},40,20,"4",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("4");}},
	five{Point{90,140},40,20,"5",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("5");}},
	six{Point{140,140},40,20,"6",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("6");}},

	seven{Point{40,110},40,20,"7",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("7");}},
	eight{Point{90,110},40,20,"8",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("8");}},
	nine{Point{140,110},40,20,"9",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("9");}},
	//Operators and signs
	comma{Point{90,200},40,20,",",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch(",");}},
	period{Point{140,200},40,20,".",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch(".");}},
	l_parenthesis{Point{240,170},40,20,"(",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("(");}}, 
	r_parenthesis{Point{240,140},40,20,")",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch(")");}},
	equal{Point{190,170},40,50,"=",[](Address, Address pw) {reference_to<Calculator>(pw).compute();}},
	plus{Point{190,110},40,50,"+",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("+");}},
	minus{Point{190,80},40,20,"-",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("-");}},
	division{Point{140,80},40,20,"/",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("/");}},
	multi{Point{90,80},40,20,"*",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("*");}},
	mod{Point{40,80},40,20,"mod(%)",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("%");}},
	//Functions
	power{Point{240,200},40,20,"x^y",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("pow");}},
	fac{Point{240,110},40,20,"!",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("!");}}, 
	sqrt{Point{240,80},40,20,"sqrt",[](Address, Address pw) {reference_to<Calculator>(pw).add_ch("sqrt");}},
	//Input/output
	input{Point{40,20},240,20,"Input"}, 
	output{Point{40,45},240,20,"Result"}
	{
		//Numbers
		attach(zero);
		attach(one);
		attach(two);
		attach(three);
		attach(four);
		attach(five);
		attach(six);
		attach(seven);
		attach(eight);
		attach(nine);
		//Operators and signs
		attach(comma);	
		attach(period);
		attach(l_parenthesis);
		attach(r_parenthesis);
		attach(equal);
		attach(plus);
		attach(minus);
		attach(division);
		attach(multi);
		attach(mod);
		//Functions
		attach(power);
		attach(fac);
		attach(sqrt);
		//Input/Output
		attach(output);
		attach(input);
	}

	void Calculator::add_ch(string ch) {
		if (is_result) {
			output.put("");
			is_result = false;
			is.clear();
		}
		output.put(output.get_string() + ch);		
	}

	void Calculator::compute() {
		is.clear();
		if (!input.get_string().empty()) is.str(input.get_string()); // istringstream is is defined in calculator.h
		else is.str(output.get_string()+';'); // istringstream is is defined in calculator.h
		output.put(calculate());
		is_result = true;
	}
}

using namespace Graph_lib;

int main() try {
	Calculator calc {Point{100,100},300,240,"Calculator"};
	gui_main();
} 
catch(runtime_error& e) {
	std::cerr << e.what() << std::endl;
}
catch (...) { // Throws an exception
	std::cerr << "error\n";
}
