#include "std_lib_facilities.h"

vector<double> numbers {3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23};

struct vector_info {
	double max;
	double min;
	double mean;
	double median;
} numbers_info;

vector_info v_info(vector<double> v) {
	vector_info info;
	info.mean = 0;

	sort(v.begin(),v.end());

	for (int i = 0; i < v.size(); i++) {
		info.mean += v[i];
	}

	info.mean = info.mean / v.size();
	info.max = v[v.size() - 1];
	info.min = v[0];
	if (v.size()%2 == 0) {
		info.median = ((v[v.size()/2-1] + v[v.size()/2])/2);
	}
	else info.median = v[v.size()/2];
	return info;
}

int main() try {
	numbers_info = v_info(numbers);
	cout << "Max: " << numbers_info.max << endl;
	cout << "Min: " << numbers_info.min << endl;
	cout << "Mean: " << numbers_info.mean << endl;
	cout << "Median: " << numbers_info.median << endl;
}
// Error processing
catch (runtime_error& e) {
	cerr << e.what() << "\n";
}
catch (...) {
	cerr << "Unknown exception\n";
} 
