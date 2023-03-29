#include "pointer.h"

void create_file_p(const char* inFile)
{
    FILE* fp;
    fp = fopen(inFile, "a");
    int size = 0;
    if (fp == NULL) {
        std::cout << "Error" << std::endl;
    }

    std::cout << "\nAdding new strings: " << std::endl;


    char* text = new char[256];
    while (true) {
        std::cin.getline(text, 255);
        if (text[0] == '\n' || text[0] == '\0')
            break;
        fprintf(fp, "%s\n", text);
    }

    delete[] text;
    fclose(fp);
}

int count_occurrences(char* str, const char* substr) {
    int count = 0;
    char* pos = str;
    while ((pos = strstr(pos, substr)) != NULL) {
        count++;
        pos += strlen(substr);
    }
    return count;
}

int search_substrings_p(const char* inFile, const char* outFile) {
    FILE* in_file = fopen("input.txt", "r");
    if (in_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    FILE* out_file = fopen("output.txt", "w");
    if (out_file == NULL) {
        printf("Error opening result file!\n");
        return 1;
    }

    char** lines = (char**)malloc(sizeof(char*) * MAX_LINE_LENGTH);
    int line_count = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, in_file) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        lines[line_count] = _strdup(buffer);
        line_count++;
    }

    fclose(in_file);

    char* substr;
    substr = new char [MAX_LINE_LENGTH];

    printf("Enter substring: ");
    scanf("%s", substr);

    for (int i = 0; i < line_count; i++) {
        int count = count_occurrences(lines[i], substr);
        char* pos = lines[i];
        while ((pos = strstr(pos, substr)) != NULL) {
            int index = pos - lines[i];
            char* new_line = (char*)malloc(sizeof(char) * (strlen(lines[i]) + 3));
            strncpy(new_line, lines[i], index);
            new_line[index] = '(';
            strncpy(new_line + index + 1, substr, strlen(substr));
            new_line[index + strlen(substr) + 1] = ')';
            strcpy(new_line + index + strlen(substr) + 2, lines[i] + index + strlen(substr));
            free(lines[i]);
            lines[i] = new_line;
            pos = new_line + index + strlen(substr) + 2;
        }
        fprintf(out_file, "%s, %d substrings\n", lines[i], count);

    }


    fclose(out_file);

    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}

int print_strings_p(const char* outFile) {
    FILE* file = fopen(outFile, "r"); 
    if (file == NULL) {
        printf("Error opening file!");
        return 1;
    }

    char line[100]; 
    while (fgets(line, sizeof(line), file)) { 
        printf("%s", line); 
    }

    fclose(file); 
    return 0;
}
