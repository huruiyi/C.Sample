#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct FilmStart
{
    char name[21]; // 24
    int age;             // 04
    char sex;           //  04
    char tel[16];     //  16
} FS;

void 结构体赋值()
{
    //FS fs;
    //strcpy(fs.name, "胡歌");
    //fs.age = 35;
    //fs.sex = 'M';
    //strcpy(fs.tel, "+86113812345678");

    //FS fs = { "胡歌",  35, 'M',  "+86113812345678" };//顺序不可以变
    FS fs = { .name = "胡歌",.age = 35,.sex = 'M',.tel = "+86113812345678" };

    printf("姓名：%s\n", fs.name);
    printf("年龄：%d\n", fs.age);
    printf("性别：%s\n", fs.name == 'F' ? "女" : "男");
    printf("号码：%s\n", fs.tel);

    printf("结构体大小：%d\n", sizeof(FS));
    FS *fp = &fs;
    printf("%p\n", &fs);
    printf("%p\n", fp);
    printf("%p	%s\n", &fp->name, fp->name);
    int len = &fp->age - fp;
    printf("姓名所占字节大小:%d\n", len * 4);
    printf("\n");
}

typedef  struct Student
{
    char *name;
    int age;
} Student;

void 结构体测试()
{
    Student stu1 = { 0 };
    //stu1.name = (char *)malloc(sizeof(char) * 21);
    //strcpy(stu1.name, "AR");
    stu1.name = "Ak";
    stu1.age = 24;

    Student stu2 = { 0 };
    stu2 = stu1;
    printf("stu1[%p]:姓名：%s,年龄：%d\n", &stu1, stu1.name, stu1.age);
    printf("stu2[%p]:姓名：%s,年龄：%d\n", &stu2, stu2.name, stu2.age);

    stu2.name = "xx";

    printf("stu1[%p]:姓名：%s,年龄：%d\n", &stu1, stu1.name, stu1.age);
    printf("stu2[%p]:姓名：%s,年龄：%d\n", &stu2, stu2.name, stu2.age);
}

void 结构体内存分配()
{
    typedef struct Data
    {
        char * key;
        char * val;
    } data;

    data *d = (data *)malloc(sizeof(data), 4);
    char chkey[21] = { 0 };
    char chval[21] = { 0 };
    for (int i = 0; i < 4; i++)
    {
        d[i].key = (char *)malloc(sizeof(char) * 21);
        memset(chkey, 0, 21);
        sprintf(chkey, "key%d", i);
        strcpy(d[i].key, chkey);

        d[i].val = (char *)malloc(sizeof(char) * 21);
        memset(chval, 0, 21);
        sprintf(chval, "val%d", i);
        strcpy(d[i].val, chval);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%s\t%s\n", d[i].key, d[i].val);
    }
    for (int i = 0; i < 4; i++)
    {
        if (d[i].key)
        {
            free(d[i].key);
        }
        if (d[i].val)
        {
            free(d[i].val);
        }
    }
    if (d)
    {
        free(d);
    }
}