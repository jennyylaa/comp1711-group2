#include <stdio.h>

int main() {
    int numbers[10];
    int i=0;
    int total = 0;
    float mean;

    for (i=0; i < 10; i++) {
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
        total += numbers[i];
    }

    mean = total/10;

    for (i=0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    
    printf("the average is %f\n", mean);
}