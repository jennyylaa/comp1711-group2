#include <stdio.h>

int main() {
    int even = 20;

    for (int i = 0; i < 11; i++) {
        printf("%d\n", even);
        even -= 2;
    }
    return 0;
}