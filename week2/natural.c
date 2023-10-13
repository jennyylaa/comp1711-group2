#include <stdio.h>

int main() {
    int num = 1;
    int square;

    for (int i = 1; i < 10; i++) {
        square = num * num;
        printf("%d\n", square);
        num += 1;
    }
    return 0;
}