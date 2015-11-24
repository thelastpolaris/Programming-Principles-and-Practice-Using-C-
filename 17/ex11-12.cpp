/* Chapter 17 Exercise 11
Complete the “list of gods” example from §17.10.1 and run it.
*/
#include <iostream>
#include <string>

class Link {
public:
          std::string value;

          Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
                    : value{v}, prev{p}, succ{s} { }

          Link* insert(Link* n) ;                                   // insert n before this object
          Link* add(Link* n) ;                                       // insert n after this object
          Link* erase() ;                                                  // remove this object from list
          Link* find(const std::string& s);                          // find s in list
          const Link* find(const std::string& s) const;    // find s in const list (see §18.5.1)

          Link* advance(int n);                          // move n positions in list

          Link* next() const { return succ; }
          Link* previous() const { return prev; }
private:
          Link* prev;
          Link* succ;
};

Link* Link::insert(Link* n) { // Insert n before this object, return n
	if (n==nullptr) return this;
    if (this==nullptr) return n;
	n->prev = prev;           // p’s predecessor becomes n’s predecessor
    if(prev) prev->succ = n;           // n comes after what used to be p’s predecessor
    
    n->succ = this;                        // p comes after n
    prev = n;                        // n becomes p’s predecessor
	return n;
}

Link* Link::add(Link* n) { //Insert n after this object, return n
	if (n==nullptr) return this;
    if (this==nullptr) return n;
	n->prev = this;           // p’s predecessor becomes n’s predecessor
    if(succ) succ->prev = n;           // n comes after what used to be p’s predecessor
    
    n->succ = succ;                        // p comes after n
    succ = n;                        // n becomes p’s predecessor
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
		if(p->value == v) return p;
		p = p->next();
	}
	return nullptr;
}

const Link* Link::find(const std::string& s) const{
	const Link* p = this;
	while(p) {
		if(p->value == s) return p;
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
}

void print_all(Link* p)
{
	std::cout << "{ ";
	while(p) {
		std::cout << p->value;
		if(p = p->next()) std::cout << ", ";
	}
	std::cout << " }\n";
}

int main() {
	Link* norse_gods = new Link {"Thor"};
	norse_gods = norse_gods->insert(	new Link {"Odin"});
	norse_gods = norse_gods->insert(new Link {"Zeus"});
	norse_gods = norse_gods->insert(new Link {"Loki",});
	Link* greek_gods = new Link {"Hera"};
	greek_gods = greek_gods->insert(new Link {"Athena"});
	greek_gods = greek_gods->insert(new Link {"Mars"});
	greek_gods = greek_gods->insert(new Link {"Poseidon"});

	Link* p = greek_gods->find("Mars");
	//std::cout << norse_gods->succ->value << " : " << greek_gods->succ->value << std::endl;
	if (p) p->value = "Ares";
	//std::cout << norse_gods->succ->value << " : " << greek_gods->succ->value << std::endl;
	Link* p2 = norse_gods->find("Zeus");
	if (p2) {
		if (p2 == norse_gods) norse_gods = norse_gods->next();
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}
	//std::cout << norse_gods->value << " : " << greek_gods->succ->value << std::endl;
	print_all(norse_gods);
	greek_gods = greek_gods->add(new Link {"Hades"});
	greek_gods = greek_gods->previous();
	print_all(greek_gods);

	/*Chapter 17 Exercise 12
	Why did we define two versions of find()?
	*/

	const Link* const_test = new const Link {"Test"};
	const Link* sp = const_test->find("Test");
	std::cout << sp->value << std::endl;
	std::cout << greek_gods->previous() << std::endl;
}
