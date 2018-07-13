#include "heaad.h"

char GetSignal(int num)
{
    switch (num)
    {
    case 1:return '+';
    case 2:return '-';
    case 3:return '*';
    case 4:return '\\';
    }
}

void main01(void)
{
    FILE * fp = fopen("D:\\c.txt", "w");
    if (!fp)
        return -1;
    char arr[1024];
    while (1)
    {
        memset(arr, 0, 1024);
        //scanf读取文件
        //scanf("%s", arr);
        gets(arr);
        //arr=="comm=exit"
        if (!strcmp(arr, "comm=exit"))
        {
            fclose(fp);
            break;
        }
        arr[strlen(arr)] = '\n';

        for (int i = 0; i < strlen(arr); i++)
        {
            fputc(arr[i], fp);
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

void main02()
{
    FILE *fp = fopen("D:\\四则运算.txt", "w");
    int i = 0;
    srand((unsigned int)time(NULL));
    int num1 = 0;
    int signal = 0;
    int num2 = 0;
    char str[100] = { "0" };
    while (++i <= 100)
    {
        num1 = rand() % 100 + 1;
        signal = rand() % 4 + 1;
        num2 = rand() % 100 + 1;
        sprintf(str, "%d%c%d=\n", num1, GetSignal(signal), num2);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            fputc(str[i], fp);
        }
        //fputc('\n', fp);
    }
    fclose(fp);
    system("pause");
}

void main03()
{
    FILE *fp = fopen("D:\\四则运算.txt", "r");
    int i = 0;
    srand((unsigned int)time(NULL));
    int num1 = 0;
    int signal = 0;
    int num2 = 0;
    char* str[2048] = { "0" };

    while (!feof(fp))
    {
        fgets(str, 2048, fp);
        sscanf(str, "%d%c%d=\n", &num1, &signal, &num2);
        printf("%d\t", num1);
        printf("%c\t", signal);
        printf("%d\n", num1);
    }

    fclose(fp);
    system("pause");
}

int main04()
{
    char **p = (char **)malloc(sizeof(char *) * 100);

    FILE * fp = fopen("D:\\四则运算.txt", "r");
    if (!fp)
        return -1;

    char buf[1024];
    for (int i = 0; i < 100; i++)
    {
        memset(buf, 0, 1024);
        fgets(buf, 1024, fp);
        p[i] = (char *)malloc(strlen(buf) + 1);
        strcpy(p[i], buf);
    }
    fclose(fp);

    fp = fopen("D:\\四则运算.txt", "w");
    if (!fp)
        return -1;

    int a, b;
    char c;
    int value = 0;
    for (int i = 0; i < 100; i++)
    {
        sscanf(p[i], "%d%c%d=\n", &a, &c, &b);
        switch (c)
        {
        case '+':
            value = a + b;
            break;
        case '-':
            value = a - b;
            break;
        case '*':
            value = a * b;
            break;
        case '/':
            value = a / b;
            break;
        }

        memset(buf, 0, 1024);

        sprintf(buf, "%d%c%d=%d\n", a, c, b, value);
        fputs(buf, fp);
    }

    fclose(fp);

    //释放内存
    for (int i = 0; i < 100; i++)
    {
        free(p[i]);
    }
    free(p);

    return EXIT_SUCCESS;
}

void main05()
{
    system("pause");
}