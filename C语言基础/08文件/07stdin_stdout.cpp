#include "heaad.h"

void stdin_stdout()
{
    int a = 0;
    fclose(stdin);
    fclose(stdout);
    perror("file open error");
    scanf("%d", &a);
    printf("%d\n", a);
}
/*
fgets:���Զ���\n����
fputs:���Զ���\n����
*/
void fgets_stdin_fputs_stdout()
{
    char str[10];
    printf("������str: ");
    fgets(str, sizeof(str), stdin);
    printf("[%s]", str);

    fputs("hello world\n", stdout);
}