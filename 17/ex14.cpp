/* Chapter 17 Exercise 14
Could the “list of gods” example from §17.10.1 have been written using a singly-Link_singleed list; that is, could we have left the prev member 
out of Link_single? Why might we want to do that? For what kind of examples would it make sense to use a singly-Link_singleed list? Re-implement that 
example using only a singly-linked list.
*/
#include <iostream>
#include <string>
#include <stdexcept>

struct God {
    God(const std::string& n, const std::string& m, const std::string& v, const std::string& w)
    : name{n}, mythology{m}, vehicle{v}, weapon{w} { }
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
};

class Link_single {
public:
          God value;

          Link_single(God v, Link_single* p = nullptr)
                    :value{v}, succ{p} { }

          Link_single* insert(Link_single* n);                                   // insert n before this object
          Link_single* erase();                                                  // remove this object from list
          Link_single* find(const std::string& s);                          // find s in list
          const Link_single* find(const std::string& s) const;    // find s in const list (see §18.5.1)
          Link_single* add_ordered(Link_single* n);

          Link_single* advance(int n);                          // move n positions in list

          Link_single* next() const { return succ; }
          Link_single* extract(const std::string& s);
private:
      	   Link_single* succ;
};

/* Non-member functions */

void print_all(Link_single* p)
{
	if(p == 0) return;
	Link_single* cp = p;
	while(cp) {
		std::cout << "{ "<< cp->value.name << ", " << cp->value.mythology << ", " << cp->value.vehicle << ", " << cp->value.weapon << " }\n";
		cp = cp->next();
	}	
}

void to_lower(std::string& s) {
	for(int i = 0; i < s.size(); ++i) if(s[i] >= 65 && s[i] <= 90) s[i] += 32;
}

bool string_compare(const std::string& f, const std::string& s) {
	int c = 0;
	std::string ff = f;
	std::string ss = s;
	to_lower(ff);
	to_lower(ss);
	while(c < ff.size() && c < ss.size()) {
		if((ff[c] - ss[c]) < 0) return 0; // if letter of first word is higher in lexicographical order return 0
		else if ((ff[c] - ss[c]) >= 1) return 1; // if it is lower return 1
		c++;
	}
	return 0;
}

Link_single* Link_single::insert(Link_single* n) { // Insert n after this object, return n
	if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->succ = this->succ;
	succ = n;
	return this;
}

Link_single* Link_single::erase() {
	if(this==nullptr) return this;
	succ = succ->succ;
	return this;
}

Link_single* Link_single::find(const std::string& v) {
	Link_single* p = this;
	while(p) {
		if(p->value.name == v) return p;
		p = p->next();
	}
	return nullptr;
}

const Link_single* Link_single::find(const std::string& s) const{
	const Link_single* p = this;
	while(p) {
		if(p->value.name == s) return p;
		p = p->next();
	}
	return nullptr;
}

Link_single* Link_single::advance(int n) {
	if(this == nullptr) return this;
	Link_single* p = this;
	if (n > 0) {
		while(n--) {
			if(succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else return 0;
	return p;
}


Link_single* Link_single::add_ordered(Link_single* n) {
	if (n==0) {
		return this;
	}
	n->succ = 0; //set n's successor to 0
    if (this==0) {  // new list
        return n;
    }
	else {
		Link_single* t = this;
		if (string_compare(t->value.name, n->value.name)) {
			n->succ = this;
			return n;
		}
		else if(t->next() == 0) {
			t->insert(n);
			return this;
		}
		while(t->next() && string_compare(n->value.name, t->next()->value.name)) {
			if (t->succ == 0) {
				n->succ = 0;
				t->insert(n);
			}
			t = t->next();
		}
		t->insert(n);
	}
	return this;
}

Link_single* Link_single::extract(const std::string& s) {
	if (this == 0) return this;
	Link_single* l = this;
	if(value.name == s) {
			Link_single* lp = new Link_single{value};
			return lp;
		}
	while(l) {
		if(l->succ->value.name == s) {
			Link_single* ls = l->succ;
			l->erase(); // delete object that needs to be extracted
			return ls;
		}

		if (l->succ) l = l->succ;
	}

	return 0;
}

int main() try {
	Link_single* gods = new Link_single {God{"Zeus", "Greek", "", "lightning"}};
	gods = gods->insert(new Link_single {God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}});
	
	gods = gods->insert(new Link_single {God{"Thor", "Norse", "", "Mjölnir"}});
	gods = gods->insert(new Link_single {God{"Heimdall", "Norse", "", "Hofund"}});

	gods = gods->insert(new Link_single {God{"Helios", "Greek", "Chariot of the sun", ""}});
	gods = gods->insert(new Link_single {God{"Ares", "Greek", "", "Spear and Shield"}});

	gods = gods->insert(new Link_single {God{"Saturn", "Roman", "", ""}});
	gods = gods->insert(new Link_single {God{"Jupiter", "Roman", "", "Thunderbolt"}});
	gods = gods->insert(new Link_single {God{"Mars", "Roman", "", ""}});

	print_all(gods);
	std::cout<< '\n';

	Link_single* norse_gods = 0;
	
	norse_gods = norse_gods->add_ordered(gods->extract("Heimdall"));
	norse_gods = norse_gods->add_ordered(gods->extract("Odin"));
	norse_gods = norse_gods->add_ordered(gods->extract("Thor"));

	Link_single* greek_gods = 0;
	
	greek_gods = greek_gods->add_ordered(gods->extract("Zeus"));
	greek_gods = greek_gods->add_ordered(gods->extract("Helios"));
	greek_gods = greek_gods->add_ordered(gods->extract("Ares"));

	Link_single* roman_gods = 0;

	roman_gods = roman_gods->add_ordered(gods->extract("Saturn"));
	roman_gods = roman_gods->add_ordered(gods->extract("Jupiter"));
	roman_gods = roman_gods->add_ordered(gods->extract("Mars"));



	//Print gods
	print_all(norse_gods);
	std::cout<< '\n';
	print_all(greek_gods);
	std::cout<< '\n';
	print_all(roman_gods);
}
catch(std::runtime_error& e) {
	std::cout << e.what() << '\n';
}
catch(...) {
	std::cout << '\n';
}
