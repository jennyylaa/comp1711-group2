#include <stdio.h>

int main() {
    int radius;
    int area;

    printf("Enter the radius: ");
    scanf("%d", &radius);
    area = 3.14 * radius * radius;

    printf("The area of the circle is %d\n", area);
    return 0;
}