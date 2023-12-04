#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
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
   // array of daily readings
    FITNESS_DATA daily_steps[100];

    char line[buffer_size];
    char filename[buffer_size];

    // why do you need this part?
    char date[11];
	char time[6];
	char steps [20];

    char choice;
    int counter = 0;
    float mean = 0;

    while (1)
    {
        

        printf("A: Specify the filename to be imported\n");                       
        printf("B: Display the total number of records in the file\n");                   
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                    
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                   
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");               
        printf("Q: Exit the program\n");

        printf("Enter choice: ");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            // get filename from the user
            printf("Please enter the name of the data file: ");

            // these lines read in a line from the stdin (where the user types)
            // and then takes the actual string out of it
            // this removes any spaces or newlines.
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }
            break;

        case 'B':
        case 'b':
            counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_steps[counter].date, daily_steps[counter].time, steps);
                counter++;
            }
            printf("Total record: %d\n", counter);
            break;
            

        case 'C':
        case 'c':
            counter = 0;
            int lowest; // have to figure out how to store first step counter into lowest one time
            char lowestdate[11];
            char lowesttime[6];

            while (fgets(line, buffer_size, input))
            {
                tokeniseRecord(line, ",", daily_steps[counter].date, daily_steps[counter].time, steps);
                
                int currentSteps = atoi(steps);

                if (currentSteps < lowest) {
                    lowest = currentSteps;
                    strcpy(lowestdate, daily_steps[counter].date);
                    strcpy(lowesttime, daily_steps[counter].time);
                }
                
                // if (daily_steps[counter].steps < lowest) {
                //     lowest = daily_steps[counter].steps;
                //     lowestdate = daily_steps[counter].date;
                //     lowesttime = daily_steps[counter].time;
                // }
                
                counter++;
            }
            
            printf("Fewest steps: %s, %s\n", lowestdate, lowesttime);
            fclose(input);

            break;

        case 'D':
        case 'd':
            counter = 0;
            float highest = 0;
            char highestdate[11];
            char highesttime[6];

            while (fgets(line, buffer_size, input))
            {
                tokeniseRecord(line, ",", daily_steps[counter].date, daily_steps[counter].time, steps);
                int currentSteps = atoi(steps);

                if (currentSteps > highest) {
                    highest = currentSteps;
                    strcpy(highestdate, daily_steps[counter].date);
                    strcpy(highesttime, daily_steps[counter].time);
                }

                // if (daily_steps[counter].steps > highest) {
                //     highest = daily_steps[counter].steps;
                //     highestdate = daily_steps[counter].date;
                //     highesttime = daily_steps[counter].time;
                // }
                
                counter++;
            }
            
            printf("Largest steps: %s, %s\n", highestdate, highesttime);
            fclose(input);

            break;

        case 'E':
        case 'e':
            counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_steps[counter].date, daily_steps[counter].time, steps);
                int currentSteps = atoi(steps);

                mean += currentSteps;
                counter++;
            }
            mean /= counter;
            printf("Mean step count: %.0f\n", mean);
            fclose(input);
            break;
            
            
            break;

        case 'F':
        case 'f':
            printf("Largest period start: ");
            printf("Largest period end: ");
            return 0;
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}