#pragma once
#include <iostream>
#include <string>
#define MAX_LENGTH 100

using namespace std;

class Person {
	string pib;
	int day, month, year, age;
public:
	Person();
	Person(string& pib1, int& day1, int& month1, int& year1);
	void set_all(string& pib, int& day, int& month, int& year);
	string get_pib();
	int get_age();
	virtual void findRank() = 0;
};

class Student : public Person {
	int num_disciplines;
	string group;
	string discipline[MAX_LENGTH];
	int discipline_rank[MAX_LENGTH];
	int rank;
public:
	Student();
	Student(int& num, string& group1, string& pib1, int& day1, int& month1, int& year1);
	void findRank();
	void set_disciplines();
	void infoS();
	int search(Student* student, int n);
};

class Teacher : public Person {
	int num_t_disciplines;
	string name_discipline[MAX_LENGTH];
	int discipline_t_rank[MAX_LENGTH];
	int t_rank;
public:
	Teacher();
	Teacher(int& num, string& pib1, int& day1, int& month1, int& year1);
	void infoT();
	void findRank();
	void set_t_disciplines();
};