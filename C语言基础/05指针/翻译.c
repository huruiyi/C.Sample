#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  DicPath  "./Dara/dict.txt";
typedef struct Dict
{
    char * key;
    char *value;
} Dicts;

typedef struct MyDict
{
    char   key[100];
    char  value[1024];
} MyDictt;

int GetDicLinesLength()
{
    /*FILE **fp = NULL;
    fopen_s(*fp, "D:\\dict.txt", "r");*/
    FILE*	dicfp = fopen("dict.txt", "r");
    if (!dicfp)
    {
        return 0;
    }
    int lenght = 0;
    char  world[1024] = { "0" };
    while (!feof(dicfp))
    {
        lenght++;
        memset(world, 0, 1024);
        fgets(world, 1024, dicfp);
    }
    fclose(dicfp);
    return lenght;
}

void ZP1()
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int) * 5);
    *(p + 0) = 1;
    *(p + 1) = 2;
    *(p + 3) = 4;
    *(p + 4) = 5;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i));
    }
}

void ZP2()
{
    Dicts *p = NULL;
    p = (Dicts *)malloc(sizeof(Dicts) * 5);

    Dicts d0 = { .key = "A",.value = "1" };
    *(p + 0) = d0;

    Dicts d1 = { .key = "B",.value = "2" };
    *(p + 1) = d1;

    Dicts d2 = { .key = "C",.value = "3" };
    *(p + 2) = d2;

    Dicts d3 = { .key = "D",.value = "4" };
    *(p + 3) = d3;

    Dicts d4 = { .key = "E",.value = "5" };
    *(p + 4) = d4;

    for (int i = 0; i < 5; i++)
    {
        Dicts d = *(p + i);
        printf("%s--%s\n", d.key, d.value);
    }
}

Dicts * dict;

Dicts * Serach(char *key, int length)
{
    Dicts*   d = NULL;

    for (int i = 0; i < length; i++)
    {
        if (strcmp(dict[i].key, key) == 0)
        {
            d = &dict[i];
            return d;
        }
    }
    return d;
}

void ReadDic()
{
    int length = GetDicLinesLength();
    length = length / 2;
    FILE*	dicfp = fopen("dict.txt", "r");
    dict = (Dicts *)malloc(sizeof(Dicts)*length);

    char buf[1024];
    int index = 0;
    while (!feof(dicfp))
    {
        memset(buf, 0, 1024);
        fgets(buf, 1024, dicfp);
        dict[index].key = (char *)malloc(strlen(buf));
        memset(dict[index].key, 0, strlen(buf));
        strcpy(dict[index].key, &buf[1]);

        memset(buf, 0, 1024);
        fgets(buf, 1024, dicfp);
        dict[index].value = (char *)malloc(strlen(buf) - 5);
        memset(dict[index].value, 0, strlen(buf) - 5);
        strcpy(dict[index].value, &buf[6]);

        //计数器增长
        index++;
    }
    fclose(dicfp);
    //for (int i = 0; i < length; i++)
    //{
    //	printf("%s", dict[i].key);
    //	printf("%s", dict[i].value);
    //}

    //for (int i = 0; i < length; i++)
    //{
    //	free(dict[i].key);
    //	dict[i].key = NULL;
    //	free(dict[i].value);
    //	dict[i].value = NULL;
    //}
    while (1)
    {
        char key[1024] = { 0 };
        fgets(key, sizeof(key), stdin);
        Dicts *  value = Serach(key, length);
        if (value != NULL)
        {
            printf(value->value);
        }
        else
        {
            printf("未查寻到结果\n");
        }
    }
}