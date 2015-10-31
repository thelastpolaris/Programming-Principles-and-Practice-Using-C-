#include "std_lib_facilities.h"

enum class Genre { //Genre of the book
	fiction, nonfiction, periodical, bibliography, children
};

class Book {
public:
	class Invalid{};
	Book(string ISBN, string tt, string aa, Genre gg, int cc, bool ch)
	:ISBN{ISBN}, t{tt}, a{aa}, g{gg}, c{cc}, ch{ch}
	{
		for (int i = 0; i < ISBN.size(); i++) { // Check if the ISBN is valid according to the notation x-x-x-n where x is int and n is a digit or letter
			if (ISBN.size() != 4) throw Invalid{}; // If ISBN consists of less than 4 characters then throw an exception
			if (i < 3) { // Check if the first 3 characters are ints
				switch(ISBN[i]) {
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						break;
					default:
						throw Invalid{};
				}
			}
		}
	}
	string write_ISBN() {return ISBN;}; // Returns ISBN
	string write_title() {return t;}; // Returns title
	string write_author() {return a;}; // Returns author
	int write_copyright() {return c;}; // Returns copyright
	int write_genre() {return int(g);}; // Returns genre
	bool write_check() {return ch;}; // Returns check
	void check_book(bool s) { ch = s;}; // Changes the value of check
private:
	string ISBN; // ISBN
	string t; // Title
	string a; // Author
	Genre g;
	int c; // Copyright date
	bool ch; // Check (indicates if the book is in library or not)
};

bool operator==(Book& a, Book& b) { // "Equal to" operator to use with books
	return a.write_ISBN() == b.write_ISBN();
	}

bool operator!=(Book& a, Book& b) { // "Not equal" to operator to use with books
	return !(a == b);
}

void operator<<(ostream& os, Book& n) {
	os << n.write_title() << endl << n.write_author() << endl << n.write_ISBN() << endl << n.write_genre();
}

int main() try {
	Book book {"567f", "The Witcher", "Andrzej Sapkowski", Genre::fiction, 1998, true};
	cout << book;
	cout << endl;
}
catch (Book::Invalid) {
	cerr << "Invalid data provided" << endl;
}