#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main() {
    char* filename = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    // char record[21] = "2023-09-01,07:30,300";
    // char date[11];
    // char time[6];
    // char steps[10];  // Large enough to hold a typical step count as a string


    // student students [] = {
    //     {"Alice Smith",    "64827593", 67},
    //     {"Bob Johnson",    "19374650", 89},
    //     {"Charlie Brown",  "82056914", 76},
    //     {"David Davis",    "45790182", 44},
    //     {"Eve Wilson",     "36102478", 91},
    //     {"Frank Anderson", "93571826", 53},
    //     {"Grace Lee",      "50249867", 78},
    //     {"Hannah Clark",   "74820591", 62},
    //     {"Isaac Harris",   "61093745", 89},
    //     {"Jack White",     "92847501", 72},
    // };

    // length of line you're going to read in, up to 100 characters read per line
    int buffer_size = 100;

    // a string that will hold each line as it's read in
    char line_buffer[buffer_size];

    // statically defining an arbritrary large number
    int numbers[1000];

    int num_lines = 0;

    int date_size = 10;

    FITNESS_DATA new;

    // FITNESS_DATA data [] {
    //     while (fgets(date, date_size, file) != NULL) {
    //         printf("%d\n", atoi(date));
    //         numbers[num_lines] = atoi(date);
    //         num_lines++;
    //     }
    // }

    FITNESS_DATA data [] = {
        {"Alice Smith",    "648", 67}
    };

    // while there is still stuff in the file --> where it needs to store, up to 100 chracters, from file
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        //printf("%d\n", atoi(line_buffer));
        numbers[num_lines] = atoi(line_buffer);
        num_lines++;
    }

    printf("Number of records in file: %d\n", num_lines);

    //tokeniseRecord(record, ",", date, time, steps);

    // for (int i = 0; i < 3; i++) {
    //     printf("%s/", date);
    //     printf("%s/", time);
    //     printf("%s\n", steps);
    // }

    for (int i = 0; i < 3; i++) {
        printf("%s/", data[i].date);
        printf("%s/", data[i].time);
        printf("%d\n", data[i].steps);
    }
    


    fclose(file);
    return 0;
}