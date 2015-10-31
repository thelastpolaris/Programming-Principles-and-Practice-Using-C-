#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	/*//Questions 1 - 8
	int birth_year = 1992;
	int a, b, c, d;
	cout << '|' << setw(4) << birth_year << setw(8) << "(decimal)" << hex << '|' << setw(4) << birth_year << setw(8) << "(hexadecimal)" << oct << '|' << setw(4) << birth_year << setw(8) << "(octal)" << '|' << '\n';
	//cin >> a >> oct >> b >> hex >> c >> d;
	cout.unsetf(ios::oct);
	//cout << a << '\t' << b << '\t'<< c << '\t'<< d << '\n' ;

	//Question 9
	cout << 1234567.89 << '\t' << fixed << 12345678.89 << '\t' << scientific << 1234567.89 << endl;
	*/

	//Question 10
	cout << isalnum('d');
	cout << setw(8) << "Jack" << '|' << setw(12) << "Jones" << '|' << setw(12) << "+77089564512" << '|' << setw(16) << "e@e.com" << endl;
	cout << setw(8) << "Abraham" << '|' << setw(12) << "Lincoln" << '|' << setw(12) << "+77056369565" << '|' << setw(16) << "e@com.com" << endl;
	cout << setw(8) << "George" << '|' << setw(12) << "Washington" << '|' << setw(12) << "+13456589858" << '|' << setw(16) << "e@america.com" << endl;
	cout << setw(8) << "Bill" << '|' << setw(12) << "Clinton" << '|' << setw(12) << "+13458975641" << '|' << setw(16) << "e@clinton.com" << endl;
	cout << setw(8) << "George" << '|' << setw(12) << "Bush" << '|' << setw(12) << "+13244568789" << '|' << setw(16) << "e@byob.com" << endl;
	cout << setw(8) << "Barack" << '|' << setw(12) << "Obama" << '|' << setw(12) << "+15845698574" << '|' << setw(16) << "e@irafukrsyr.com" << endl;
}
