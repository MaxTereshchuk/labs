#include "stream.h"


int create_strings(std::string path, std::string line) {
    std::ofstream input_file;
    input_file.open(path, std::ios_base::app);


    if (!input_file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::cout << "\nAdding new strings:" << std::endl;
    while (true) {
        std::getline(std::cin, line);
        if (line[0] == '\n' || line[0] == '\0')
            break;
        input_file << line << std::endl;
    }

    input_file.close();
    return 0;
}

void search_substrings(std::string in_path, std::string ou_path, std::string line) {
    std::cout << "Enter substring: ";
    std::string substring;
    std::getline(std::cin, substring);
    std::ifstream input_file(in_path); 
    std::ofstream output_file(ou_path); 

    while (getline(input_file, line)) {
        int occurrences = 0; 

        size_t pos = line.find(substring);
        while (pos != std::string::npos) {
            line.insert(pos, "(");
            line.insert(pos + substring.length() + 1, ")");
            occurrences++; 
            pos = line.find(substring, pos + 2); 
        }

        output_file << line << ", " << occurrences << " substrings" << std::endl;
    }
    input_file.close(); 
    output_file.close(); 
}
int print_strings(std::string ou_path, std::string line) {

    std::ifstream output_file(ou_path);
    while (std::getline(output_file, line)) { 
        std::cout << line << std::endl; 
    }
    output_file.close(); 
    return 0;
}