#ifndef _DARRAY_H
#define _DARRAY_H

// 自定义一个结构体 - 动态数组
// 操作动态数组
typedef struct darray
{
    // 容量
    int capacity;
    // 长度-已经存储的元素个数
    int size;
    // 存储数据的数组
    // 存储任意的数据类型
    // void* data[];
    void** data;
}DArray;

// 告诉C++编译器用C的方式编译以下函数
#ifdef __cplusplus
extern "C" {
#endif

    // 函数声明
    // 初始化动态数组
    DArray* Init_DArray(int capacity);
    // 元素的插入
    void Insert_DArray(DArray* arry, int pos, void* data);
    // 元素的删除
    void Delete_DArray(DArray*arry, int pos);
    // 遍历 - 打印数组的值
    // 不知道数据的实际类型 - 提供一个回调函数
    // 用户知道, 让用户提供遍历函数, 在当前接口中调用用户提供的接口函数
    // 函数指针作用 - 实现回调函数
    // 函数指针就是函数的地址 - 函数名
    // 回调函数的特点:
    // --	需要用户自己写, 不需要用掉用(需要提供一个函数指针)
    // --   实现的普通函数: 字节写, 自己调用
    void Traverse_DArray(DArray* arry, void(*print)(void*));
    // 释放动态数组
    void Destroy_DArray(DArray* arry);

#ifdef __cplusplus
}
#endif

#endif