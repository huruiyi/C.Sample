#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Persion
{
	int id;
	int age;
}Persion;

int main()
{
	Persion p[10];
	// 创建一个管理栈的结构体变量
	SeqStack st;
	InitStack(&st);
	// 数据压栈
	for (int i = 0; i < 10; ++i)
	{
		p[i].id = i;
		p[i].age = i + 20;
		PushStack(&st, &p[i]);
	}
	printf("stack size = %d\n", sizeStack(&st));
	// 出栈
	while (sizeStack(&st))
	{
		Persion* pt = (Persion*)GetTop(&st);
		printf("id = %d, age = %d\n", pt->id, pt->age);
		PopStack(&st);
	}
	printf("stack size = %d\n", sizeStack(&st));
	system("pause");
	return 0;
}