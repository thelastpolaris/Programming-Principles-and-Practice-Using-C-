#include "std_lib_facilities.h"

vector<string> nouns;
vector<string> verbs;
vector<string> conjunctions;

void init()
// initialize word classes
{
	nouns.push_back("birds");
	nouns.push_back("fish");
	nouns.push_back("C++");	// I didn't suggest addin "C+" to this exercise
							// but it seems some people like that
	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");

	conjunctions.push_back("and");
	conjunctions.push_back("or");
	conjunctions.push_back("but");
}

bool noun(string w) {
	for(string x: nouns) {
		if (x == w) return true;
	}
	return false;
}

bool verb(string w2) {
	for(string x: verbs) {
		if (x == w2) return true;
	}
	return false;
}

bool conjunction(string w3) {
	for(string x: conjunctions) {
		if (x == w3) return true;
	}
	return false;
}

bool sentence() {
	string w;
	cin >> w;
	if (!noun(w)) return false;

	string w2;
	cin >> w2;
	if (!verb(w2)) return false;

	string w3;
	cin >> w3;
	if (w3 == ".") return true;
	if (!conjunction(w3)) return false;
	return sentence();

}

int main() {
	try {
		init();
		while (cin) {
			bool b = sentence();
			if (b)
				cout << "OK\n";
			else
				cout << "not OK\n";
			cout << "Try again: ";
		}
	}
	catch(runtime_error&e) {
		cerr << e.what() << "\n";
	}
}