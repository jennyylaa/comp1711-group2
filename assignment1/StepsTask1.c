#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

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

int main() {
    char* filename = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    FITNESS_DATA fitness [100];
    FITNESS_DATA fitnessdata;

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int num_lines = 0;

    char date[11];
	char time[6];
	char steps [20];

    while (fgets(line_buffer, buffer_size, file) != NULL){
        tokeniseRecord(line_buffer, ",", date, time, steps);
        
        strcpy(fitnessdata.date, date);
        strcpy(fitnessdata.time, time);
        fitnessdata.steps = atoi(steps);
        fitness[num_lines] = fitnessdata;
        
        num_lines++;
    }

    printf("Number of records in file: %d\n", num_lines);
    
    for (int i = 0; i < 3; i++) {
        printf("%s/", fitness[i].date);
        printf("%s/", fitness[i].time);
        printf("%d\n", fitness[i].steps);
    }

    fclose(file);
    return 0;
}