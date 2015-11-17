// run-time checked narrowing cast (type conversion). See ???.
/*template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r)!=a) error(string("info loss"));
	return r;
}*/
#include "../../fltk/Fl_GUI.h"

// Token holds operators, operands and names of variables

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { } // Operator
	Token(char ch, double val) :kind(ch), value(val) { } // Operand
	Token(char ch, string n) :kind(ch), name(n) { } // Name of variable
}; 

// Stream of tokens

class Token_stream {
	bool full;
	Token buffer; // Holds a symbol that wasn't used by specific function
	istringstream& is;
public:
	Token_stream(istringstream& iss) :full(0), buffer(0), is{iss} { }

	Token get();
	void unget(Token t) { buffer=t; full=true; } // Returns symbol to buffer. If 'full' = true, get() will use symbol from buffer

	void ignore(char); // Ignores all characters before specific symbol
};

const char let = 'L'; // Let is used to define variables
const char print = ';'; // Prints the result of calculation
const char number = '8'; // Indicates that this is a number
const char name = 'a'; // Indicates that this is a variable
const char sqrts = 's'; // @ indicates square root
const char pows = 'p'; // Indicates pow()
const char assign = '='; // Indicates assignment of a new value to the variable
const char constant = 'c'; // Constant is used to define a constant
const char prompt = '>'; // Prompt used at the beginning of every line
const char quit = 'q'; // Quit is used to exit the program
const char help = 'h'; // Help opens the program manual
const char help_up = 'H'; // Help(uppercase) opens the program manual
const string result = "= "; // = used to before the result
const string version = "1.0"; // Shows the version of the program

struct Calc_error : std::runtime_error {

};

struct Variable { // Holds variables names and values
	string name; // Variable name
	double value; // Variable value
	char constant; // For constants
	Variable(string n, double v) :name(n), value(v) { }
	Variable(string n, double v, char c) :name(n), value(v), constant(c) { } // To hold the constants
};

class Symbol_table {
	vector<Variable> names;
	public:
		double get_value(string s);
		void set_value(string s, double d);
		bool is_declared(string s);
		double define_name(char type);
};

extern istringstream is;

extern Token_stream ts; // Holds all Tokens

extern Symbol_table names; // Holds all variables

double expression(); // Declaration of expression()

double primary(); // Declaration of primary()

double squareroot(); // Calculates a square root of the number

double pow(); // Multiplies n by n m times

double primary(); // Processes semicolons, numbers and returns variables

double term(); // Performs '*', '/', '!', '%' and @(sqrt) operations

double expression(); // Performs '+' and '-' operations

double statement(); // Divides definition of variable and expressions

void clean_up_mess(); // Ignores all characters before ';' if an exception was thrown

string calculate(); // Performs calculations