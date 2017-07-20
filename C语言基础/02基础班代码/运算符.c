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

void 加号运算符()
{
    int i = 1;
    int a = i++ + i++ + i++; //3
    printf("%d \n", a);

    printf("%d\n", i); //4

    printf("%d\n", ++i);//5
    printf("%d\n", ++i);//6
    printf("%d\n", ++i);//7

    int b0 = ++i;
    printf("%d \n", b0);

    int b1 = ++i + ++i;
    printf("%d \n", b1);

    int b2 = ++i + ++i + ++i;
    printf("%d \n", b2);
}

void 加号运算符1()
{
	int a = 3;
	printf("%d, %d, %d, %d", a, a++, a, a++);
}