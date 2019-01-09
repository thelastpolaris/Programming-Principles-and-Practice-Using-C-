#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Point {
	int x;
	int y;
};

istream& operator>>(istream& is, Point& a) {
	is >> a.x >> a.y;
	return is;
}

ostream& operator>>(ostream& os, Point& a) {
	os << "(" a.x << ", " << a.y << ")";
	return os;
}

int main() {
	Point a;
	cin >> a;
	cout << a;
}

