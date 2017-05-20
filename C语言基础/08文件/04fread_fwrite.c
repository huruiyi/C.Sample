#include "heaad.h"

#define AVISRC "D:\\video\\1.zip"
#define AVIDES "D:\\video\\2.zip"
#define Speed 1024*1024*5

typedef struct student
{
    char name[21];//24
    int scores[3];//12
} Stu;

void  fread_demoy()
{
    FILE * fp = fopen("./a.txt", "rb");
    int a = 0;
    fread(&a, 1, 4, fp);
    printf("%d\n", a);
    fclose(fp);
}

void fread_demox()
{
    FILE *fp = fopen("D:\\a.txt", "rb");
    int buf[100] = { 0 };
    fread(buf, 40, 1, fp);
    printf("%s\n", buf);
    fclose(fp);
}

void fread_demo0()
{
    int arr[10] = { 0 };

    FILE * fp = fopen("./c.txt", "rb");

    //fread(arr, sizeof(arr[0]), 10, fp);
    //for (int i = 0; i < 10; i++)
    //	printf("%d\n", arr[i]);
    int i = 0;
    while (!feof(fp))//二进制文件只能通过feof来判断文件结尾
    {
        fread(&arr[i], sizeof(arr[0]), 1, fp);
        i++;
    }
    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
    fclose(fp);
}

int fread_demo1()
{
    Stu st[3];
    memset(st, 0, sizeof(st));

    FILE * fp = fopen("./d.txt", "rb");
    if (!fp)
        return -1;

    int i = 0;
    while (!feof(fp))
    {
        fread(&st[i], sizeof(st[0]), 1, fp);
        i++;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("姓名：%s\n成绩1：%d   成绩2：%d   成绩3：%d\n",
            st[i].name, st[i].scores[0], st[i].scores[1], st[i].scores[2]);
    }

    //fread(st, sizeof(st), 1, fp);
    //for (int i = 0; i < 3;i++)
    //printf("姓名：%s\n成绩1：%d   成绩2：%d   成绩3：%d\n",
    //	st[i].name, st[i].scores[0], st[i].scores[1], st[i].scores[2]);
    fclose(fp);
    return 0;
}

void fwrite_demo1()
{
    Stu st[3] = {
        {.name = "刘能",.scores[0] = 20,.scores[1] = 30,.scores[2] = 40 },
        {.name = "张老气" ,.scores[0] = 30,.scores[1] = 40 ,.scores[2] = 50 },
        {.name = "赵四" ,.scores[0] = 40,.scores[1] = 50,.scores[2] = 60 } };

    FILE * fp = fopen("./d.txt", "wb");
    if (!fp)
    {
        perror("file open error");
        return;
    }

    fwrite(st, sizeof(st[0]), 3, fp);
    fclose(fp);
}

int fwrite_demo2()
{
    Stu st[3];//36*3
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", st[i].name);

        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &st[i].scores[j]);
        }
    }

    FILE * fp = fopen("./d.txt", "wb");
    if (!fp)
    {
        perror("file open error");
        return -1;
    }

    fwrite(st, sizeof(st[0]), 3, fp);
    fclose(fp);

    return EXIT_SUCCESS;
}

void fwrite_fread_wbrb()
{
    FILE *fp = fopen("D:\\a.txt", "wb");
    int bufWrite[] = { 1,2,3,4,5,6 };
    fwrite(bufWrite, sizeof(int), sizeof(bufWrite) / sizeof(int), fp);
    fclose(fp);

    fp = fopen("D:\\a.txt", "rb");
    int bufRead[6] = { 0 };
    fread(bufRead, sizeof(int), sizeof(bufRead) / sizeof(int), fp);
    fclose(fp);
}

void fwrite_fread_wr()
{
    FILE *fp = fopen("D:\\a.txt", "w");
    int bufWrite[] = { 1,2,3,4,5,6 };
    fwrite(bufWrite, sizeof(int), sizeof(bufWrite) / sizeof(int), fp);
    fclose(fp);

    fp = fopen("D:\\a.txt", "r");
    int bufRead[6] = { 0 };
    fread(bufRead, sizeof(int), sizeof(bufRead) / sizeof(int), fp);
    fclose(fp);
}

void CopyFile1()
{
    struct stat st;
    stat(AVISRC, &st);
    long sizeSrc = st.st_size;
    long lastReadSize = sizeSrc % Speed;
    long readCount = lastReadSize == 0 ? (sizeSrc / Speed) : (sizeSrc / Speed) + 1;
    printf("%ld\n", readCount);
    FILE *f1 = fopen(AVISRC, "rb");
    FILE *f2 = fopen(AVIDES, "wb");

    char *buf = (char *)malloc(sizeof(char)*Speed);
    long index = 0;
    for (long i = 0; i < readCount; i++)
    {
        memset(buf, 0, Speed);
        if (i == readCount - 1)
        {
            fread(buf, 1, lastReadSize, f1);
            fwrite(buf, 1, lastReadSize, f2);
        }
        else
        {
            fread(buf, 1, Speed, f1);
            fwrite(buf, 1, Speed, f2);
        }
    }
    fclose(f1);
    fclose(f2);
    free(buf);
}

void CopyFile2()
{
    FILE* pf1 = fopen(AVISRC, "rb");
    FILE* pf2 = fopen(AVIDES, "wb");

    int count = 0;
    struct stat s = { 0 };
    stat(AVISRC, &s);
    int filesize = s.st_size;

    char *	buff = (char*)malloc(Speed);

    while (!feof(pf1))
    {
        memset(buff, 0, Speed);
        count = fread(buff, 1, Speed, pf1);
        fwrite(buff, count, 1, pf2);
    }
    fclose(pf1);
    fclose(pf2);
    free(buff);
}

int CopyFile3(char *filename1, char *filename2)
{
    int ret = 0;
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    int plainlen;
    unsigned char plain[4096];
    int writtenlen;

    fp1 = fopen(filename1, "rb");
    if (fp1 == NULL)
    {
        ret = -1;
        printf("fopen: %s \n", filename1);
        goto End;
    }

    fp2 = fopen(filename2, "wb");
    if (fp2 == NULL)
    {
        ret = -2;
        printf("fopen: %s \n", filename2);
        goto End;
    }

    while (!feof(fp1))
    {
        plainlen = fread(plain, 1, 4096, fp1);
        if (feof(fp1))
        {
            break;
        }

        writtenlen = fwrite(plain, 1, plainlen, fp2);
        if (writtenlen != plainlen)
        {
            ret = -3;
            printf("判断释放IO错误\n");
            goto End;
        }
    }

    writtenlen = fwrite(plain, 1, plainlen, fp2);
    //判断释放IO错误
    if (writtenlen != plainlen)
    {
        ret = -4;
        printf("判断释放IO错误\n");
        goto End;
    }

End:
    if (fp1 != NULL)
    {
        fclose(fp1);
    }
    if (fp2 != NULL)
    {
        fclose(fp2);
    }
    return 0;
}