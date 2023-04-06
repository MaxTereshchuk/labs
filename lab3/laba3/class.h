#pragma once
#include <iostream>
#include <string>
#include <cstring>
#define MAX_LENGTH 1000

using namespace std;

class Text {
	string text;
public:
    Text();
    void add_str(string line);
    void print_str();
    string find_Longest_Line();
};

void create_text(Text* texts, int n);
void print_text(Text* texts, int n);
void print_max_text_length(Text* texts, int n);
void search_max_length(Text* texts, int n);
