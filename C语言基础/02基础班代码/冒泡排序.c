void PrintfArr(int * arr, int len)
{
    printf("\n\t");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(arr + i));
    }
}

void √∞≈›≈≈–Ú0()
{
    int arr[] = { 15,268,21,8,59,88,226,21,33,8 };
    int length = sizeof(arr) / sizeof(int);

    printf("≈≈–Ú«∞£∫");
    PrintfArr(arr, length);
    printf("\n≈≈–Úø™ º£∫\n");

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
        printf("\n******************************************************************************************\n");
        PrintfArr(arr, length);
    }

    printf("\n≈≈–Ú∫Û£∫");
    PrintfArr(arr, length);
}

void √∞≈›≈≈–Ú1()
{
    int arr[] = { 15,268,21,8,59,88,226,21,33,8 };
    int length = sizeof(arr) / sizeof(int);
    printf("≈≈–Ú«∞£∫");
    PrintfArr(arr, length);
    printf("\n≈≈–Úø™ º£∫\n");
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            PrintfArr(arr, length);
        }
        printf("\n******************************************************************************************\n");
        PrintfArr(arr, length);
    }
    printf("\n≈≈–Ú∫Û£∫");
    PrintfArr(arr, length);
}

void BubbleSort(int * arr, int len)//Õ’∑Â «√¸√˚  Linuxœ¬  bubble_sort  win int _i_role_level
{
    //printf("%d\n", sizeof(int *));
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}