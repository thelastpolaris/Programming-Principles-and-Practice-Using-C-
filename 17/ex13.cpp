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
          God(const std::string& n, std::string m, std::string v, std::string w, God* p = nullptr, God* s = nullptr)
                    : name{n}, mythology{m}, vehicle{v}, weapon{w}, prev{p}, succ{s} { }

          God* insert(God* n) ;                                   // insert n before this object

          God* add(God* n) ;                                       // insert n after this object
          God* add_ordered(God* n);
          God* erase() ;                                                  // remove this object from list
          //God* find(const std::string& s);                          // find s in list
         // const God* find(const std::string& s) const;    // find s in const list (see §18.5.1)

          //God* advance(int n);                          // move n positions in list

          God* next() const { return succ; }
          God* previous() const { return prev; }
          std::string name;
          std::string mythology;
          std::string vehicle;
          std::string weapon;
private:
          God* prev;
          God* succ;
};

God* God::insert(God* n) { // Insert n before this object, return n
	if (n==nullptr) return this;
    if (this==nullptr) return n;
	n->prev = prev;           // p’s predecessor becomes n’s predecessor
    if(prev) prev->succ = n;           // n comes after what used to be p’s predecessor
    
    n->succ = this;                        // p comes after n
    prev = n;                        // n becomes p’s predecessor
	return n;
}

God* God::add(God* n) { //Insert n after this object, return n
	if (n==nullptr) return this;
    if (this==nullptr) return n;
	n->prev = this;           // p’s predecessor becomes n’s predecessor
    if(succ) succ->prev = n;           // n comes after what used to be p’s predecessor
    
    n->succ = succ;                        // p comes after n
    succ = n;                        // n becomes p’s predecessor
	return n;
}

God* God::erase() {
	if(this==nullptr) return this;
	if(succ) succ->prev = prev;
	if(prev) prev->succ = succ;
	return succ;
}

God* add_ordered(God* n) {
	
	n->name.
}

/*God* God::find(const std::string& v) {
	God* p = this;
	while(p) {
		if(p->value == v) return p;
		p = p->next();
	}
	return nullptr;
}*/

/*const God* God::find(const std::string& s) const{
	const God* p = this;
	while(p) {
		if(p->value == s) return p;
		p = p->next();
	}
	return nullptr;
}*/

/*God* God::advance(int n) {
	if(this == nullptr) return this;
	God* p = this;
	if (0 < n) {
		while(n--) {
			if(succ == nullptr) return nullptr;
			p = succ;
		}
	}
	else if (n < 0) {
		while(n++) {
			if(prev == nullptr) return nullptr;
			p = prev;
		}
	}
	return p;
}*/

void print_all(God* p)
{
	while(p) {
	std::cout << "{ "<< p->name << ", " << p->mythology << ", " << p->vehicle << ", " << p->weapon << " }\n";
	p = p->next();
	}
	
}

int main() {
	God* gods = new God{"Zeus", "Greek", "", "lightning"};
	gods = gods->insert(new God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"});
	gods = gods->insert(new God{"Thor", "Norse", "", "Mjölnir"});
	gods = gods->insert(new God{"Heimdall", "Norse", "", "Hofund"});

	gods = gods->insert(new God{"Helios", "Greek", "Chariot of the sun", ""});
	gods = gods->insert(new God{"Ares", "Greek", "", "Spear and Shield"});

	gods = gods->insert(new God{"Saturn", "Roman", "", ""});
	gods = gods->insert(new God{"Jupiter", "Roman", "", "Thunderbolt"});
	gods = gods->insert(new God{"Mars", "Roman", "", ""});
	print_all(gods);
}
