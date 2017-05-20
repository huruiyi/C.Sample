void 数据类型字节大小()
{
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(int));

    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));

    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(long long));

    int f[2];
    printf("%d\n", sizeof(f));

    /*
        在32位平台，所有的指针（地址）都是32位(4字节)
        在64位平台，所有的指针（地址）都是64位(8字节)
    */
    int *p = f;
    printf("%d\n", sizeof(p));
    printf("sizeof(char *)=%d\n", sizeof(char *));
    printf("sizeof(short *)=%d\n", sizeof(short *));
    printf("sizeof(int *)=%d\n", sizeof(int *));
    printf("sizeof(long *)=%d\n", sizeof(long *));
    printf("sizeof(long long *)=%d\n", sizeof(long long *));
    printf("sizeof(double *)=%d\n", sizeof(double *));
    printf("sizeof(float *)=%d\n", sizeof(float *));
}

void 数据类型长度()
{
    unsigned int a1 = 1;
    int a2 = 1;

    printf("sizeof(a1)=%d,sizeof(a1)=%d\n", sizeof(a1), sizeof(a2));

    unsigned short b1 = 1;
    short b2 = 1;
    printf("sizeof(b1)=%d,sizeof(b1)=%d\n", sizeof(b1), sizeof(b2));

    float c = 12.12;
    double d = 12.12;
    printf("sizeof(c)=%d,sizeof(d)=%d\n", sizeof(c), sizeof(d));
}