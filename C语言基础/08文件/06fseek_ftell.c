#include "heaad.h"

void fseek_ftell()
{
    FILE *fp = fopen("D:\\a.txt", "r");

    //���ļ���ʼ��ʼ����ƫ��
    //fseek(fp, 4, SEEK_SET);

    //���ļ�β����ʼ����ƫ��
    fseek(fp, -2, SEEK_END);
    long l = ftell(fp);
    printf("��ǰƫ������%ld\n", l);

    //rewind(fp);//����ƶ�����ʼλ��
    //fseek(fp, 1, SEEK_SET);

    //fseek(fp, 2, SEEK_CUR);

    char ch = fgetc(fp);
    fclose(fp);

    printf("%c", ch);
}