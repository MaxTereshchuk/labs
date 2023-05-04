#include "func.h"

Person::Person() {
	pib = "";
	day = 0;
	month = 0;
	year = 0;
}

Person::Person(string& pib1, int& day1, int& month1, int& year1) {
	this->pib = pib1;
	this->day = day1;
	this->month = month1;
	this->year = year1;
}

Student::Student() {
	num_disciplines = 0;
	group = "";
	discipline[MAX_LENGTH];
	discipline_rank[MAX_LENGTH];
	rank = 0;
}

Student::Student(int& num, string& group1,string& pib1, int& day1, int& month1, int& year1) : Person(pib1, day1, month1, year1) {
	this->num_disciplines = num;
	this->group = group1;
}

Teacher::Teacher() {
	num_t_disciplines = 0;
	name_discipline[MAX_LENGTH];
	discipline_t_rank[MAX_LENGTH];
	t_rank = 0;
}

Teacher::Teacher(int& num, string& pib1, int& day1, int& month1, int& year1) : Person(pib1, day1, month1, year1) {
	this->num_t_disciplines = num;
}


int Person::get_age() {
	if (month <= 5 && day <= 5) {
		age = 2023 - year;
	}
	else {
		age = 2023 - year - 1;
	}
	return age;
}

string Person::get_pib() {
	return pib;
}

void Person::set_all(string& pib1, int& day1, int& month1, int& year1) {
	pib = pib1;
	day = day1;
	month = month1;
	year = year1;
}

void Student::set_disciplines() {
	for (int i = 0; i < num_disciplines; i++) {
		cin.ignore();
		cout << "Enter name of discipline " << i + 1 << ": ";
		getline(cin, discipline[i]);
		cout << "Enter rank this discipline (1-100): ";
		cin >> discipline_rank[i];
	}
}

void Student::infoS() {
	cout << "Group: " << group << endl;
	cout << "Rank: " << rank << endl;
}

int Student::search(Student* student, int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (student[i].get_age() < 18 && student[i].discipline_rank[i] < 60) {
			counter += 1;
		}
	}
	return counter;
}

void Teacher::set_t_disciplines() {
	cin.ignore();
	for (int i = 0; i < num_t_disciplines; i++) {
		cout << "Enter name of discipline " << i+1 << ": ";
		getline(cin, name_discipline[i]);
		cout << "Enter rank this discipline (1-10): ";
		cin >> discipline_t_rank[i];
	}
}

void Teacher::infoT() {
	cout << "Rank: " << t_rank << endl;
}

void Student::findRank() {
	int all = 0;
	for (int i = 0; i < num_disciplines; i++) {
		all += discipline_rank[i];
	}
	rank = all / num_disciplines;
}

void Teacher::findRank() {
	int all = 0;
	for (int i = 0; i < num_t_disciplines; i++) {
		all += discipline_t_rank[i];
	}
	t_rank = all / num_t_disciplines;
}