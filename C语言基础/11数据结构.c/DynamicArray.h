#ifndef _DynamicArray_H_
#define _DynamicArray_H_

typedef struct  DynamicArray
{
    //����������Ԫ������
    int capacity;
    //��ǰԪ������
    int size;
    void **data;
} DynamicSet;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    DynamicSet *   Init_DynamicSet_Ele(int capacity);
    void Insert_DynamicSet_Ele(DynamicSet *arr, int postion, void *data);
    void Delete_DynamicSet_Ele(DynamicSet *arr, int postion);
    void Foreach_DynamicSet_Ele(DynamicSet *arr, void(*func)(void *));
    void Destory_DynamicSet_Ele(DynamicSet *arr);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !_DynamicArray_H_