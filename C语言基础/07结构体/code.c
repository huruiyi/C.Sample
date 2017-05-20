#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef union Last
{
    int  a;
    char b;
    int c;
    char d;
}Last;

typedef enum Color
{
    Red = 1, Brown, Yellow = 6, Green, Blue, Purple
};

typedef struct Student
{
    char * name;
    int age;
} stu;

typedef struct Student Studentx;

struct Employee
{
    int Id;
    char Name[20];
    int Score;
};

typedef struct Teacher
{
    int Id;
    char Name[20];
    int Score;
} Teacher;

typedef struct Studenty
{
    char a[10];  //16
    char *b;     //4
    long long c;  //8
    float d;     //8
    int f[2];  //8
    short g; //8
    double h; //8
} sru;

typedef struct A
{
    char a[10];
    char *b;
    int c;
    short d;
    double f;
} a;

void StructDemo0()
{
    struct Employee stu1;
    stu1.Id = 123;
    strcpy(stu1.Name, "胡睿毅");
    stu1.Score = 100;
    printf("Id=%d,Name=%s,Score=%d", stu1.Id, stu1.Name, stu1.Score);
}

void StructDemo1()
{
    stu s1;
    s1.name = "刘德华1";
    s1.age = 123;

    stu *s2;//必须先初始化才能赋值
    s2 = (stu *)malloc(sizeof(stu));
    s2->name = (char *)malloc(sizeof(char) * 21);
    s2->name = "刘德华2";
    s2->age = 123;

    printf("姓名：%s，年纪：%d\n", s1.name, s1.age);
    printf("姓名：%s，年纪：%d\n", s2->name, s2->age);
}

void UnionDemo()
{
    Last last;
    last.a = 511;
    printf("%p\n", &last);
    printf("Last.a=%d\n", last.a);
    last.b = 1;
    printf("Last.a=%d\n", last.a);
}
void mainx(void)
{
    enum Color col = Red;
    switch (col)
    {
    case Red:
        break;
    case Brown:
        break;
    case Yellow:
        break;
    case Green:
        break;
    case Blue:
        break;
    case Purple:
        break;
    default:
        break;
    }
    stu s[2];
    s[0].name = "刘德华0";
    s[0].age = 19;
    s[1].name = "刘德华1";
    s[1].age = 20;

    printf("姓名：%s，年纪：%d\n", s[0].name, s[0].age);
    printf("姓名：%s，年纪：%d\n", s[1].name, s[1].age);
    system("pause");
}