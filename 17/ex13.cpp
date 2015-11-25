/* Chapter 17 Exercise 13
Modify the Link class from §17.10.1 to hold a value of a struct God. struct God should have members of type string: name, mythology, vehicle, 
and weapon. For example, God{"Zeus", "Greek", "", "lightning"} and God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", 
"Spear called Gungnir"}. Write a print_all() function that lists gods with their attributes one per line. Add a member function add_ordered() 
that places its new element in its correct lexicographical position. Using the Links with the values of type God, make a list of gods from 
three mythologies; then move the elements (gods) from that list to three lexicographically ordered lists — one for each mythology.
*/
#include <iostream>
#include <string>

struct God {
    God(const std::string& n, const std::string& m, const std::string& v, const std::string& w)
    : name{n}, mythology{m}, vehicle{v}, weapon{w} { }
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
};

class Link {
public:
          God value;

          Link(God v, Link* p = nullptr, Link* s = nullptr)
                    :value{v}, prev{p}, succ{s} { }

          Link* insert(Link* n) ;                                   // insert n before this object
          Link* add(Link* n) ;                                       // insert n after this object
          Link* erase() ;                                                  // remove this object from list
          Link* find(const std::string& s);                          // find s in list
          const Link* find(const std::string& s) const;    // find s in const list (see §18.5.1)
          Link* add_ordered(Link* n);

          Link* advance(int n);                          // move n positions in list

          Link* next() const { return succ; }
          Link* previous() const { return prev; }
          Link* extract();
private:
          Link* prev;
          Link* succ;
};

/*Non-member functions */

Link* to_start(Link* n) {
	while(n->next()) {
		n = n->next();
	}
	return n;
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

void print_all(Link* p)
{
	if(p == 0) return;
	Link* cp = p;
	while (cp->next()) cp = cp->next();
	while(cp) {
		std::cout << "{ "<< cp->value.name << ", " << cp->value.mythology << ", " << cp->value.vehicle << ", " << cp->value.weapon << " }\n";
		cp = cp->previous();
	}
	
}

Link* Link::insert(Link* n) { // Insert n after this object, return n
	if (n==nullptr) return this;
    if (this==nullptr) return n;
	n->prev = prev;           // p’s predecessor becomes n’s predecessor
    if(prev) prev->succ = n;           // n comes after what used to be p’s predecessor
    
    n->succ = this;                        // p comes after n
    prev = n;                        // n becomes p’s predecessor
	return n;
}

Link* Link::add(Link* n) { //Insert n before this object, return n
	if (n==nullptr) return this;
    if (this==nullptr) return n;
	n->prev = this;          
    if(succ) succ->prev = n;          
    
    n->succ = succ;                    
    succ = n;                       
	return n;
}

Link* Link::erase() {
	if(this==nullptr) return this;
	if(succ) succ->prev = prev;
	if(prev) prev->succ = succ;
	return succ;
}

Link* Link::find(const std::string& v) {
	Link* p = this;
	while(p) {
		if(p->value.name == v) return p;
		p = p->next();
	}
	return nullptr;
}

const Link* Link::find(const std::string& s) const{
	const Link* p = this;
	while(p) {
		if(p->value.name == s) return p;
		p = p->next();
	}
	return nullptr;
}

Link* Link::advance(int n) {
	if(this == nullptr) return this;
	Link* p = this;
	if (0 < n) {
		while(n--) {
			if(succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while(n++) {
			if(prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}


Link* Link::add_ordered(Link* n) {
	if (n==0) {
		return this;
	}
    if (this==0) {  // new list
        n->succ = 0;
        n->prev = 0;
        return n;
    }
	else {
		Link* t = to_start(this);
		if(string_compare(t->value.name, n->value.name)) { // if the word is higher than the first word in link's list
			t->add(n);
			return n;		
		}
		while(string_compare(n->value.name, t->value.name)) { // start to search for the word that is higher than ours
			if(!(t->previous())) {
				t->insert(n);
				return this;
			}
			t = t->previous();
		}
		t->add(n);
	}
	return this;
}

Link* Link::extract() {
	if (this == 0) return this;
	Link* l = this;
	this->erase(); // delete object that needs to be extracted
	l->succ = 0;
	l->prev = 0;
	return l;
}

int main() {
	Link* gods = new Link {God{"Zeus", "Greek", "", "lightning"}};
	gods = gods->insert(new Link { God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}});
	
	gods = gods->insert(new Link {God{"Thor", "Norse", "", "Mjölnir"}});
	gods = gods->insert(new Link {God{"Heimdall", "Norse", "", "Hofund"}});

	gods = gods->insert(new Link {God{"Helios", "Greek", "Chariot of the sun", ""}});
	gods = gods->insert(new Link {God{"Ares", "Greek", "", "Spear and Shield"}});

	gods = gods->insert(new Link {God{"Saturn", "Roman", "", ""}});
	gods = gods->insert(new Link {God{"Jupiter", "Roman", "", "Thunderbolt"}});
	gods = gods->insert(new Link {God{"Mars", "Roman", "", ""}});

	print_all(gods);
	std::cout<< '\n';

	Link* norse_gods = 0;

	norse_gods = norse_gods->add_ordered(gods->find("Thor")->extract());
	norse_gods = norse_gods->add_ordered(gods->find("Odin")->extract());	
	norse_gods = norse_gods->add_ordered(gods->find("Heimdall")->extract());

	Link* greek_gods = 0;
	
	greek_gods = greek_gods->add_ordered(gods->find("Zeus")->extract());
	greek_gods = greek_gods->add_ordered(gods->find("Helios")->extract());
	greek_gods = greek_gods->add_ordered(gods->find("Ares")->extract());

	Link* roman_gods = 0;

	roman_gods = roman_gods->add_ordered(gods->find("Saturn")->extract());
	roman_gods = roman_gods->add_ordered(gods->find("Jupiter")->extract());
	roman_gods = roman_gods->add_ordered(gods->find("Mars")->extract());

	//Print gods
	print_all(norse_gods);
	std::cout<< '\n';
	print_all(greek_gods);
	std::cout<< '\n';
	print_all(roman_gods);
}
