void ShutDownComputer()
{
    system("title C语言关机程序");
    system("mode con cols=48 lines=25");
    system("color f0");
    system("date /T");

    printf("--------------C语言关机程序--------------\n");
    printf("1:实现10分钟后关闭计算机\n");
    printf("2:立即关闭计算机\n");
    printf("3:注销计算机\n");
    printf("4:取消计算机关机计划\n");
    printf("0:退出系统\n");
    printf("-----------------------------------------\n");
    int c;
    printf("请输入指令:\n");
    scanf("%d", &c);
    switch (c)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("shutdown -s -t 600");
        break;
    case 2:
        system("shutdown -p");
        break;
    case 3:
        system("shutdown -l");
        break;
    case 4:
        system("shutdown -a");
        break;
    default:
        break;
    }
}