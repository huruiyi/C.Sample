#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DArray.h"

DArray* Init_DArray(int capacity)
{
    DArray* ptr = (DArray*)malloc(sizeof(DArray));
    // 初始化操作
    ptr->capacity = capacity;
    ptr->size = 0;
    // 存放指针 (void*)的数组
    ptr->data = malloc(sizeof(void*) * capacity);

    return ptr;
}

void Insert_DArray(DArray* arry, int pos, void* data)
{
    // 错误处理
    if (NULL == arry || data == NULL)
    {
        return;
    }
    // pos 位置
    if (pos < 0 || pos > arry->size)
    {
        // 元素插入到数组的尾部
        pos = arry->size;
    }

    // 插入数据
    // 如果数据已满, 需要重新开辟内存
    if (arry->capacity == arry->size)
    {
        // 新内存是多么大, 规则开发人员制定
        int size = arry->capacity * 2;
        void **space = malloc(sizeof(void*)* size);
        // 旧数据拷贝到新内存
        memcpy(space, arry->data, sizeof(void*)* arry->size);

        // 释放旧内存
        free(arry->data);
        arry->capacity = size;
        arry->data = space;
    }

    // 数据的插入
    // 从尾部到pos位置移动元素 - 向后移动
    for (int i = arry->size; i > pos; --i)
    {
        arry->data[i] = arry->data[i - 1];
    }

    // 存储数据
    arry->data[pos] = data;
    arry->size++;
}

void Traverse_DArray(DArray* arry, void(*print)(void*))
{
    // 遍历数组
    for (int i = 0; i < arry->size; ++i)
    {
        print(arry->data[i]);
    }
}

void Delete_DArray(DArray*arry, int pos)
{
    if (NULL == arry)
    {
        return;
    }
    if (pos < 0 || pos >= arry->size)
    {
        return;
    }
    // 从pos+1到len-1元素依次前移
    for (int i = pos + 1; i < arry->size; ++i)
    {
        arry->data[i - 1] = arry->data[i];
    }
    arry->size--;
}

void Destroy_DArray(DArray* arry)
{
    if (arry == NULL)
    {
        return;
    }
    // 释放void*数组
    if (arry->data)
    {
        free(arry->data);
        arry->data = NULL;
    }
    free(arry);
}