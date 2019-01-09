/*
This program implements a basic expression calculator.
          Input from cin; output to cout.
          The grammar for input is:

          Statement:
                    Expression
                    Print
                    Quit
          Print:
                    ;

          Quit:
                    q

          Expression:
                    Term
                    Expression + Term
                    Expression – Term
          Term:
                    Primary
                    Term * Primary
                    Term / Primary
                    Term % Primary
                    Primary !
          Primary:
                    Number
                    ( Expression )
                    – Primary
                    + Primary
                    sqrt (Primary)
          Number:
                    floating-point-literal


          Input comes from cin through the Token_stream called ts.
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

const char let = 'L'; // Let is used for declaration of variables
const char quit = 'E'; // Quit is used to exit the program
const char print = ';'; // Prints the result of calculation
const char number = '8'; // Indicates that this is a number
const char name = 'a'; // Indicates that this is a variable
const char sqrts = 's'; // @ indicates square root
const char pows = 'p'; // Indicates pow()
const char assign = '='; // Indicates assignment of a new value to the variable

Token Token_stream::get() // Get characters from cin
{
	if (full) { full=false; return buffer; } // If buffer is not empty, return value from it
	char ch; 
	cin >> ch; // Otherwise start looking for characters in input stream
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
			s += ch; // Put the letter in 's' because it has been already read
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch; // Continue to read in 's'
			cin.unget(); // Return the character into the stream
			if (s == "let") return Token(let);	// If user declares the variable then return 'let'
			if (s == "sqrt") return Token(sqrts);
			if (s == "pow") return Token(pows);
			if (s == "exit") return Token(quit); // Close the program
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
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;	// Holds all variables

double get_value(string s) // Gets variable's value
{
	for (Variable i: names) {
		if (i.name == s) return i.value;
	}
	error("get: undefined name ",s);
}

void set_value(string s, double d) // Sets variable's value
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s) // Checks whether variable is already declared
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; // Holds all Tokens

double expression(); // Declaration of expression()

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
		double d = primary();
		if (d < 0) error("square root of negative number was detected"); // Print error message if negative number was thrown to sqrt
		return sqrt(d);
	}
	case pows:
	{
		t = ts.get();
		if (t.kind == '(') {
			double lval = primary();
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
	case '-': // For negative digits
		return - primary(); // Return negative digit
	case number: // If Token is a number
		return t.value; // Return the number
	case name: // If Token is a name of variable
		return get_value(t.name); // Return the value of the variable
	default:
		error("primary expected"); // Return an error if an inappropriate character was provided
	}
}

double term() // Performs '*', '/', '!', '%' and @(sqrt) operations
{
	double left = primary(); // Get the number or the variable
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

double declaration() // Declares a name of the variable
{
	Token t = ts.get(); // Get a character from the stream
	if (t.kind != 'a') error ("name expected in declaration"); // If there is no name return an error
	string name = t.name; // Read the name in 'name'
	if (is_declared(name)) error(name, " declared twice"); // Check if the variable had been already declared
	Token t2 = ts.get(); // Get a character from the stream
	if (t2.kind != '=') error("= missing in declaration of " ,name); /* If there is no '=' symbol used to assign a value
																		to the variable return an error */
	double d = expression(); // Process the provided value
	names.push_back(Variable(name,d)); // Add new variable to a vector
	return d; // Return the value of new variable
}

double statement() // Distinguishes between declarations and expressions
{
	Token t = ts.get();
	switch(t.kind) {
	case let: // User wants to declare the variable
		return declaration();
	case assign:
		cout << "Yes!";
		break;
	default: // User wants another operation
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess() // Ignores all characters before ';' if an exception was thrown
{
	ts.ignore(print);
}

const string prompt = "> "; // Prompt used at the beginning of every line
const string result = "= "; // = used to before the result

void calculate() // Performs calculations
{
	while(true) try {
		cout << prompt; // Output '>' symbol
		Token t = ts.get(); // Get a new character
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
		names.push_back(Variable("k",1000)); // Pre-defined variable 'k'

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
