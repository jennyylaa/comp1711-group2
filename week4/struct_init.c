#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

struct group {
    struct student jenny;
};

int main () {
    struct student new_student = {"Name Surname", "28932123", 35};

    char name[20];
    int mark;

    //scanf("%s", name);
    //scanf("%d", &mark);
    scanf("%d", &new_student.mark);

    //new_student.name = name;
    //new_student.mark = mark;

    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}