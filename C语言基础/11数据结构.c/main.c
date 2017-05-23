#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<Windows.Media.Protection.PlayReadyResults.h>

#include "DynamicArray.h"
void main(void)
{
    DynamicSet * ds = Init_DynamicSet_Ele(10);
    for (int i = 0; i < 20; i++)
    {
        ds->data[i] = i + 10;
        Insert_DynamicSet_Ele(ds, i, i + 10);
    }
    system("pause");
}