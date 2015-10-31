
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
	This file is known as calculator002buggy.cpp

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

*/

#include "std_lib_facilities.h"

const char number = '8'; //Number means that t is a number Token
const char quit = 'q'; //Quit means that t is a quit Token
const char print = ';'; //Print means that t is a Token for printing the results
const string prompt = "> ";
const string result = "= ";// used to indicate that what follows is a result

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)
        :kind(ch), name(n) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c); // ignores desired symbol in Token stream
private:
    bool full {false};        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

class Variable {
public:
        string name;
        double value;
    Variable(string n, double v)
        :name(n), value(v) { }
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
          // c represents the kind of Token
{
          // first look in buffer:
          if (full && c==buffer.kind) {
                    full = false;
                    return;
          }
          full = false;

          // now search input:
          char ch = 0;
          while (cin>>ch) if (ch==c) return;
}

//------------------------------------------------------------------------------

const char name = 'a';                         // name token
const char let = 'L';                              // declaration token
const string declkey = "let";              // declaration keyword

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:    // for "print"
    case quit:    // for "quit"
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '{': 
    case '}': 
    case '!': 
    case '%':
    case '=':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token(number,val);   // let '8' represent "a number"
        }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch)||isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == declkey) return Token(let);    // declaration keyword
            return Token{name,s};
        }
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

vector<Variable> var_table;         // holds variables and their values

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// ignore all characters before semicolon when exception is thrown

void clean_up_mess() {
    ts.ignore(print);
}

//------------------------------------------------------------------------------

// return the value of variable

double get_value(string s) {

    for (const Variable&v: var_table) if (v.name==s) return v.value;
    error("get: undefined variable ", s);

}

//------------------------------------------------------------------------------

// set value of variable

void set_value(string s, double d) {
    for (Variable& v : var_table) {
        if (v.name == s) {
            v.value = d;
            return;
            }
        error("set: undefined variable ", s);
    }
}

//------------------------------------------------------------------------------

// check whether the variable has been already declared

bool is_declared(string var)
{
          for (const Variable& v : var_table)
                    if (v.name == var) return true;
          return false;
}

//------------------------------------------------------------------------------

// add variable to var_table

double define_name(string var, double val)
{
          if (is_declared(var)) error(var," declared twice");
          var_table.push_back(Variable(var,val));
          return val;
}

//------------------------------------------------------------------------------

// declare a variable and add it to var_table

double declaration()
          // assume we have seen "let”
          // handle: name = expression
          // declare a variable called "name” with the initial value "expression”
{
          Token t = ts.get();
          if (t.kind != name) error ("name expected in declaration");
          string var_name = t.name;

          Token t2 = ts.get();
          if (t2.kind != '=') error("= missing in declaration of ", var_name);

          double d = expression();
          define_name(var_name,d);
          return d;
}

//------------------------------------------------------------------------------

// deal with declaration of variable

double statement()
{
          Token t = ts.get();
          switch (t.kind) {
          case let:
                    return declaration();
          default:
                    ts.putback(t);
                    return expression();
          }
}

//------------------------------------------------------------------------------

// deal with calculations

void calculate() {

    cout << "Welcome to our simple calculator.Please enter expressions using floating-point numbers.\n" <<
    "Available operators are '+','-','/','*'. To print results please use '"<< print <<"' at the end of your statement.\n" <<
    "To exit the program input '"<< quit <<"'\n";
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t=ts.get();
            if (t.kind == quit) return; // 'q' for quit
            ts.putback(t);
            cout << result << statement() << '\n';
        }
        catch (exception& e) {
            cerr << "error: " << e.what() << '\n';
            clean_up_mess();
        }
    }
}

//------------------------------------------------------------------------------

// deal with numbers and parentheses

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(': case '{':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')' && t.kind !='}') error("')' or '}' expected");
            return d;
        }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':
        return - primary();
    case '+':
        return primary();
    case 'a':
        return get_value(t.name);
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %

double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("division by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '!':
            {   
                int x = left;
                for (int i = 1; i < left; i++) {
                    x*=i;
                }
                if (x == 0) left = 1;
                else left = x;
                t = ts.get();
                break;
            }        
        case '%':
            {
                double d = primary();
                if(d == 0) error("division by zero");
                left = fmod(left,d);
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);
	calculate();
	keep_window_open();
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
	keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------
 
