#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    r:fgets() 时文件以\n结尾
    rb:fgets() 时文件以\r\n结尾
*/
typedef struct Data
{
    char * key;
    char * val;
} data;

typedef struct FileInfo
{
    FILE * fp;
    data * lists;
    int lines;
} fi;

void LoadFile(fi **f, char *path)
{
    *f = (fi *)malloc(sizeof(fi));
    (*f)->fp = fopen(path, "r");
    (*f)->lines = 0;
    (*f)->lists = NULL;
}

int GetFileLines(fi **f)
{
    //char *ch1 = "hello";
    //char *ch2 = "haha";
    //int x = strncmp(ch1, "h", 1);
    //if (x == 0)
    //{
    //    printf("存在");
    //}
    //else
    //{
    //    printf("不存在");
    //}

    char buf[1024] = { 0 };

    int lines = 0;
    while (!feof((*f)->fp))
    {
        fgets(buf, 1024, (*f)->fp);
        if (strncmp(buf, "#", 1) != 0)
        {
            lines++;
        }
    }
    rewind((*f)->fp);
    return lines;
}

void ReadFile(fi **f)
{
    (*f)->lines = GetFileLines(f);
    (*f)->lists = (data *)malloc(sizeof(data)* (*f)->lines);

    char buf[512] = { 0 };
    int index = 0;
    while (!feof((*f)->fp))
    {
        memset(buf, 0, 512);
        fgets(buf, 512, (*f)->fp);

        buf[strlen(buf) - 1] = 0;
        char * cut = strchr(buf, ':');

        (*f)->lists[index].key = (char *)malloc(cut - buf + 1);
        memset((*f)->lists[index].key, 0, cut - buf + 1);
        strncpy((*f)->lists[index].key, buf, cut - buf);

        (*f)->lists[index].val = (char *)malloc(strlen(cut));
        memset((*f)->lists[index].val, 0, strlen(cut));
        strcpy((*f)->lists[index].val, cut + 1);

        index++;
    }
}

char *ForeachValue(fi **f)
{
    for (int index = 0; index < (*f)->lines; index++)
    {
        printf("%s：%s\n", (*f)->lists[index].key, (*f)->lists[index].val);
    }
}

char *SerachByKey(fi **f, char *key)
{
    for (int index = 0; index < (*f)->lines; index++)
    {
        if (strcmp((*f)->lists[index].key, key) == 0)
        {
            return  (*f)->lists[index].val;
        }
    }
    return NULL;
}

char *FreeSpace(fi **f)
{
    for (int index = 0; index < (*f)->lines; index++)
    {
        if ((*f)->lists[index].key)
        {
            free((*f)->lists[index].key);
        }
        if ((*f)->lists[index].val)
        {
            free((*f)->lists[index].val);
        }
    }
    if ((*f)->lists)
    {
        free((*f)->lists);
    }
    if ((*f)->fp)
    {
        free((*f)->fp);
    }
}

void ConfigReadDemo()
{
    char * filepath = "config.ini";
    fi * f = NULL;
    LoadFile(&f, filepath);
    ReadFile(&f);
    ForeachValue(&f);
    char *val1 = SerachByKey(&f, "ip");
    char *val2 = SerachByKey(&f, "port");
    char *val3 = SerachByKey(&f, "username");
    char *val4 = SerachByKey(&f, "password");
    printf("%s\n", val1);
    printf("%s\n", val2);
    printf("%s\n", val3);
    printf("%s\n", val4);
    FreeSpace(&f);
    //if (f->fp)
    //{
    //    char buf[1024] = { 0 };
    //    while (!feof(f->fp))
    //    {
    //        fgets(buf, 1024, f->fp);
    //        printf("%s", buf);
    //    }
    //}
}