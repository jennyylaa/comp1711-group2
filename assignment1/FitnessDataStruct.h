
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#define buffer_size 100

#include <stdio.h>

// Define an appropriate struact
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H