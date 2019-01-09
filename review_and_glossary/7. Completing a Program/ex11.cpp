/*
	This program prints all prime numbers but not more than 'n', which is provided by user.
	2015
*/

#include "std_lib_facilities.h";
	
	int maximal; //Maximal number of primes
	
	int main() {
		try {
			cout << "Enter maximal number of primes\n";
			cin >> maximal; // Write maximal number of primes
			vector<int> numbers(maximal); // Create vector to hold all the numbers
			for (int b = 0; b < maximal; b++) {
				numbers[b] = 1; // Assign value 1 to all elements of vector 
			}

			for (int i = 2; i < maximal; i++) {
				if (numbers[i] == 1) { //If it is prime
					for (int c = i*i; c < maximal; c += i) { // Prime*Prime + Prime
						numbers[c] = 0; // If it is a composite number then assign 0 to the element of vector
					}
				}
			}
			
			for (int x = 0; x < numbers.size(); x++) {
				if (numbers[x] == 1) cout << x << " | "; // Print all prime numbers
			}
		}
		catch(runtime_error& e) {
			cout << e.what() << "\n";
			return 1;
		}
		catch(...) {
			cout << "Uknown exception" << "\n";
			return 2;
		}
	}