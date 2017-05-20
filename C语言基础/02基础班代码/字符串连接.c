void ×Ö·û´®Á¬½Ó()
{
    char c1[] = "hello";
    char c2[] = "world";
    char c3[100];
    int i = 0;
    int j = 0;
    while (c1[i] != '\0')
    {
        c3[i] = c1[i];
        i++;
    }
    do
    {
        c3[i + j] = c2[j];
        j++;
    } while (c1[i] == '\0');

    printf("%s\n", c3);
}