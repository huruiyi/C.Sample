void ��ά����()
{
    //int arr[3][4] =
    //{
    //	{1,2,3,4},
    //	{5,6,7,8},
    //	{10,11,12,13}
    //};
    //printf("%p\n", arr);

    int arr[2][3] = { 1,2,3,4,5,6 };
    printf("�ܳ��ȣ�%d\n", sizeof(arr));
    printf("�г��ȣ�%d\n", sizeof(arr[0]));
    printf("�У�%d\n", sizeof(arr) / sizeof(arr[0]));

    printf("�г��ȣ�%d\n", sizeof(arr[0]));
    printf("��Ԫ�س��ȣ�%d\n", sizeof(arr[0][0]));
    printf("�У�%d\n", sizeof(arr[0]) / sizeof(int));

    printf("�����Ԫ�ظ�����%d\n", (sizeof(arr) / sizeof(arr[0]))*(sizeof(arr[0]) / sizeof(int)));
    printf("%p\n", &arr[0][0]);
    printf("%p\n", arr);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", *(&(arr[0][0]) + i));
    }
}