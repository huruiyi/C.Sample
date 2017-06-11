#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DArray.h"

DArray* Init_DArray(int capacity)
{
    DArray* ptr = (DArray*)malloc(sizeof(DArray));
    // ��ʼ������
    ptr->capacity = capacity;
    ptr->size = 0;
    // ���ָ�� (void*)������
    ptr->data = malloc(sizeof(void*) * capacity);

    return ptr;
}

void Insert_DArray(DArray* arry, int pos, void* data)
{
    // ������
    if (NULL == arry || data == NULL)
    {
        return;
    }
    // pos λ��
    if (pos < 0 || pos > arry->size)
    {
        // Ԫ�ز��뵽�����β��
        pos = arry->size;
    }

    // ��������
    // �����������, ��Ҫ���¿����ڴ�
    if (arry->capacity == arry->size)
    {
        // ���ڴ��Ƕ�ô��, ���򿪷���Ա�ƶ�
        int size = arry->capacity * 2;
        void **space = malloc(sizeof(void*)* size);
        // �����ݿ��������ڴ�
        memcpy(space, arry->data, sizeof(void*)* arry->size);

        // �ͷž��ڴ�
        free(arry->data);
        arry->capacity = size;
        arry->data = space;
    }

    // ���ݵĲ���
    // ��β����posλ���ƶ�Ԫ�� - ����ƶ�
    for (int i = arry->size; i > pos; --i)
    {
        arry->data[i] = arry->data[i - 1];
    }

    // �洢����
    arry->data[pos] = data;
    arry->size++;
}

void Traverse_DArray(DArray* arry, void(*print)(void*))
{
    // ��������
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
    // ��pos+1��len-1Ԫ������ǰ��
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
    // �ͷ�void*����
    if (arry->data)
    {
        free(arry->data);
        arry->data = NULL;
    }
    free(arry);
}