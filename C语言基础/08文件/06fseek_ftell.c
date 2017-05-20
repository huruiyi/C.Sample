#include "heaad.h"

void fseek_ftell()
{
    FILE *fp = fopen("D:\\a.txt", "r");

    //从文件起始开始向右偏移
    //fseek(fp, 4, SEEK_SET);

    //从文件尾部开始向左偏移
    fseek(fp, -2, SEEK_END);
    long l = ftell(fp);
    printf("当前偏移量：%ld\n", l);

    //rewind(fp);//光标移动到起始位置
    //fseek(fp, 1, SEEK_SET);

    //fseek(fp, 2, SEEK_CUR);

    char ch = fgetc(fp);
    fclose(fp);

    printf("%c", ch);
}