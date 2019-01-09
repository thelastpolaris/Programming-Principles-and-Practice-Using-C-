/* Chapter 11 Exercise 9
Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary text file into binary and 
one program that reads binary and converts it to text. Test these programs by comparing a text file with what you get 
by converting it to binary and back.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using std::string;

template<class T>
char* as_bytes(T& i)                          // treat a T as a sequence of bytes
{
          void* addr = &i;                      // get the address of the first byte
                                                                 // of memory used to store the object
          return static_cast<char*>(addr);        // treat that memory as bytes
}

void error(string s) {
	throw std::runtime_error(s);
}

int main() try {
	std::cout << "Please input the name of file\n";
	string iname;
	std::cin >> iname;
	std::ifstream ifs {iname, std::ios_base::binary};
	if (!ifs) error("Wrong filename");
	string out;
	string oname;
	std::cout << "Please input the name of output file\n";
	std::cin >> oname;
	std::ofstream ofs {oname, std::ios_base::binary};
	if (!ofs) error("Wrong filename");
	for (int x; ifs.read(as_bytes(x),sizeof(int));) ofs << x << std::endl;
}
catch (std::runtime_error& e) {
	std::cout << e.what() << std::endl;
}