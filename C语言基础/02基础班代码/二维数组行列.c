void 二维数组()
{
    //int arr[3][4] =
    //{
    //	{1,2,3,4},
    //	{5,6,7,8},
    //	{10,11,12,13}
    //};
    //printf("%p\n", arr);

    int arr[2][3] = { 1,2,3,4,5,6 };
    printf("总长度：%d\n", sizeof(arr));
    printf("列长度：%d\n", sizeof(arr[0]));
    printf("行：%d\n", sizeof(arr) / sizeof(arr[0]));

    printf("列长度：%d\n", sizeof(arr[0]));
    printf("单元素长度：%d\n", sizeof(arr[0][0]));
    printf("列：%d\n", sizeof(arr[0]) / sizeof(int));

    printf("数组的元素个数：%d\n", (sizeof(arr) / sizeof(arr[0]))*(sizeof(arr[0]) / sizeof(int)));
    printf("%p\n", &arr[0][0]);
    printf("%p\n", arr);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", *(&(arr[0][0]) + i));
    }
}