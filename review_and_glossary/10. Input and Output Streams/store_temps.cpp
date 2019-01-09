/* Chapter 10 
Exercise 2
Write a program that creates a file of data in the form of the temperature Reading type defined in §10.5. 
For testing, fill the file with at least 50 “temperature readings.” 
Call this program store_temps.cpp and the file it creates raw_temps.txt.
----------------------------------------------------------------------------------------------------------
Exercise 4
Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit temperatures. 
Then modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to Fahrenheit 
before putting them into the vector.
*/

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void error(string s) {
	throw runtime_error(s);
}

int main() try{
	cout << "Enter the name of file to read" << endl;
	string in;
	cin >> in;
	ifstream ifs {in};
	if (!ifs) error("Wrong name of file");
	cout << "Enter the name of output file" << endl;
	string out;
	cin >> out;
	ofstream ofs {out};
	if (!ofs) error("Wrong name of file");
	while (ifs) {
		int hour;
		double temp;
		char ch;
		ifs >> hour;
		if (!(ifs >> temp)) break;
		ifs >> ch;
		if (ch!='c' && ch!='C' && ch!='f' && ch!='F') error("Not a celsius and not a fahrenheit");
		ofs << temp << ch << endl;
	}
}

catch (runtime_error& e) {
	cout << e.what() << endl;
}