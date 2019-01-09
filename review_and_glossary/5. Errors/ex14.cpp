#include "std_lib_facilities.h"

	vector<int> numbers;
	vector<string> dow;
	int number = 0;
	string day;
	int vectors_sum = 0;

	int main() {
		cout << "Enter the pair of values (Day of weak | number)\n";
		while(cin >> day >> number) {
			if (day != "Mon"&&
				day != "Monday"&&
				day != "Monday" &&
				day != "monday" &&
				day != "Tue" &&
				day != "Tuesday" &&
				day != "tuesday" &&
				day != "Wed" &&
				day != "Wednesday" &&
				day != "wednesday" &&
				day != "Th" &&
				day != "Thursday" &&
				day != "thursday" &&
				day != "Fr" &&
				day != "Friday" &&
				day != "friday" &&
				day != "Sat" &&
				day != "Saturday" &&
				day != "saturday" &&
				day != "Sun" &&
				day != "Sunday" &&
				day != "sunday") {
				cerr << "Please, enter the correct day of the week\n";
				continue;
			}
			dow.push_back(day);
			numbers.push_back(number);
		}
		for (int x: numbers) vectors_sum += x;
		for (int i = 0; i < dow.size(); i++) {
			cout << dow[i] << " : " << numbers[i] << "\n";
		}
		cout << "Sum of numbers is " << vectors_sum << "\n";
	}