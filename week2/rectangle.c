#include <stdio.h>

int main() {
    float width, length, area;

    printf("Width of rectangle: ");
    scanf("%f", &width);

    printf("Length of rectangle: ");
    scanf("%f", &length);

    area = width * length;

    printf("The area of the rectangle is %.3f\n", area);

    return 0;
}