int 指针数组偏移()
{
    int a[5] = { 1,2,3,4,5 };

    int *p1 = a;
    int *p3 = a + 1;

    int *p2 = &a;
    int *p4 = &a + 1;

    int *p5 = (int *)(a + 1);
    int *p6 = (int *)(&a + 1);
    printf("1:%x	%x\n", &a, a);
    printf("2:%d	%d\n", *(&a), *a);

    // &a + 1		 ：指的是移动到数组尾部
    //(&a + 1)-1 ：恢复数组
    printf("3:%x		%x\n", a + 1, &a + 1);
    printf("4:%d		%d	%d\n", *(a + 1), *((&a + 1) - 1)[0], *(&a + 1)[0]);

    printf("%d	%d\n", *p2, *p1);
    printf("%d	%d\n", *p2, *(p2 - 1));

    printf("%d	%d\n", *(p3), *(p3 - 1));

    printf("%d	%d\n", *(p4), *(p4 - 1));
    printf("%d	%d\n", *(p4 + 1), *(p4 - 1));

    printf("%d	%d\n", *(p5), *(p5 - 1));

    printf("%d	%d\n", *(p6), *(p6 - 1));

    return 0;
}

void 字符串的偏移()
{
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 }, *p = &a[3], b;
    b = p[5];

    char *ptr = "thisisademo!";
    ptr += 1;
    printf("%s", ptr);

    char *ch = "123456";
    printf("%s\n%s\n\n", ch + 1, &ch[1]);

    char chx[1024] = "0123456789\0";
    printf("%s\n", chx + 1);//ok
    printf("%s\n", chx + 1);//ok

    //printf("%s\n", chx[0]); //error
    //printf("%s\n", chx[1]); //error

    //system("pause");
}