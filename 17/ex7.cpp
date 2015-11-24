/* Chapter 17 Exercise 7
Write a program that reads characters from cin into an array that you allocate on the free store. Read individual characters until 
an exclamation mark (!) is entered. Do not use a std::string. Do not worry about memory exhaustion.
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdio>

char* add_size(char* s, int n) {
	int i = 0;
	while(s[i] != '\0') i++;
	char* arr = new char[i+n+1]; // 1 for null character
	for (int b = 0; s[b]; ++b) arr[b] = s[b];
	arr[i+n+1] = '\0';
	delete[] s;
	return arr;
}

int main() try {
	char* ch = new char[0];
	char c;
	int length = 0;
	while(std::cin.get(c) && c != '!') {
		ch = add_size(ch, 1);
		length++;
		ch[length-1] = c;
	}
	for(int i = 0; ch[i]; ++i) std::cout << ch[i];
	std::cout << '\n';
	delete[] ch;
}
catch(std::runtime_error& e) {
	std::cout<< e.what() << '\n';
}
catch(...) {
	std::cout << "Unknown error" << '\n';
}