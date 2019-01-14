/**
Exercsie 4
Consider what happens if you give strdup() , findx() , and strcmp() an argument that is not a C-style string. 
Try it! First figure out how to get a char* that doesn’t point to a zero-terminated array of characters and then 
use it (never do this in real — non-experimental — code; it can create havoc). Try it with free-store-allocated 
and stack-allocated “fake C-style strings.” If the results still look reasonable, turn off debug mode. Redesign 
and re-implement those three functions so that they take another argument giving the maximum number of elements 
allowed in argument strings. Then, test that with correct C-style strings and “bad” strings.
**/

#include <iostream>
#include <string>
using namespace std;

char* strdup(const char* s, int len) {
	char* dup = new char[len];
	while(*s) *dup++ = *s++;

	dup -= len;
	return dup;
}

char* strdup_array(const char s, int len) {
	char* dup = new char[len];
	while(*s) *dup++ = *s++;

	dup -= len;
	return dup;
}

const char* findx(const char* s, const char* x) {
	const char* x_orig = x;
	const char* starting_pointer = nullptr;
	while(*s) {
		if(!*x) {
			return starting_pointer;
		}
		if(*x == *s) {
			if(!starting_pointer) starting_pointer = s;
			++x;
		} else {
			x = x_orig;
			starting_pointer = nullptr;
		}
		++s;
	}

	return starting_pointer;
}

int strcmp(const char* s1, const char* s2) {
	while(*s1 && *s2) {
		if(*s1 > *s2) return -1;
		else if(*s1 < *s2) return 1;
		++s1;
		++s2;
	}

	if(*s1 && !*s2) return 1;
	else if(!*s1 && !s2) return -1;
	return 0;
}

int main() {
	cout << "Pointer: " << endl;
	const char* p = new char[5];
	p = "hello";
	cout << "strdup: " << strdup(p, 5) << endl;
	
	const char* s = new char[10];
	s = "hel";

	const char* x = findx(p, s);
	if(x) cout << "findx " << x << endl;
	else cout << "string not found" << endl;
	cout << "strcmp " << strcmp(p, s) << endl;

	cout << "Array: " << endl;
	const char a[5] = "hell";
	cout << "strdup: " << strdup(a, 5) << endl;

	const char w[5] = "hel";

	x = findx(a, w);
	if(x) cout << "findx: " << x << endl;
	else cout << "string not found" << endl;
	cout << "strcmp: " << strcmp(a, w) << endl;
}