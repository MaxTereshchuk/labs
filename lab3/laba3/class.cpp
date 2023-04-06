#include "class.h"

void create_text(Text* texts, int n) {
	int answer = 1;

	for (int i = 0; i < n; i++) {
		cout << "Enter text " << i + 1 << ":\n";
		string line;
		while (1) {
			cout << "Input string: ";
			cin.ignore();
			getline(cin, line);
			texts[i].add_str(line);
			cout << "If you want to add to the text enter 1, else enter 2: ";
			cin >> answer;
			if (answer == 2) break;
		}
	}
}


void print_text(Text* texts, int n) {
	cout << "Text: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Text " << i + 1 << ": " << endl;
		texts[i].print_str();
	}
}

void print_max_text_length(Text* texts, int n) {
	cout << "Length: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "The longest line in the text " << i + 1 << ": " << texts[i].find_Longest_Line() << endl;
	}
}

void search_max_length(Text* texts, int n) {
	int min = 0;
	string shortestLongest = texts[0].find_Longest_Line();
	for (int i = 1; i < n; i++) {
		string longest = texts[i].find_Longest_Line();
		if (longest.length() < shortestLongest.length()) {
			min = shortestLongest.length();
			shortestLongest = longest;
		}
	}
	cout << "\nThe shortest longest line is: " << shortestLongest << endl;
}

string Text::find_Longest_Line() {
	string longest;
	string line;
	for (char c : text) {
		if (c == '\n') {
			if (line.length() > longest.length()) {
				longest = line;
			}
			line = "";
		}
		else {
			line += c;
		}
	}
	if (line.length() > longest.length()) {
		longest = line;
	}
	return longest;
}

void Text::print_str() {
	cout << text << endl;
}

void Text::add_str(string line) {
	text += line + "\n";
}

Text::Text() {
	text = "";
}