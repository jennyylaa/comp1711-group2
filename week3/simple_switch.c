#include <stdio.h>

int main() {
    int a;

    // add case for 2 and 3
    // take input from user
    // validate the input from the user so it is always between 0 and 3 (inclusive)

    // really only use switches for menus

    while (a < 0 || a > 3) {
        printf("Enter your switch selection: ");
        scanf("%d", &a);
    }

    switch (a)
    {
        case 0:
            printf ("Option 0 has been selected\n");
            break;

        case 1:
            printf ("Option 1 has been selected\n");
            break;
        
        case 2:
            printf ("Option 2 has been selected\n");
            break;

        case 3:
            printf ("Option 3 has been selected\n");
            break;

        default:
            printf ("A different option has been selected\n");
    }
}