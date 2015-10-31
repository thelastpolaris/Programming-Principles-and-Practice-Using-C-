/*
Awesome Calculator 1.0
Initially developed by Bjarn Stroustroup. Updated and modified by Fedoskin Artjom.
This program implements a basic expression calculator.
          Input from cin; output to cout.
          The grammar for input is:

          Statement:
          			Expression Print
                    Expression Print Expression Print
					Define Variable = Expression
					Define Constant = Expression
					Variable Assign Expression
                    Print
                    Quit
                    Help

          Print:
                    ;

          Quit:
                    q or quit

		  Help:
		  			h or H or help

		  Define:
		  			let

		  Assign:
		  			=

          Expression:
                    Term
                    Expression/Variable/Constant + Term/Variable/Constant
                    Expression/Variable/Constant – Term/Variable/Constant
          Term:
                    Primary
                    Percent
                    Term/Variable/Constant * Primary/Variable/Constant
                    Term/Variable/Constant / Primary/Variable/Constant
                    Term/Variable/Constant % Primary/Variable/Constant
                    Primary/Variable/Constant !
          Primary:
                    Number
                    ( Expression )
                    – Primary
                    + Primary
                    sqrt (Primary)
                    pow (Primary, Primary)
          Number:
                    floating-point-literal


          Input comes from cin through the Token_stream called ts.
          Possible improvements:
          1. Add percents
          2. Add history of calculations
          3. Add ability to export calculations in file
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

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
public:
	Token_stream() :full(0), buffer(0) { }

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

Token Token_stream::get() // Get characters from cin
{
	if (full) { full=false; return buffer; } // If buffer is not empty, return value from it
	char ch;
	cin >> ch; // Otherwise start looking for characters in input stream
	if (isspace(ch)) { 
		return Token(prompt); // Return prompt if it is a new line
	}
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '!':
	case ',':
		return Token(ch); // If it is an operator or comma then return it
	case assign:
		return Token(assign); // If it is assignment operator return its character
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
		cin.unget(); // If it is a number then return it to the stream
		double val;
		cin >> val; // Read the complete value
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) { // If it is a letter
			string s;
			char ch2 = ch; // If help or quit was entered then save it to use in 'if' condition later
			s += ch; // Put the letter in 's' because it has been already read
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) {
				s+=ch; // Continue to read in 's'
			}
			cin.unget(); // Return the character into the stream
			if (s == "let") return Token(let);	// If user declares the variable then return 'let'
			if (s == "sqrt") return Token(sqrts); // Square root
			if (s == "const") return Token(constant); // Used to define constants
			if (s == "pow") return Token(pows); // To call pow in primary()
			if (ch2 == quit || s == "quit") return Token(quit); // Close the program
			if (ch2 == help || ch2 == help_up || s == "help" || s =="Help") return Token(help); // Opens help menu
			return Token(name,s); // Return name of variable
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c) // Ignores all characters before specific symbol
{
	if (full && c==buffer.kind) { // If 'c' is already in buffer then just discard it
		full = false;
		return;
	}
	full = false; // Otherwise discard value in buffer and look for it further
	char ch;
	while (cin>>ch) // Read all values before 'c'
		if (ch==c) return; // Return when 'c' is found
}

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

double Symbol_table::get_value(string s) // Gets variable's value
{
	for (Variable i: names) {
		if (i.name == s) return i.value;
	}
	error("get: undefined name ",s);
}

void Symbol_table::set_value(string s, double d) // Sets variable's value
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].constant == constant) error("constant assignment"); // If it is a constant then return an error
		else if (names[i].name == s) {	// Else assign a value to the variable
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool Symbol_table::is_declared(string s) // Checks whether variable is already declared
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; // Holds all Tokens

Symbol_table names; // Holds all variables

double expression(); // Declaration of expression()

double primary(); // Declaration of primary()

double squareroot(){ // Calculates a square root of the number
	double d = expression();
	if (d < 0) error("square root of negative number was detected"); // Print error message if negative number was thrown to sqrt
	return sqrt(d);
}

double pow(){ // Multiplies n by n m times
	Token t = ts.get();
	if (t.kind == '(') {
		double lval = expression();
		int rval = 0;
		t = ts.get();
		if(t.kind == ',') rval = narrow_cast<int>(primary());
		else error("Second argument is not provided");
		double result = 1;
		for(double i = 0; i < rval; i++) {
			result*=lval;
		}
		t = ts.get();
		if (t.kind != ')') error("')' expected"); // If there wasn't any ')' return an error
			return result;
	}
	else error("'(' expected"); // If there wasn't any ')' return an error	
}

double primary() // Processes semicolons, numbers and returns variables
{
	Token t = ts.get(); // Get a character
	switch (t.kind) {
	case '(': 
	{	double d = expression(); // Perform calculations in semicolons
		t = ts.get(); // Get a ')' closing character
		if (t.kind != ')') error("')' expected"); // If there wasn't any ')' return an error
		return d;
	}
	case sqrts: // Calculate square root of number or group of numbers
	{
		return squareroot();
	}
	case pows:
	{
		return pow();
	}
	case '-': // For negative digits
		return - primary(); // Return negative digit
	case number: // If Token is a number
		return t.value; // Return the number
	case name: // If Token is a name of variable
	{	
		string s = t.name; // Save name of variable
		t = ts.get();
		if (t.kind == assign) names.set_value(s,expression()); // If there is an assignment symbol then update the value of variable
		else ts.unget(t);
		return names.get_value(s); // Return the value of the variable
	}
	case help:
		return primary();
	default:
		error("primary expected"); // Return an error if an inappropriate character was provided
	}
}

double term() // Performs '*', '/', '!', '%' and @(sqrt) operations
{	
	double left = primary(); // Get a number
	while(true) {
		Token t = ts.get(); // Get a new character
		switch(t.kind) {
		case '*': // Multiplication
			left *= primary(); 
			break;
		case '/': // Division
		{	double d = primary(); 
			if (d == 0) error("division by zero"); // Division by zero is prohibited
			left /= d;
			break;
		}
        case '!': // Factorial
            {   
                int x = left;
                for (int i = 1; i < left; i++) { // Get a multiplication of all numbers before x (including x)
                    x*=i;
                }
                if (x == 0) left = 1;
                else left = x;
                break;
            }        
        case '%': // Modulo
            {
                double d = primary();
                if(d == 0) error("division by zero");
                left = fmod(left,d); // Use fmod to divide floating-point numbers with remainder
                break;
            }
		default:
			ts.unget(t); // If nothing was done return character to the stream
			if (left == -0) return 0; // Change -0 to 0 when it was multiplied or divided by negative digit
			return left; // Return new or unchanged value of 'left'
		}

	}
}

double expression() // Performs '+' and '-' operations
{
	double left = term(); // Get the number or the result of calculations in term
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term(); // Addition
			break;
		case '-':
			left -= term(); // Subtraction
			break;
		default:
			ts.unget(t); // If nothing was done return character to the stream
			return left; // Return the new or unchanged value of 'left'
		}
	}
}

double Symbol_table::define_name(char type) // Defines a variable
{
	Token t = ts.get(); // Get a character from the stream
	if (t.kind != 'a') error ("name expected in declaration"); // If there is no name return an error
	string name = t.name; // Read the name in 'name'
	if (is_declared(name)) error(name, " declared twice"); // Check if the variable had been already declared
	Token t2 = ts.get(); // Get a character from the stream
	if (t2.kind != '=') error("= missing in definition of " ,name); /* If there is no '=' symbol used to assign a value
																		to the variable return an error */
	double d = expression(); // Process the provided value
	switch(type) {
	case let:
		names.push_back(Variable(name,d)); // Add new variable to a vector
		return d; // Return the value of new variable
	case constant:
		names.push_back(Variable(name,d,constant)); // Add new constant to a vector
		return d; // Return the value of new constant
	}
}

double statement() // Divides definition of variable and expressions
{
	Token t = ts.get();
	switch(t.kind) {
	case let: // User wants to declare the variable
		return  names.define_name(let);
	case constant:
		return names.define_name(constant);
	default: // User wants another operation
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess() // Ignores all characters before ';' if an exception was thrown
{
	ts.ignore(print);
}

void calculate() // Performs calculations
{
	while(true) try {
		ts.unget(Token(prompt));
		Token t = ts.get(); // Get a new character
		if (t.kind == prompt) {
			cout << prompt; // Output '>' symbol
			t = ts.get();
		}
		if (t.kind == help) { // If help was entered open help menu
		cout << "Welcome to Awesome Calculator " << version << " ! Here is the list of the commands:\n"
			"Available operators are '+','-','/','*'. The program is able to work with floating-point numbers\n"
			"'Expression' + ';' - Prints the result (always use it at the end of the statement)\n"
			"'let' + 'name of variable' + '='' + 'value' - defines a variable\n"
			"'const' + 'name of constant' + '='' + 'value' - defines a constant\n"
			"'name of variable' + '=' + 'new value' - assigns a new value to the variable\n"
			"'pow(x,y)' - multiplies x by y times (y must be of type int)\n"
			"'sqrt(x)' - returns square root of x\n"
			"'h' or 'help' - opens this menu\n"
			"'quit' - closes the program\n";
			continue; // Move to next iteration
		}
		while (t.kind == print) t=ts.get(); // Read all ';'
		if (t.kind == quit) return; // Close the program if exit was entered
		ts.unget(t); // Return a character into the stream
		cout << result << statement() << endl; // Output the result
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl; // Cout the error if the exception was thrown
		clean_up_mess(); // Ignores all characters till the ';'
	}
}

int main()
	try {
		calculate(); // Performs calculations
		return 0;
	}
	catch (exception& e) { // Throws an exception
		cerr << "exception: " << e.what() << endl; // Describe the error
		char c;
		while (cin >>c&& c!=';');
		return 1;
	}
	catch (...) { // Throws an exception
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
