#include "std_lib_facilities.h"

class DegreeErrror { };

double ctok(double c)                   // converts Celsius to Kelvin
{	
		  if (c <= -273.15)	throw DegreeErrror{};
          double k = c + 273.15;
          return k;
}
int main()
try {
          double c = 0;                         // declare input variable
           cin >> c;                                // retrieve temperature to input variable
          double k = ctok(c);           // convert temperature
          cout << k << "/n" ;                 // print out temperature
}
catch (DegreeErrror) {
		  cerr << "Degree error\n";
}