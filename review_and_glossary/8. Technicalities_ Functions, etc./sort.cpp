#include "std_lib_facilities.h"

vector<int> numbers {15000,10,87,2300,45,61,23,42,12,15,11,20,53,32,49,5060,430,29,900,1,0,30,420,52,12,14,15,78};
bool status = true;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int counter = 0;
	while (status) {
		status = false;
		counter++;
		for (int i = 1; i < numbers.size(); i++) {
			if (numbers[i - 1] > numbers[i]) { swap(numbers[i-1],numbers[i]); status = true; }
			//if (numbers[numbers.size() - i] < numbers[numbers.size() - i-1]) { swap(numbers[numbers.size() - i-1],numbers[numbers.size() - i]); status = true; }
		}
		for (int i = 2; i < numbers.size() - 1; i++) {
			if (numbers[i - 1] > numbers[i]) { swap(numbers[i-1],numbers[i]); status = true; }
		}

	}
	cout << counter << endl;
	for (int x: numbers) cout << x << " ";
}