#include "std_lib_facilities.h"

class DegreeErrror { };

double ctok(double t, char d)                   // converts Celsius to Fahrenheit or Fahrenheit to Celsius
{
		  double result;
		  if (d == 'c')	{
		  	if (t < -273.15) throw DegreeErrror{};
		  	else result = (t*9)/5+32;
		  }
		  else if (d == 'f') {
		  	if (t < -459.67) throw DegreeErrror{};
		  	else result = (t-32)/9*5;
		  }
		  else error("Char error");
          return result;
}
int main()
try {
			char d;
			double t = 0;                         // declare input variable
			cout << "Please, choose the type of conversion (c for Celsius to Fahrenheit and f for Fahrenheit to Celsius)\n";
			cin >> d;                                         // retrieve temperature to input variable
		  	cout << "Please, enter the number\n";
           cin >> t;                                         // retrieve temperature to input variable
          double k = ctok(t, d);           // convert temperature
          cout << k << "/n" ;                 // print out temperature
}
catch (DegreeErrror) {
		  cerr << "Degree error\n";
}