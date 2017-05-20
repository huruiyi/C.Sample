#include "heaad.h"

void fprintf_demo()
{
    srand((unsigned int)time(NULL));
    FILE * fp = fopen("D:\\a.txt", "w");

    for (int i = 0; i < 256; i++)
    {
        fprintf(fp, "%d\n", rand() % 256);//0-255
    }

    fclose(fp);
}

void fprintf_fscanf_demo()
{
    FILE * fp = fopen("D:\\a.txt", "r");

    int arr[256];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < 256; i++)
    {
        fscanf(fp, "%d\n", &arr[i]);
    }
    fclose(fp);

    fp = fopen("D:\\a.txt", "w");

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 256; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
}