union
{
    int i;
    char x[2];
}a;

void ÁªºÏÌå()
{
    a.x[0] = 10;
    a.x[1] = 1;
    printf("a.i = %d\n", a.i);
    printf("&a.i = %p\n", &a.i);
    printf("&a.x[0] = %p\n", &a.x[0]);
    printf("&a.x[1] = %p\n", &a.x[1]);
}