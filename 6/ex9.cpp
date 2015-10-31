#include "std_lib_facilities.h"

vector<char> digits;
vector<string> unit;
char ch;
int num = 0;
int digit = 0;

int main() 
	try{
		unit.push_back(" hundreds of millions ");
		unit.push_back(" tens of millions ");
		unit.push_back(" millions ");
		unit.push_back(" hundreds of thousands ");
		unit.push_back(" tens of thousands ");
		unit.push_back(" thousands ");
		unit.push_back(" hundreds ");;
		unit.push_back(" tens ");
		unit.push_back(" ones ");
		cout << "Input integer with no more than " << unit.size() << " digits followed by a semicolon ; \n";
		while(cin>>ch) {
			if (ch<'0' || '9'<ch) break;
			digits.push_back(ch);
		}
		if (digits.size() > unit.size()) {
			error("Too much digits were entered. Exiting\n");
		}
		for (int i = 0; i < digits.size(); ++i) {
				cout << digits[i] << unit[unit.size() - (digits.size() - i) ] << "\n";
				digit = digits[i] - '0';
				num = num*10 + digit;
			}
		cout << "Your number was " << num << "\n";

	}
	catch(exception& e){
		cerr << e.what() << "\n";
	}