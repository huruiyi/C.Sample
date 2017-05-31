#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkQueue.h"

// 指针的本质 unsigned int
// %p 
typedef struct Persion
{
	Node node;
	int id;
	int age;
}Persion;

int main()
{
	Persion p[10];
	LinkQueue q;
	InitSeqQueue(&q);
	// 入队列
	for (int i = 0; i < 10; ++i)
	{
		p[i].age = i + 20;
		p[i].id = i;
		PushQ(&q, &p[i]);
	}
	printf("queue size = %d\n", SizeQ(&q));

	// 出队列
	while (SizeQ(&q))
	{
		Persion* p = (Persion *)GetHead(&q);
		printf("id = %d, age = %d\n", p->id, p->age);
		PopQ(&q);
	}
	printf("queue size = %d\n", SizeQ(&q));
	system("pause");
	return 0;
}