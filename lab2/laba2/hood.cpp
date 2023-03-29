#include "hood.h"

string get_filename() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;
    return filename;
}

string get_new_filename() {
    string filename;
    cout << "Enter new filename: ";
    cin >> filename;
    return filename;
}

void addUniversities(University*& universities, int& num_universities, string filename) {
    ofstream outfile(filename, ios::binary | ios::app);
    string answer;
    while (answer != "N" && answer != "n") {
        University university;
        cout << "Enter the name of the university: ";
        cin >> university.name;

        if (strcmp(university.name, "") == 0) {
            break;
        }

        cout << "Enter the city of the university: ";
        cin >> university.city;

        cout << "Enter the accreditation of the university(1-4): ";
        cin >> university.accreditation;

        cout << "Enter the number of faculties of the university: ";
        cin >> university.num_faculties;

        for (int j = 0; j < university.num_faculties; j++) {
            cout << "Enter the name of faculty " << j + 1 << ": ";
            cin >> university.faculty_names[j];

            cout << "Enter the number of students of faculty " << university.faculty_names[j] << ": ";
            cin >> university.num_students[j];
        }

        // Add university to array
        num_universities++;
        universities = (University*)realloc(universities, sizeof(University) * num_universities);
        universities[num_universities - 1] = university;

        cout << "You want to add one more university? (Y/N): ";
        cin >> answer;
    }
    
    outfile.write((char*)universities, sizeof(University) * num_universities);
    outfile.close();
}

void read(string filename) {
    // Read universities from binary file and output to console
    ifstream infile(filename, ios::binary);

    if (!infile) {
        cout << "Error: could not open file" << endl;
        return;
    }

    University university;
    while (infile.read((char*)&university, sizeof(University))) {
        cout << "Name: " << university.name << endl;
        cout << "City: " << university.city << endl;
        cout << "Accreditation: " << university.accreditation << endl;
        cout << "Number of faculties: " << university.num_faculties << endl;
        for (int j = 0; j < university.num_faculties; j++) {
            cout << "Faculty " << j + 1 << " name: " << university.faculty_names[j] << endl;
            cout << "Faculty " << j + 1 << " number of students: " << university.num_students[j] << endl;
        }
        cout << endl;
    }

    infile.close();
}
void search(University* universities, int num_universities) {
    // Search for faculty with most students in specified city
    char city_to_search[50];
    cout << "Enter the city to search: ";
    cin >> city_to_search;

    int max_students = -1;
    char max_faculty_name[50];
    char max_university_name[50];

    for (int i = 0; i < num_universities; i++) {
        if (strcmp(universities[i].city, city_to_search) == 0) {
            for (int j = 0; j < universities[i].num_faculties; j++) {
                if (universities[i].num_students[j] > max_students) {
                    max_students = universities[i].num_students[j];
                    strcpy(max_faculty_name, universities[i].faculty_names[j]);
                    strcpy(max_university_name, universities[i].name);
                }
            }
        }
    }

    if (max_students == -1) {
        cout << "No universities found in " << city_to_search << endl;
    }
    else {
        cout << "Faculty with most students in " << city_to_search << ": is " << max_faculty_name << " at " << max_university_name << " (" << max_students << " students)" << endl;
    }
}

void check_accreditation(string new_filename, string filename) {
    ifstream outfile(filename, ios::binary);
    ofstream infile(new_filename, ios::binary | ios::app);

    if (!outfile) {
        cout << "Error: could not open file" << endl;
        return;
    }

    if (!infile) {
        cout << "Error: could not open file" << endl;
        return;
    }
    University uni;
    while (outfile.read((char*)&uni, sizeof(University))) {
        if (uni.accreditation == 3 || uni.accreditation == 4) {
            infile.write((char*)&uni, sizeof(University));
        }
    }
    infile.close(); 
    outfile.close(); 
}

void read_new(string new_filename) {
    // Read universities from binary file and output to console
    ifstream infile(new_filename, ios::binary);

    if (!infile) {
        cout << "Error: could not open file" << endl;
        return;
    }

    University university;
    while (infile.read((char*)&university, sizeof(University))) {
        cout << "Name: " << university.name << endl;
        cout << "City: " << university.city << endl;
        cout << "Accreditation: " << university.accreditation << endl;
        cout << endl;
    }

    infile.close();
}