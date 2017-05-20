void ¼ÓºÅÔËËã·û()
{
    int i = 1;
    int a = i++ + i++ + i++; //3
    printf("%d \n", a);

    printf("%d\n", i); //4

    printf("%d\n", ++i);//5
    printf("%d\n", ++i);//6
    printf("%d\n", ++i);//7

    int b0 = ++i;
    printf("%d \n", b0);

    int b1 = ++i + ++i;
    printf("%d \n", b1);

    int b2 = ++i + ++i + ++i;
    printf("%d \n", b2);
}