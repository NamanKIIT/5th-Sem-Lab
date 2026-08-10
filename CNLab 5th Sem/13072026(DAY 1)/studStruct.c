#include <stdio.h>
#include <string.h>

struct dob
{
    int day;
    int month;
    int year;
};

struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void printByValue(struct student_info s)
{
    printf("\n--- Details using Call by Value ---\n");
    printf("Roll No : %d\n", s.roll_no);
    printf("Name    : %s\n", s.name);
    printf("CGPA    : %.2f\n", s.CGPA);
    printf("DOB     : %02d-%02d-%04d\n",s.age.day, s.age.month, s.age.year);
}

void printByAddress(struct student_info *s)
{
    printf("\n--- Details using Call by Address ---\n");
    printf("Roll No : %d\n", s->roll_no);
    printf("Name    : %s\n", s->name);
    printf("CGPA    : %.2f\n", s->CGPA);
    printf("DOB     : %02d-%02d-%04d\n",s->age.day, s->age.month, s->age.year);
}

int main()
{
    struct student_info student;

    student.roll_no = 1185;
    strcpy(student.name, "Naman Chokhani");
    student.CGPA = 9.23;

    student.age.day = 29;
    student.age.month = 7;
    student.age.year = 2005;

    printByValue(student);
    printByAddress(&student);

    return 0;
}