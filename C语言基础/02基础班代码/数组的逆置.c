void Êı×éµÄÄæÖÃ()
{
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int length = (sizeof(arr) / sizeof(int));
    for (int i = 0; i < length / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
}