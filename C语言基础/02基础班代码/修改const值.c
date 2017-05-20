void 常量值的修改()
{
    //常量的只不安全，可通过指针修改
    const float PI = 3.1415926;
    printf("PI=%f\n", PI);
    float *p = &PI;
    *p = 3.11111111f;
    printf("PI=%f\n", PI);
}