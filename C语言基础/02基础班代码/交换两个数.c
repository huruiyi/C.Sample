void ����������0()
{
    int a = 10;
    int b = 20;
    printf("a=%d,b=%d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a=%d,b=%d\n", a, b);
}

void ����������1()
{
    int a = 10;
    int b = 20;
    printf("a=%d,b=%d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("a=%d,b=%d\n", a, b);
}

void ����������2()
{
    int a = 10;
    int b = 20;
    printf("a=%d,b=%d\n", a, b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a=%d,b=%d\n", a, b);
}