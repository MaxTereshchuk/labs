#include "stream.h"
#include "pointer.h"

int main(int argc, char* argv[]) {
    std::string mode_flag(argv[1]);
    std::string mode(argv[2]);
    char s[MAX_LINE_LENGTH][MAX_LINE_LENGTH];
    if (mode_flag != "-mode") {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::cout << "In this program, the substring will be separated by parentheses" << std::endl;
    std::cout << "The number of substrings will be displayed at the end of the line" << std::endl;
    std::cout << "To finish entering new lines, press the spacebar twice\n" << std::endl;
    std::cout << "The contents of the input file" << std::endl;
    if (mode == "FileStream" || mode == "fileStream") {
        std::string line;
        print_strings("output.txt", line);
        std::cout << "\nAll subsequent lines will be added" << std::endl;
        create_strings("input.txt", line);
        search_substrings("input.txt", "output.txt", line);
        std::cout << "The content of the created file:" << std::endl;
        print_strings("output.txt", line);
    }
    else if (mode == "FilePointer" || mode == "filePointer") {
        print_strings_p("output.txt");
        std::cout << "\nAll subsequent lines will be added" << std::endl;
        create_file_p("input.txt");
        search_substrings_p("input.txt", "output.txt");
        std::cout << "The content of the created file:" << std::endl;
        print_strings_p("output.txt");
    }
    else {
        std::cout << "Wrong mode :(" << std::endl;
    }
}