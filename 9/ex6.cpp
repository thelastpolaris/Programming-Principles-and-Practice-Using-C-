#include "std_lib_facilities.h"

class Book {
public:
	class Invalid{};
	Book(string ISBN, string title, string author, int copyright, bool check)
	:ISBN{ISBN}, title{title}, author{author}, copyright{copyright}, check{check} 
	{
		for (int i = 0; i < ISBN.size(); i++) { // Check if the ISBN is valid according to the notation x-x-x-n where x is int and n is digit or letter
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
	string write_ISBN() {return ISBN;}; // Outputs ISBN
	string write_title() {return title;}; // Outputs title
	string write_author() {return author;}; // Outputs author
	int write_copyright() {return copyright;}; // Outputs copyright
	bool write_check() {return check;}; // Outputs check
	void check_book(bool s) { check = s;}; // Changes the value of check
private:
	string ISBN;
	string title;
	string author;
	int copyright;
	bool check;
};

bool operator==(Book& a, Book& b) { // "Equal to" operator to use with books
	return a.write_ISBN() == b.write_ISBN();
	}
bool operator!=(Book& a, Book& b) { // "Not equal" to operator to use with books
	return !(a == b);
}

void operator<<(ostream& os, Book& n) {
	os << n.write_title() << endl << n.write_author() << endl << n.write_ISBN();
}

int main() try {
	Book book {"567f", "The Witcher", "Andrzej Sapkowski", 1998, true};
	cout << book;
	cout << endl;
}
catch (Book::Invalid) {
	cerr << "Invalid data provided" << endl;
}