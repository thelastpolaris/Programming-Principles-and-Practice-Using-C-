#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Point {
	int x;
	int y;
};

istream& operator>>(istream& is, Point& a) {
	is >> a.x >> a.y;
	return is;
}

ostream& operator<<(ostream& os, Point& a) {
	os << "(" << a.x << ", " << a.y << ")";
	return os;
}

void write_to_file(const vector<Point>& a, const string& filename) {
	ofstream file {filename};
	for (Point x : a) file << x << endl;
}

vector<Point> read_from_file(const string& filename) {
	ifstream file {filename};
	vector<Point> v;
	int a = 0;
	int b = 0;
	char ch1;
	char ch2;
	char ch3;
	while (file >> ch1 >> a >> ch2 >> b >> ch3) if (ch1 == '(' && ch2 == ',' && ch3 == ')') v.push_back(Point {a,b});
	return v; 
}

bool compare_vectors(const vector<Point>& a, const vector<Point>& b) {
	if (a.size() != b.size()) return false;
	return true;
}

int main() {
	string filename = "drill.txt";
	Point a;
	vector<Point> original_points;
	while(cin >> a) {
		original_points.push_back(a);
	}
	write_to_file(original_points, filename);
	vector<Point> processed_points = read_from_file(filename);
	for (Point x : original_points) cout << x;
	for (Point x : processed_points) cout << x;
	if (!compare_vectors(original_points, processed_points)) cout << "Something's wrong!" << endl;
}

