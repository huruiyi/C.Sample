void ShutDownComputer()
{
    system("title C���Թػ�����");
    system("mode con cols=48 lines=25");
    system("color f0");
    system("date /T");

    printf("--------------C���Թػ�����--------------\n");
    printf("1:ʵ��10���Ӻ�رռ����\n");
    printf("2:�����رռ����\n");
    printf("3:ע�������\n");
    printf("4:ȡ��������ػ��ƻ�\n");
    printf("0:�˳�ϵͳ\n");
    printf("-----------------------------------------\n");
    int c;
    printf("������ָ��:\n");
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