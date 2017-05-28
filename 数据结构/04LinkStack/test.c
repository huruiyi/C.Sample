#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.h"

typedef struct Persion
{
	Node node;
	int age;
	char name;
}Persion;

#if 1
int main()
{
	Persion p[10];
	LinkStack list;
	InitStack(&list);
	// Ñ¹Õ»
	for (int i = 0; i < 10; i++)
	{
		p[i].age = i + 10;
		p[i].name = 'a' + i;
		Push(&list, &p[i].node);
	}
	printf("stack size = %d\n", Size(&list));

	// ³öÕ»
	while (Size(&list))
	{
		Persion* pt = (Persion*)GetTop(&list);
		printf("name = %c, age = %d\n", pt->name, pt->age);
		Pop(&list);
	}
	printf("stack size = %d\n", Size(&list));

	system("pause");
	return 0;
}
#endif