#include <iostream>
//#include <iomanip>
#include <bitset>
#include <string>

int int_length(int n) {
	int len = 0;
	for (int i = n; i > 0; len++) {
		i /= 10;
	}
	return len;
}

const int binary_size = 64;

int main() {
	while (true) {
		std::cout << "What type of number do you have?" << std::endl;
		std::cout << "- 1 - decimal" << std::endl;
		std::cout << "- 2 - binary" << std::endl;
		std::cout << "- 3 - hexadecimal" << std::endl;
		std::cout << "- 4 - octal" << std::endl;
		int h = 0;
		std::cin >> h;
		std::cout << "What type of number do you need?" << std::endl;
		std::cout << "- 1 - decimal" << std::endl;
		std::cout << "- 2 - binary" << std::endl;
		std::cout << "- 3 - hexadecimal" << std::endl;
		std::cout << "- 4 - octal" << std::endl;
		int n = 0;
		std::cin >> n;
		std::cout << "Enter the number that needs to be converted" << std::endl;
		switch(h) {
			case 1:
			{	int num = 0;
				std::cin >> num;
				switch(n) {
					case 1:{
						std::cout << num << std::endl;
					}
						break;
					case 2:{
						std::bitset<binary_size> b(num);
						std::cout << b << std::endl;
					}
						break;
					case 3:{
						std::cout << std::hex << num << std::endl;
					}
						break;
					case 4:{
						std::cout << std::oct << num << std::endl;
					}																		
						break;
				}
			
			}break;
			case 2:
			{
				std::string num;
				std::cin >> num;
				std::bitset<binary_size> b(num);
				unsigned long c = b.to_ulong();
				switch(n) {
					case 1:{
						std::cout << c << std::endl;
					}
						break;
					case 2:{
						std::cout << b << std::endl;
					}
						break;
					case 3:{
						std::cout << std::hex << c << std::endl;
					}
						break;
					case 4:{
						std::cout << std::oct << c << std::endl;
					}
						break;
				}
			
			}break;
			case 3:
			{
				int num = 0;
				std::cin.unsetf(std::ios::oct);
				std::cin >> std::hex >> num;
				switch(n) {
					case 1:{
						std::cout << num << std::endl;
					}
						break;
					case 2:{
						std::bitset<binary_size> b(num);
						std::cout << b << std::endl;
					}
						break;
					case 3:{
						std::cout << std::hex << num << std::endl;
					}
						break;
					case 4:{
						std::cout << std::oct << num << std::endl;																		
					}
						break;
				}
				
			}break;
			case 4:
			{
				int num = 0;
				std::cin.unsetf(std::ios::hex);
				std::cin >> std::oct >> num;
				switch(n) {
					case 1:{
						std::cout << num << std::endl;
					}
						break;
					case 2:{
						std::bitset<binary_size> b(num);
						std::cout << b << std::endl;
					}
						break;
					case 3:{
						std::cout << std::hex << num << std::endl;
					}
						break;
					case 4:{
						std::cout << std::oct << num << std::endl;																		
					}
						break;
			}
			
		}break;
	}
}
}

