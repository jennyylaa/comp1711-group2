#include <stdio.h>

int main() {
    int odd = 1;

    for (int i = 0; i < 10; i++) {
        printf("%d\n", odd);
        odd += 2;
    }
    return 0;
}