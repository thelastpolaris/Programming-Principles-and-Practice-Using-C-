/* Chapter 11 Exercise 1 
Write a program that reads a text file and converts its input to all lower case, producing a new file.
*/
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream ifs {"ex1_in.txt"};
	ofstream ofs {"ex1_out.txt", ios_base::ate};
	string s;
	while (ifs) {
		getline(ifs, s);
		for (char& ch : s) ch = tolower(ch);
		ofs << s << endl;
		s.clear();
	}
}
