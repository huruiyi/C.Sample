#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "DynamicArray.h"

DynamicSet *   Init_DynamicSet_Ele(int capacity)
{
    DynamicSet *ds = (DynamicSet *)malloc(sizeof(DynamicSet));
    ds->capacity = capacity;
    ds->size = 0;

    ds->data = (void **)malloc(sizeof(void *)*capacity);
    return ds;
}
/*
A   B    C   D   E   F   G   H    I
0    1    2   3   4    5   6   7    8     9

*/
void Insert_DynamicSet_Ele(DynamicSet *arr, int postion, void *data)
{
    if (NULL == arr || NULL == data)
    {
        return;
    }
    if (postion<0 || postion>arr->size)
    {
        postion = arr->size;
    }
    if (arr->size == arr->capacity)
    {

    }
}
void Delete_DynamicSet_Ele(DynamicSet *arr, int postion)
{
}
void Foreach_DynamicSet_Ele(DynamicSet *arr, void(*func)(void *))
{
}
void Destory_DynamicSet_Ele(DynamicSet *arr)
{
}