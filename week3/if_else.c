#include <stdio.h>

int main() {

    int mark = 70;

    if (mark >= 40 && mark >= 70) {
        printf("the mark of %d is a first\n", mark);
    }
    else if (mark >= 40) {
        printf ("The mark of %d is a pass\n", mark);
    }
    else {
        printf ("The mark of %d is a fail\n", mark);
    }

    return 0;
}