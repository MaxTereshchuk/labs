#include "class.h"

int main() {
	roman_numerals N1;
	roman_numerals N2;
	roman_numerals N3;
	string a, b;

	cout << "prefixed (++) - to increment N1." << endl;
	cout << "(+=) - to increase by the specified amount N2." << endl;
	cout << "(+) - to add N1 and N2 (N3)." << endl;
	cout << "Enter N1,N2 in roman numeral format\n\n";
	cout << "Enter N1: ";
	getline(cin, a);
	N1 = roman_numerals(a);
	cout << "Enter N2: ";
	getline(cin, b);
	N2 = roman_numerals(b);
	cout << "Enter number to add(roman numeral): ";
	string add;
	getline(cin, add);

	N1++;
	N2 += add;
	N3 = N1 + N2;
	int decimalN3 = N3.Arab(N3.getRoman());

	cout << "N1 = " << N1.getRoman() << endl;
	cout << "N2 = " << N2.getRoman() << endl;
	cout << "N3 = " << N3.getRoman() << endl;
	cout << "N3 in Decinal: " << decimalN3 << endl;
}
