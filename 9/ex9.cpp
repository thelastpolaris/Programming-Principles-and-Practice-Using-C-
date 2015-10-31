#include "Chrono.h"

using namespace Chrono;

enum class Genre { //Genre of the book
	fiction, nonfiction, periodical, bibliography, children
};

class Patron {
public:
	Patron(string nn, int cn, double ff)
	:n{nn}, cn{cn}, f{ff}
	{
	}
	string write_name() const {return n;};
	int write_cn() const {return cn;};
	double write_fee() const {return f;};
	void fee(double sum) {f += sum;}; // Changes the value of fee
	bool check_fee() const {return f;}; // Checks if the user owes a fee
private:
	string n; // User's name
	int cn; // Card number
	double f; // Library fees
};

bool operator==(Patron& a, Patron& b) { // "Equal to" operator to use with patrons
	return a.write_name() == b.write_name() &&
		a.write_cn() == b.write_cn() &&
		a.write_fee() == b.write_fee();
	}

bool operator!=(Patron& a, Patron& b) { // "Not equal to" operator to use with patrons
	return !(a == b);
}

void operator<<(ostream& os, Patron& n) {
	os << n.write_name() << endl << n.write_cn() << endl << n.write_fee() << endl;
}

vector<string> patron_fee(const vector<Patron>& p) { // Returns vector with patrons that owe fees
	vector<string> owe; // To hold patrons with fees
	for (int i = 0; i < p.size(); i++) {
		if (p[i].check_fee()) owe.push_back(p[i].write_name());
	}
	return owe;
}

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

bool operator!=(Book& a, Book& b) { // "Not equal to" operator to use with books
	return !(a == b);
}

void operator<<(ostream& os, Book& n) {
	os << n.write_title() << endl << n.write_author() << endl << n.write_ISBN() << endl << n.write_genre();
}

class Library {
public:
	Library()
	:patrons{}, books{} 
	{
	}

	void add_book(Book b);
	void add_patron(Patron p);
	void check_out(Patron p, Book b); // Checks out the book
	bool find_book(Book b);
	bool find_patron(Patron b);
	class Library_error{};
	vector<Book> write_book() {return books;}; // Returns the vector of books in library
	vector<Patron> write_patron() {return patrons;}; // Returns the vector of patrons in library
private:
	struct Transaction { // Library transactions
		Book b;
		Patron p;
		Date d;
	};
	vector<Transaction> transactions; // Holds all transactions
	vector<Patron> patrons;
	vector<Book> books;
};

void Library::add_book(Book b) { // Adds book into the library
	if (find_book(b)) throw Library_error{};
	books.push_back(b);
}

void Library::add_patron(Patron p) { // Adds new patron into the library
	if (find_patron(p)) throw Library_error{};
	patrons.push_back(p);
}

void Library::check_out(Patron p, Book b) { // Checks out a book in the library
	if (!find_book(b)) throw Library_error{};

	if (!find_patron(p)) throw Library_error{};

	if (p.check_fee()) { // Check if patron owes a fee
		char ch;
		cout << "This patron owes fee. Do you want to issue him the book(s)? (y or n)" << endl;
		cin >> ch;
		if (ch == 'n') return;
		if (ch != 'y') error("Wrong character detected\n");
	}

	b.check_book(true);
	transactions.push_back(Transaction {b, p, Date{}});
}

bool Library::find_book(Book b) { // Searches for the book in the library
	for (Book x : books) { 
		if (b == x) return true;
	}
	return false;
}

bool Library::find_patron(Patron b) { // Searches for the patron in the library
	for (Patron x : patrons) { 
		if (b == x) return true;
	}
	return false;
}

int main() try {
	Library l;
	l.add_book(Book {"987f", "The Witcher", "Andrzej Sapkowski", Genre::fiction, 1990, 0});
	l.add_patron(Patron {"Charles Dickens", 210817, 10});

	vector<Patron> patron = l.write_patron();
	vector<Book> books = l.write_book();

	l.check_out(patron[0], books[0]);

	vector<string> patronfee = patron_fee(l.write_patron());

	for (string x : patronfee) cout << x << endl;

	Date dd = Date {1992, Month::Feb, 29};

	dd.add_year(1);

	cout << dd;
}

catch (Book::Invalid) {
	cerr << "Invalid data provided" << endl;
}
catch (Library::Library_error) {
	cerr << "No such patron or a book in the library" << endl;
}