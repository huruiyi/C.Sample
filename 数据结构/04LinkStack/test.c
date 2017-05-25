#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "LinkStack.h"

void main(void)
{
    LinkStack  list;
    InitStack(&list);
    int arr[15];
    struct N {
        Node node;
        int s;
    };
    struct N n[15];
    for (int i = 0; i < 15; i++)
    {
        n[i].s = 10 + i;
        //printf("%d---%p\n", n[i].s, &n[i]);
        Push(&list, &n[i]);
    }
    printf("stack size = %d\n", Size(&list));

    while (Size(&list))
    {
        struct N * pdata = (struct N *)GetTop(&list);
        printf("%d\n", pdata->s);
        Pop(&list);
    }
    printf("stack size = %d\n", Size(&list));

    system("pause");
}