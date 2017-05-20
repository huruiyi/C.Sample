int 逗号运算符()
{
    //C语言中逗号运算符返回最后一个参数作为表达式的值
    int a = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("%d\n", a);

    int y, z, k;
    int x = (y = 4, z = 16, k = 32);
    printf("%d\n\n", x); //结果为：32

    return 0;
}