#define D双精度指针 double *
typedef double * T双精度指针;

void 求大小()
{
    D双精度指针 p1, p2;
    T双精度指针 p3, p4;
    printf("%d\t%d\n", sizeof(p1), sizeof(p2));
    printf("%d\t%d\n", sizeof(p3), sizeof(p4));
}