#include "func.h"

int main() {
	int n = 0, m = 0;
	cout << "Create n students and m teachers" << endl;
	cout << "For students, calculate their average rating score, and for teachers, the average popularity rating score" << endl;

	cout << "\nEnter number of students: ";
	cin >> n;
	Student* student = new Student[n];
	for (int i = 0; i < n; i++) {
		cin.ignore();
		int number = 0, day = 0, month = 0, year = 0;
		char s;
		string nameGroup, name;
		cout << "\nEnter the name of student number " << i+1 << ": ";
		getline(cin, name);
		cout << "Enter birthday: ";
		cin >> day >> s >> month >> s >> year;
		student[i].set_all(name, day, month, year);
		cout << "Enter name of group: ";
		cin >> nameGroup;
		cout << "Enter number of disciplines: ";
		cin >> number;
		
		student[i] = Student(number, nameGroup, name, day, month, year);

		student[i].set_disciplines();

		student[i].findRank();
	}

	cin.ignore();
	cout << "\nEnter number of Teachers: ";
	cin >> m;
	Teacher* teacher = new Teacher[m];
	for (int i = 0; i < m; i++) {
		cin.ignore();
		int number1 = 0, day1 = 0, month1 = 0, year1 = 0;
		char s1;
		string nameGroup1, name1;
		cout << "Enter the name of teacher number " << i + 1 << ": ";
		getline(cin, name1);
		cout << "Enter birthday: ";
		cin >> day1 >> s1 >> month1 >> s1 >> year1;
		teacher[i].set_all(name1, day1, month1, year1);
		cout << "Enter number of disciplines: ";
		cin >> number1;

		teacher[i] = Teacher(number1, name1, day1, month1, year1);

		teacher[i].set_t_disciplines();
		
		teacher[i].findRank();
	}

	int kilk = student->search(student, n);

	cout << "\nSudents:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "\nName: " << student[i].get_pib() << endl;
		cout << "Age: " << student[i].get_age() << endl;
		student[i].infoS();
	}

	cout << "\nTeachers:" << endl;
	for (int i = 0; i < m; i++) {
		cout << "\nName: " << teacher[i].get_pib() << endl;
		cout << "Age: " << teacher[i].get_age() << endl;
		teacher[i].infoT();
	}

	cout << "\nNumber of underage students with academic debts: ";
	cout << kilk;
	delete[] student;
	delete[] teacher;
}