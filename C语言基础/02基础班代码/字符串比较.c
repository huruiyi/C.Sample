int CompareStr1(char ch1[], char ch2[])
{
    if (strlen(ch1) != strlen(ch2))
    {
        return 0;
    }
    for (int k = 0; k < strlen(ch1); k++)
    {
        if (ch1[k] != ch2[k])
        {
            return 0;
        }
    }
    return 1;
}

int CompareStr2(char * s1, char * s2)
{
    if (strlen(s1) != strlen(s2))
    {
        return 0;
    }
    while (1)
    {
        //printf("%c-%c\n", *s1, *s2);
        if (*s1++ != *s2++)
        {
            return 0;
        }
    }
    return 1;
    /*
    char str1[] = { "hello" };
    char str2[] = { "hexlo" };
    int result = CompareStr2(str1, str2);
    printf("%s %s %s\n", str1, result ? "等于" : "不等于", str2);
    */
}