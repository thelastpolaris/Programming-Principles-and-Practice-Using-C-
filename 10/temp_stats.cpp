/* Chapter 10 
Exercise 3
Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector
and then calculates the mean and median temperatures in your data set. Call this program temp_stats.cpp.
----------------------------------------------------------------------------------------------------------
Exercise 4
Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit temperatures. 
Then modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to Fahrenheit 
before putting them into the vector.
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

void error(string s) {
	throw runtime_error(s);
}

int main() try{
	cout << "Enter the name of file to read" << endl;
	string in;
	cin >> in;
	ifstream ifs {in};

	double t;
	vector<double> temps;
	while (ifs >> t) {
		char ch;
		if(!(ifs >> ch)) error("Not a celsius and not a fahrenheit");
		if(ch == 'c' || ch == 'C') t = t * 1.8 + 32;
		temps.push_back(t);
	}

	double mean = 0;
	double median = 0;

	for (double x : temps) mean+= x; // Calculating the mean of all temperatures
	mean = mean / temps.size();

	sort(temps.begin(),temps.end()); // Sort the array to find the median

	median = temps.size()/2; // Calculating the median of all temperatures
	if (temps.size()%2) median = temps[median];
	else median = (temps[median-1]+temps[median])/2;

	cout << "The mean of all temperatures is: " << mean << endl;
	cout << "The median of all temperatures is: " << median << endl;
}
catch (exception& e) {
	cout << "Error: " << e.what() << endl;
}