#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // length of line you're going to read in, up to 100 characters read per line
    int buffer_size = 100;

    // a string that will hold each line as it's read in
    char line_buffer[buffer_size];

    // statically defining an arbritrary large number
    int numbers[1000];

    int line_number_something = 0;

    // while there is still stuff in the file --> where it needs to store, up to 100 chracters, from file
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%d\n", atoi(line_buffer));
        numbers[line_number_something] = atoi(line_buffer);
        line_number_something++;
    }

    printf("There were %d lines\n", line_number_something);

    fclose(file);
    return 0;
}