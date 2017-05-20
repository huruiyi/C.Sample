#include "head.h"

void puts_demo()
{
    /*puts���һ�к��Զ������У�printf�����Զ�����*/
    printf("hello world");
    puts("hello world");
}

void fputs_demo0()
{
    //fputs()�����Զ����һ��'\n'��

    printf("1:hello world\n");
    puts("2:hello world\n");
    fputs("3:hello world\n", stdout);

    char str1[7] = { "1" };
    fputs(str1, stdout);
    putchar('\n');

    char str2[7] = { "2" };
    fputs(str2, stdout);
    putchar('\n');

    char str3[7] = { "12345\n" };
    char str4[7] = { "123456\n" };//���߸��ַ���\n��û��\0

    printf("\str3.size=%d\n", sizeof(str3));
    printf("\nstr3.length=%d\n", strlen(str3));
    fputs(str3, stdout);

    printf("\str4.size=%d\n", sizeof(str4));
    printf("\str4.length=%d\n", strlen(str4));
    fputs(str4, stdout);

    FILE *fp = fopen("123.txt", " w");
    fputc('a', fp);
    fclose(fp);
}

void fputs_demo1()
{
    //fputs  �����������
    char ch1[10] = "hello";
    fputs(ch1, stdout);
    printf("%s", ch1);
}

/*
    �ַ�����\0ռ��һ���ֽڴ�С
    gets:����ȫ���������������
    �����Զ�����
    puts:��������ַ�����Զ����\n����(ֻ�����ַ�����������ʱ�������������)

    fgets:�ǰ�ȫ��,�ո�ռһ���ַ�
    ���Զ�����
    fputs:�����Զ�����
*/
void main()
{
    //puts_demo2();
    fgets_demo2();
    system("pause");
}
gets_demo2()
{
    char buf[5] = { 0 };
    gets(buf);
    printf("[%s]", buf);
}
puts_demo2()
{
    char che[11] = "hello world";//������쳣��û��\0��λ��
    printf("%d\n", sizeof(che));
    printf("%d\n", strlen(che));
    puts(che);

    //char che[12] = "hello world";
    //printf("%d\n", sizeof(che));
    //printf("%d\n", strlen(che));
    //puts(che);

    //puts("hello world");//��ֱ�ӻ���

    puts("1:hello");
    char ch[6] = "hello"; //ok
    //char ch[5] = "hello"; //error ,û��\0��λ�ã��ᵼ���쳣
    //char ch[6] = "hello";
    //printf("%s\n", ch);
    //printf("%d\n", sizeof(ch));
    //printf("%d\n", strlen(ch));
    puts(ch);
}
fgets_demo2()
{
    //char str[10];
    //printf("str: ");
    //fgets(str, sizeof(str), stdin);
    //printf("str: %s", str);

    char buf[5];
    //fgets(buf, sizeof(buf), stdin);  //��ȫ�ģ��������������
    fgets(buf, 4, stdin);  //����ȫ
    printf("[%s]", buf);
}
fputs_demo2()
{
    char buf[5] = "1234";
    int a = 123;
    fputs(buf, stdout);
    printf("[%s]", buf);
}