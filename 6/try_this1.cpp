#include "std_lib_facilities.h"

class Token {
	public:
		char kind;
		double value;
	Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream
{
    public:
        Token_stream();
        Token get();
        void putback(Token t);
    private:
        bool full;
        Token buffer;
};

Token_stream::Token_stream()
    :full(false), buffer(0){}

void Token_stream::putback(Token t)
{
          if (full) error("putback() into a full buffer");
          buffer = t;             // copy t to buffer
          full = true;            // buffer is now full
}

Token Token_stream::get()
{
    if (full)
    {
        full=false;
        return buffer;
    }

    char ch;
    std::cin>>ch;
    switch(ch)
    {
        case ';':
        case 'q': 
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);
        case'.':
        case'0': case'1': case'2': case'3': case'4':
        case'5': case'6': case'7': case'8': case'9':
        {
           std::cin.putback(ch);
           double val;
           std::cin>>val;
           return Token('8', val);
        }
        default: throw std::runtime_error("Bad Token");
    }
}

Token_stream ts;

double expression();

double term();

double primary() {
	Token t = ts.get();
	switch(t.kind) {
		case '(': case ')':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')'expected");
			return d;
			break;
		}
		case '8':
			return t.value;
			break;
		default:
			error("primary expected");
	}
}

double term() {
	double lval = primary();
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
			case '*':
				lval *= primary();
				t = ts.get();
				break;
			case '/':
				{
				double d = primary();
				if (d == 0) error("divide by zero");
				lval /= d;
				t = ts.get();
				break;
				}
			default:
				ts.putback(t);
				return lval;
			}
		}
	}

double expression() {
	double lval = term();
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
			case '+':
				lval+=term();
				t = ts.get();
				break;
			case '-':
				lval-=term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return lval;
				break;
		}
	}
}

int main() {
	try {
		double val = 0;
		while(cin) {
			Token t = ts.get();
			if (t.kind == 'q') break;
			if (t.kind == ';') cout << "=" << val << '\n';
            else ts.putback(t);
          val = expression();
		}
	}
	catch(exception& e) {
		cout << e.what() << '\n';
		return 1;
	}
	catch(...) {
		cerr << "exception \n";
		return 2;
	}
}