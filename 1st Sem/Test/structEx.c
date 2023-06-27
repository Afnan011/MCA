#include<stdio.h>

typedef struct student 
{
    int rollNo;
    char name[20];
    int m1, m2, m3;
} student;

void main()
{
    student s1 = {1001, "Afnan", 100, 100, 100};
    int total = s1.m1 + s1.m2 + s1.m3;
    float avg = total / 3;

    student *ptr;
    ptr = &s1;
    
    printf("Roll no = %d\n", ptr -> rollNo);
    printf("Name = %s\n", ptr -> name);
    printf("Total Marks = %d / 300\n", total);
    printf("Percentage = %0.2f\n", avg);


}