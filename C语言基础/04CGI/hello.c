#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <stdio.h>

void main()
{
    printf("Content-Type:text/html \n\n");
    printf("<p style='color: red;'>CGIÍøÒ³±à³Ì£¡£¡£¡</p>");

    char * queryString = getenv("QUERY_STRING");
    char * userName = getenv("userName");
    char * userSkill = getenv("userSkill");
    char un[50] = "";
    char unValue[50] = "";
    char usk[50] = "";
    char uskValue[50] = "";

    sscanf(queryString, "%s=%s&%s=%s", &un, &unValue, &usk, &uskValue);

    printf("%s\n", queryString);
    printf("%s\n", un);
    printf("%s\n", unValue);
    printf("%s\n", usk);
    printf("%s\n", uskValue);

    printf("%s\n", userName);
    printf("%s\n", userSkill);
    getchar();
}