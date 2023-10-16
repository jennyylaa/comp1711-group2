#include <stdio.h>

int main() {
    int menu;

    printf("Hi there! Welcome to JennyyCooks Restaurant :)\nWhat would you like from our menu? Please enter a number from 1 to 5: ");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            printf("You chose lamb rogan josh for dinner\n");
            break;

        case 2:
            printf("You chose bun mam for dinner\n");
            break;

        case 3:
            printf("You chose beans on toast for dinner\n");
            break;
        
        case 4:
            printf("You chose sushi for dinner\n");
            break;

        case 5:
            printf("You chose tonkatsu ramen for dinner\n");
            break;

        default:
            printf("Sorry that menu selection is invalid :(\n");
    }
    return 0;
}