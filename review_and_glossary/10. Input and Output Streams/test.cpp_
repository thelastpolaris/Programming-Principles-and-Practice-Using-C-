// Roman Numeral Convert.cpp : main project file.

#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void printValue(char numeral[15])
{
 int RomanValues[7] = {1000,500,100,50,10,5,1};
 char Roman[7] = {'M','D','C','L','X','V','I'};
 int number = 0, ck[15] = {0},len = 0;
 bool ok = false;
 for(int x=0;x<15;x++)
	if (numeral[x] !='\0')
	 len++; //Find how long the numeral input was
	else
	 x=15;

 for(int x=0;x<len;x++)
 {
	ok = false;
	for(int y=0;y<7;y++)
	{
	 if(numeral[x] == Roman[y])
		ok = true; // Making sure the inputs were all Roman numerals
	}
	if( !ok )
	{
	 cout << "Sorry, the '" << numeral[x] << "' is NOT a Roman Numeral." << endl << "Try again.." << endl << endl;
	 return;
	}
 }
 for(int x=0;x<len;x++)
 {
	for(int y=0;y<7;y++)
	{
	 if(numeral[x] == Roman[y])
	 {
		ck[x] = RomanValues[y];// Fill array ck with decimal value of inputted Roman #
	 }
	}
 }
 for(int x=0;x<len;x++)
 {
	if((ck[x+1] > ck[x]))
	{
	 number+=(ck[x+1] - ck[x]); // If number is lower than next number, subtract
   // So IV is 4 and VI is 6
	 x++;
	}
	else
	 number+=ck[x]; // else add
 }
 cout << number<< endl << endl;
}

void Menu()
{
 cout << "\tRoman Numeral Values" << endl << endl;
 cout << "\t\tM = 1000" << endl;
 cout << "\t\tD =  500" << endl;
 cout << "\t\tC =  100" << endl;
 cout << "\t\tL =   50" << endl;
 cout << "\t\tX =   10" << endl;
 cout << "\t\tV =    5" << endl;
 cout << "\t\tI =    1" << endl;

}

void getRoman()
{
 char numeral[15];

 do
 {
	Menu();
	cout << endl << "Please enter a Roman Numeral.\n(Enter 'Q', to end program)" << endl;
	cin >> numeral;
	for(int x=0;x<15;x++)
	 numeral[x] = toupper(numeral[x]);
	if(numeral[0] == 'Q')
	 cout << "Program terminating!" << endl;
	else
	 printValue( numeral);
 }while (numeral[0] != 'Q');
}

int main()
{
 getRoman();
 return 0;
}