#include <stdio.h>

int main(){
    // setting up 15 slots of memory for a string 
    char name[15];

    // prompting the user
    printf("Hello, please enter your name: ");

    // Take the user input and storing it into name
    scanf("%s", name);

    // printing out user's name
    printf("Your name is %s\n", name);

    return 0;
}