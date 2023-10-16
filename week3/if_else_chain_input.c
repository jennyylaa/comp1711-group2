#include <stdio.h>

int main() {

    int mark;

    // add in: checking that the value is over 60 for a 2:1
    // check the value is over 70 for a first
    // check that the value is a valid mark (between 0 and 100, inclusive)

    while (mark < 0 || mark > 100 ) {
        printf ("Enter the mark: ");
        scanf ("%d", &mark);
        //printf ("The mark to be checked is: %d \n", mark);
    }
    
    if (mark >= 0 && mark <= 100) {
        if (mark == 0)
        {
            printf ("The mark of %d is zero\n", mark);
        }
        else if (mark < 40)
        {
            printf ("The mark of %d is a fail\n", mark);
        }
        else if (mark > 60 && mark <= 70) {
            printf ("The mark of %d is a 2:1\n", mark);
        }
        else if (mark > 70) {
            printf ("The mark of %d is a first\n", mark);
        } 
        else {
        printf ("The mark of %d is a pass\n", mark);
        }
    } else {
        printf ("Marks must be between 0 and 100\n");
    }

    return 0;
}