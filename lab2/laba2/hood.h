#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct University {
    char name[50];
    char city[50];
    int accreditation;
    int num_faculties;
    char faculty_names[50][50];
    int num_students[50];
};


string get_filename();
string get_new_filename();
void addUniversities(University*& universities, int& num_universities, string filename);
void read(string filename);
void search(University* universities, int num_universities);
void check_accreditation(string new_filename, string filename);
void read_new(string new_filename);
