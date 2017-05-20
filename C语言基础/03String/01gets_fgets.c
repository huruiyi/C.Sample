#include "head.h"
void gets_demo()
{
    /*
    gets(s) 函数中的变量s为一字符串指针。
    如果为单个字符指针，编译连接不会有错误，但运行后内存溢出错误。
    宽字符版本，当使用unicode宽字符文本时，使用这个函数 _getws();
    在C11标准中被删除，可用C标准库中的fgets代替.
    */
    /*允许输入空格,输入过多字符会报错，不安全*/
    char ss[10] = "123456789\0";
    printf("%s\n", ss);
    printf("请输入: ");
    gets(ss);
    printf("%s\n", ss);
}

void fgets_demo()
{
    /*允许输入空格,输入过多字符会自动截取多余的，是安全,,会自动换行*/
    //char str[5] = {0};
    //fgets(str, sizeof(str), stdin);
    //printf("[%s]", str);

    //fgets在文件中进行读写操作  也可以接收字符串
    //如果接收到的字符串长度小于字符串的长度在字符串结束时加上\n\023
    //接收长度大于字符串长度  先接收前9个字符  等在换行 将\n替换为\0
    //fgets是安全的

    char ch1[10] = "hello"; //此处的初始化，不会输出
    fgets(ch1, 10, stdin); //此处可能出错
    printf("{%s}", ch1);
}