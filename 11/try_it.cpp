#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Punct_stream {
	public:
		Punct_stream(istream& is)
		:source{is}, sensitive{true} { }
		void whitespace(const string& s) { white = s; }
		void add_white(char c) {white += c;}
		bool is_whitespace(char c);
		void case_sensitive(bool b) {sensitive = b;}
		bool is_case_sensitive() {return sensitive;}
		Punct_stream& operator>>(string& s);
		operator bool();
	private:
		istream& source;
		istringstream buffer;
		string white;
		bool sensitive;
};

bool Punct_stream::is_whitespace(char c) {
	for (char x : white) if (c == x) return true;
	return false;
}

Punct_stream::operator bool() {
	return !(source.bad()||source.fail()) && source.good();
}

Punct_stream& Punct_stream::operator>>(string& s) {
	while(!(buffer>>s)) {
		if(buffer.bad() || !source.good()) return *this;
		buffer.clear();
		string line;
		getline(source,line);
		for (char& ch: line) {
			if(is_whitespace(ch)) ch = ' ';
			else if(!sensitive) tolower(ch);
		}
		std::cout << line << '|' << std::endl;
		buffer.str(line);
	}
	return *this;
}

int main() {
	Punct_stream ps {cin};
	ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
	ps.case_sensitive(false);
	cout << "please enter words\n";
    vector<string> vs;
    string word;
    ps >> word;
    /*for (string word; ps>>word; )
         vs.push_back(word);            // read words
    sort(vs.begin(),vs.end());               // sort in lexicographical order
    for (int i=0; i<vs.size(); ++i) if (i==0 || vs[i]!=vs[i-1]) cout << vs[i] << '\n';
*/
}
