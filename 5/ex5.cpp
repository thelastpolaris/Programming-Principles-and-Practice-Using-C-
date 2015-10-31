#include "std_lib_facilities.h"

class DegreeErrror { };

double ctok(double t, char d)                   // converts Celsius to Kelvin or Kelvin to Celsius
{
		  double result;
		  if (d == 'c')	{
		  	if (t < -273.15) throw DegreeErrror{};
		  	else result = t + 273.15;
		  }
		  else if (d == 'k') {
		  	if (t < 0) throw DegreeErrror{};
		  	else result = t - 273.15;
		  }
		  else error("Char error");
          return result;
}
int main()
try {
			char d;
			double t = 0;                         // declare input variable
			cout << "Please, choose the type of conversion (c for Celsius to Kelvin and k for Kelvin to Celsius)\n";
			cin >> d;                                         // retrieve temperature to input variable
		  	cout << "Please, enter the number\n";
           cin >> t;                                         // retrieve temperature to input variable
          double k = ctok(t, d);           // convert temperature
          cout << k << "/n" ;                 // print out temperature
}
catch (DegreeErrror) {
		  cerr << "Degree error\n";
}