#include <stdio.h>

int main() {
    int num, factorial=1;

    printf("Enter a variable: ");
    scanf("%d", &num);
    for (int i=1; i<=num; i++) {
        factorial*=i; 
    }
    printf("The result is %d\n", factorial);

    return 0;
}