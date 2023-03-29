#include "hood.h"


int main() {
	University* universities = nullptr;
	int num_universities = 0;
	string filename = get_filename();
	cout << "Enter information about universities:\n";
	addUniversities(universities, num_universities, filename);
	read(filename);
	search(universities, num_universities);
	cout << "New file containing universities of 3rd and 4th accreditation\n";
	string new_filename =  get_new_filename();
	check_accreditation(new_filename, filename);
	read_new(new_filename);
	free(universities);
	return 0;
}

