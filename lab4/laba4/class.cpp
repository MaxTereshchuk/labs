#include "class.h"

roman_numerals::roman_numerals() {
	number = "";
}

roman_numerals::roman_numerals(string& number) {
	this->number = number;
}

string roman_numerals::getRoman() {
	return number;
}

string roman_numerals::Roman(int arab) {
	const string Rom[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I", "" };
	const int Ar[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 0 };
	string roman;
	int i = 0;
	while (arab > 0) {
		while (Ar[i] <= arab) { roman += Rom[i]; arab -= Ar[i]; }
		++i;
	}
	return roman;
}

int roman_numerals::Arab(string roman){
	const string Rom[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I", "" };
	const int Ar[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 0 };
	int arab = 0, i = 0;
	while (roman != "") {
		while (Rom[i] == roman.substr(0, Rom[i].length())) {
			roman.replace(0, Rom[i].length(), "");
			arab += Ar[i];
		}
		++i;
	}
	return arab;
}

roman_numerals roman_numerals::operator +=(string other) {
	int result = this->Arab(number);
	int rak = Arab(other);
	number = Roman(result + rak);
	return *this;

}

roman_numerals roman_numerals::operator ++(int other){
	int res = Arab(number);
	++res;
	this->number = Roman(res);
	return *this;
}

roman_numerals roman_numerals::operator +(roman_numerals& other) {
	int var1 = Arab(this->number);
	int var2 = Arab(other.number);

	int var3 = 0;
	var3 = var1 + var2;
	string temp = Roman(var3);
	return temp;
}