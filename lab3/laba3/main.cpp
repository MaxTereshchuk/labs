#include "class.h"

int main() {
	int n = 0;
	cout << "Number of texts: ";
	cin >> n;
	Text* texts = new Text[n];
	create_text(texts, n);
	print_text(texts, n);
	print_max_text_length(texts, n);
	search_max_length(texts, n);
	delete[] texts;
}