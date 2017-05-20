#include "heaad.h"

void fputs_demo()
{
    FILE * fp = fopen("D:\\a.txt", "w");
    char *buf[] = { "1\n", "3", "45\0", "7\n" , "9\0\n" };

    int l1 = sizeof(buf);
    int l2 = sizeof(buf[0]);
    printf("%d\n", l1);
    printf("%d\n", l2);

    int length = l1 / l2;
    printf("buf.length=%d\n", length);

    for (int i = 0; i < length; i++)
    {
        fputs(buf[i], fp);
    }
    fclose(fp);
}

void fgets_demo0()
{
    FILE * fp = fopen("D:\\a.txt", "r");
    char buf[100] = { 0 };
    while (!feof(fp)) //文件没有结束
    {
        memset(buf, 0, sizeof(buf));
        char *p = fgets(buf, sizeof(buf), fp);
        if (p != NULL)
        {
            printf("%s", buf);
        }
    }
    fclose(fp);
}

void fgets_demo1()
{
    FILE * fp = fopen("源文件0", "r");
    char buf[1024] = { 0 };
    while (!feof(fp))
    {
        fgets(buf, 1024, fp);
        buf[strlen(buf) - 1] = '\0';//每行文件以\n结束
        printf("[%s]", buf);
        int a = 0;
    }
    fclose(fp);
}

void fgets_fflush()
{
    FILE * fp = fopen("./f.txt", "w");
    char buf[1024];
    while (1)
    {
        memset(buf, 0, 1024);

        //gets(buf);
        fgets(buf, sizeof(buf), stdin);

        if (!strcmp(buf, "comm=exit"))
        {
            break;
        }
        //buf[strlen(buf)] = '\n';
        fputs(buf, fp);

        fflush(fp);
    }

    fclose(fp);
}

void fflush_stdin()
{
    char c;
    scanf("%c", &c);
    printf("%d ", c);

    fflush(stdin);
    scanf("%c", &c);
    printf("%d\n", c);
}

void fgets_stdin()
{
    char str[100];
    printf("请输入str: ");
    fgets(str, sizeof(str), stdin);
    printf("str = \"%s\"\n", str);
}