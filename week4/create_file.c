#include "utils.h"

int main () {
    char* filename = "data.txt"; //string file name

    //file pointer file return type
    // w means writing to file, you have permission to open in write mode
    FILE *file = fopen (filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        printf("Error opening file\n");
        return 1; //if theres an error you return something thats not 0
    }

    fprintf(file, "Hello world!\n");

    fclose(file); //you have to close every file you open
    return 0;
}