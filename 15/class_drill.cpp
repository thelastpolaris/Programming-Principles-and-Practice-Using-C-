#include "../14/14.h"
#include <iomanip>

struct Person {
	Person(string f, string l, int a);
	Person() :first_name{"n"},last_name{"n"},age{0} {}
	string mName() const {return first_name + " " + last_name;};
	string mFirst_name() const {return first_name;};
	string mLast_name() const {return last_name;};
	int mAge() const {return age;};
private:
	string first_name;
	string last_name;
	int age;
};

Person::Person(string f, string l, int a)
:first_name{f}, last_name{l}, age{a} {
	if (age < 0 || age >= 150) {
		error("wrong date");
	}
	string err = ";:\"[]*&^%$#@!";
	string name = f + l;
	for (int i = 0; i < name.length(); ++i) {
		for (int c = 0; c < err.length(); ++c) {
			if (name[i] == err[c]) error("wrong character");
		}
	}
}

istream& operator>>(istream& is, Person& p) {
	string f;
	string l;
	int a;
	if (is >> f >> l >> a) {
		p = Person{f,l,a};
	}
	else {
		is.clear(ios_base::failbit);
	}
	return is;
}

ostream& operator<<(ostream& os, Person& p) {
	os << p.mName() << " " << p.mAge();
	return os;
}

int main()  {	
	Person p;
	vector<Person> persons;
	while (cin >> p) {
		persons.push_back(p);
	}
	for (Person x : persons) cout << x << " ";
}
