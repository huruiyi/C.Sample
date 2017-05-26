void PrintfArr(int * arr, int len)
{
    printf("\n\t");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(arr + i));
    }
}

void BubbleSort(int *arr, int length)
{
    int flag = 0;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!flag)
        {
            return;
        }
        flag = 0;
    }
}

//选择排序：原生版
void SelectSort0(int * arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//选择排序：优化版
void SelectSort1(int * arr, int len)
{
    int min = 0;
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
//选择排序：测试实例
void SelectSortDemo(void)
{
    int arr[] = { 5,3,8,7,1,6,8,2,4 };
    int len = sizeof(arr) / sizeof(arr[0]);
    SelectSort1(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    system("pause");
}

void InsertSort(int *arr, int len)
{
    int pos = 0;
    int temp = 0;
    //无序序列
    for (int i = 1; i < len; i++)
    {
        temp = arr[i];
        pos = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                pos = j;
            }
            else
            {
                break;
            }
        }
        arr[pos] = temp;
    }
}
void InsertSortDemo()
{
    int arr[] = { 5,3,8,7,1,6,8,2,4 };
    int len = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    system("pause");
}