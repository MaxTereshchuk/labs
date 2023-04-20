#pragma once
#include <iostream>
#include <string>

using namespace std;

class roman_numerals {
	string number;
public:
	roman_numerals();
	roman_numerals(string& number);
	string getRoman();
	string Roman(int arab);
	int Arab(string roman);
	roman_numerals operator +(roman_numerals& other);
	roman_numerals operator +=(string other);
	roman_numerals operator ++(int other);
};