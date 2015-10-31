/*// bad_alloc example
#include <iostream>     // std::cout
#include <new>          // std::bad_alloc

int main () {
  try
  {
    int* myarray= new int[100000000];
  }
  catch (std::bad_alloc& ba)
  {
    std::cerr << "bad_alloc caught: " << ba.what() << '\n';
  }
  return 0;
}*/
// bad_cast example
/*#include <iostream>       // std::cout
#include <typeinfo>       // std::bad_cast

class Base {virtual void member(){}};
class Derived : Base {};

int main () {
  try
  {
    Base b;
    Derived& rd = dynamic_cast<Derived&>(b);
  }
  catch (std::bad_cast& bc)
  {
     std::cerr << "bad_cast caught: " << bc.what() << '\n';
  }
  return 0;
}*/
// bad_exception example
/*#include <iostream>       // std::cerr
#include <exception>      // std::bad_exception, std::set_unexpected

void myunexpected () {
  std::cerr << "unexpected handler called\n";
  throw;
}

void myfunction () throw (int,std::bad_exception) {
  throw 'x'; // throws char (not in exception-specification)
}

int main (void) {
  std::set_unexpected (myunexpected);
  try {
    myfunction();
  }
  catch (int) { std::cerr << "caught int\n"; }
  catch (std::bad_exception be) { std::cerr << "caught bad_exception\n"; }
  catch (...) { std::cerr << "caught some other exception\n"; }
  return 0;
}*/
/*#include <iostream>     // std::cout
#include <functional>   // std::function, std::plus, std::bad_function_call

int main () {
  std::function<int(int,int)> foo = std::plus<int>();
  std::function<int(int,int)> bar;

  try {
    std::cout << foo(10,30) << '\n';
    std::cout << bar(10,20) << '\n';
  }
  catch (std::bad_function_call& e)
  {
    std::cout << "ERROR: Bad function call\n";
  }

  return 0;
}*/
/*// bad_typeid example
#include <iostream>       // std::cout
#include <typeinfo>       // operator typeid, std::bad_typeid

class Polymorphic {virtual void Member(){}};

int main () {
  try
  {
    Polymorphic * pb = 0;
	std::cout << typeid(*pb).name();
  }
  catch (std::bad_typeid& bt)
  {
    std::cerr << "bad_typeid caught: " << bt.what() << '\n';
  }
  return 0;
}*/
/*// invalid_argument example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::invalid_argument
#include <bitset>         // std::bitset
#include <string>         // std::string

int main (void) {
  try {
    // bitset constructor throws an invalid_argument if initialized
    // with a string containing characters other than 0 and 1
    std::bitset<5> mybitset (std::string("012"));
  }
  catch (const std::invalid_argument& ia) {
	  std::cerr << "Invalid argument: " << ia.what() << '\n';
  }
  return 0;
}*/
/*// length_error example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::length_error
#include <vector>         // std::vector

int main (void) {
  try {
    // vector throws a length_error if resized above max_size
    std::vector<int> myvector;
    myvector.resize(myvector.max_size() + 1);
  }
  catch (const std::length_error& le) {
	  std::cerr << "Length error: " << le.what() << '\n';
  }
  return 0;
}*/
/*// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector

int main (void) {
  std::vector<int> myvector(10);
  try {
    myvector.at(20)=100;      // vector::at throws an out-of-range
  }
  catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }
  return 0;
}*/
/*#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
int main()
try {
          std::vector<int> v;                                    // a vector of ints
          for (int x; std::cin>>x; )
                    v.push_back(x);                      // set values
          std::cout << v.size() << std::endl;
          for (int i = 0; i<=v.size(); ++i) {         // print values
                std::cout << "v[" << i <<"] == " << v[i]; 
               	std::cout << v.at(i) << '\n';
           }	
} catch (std::out_of_range) {
          std::cerr << "Oops! Range error\n";
          return 1;
} catch (...) {                                                // catch all other exceptions
          std::cerr << "Exception: something went wrong\n";
          return 2;
}*/
/*#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range

void f(void) {
	throw std::overflow_error("it happened");
}

int main()
try {
	f();
}
catch(const std::overflow_error& oe) {
	std::cout << oe.what() << std::endl;
}*/
#include <iostream>
#include <system_error>
 
int main()
{
    try
    {
        throw std::system_error(EDOM, std::system_category());
    }
    catch (const std::system_error& error)
    {
        std::cout << "Error: " << error.code()
        << " - " << error.code().message() << '\n';
    }
}*/