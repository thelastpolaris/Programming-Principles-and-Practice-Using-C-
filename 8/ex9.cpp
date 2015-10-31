#include "std_lib_facilities.h"

vector<double> price; // Holds prices
vector<double> weight; // Holds weight

int main() try {
	cout << "Enter the price and corresponding weight\n";
	double x; // Holds price
	double s; // Holds weight
	while(cin >> x >> s) {
		price.push_back(x); // Add price to the vector 'price'
		weight.push_back(s); // Add weight to the vector 'weight'
	}
	for (int i = 0; i < price.size(); i++) cout << price[i] << " * " << weight[i] << " = " << price[i]*weight[i] << "\n"; //Print the result of price and weight multiplication
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
}