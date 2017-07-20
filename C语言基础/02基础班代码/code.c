#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>
/*
32位操作系统：
    2~32=2~2*2~10*2~10*2~10
            =4*1024*1024*1024
    1B=8b
    1k=1024B
    1M=1024kb
    1G=1024M
*/

void DrawTextDemo()
{
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);
    SetTextColor(hdc, RGB(255, 0, 0));
    SetBkColor(hdc, RGB(0, 0, 255));//设置背景

    while (1)
    {
        RECT rctext;
        rctext.left = 10;
        rctext.top = 10;
        rctext.right = 300;
        rctext.bottom = 300;
        DrawTextA(hdc, "XYZ", strlen("XYZ"), &rctext, DT_CENTER);
    }
}

void FindQQWindowDemo()
{
    while (1)
    {
        HWND win = FindWindowA("TXGuiFoundation", "QQ");//获取窗口
        POINT pt;
        pt.x = pt.y = 0;//初始化
        GetCursorPos(&pt);//获取位置
        SetWindowPos(win, NULL, pt.x, pt.y, 0, 0, 1);//1禁止改变窗口大小
    }
}

void MessageBoxDemo()
{
    for (int i = 0; i < 7; i++)
    {
        _beginthread(MessageBoxDemo, 0, NULL);
    }
    //Unicode不支持中文
    MessageBox(NULL, TEXT("你好吗"), TEXT("问候"), 1);

    MessageBoxA(0, "QQ登录失败，请重新登录", "QQ", 3);

    MessageBoxA(0, "你的360云盘存放的岛国大片被网络警察所监督", "请自首", 0);

    int result = MessageBox(NULL, TEXT("这是对话框"), TEXT("你好"), MB_ICONINFORMATION | MB_YESNO);
    switch (result)/*注意！使用Unicode应用TEXT包围字串*/
    {
    case IDYES:
        MessageBox(NULL, TEXT("您选择了YES"), TEXT("YES"), MB_OK);
        break;
    case IDNO:
        MessageBox(NULL, TEXT("您选择了NO"), TEXT("NO"), MB_OK);
        break;
    }
}

fuch(char *str)
{
    int num = 0;
    while (*(str + num) != '\0')
        num++;
    return num;

    //char str[10], *p = str;
    //gets(p);
    //printf("%d\n", fuch(p));
}

void 三目运算符优先级()
{
    //三目运算符优先级是从右到左
    // 比较运算符优先级大于三目运算符
    int w = 1;
    int x = 2;
    int y = 3;
    int z = 4;
    //w<x ? w : y<z ? y : z
    //1<2 ? 1 : 4<4 ？3 : 4
    //
    printf("%d\n", w < x ? w : y);
    printf("%d\n", y < z ? y : z);
    printf("%d\n", w < x ? w : 3);
    printf("%d\n", 1 < 3);
    printf("%d\n", w < x ? w : y < z ? y : z);
    printf("%d\n", w < x ? y : w < z ? y : z);
    printf("%d\n", 2 < 3);
    printf("%d\n", 3 > 3);
    printf("%d\n", 2 > 3);
}

void 优先级()
{
    //比较运算符优先级大于逻辑运算符
    int x = 1;
    int y = 0;
    int z = 1;
    printf("%d\n", x || y < z);
    printf("%d\n", 1 || 1);
    printf("%d\n", 0 || 1);
    printf("%d\n", 1 || 0);
}

//20 . 循环输入字母，并将每个字母逐行保存到 C:\code\test.txt 文件里，输入其他则退出循环。
void InputWorldDemo()
{
    FILE * fp = fopen("C:\\code\\test.txt", "w");
    if (fp == NULL)
    {
        perror("文件打开异常");
        return;
    }
    char buf[1024] = { 0 };
    char c[2] = { 0 };
    while (1)
    {
        gets_s(c, 2);
        if ((c[0] >= 'a'&&c[0] <= 'z') || (c[0] >= 'A'&&c[0] <= 'Z'))
        {
            fputc(c[0], fp);
        }
        else
        {
            fclose(fp);
            exit(0);
        }
    }
}

//22 . C语言编程实现文件拷贝.即使用C语言标准库函数，将test.avi 的内容拷贝到test1.avi 中。

void Demo1()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int xxxx = a < b ? a : c < d ? a : d;
    //  1<2?1:3<4?1:2
    printf("%d\n\n", xxxx);//结果为1
}
void Demo2()
{
    char ch[][2] = { "h","e","l","l","o" };

    printf("%d\t%d\n", sizeof(ch), strlen(ch));

    printf("%s\n", ch[0]);
    printf("%s\n", ch[0][1]);
    //printf("%s\n", ch[1]);
    //printf("%s\n", ch[2]);
    //printf("%s\n", ch[3]);
    //printf("%s\n", ch[4]);
}
void Dmeo3()
{
    int x = 23;
    do
    {
        printf("%2d\n", x--);
    } while (!x);//结果为23
}
void Demo4()
{
    int x = 1, a = 0, b = 0;
    switch (x)
    {
    case 0:
        b++;
    case 1:

        a++;
    case 2:
        a++;
        b++;
    }
    printf("a=%d,b=%d\n", a, b);
    //结果为 a=2,b=1
}
void Demo5()
{
    double a = 8, b = 5;
    int c;
    c = a / b + 0.5;
    printf("%d\n", c);
    //结果为：2
}
void Demo6()
{
    int x, y;
    for (x = 1, y = 1; x <= 100; x++)
    {
        if (y >= 20)
            break;
        if (y % 3 == 1)
        {
            y += 3;
            continue;
        }
        y -= 5;
    }
    printf("%d\n", x);
}
void Demo7()
{
    short sa = 0xfffe;
    printf("%d\n", sa); //结果为多少？
    printf("%X\n", sa); //结果为多少？
    printf("%p\n\n", &sa);

    unsigned short sa2 = 0xfffe;
    printf("%u\n\n", sa2); //结果为多少？

    short sa3 = 0x7fff + 2;
    printf("%d\n\n", sa3); //结果为多少？

    unsigned short sa4 = 0xffff + 5;
    printf("%u\n\n", sa4); //结果为多少？

    int num = 0x19;
    printf("%d\n", num + 1);
}
void Demo8()
{
    char str[50] = "xyz";
    char p1[10] = "abcd";
    char p2[] = "ABCD";
    printf("%s\n", (p1 + 2));
    printf("%s\n", (p2 + 1));
    printf("%s\n", strcat(p1 + 2, p2 + 1));
    strcpy(str + 2, strcat(p1 + 2, p2 + 1));
    printf("%s\n", str);
}
void Demo9()
{
    printf("%d\n", strlen("ATS\n012\1\\"));
    printf("%d\n", sizeof("ATS\n012\1\\"));
}
void DemoA()
{
    time_t t;// 时间的数据类型的变量T；
    srand((unsigned int)time(&t)); //time函数 仓鼠就是变量t的地址；
    int num = rand() % 100;
    printf("%d", num);
}
void DemoB()
{
    int abd = 35444;
    char sss[32];
    _itoa_s(abd, sss, 32, 2);//把变量cbd，就是你要转换的数把结果保存到sss这个字符数组里面。32是要调用的位数；打印成2进制；

    printf("BBBB%sAAAA", "hellworld");//字符串要带双引号
    puts("helleQianFei"); //输出一串字符；

    "A", 'A';//的大小不同，字符一个字节，字符串2个字节，字符串有个\0作为结束；
    char ch0 = 'a';
    char ch1 = "A";
    char ch2 = getchar();//等待输入一个字符。char=字符型，ch 变量名
    putchar(ch2);    //Print a character
}
void DemoC()
{
    int num = 1;
    char str[50];
    gets_s(str, 50);//输入一个字符串，字符长度是50；
    scanf_s("%d", &num);
    char abc[80];
    wsprintf(abc, "for /l %%i in (1,1,%d) do %s", num, str);//字符串格式化；把后面的字符串命令赋值到abc里面;
    //l按照数学循环；//  %i  整数变量; //do 是干活；//do 后面加@echo 不会打印命令执行的过程;
    system(abc);
}
void DemoD()
{
    keybd_event(0x5b, 0, 0, 0);//按下win键
    keybd_event('D', 0, 0, 0);//按下D键
    keybd_event('D', 0, 2, 0);//松开D键
    keybd_event(0x5b, 0, 2, 0);//松开win键

    Sleep(4000);//等待4秒
    SetCursorPos(35, 35);//鼠标移到屏幕35,35坐标做
    Sleep(4000);//等待4秒

    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//按下鼠标左键
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开鼠标左键
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//按下鼠标左键；
}
void DemoE()
{
    //char* path = "C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe";
    //ShellExecute(0, "open", path, 0, 0, SW_SHOWNORMAL);//0代表隐藏

    //对话框的类型0.纯粹提示，1代表是否，2，忽略，继续3.是否取消，
    system("start /b ping www.baidu.com -t");
    //ShellExecute(0,"open","calc.exe","","",SW_SHOWNORMAL);
    //ShellExecute(0,"open","notepad",0,0,3);
    ShellExecute(0, "open", "http://www.qq.com", 0, 0, 1);
    ShellExecute(0, "open", "C:\\Program Files (x86)\\Tencent\\QQ\\QQProtect\\Bin\\QQProtect.exe", 0, 0, 1);

    //1窗口的编号，谁打开的。0代表系统打开的
    //2"open" 操作,print
    //3“路径”
    //4,5默认的两个两个参数，默认都是0
    //6窗口显示，1一般状态，3最大化，6最小化
    system("pause");
}
void DemoF()
{
    int x = 1, y = 1;
    printf("%d\n", !x);
    printf("%d\n", y--);
    printf("%d\n", (!x || y--));
}
void DemoG()
{
    int x = 10;
    x += 3 + x % (3);
    printf("%d\n\n", x);
}

void GetTimeDemo()
{
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
}
void SystemInfo()
{
    system("ipconfig");	  //打印ipconfig信息
    system("ping www.qq.com");
    system("pause");//暂停
    system("C:\\CMD.exe");
    system("route print");
    system("taskkill /im  QQ.exe");
    system("pause");
}

void 位运算()
{
    int a = 7;
    int b = ~a;
    printf("[%d]\n", b);
}

void main(int args, char * argv[])
{
 
	加号运算符1();
    //printf("\n参数个数%d\n", args);
    //for (size_t i = 0; i < args; i++)
    //{
    //    printf("%s\n", argv[i]);
    //}

    HWND win = FindWindowA("Qt5QWindowIcon", "HydraViewer");//获取窗口
    if (win)
    {
        SetWindowText(win, TEXT("23期C++ STL课程讲解"));
    }


    system("pause");
}