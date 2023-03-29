#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

#define MAX_LINE_LENGTH 1000

void create_file_p(const char* inFile);
int search_substrings_p(const char* inFile, const char* outFile);
int print_strings_p(const char* outFile);

