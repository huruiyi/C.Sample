#include "heaad.h"

char * GetFileTime(time_t * time_t)
{
    char buf[65];
    struct  tm * t = localtime(time_t);
    sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return buf;
}

void GetFileInfo()
{
    struct	stat  st;
    stat("D:\\Software\\xunlei\\ChromeStandalone_57.0.2987.133_Setup.exe", &st);
    printf("%u\n", st.st_dev);
    printf("%u\n", st.st_ino);
    printf("%u\n", st.st_rdev);
    printf("%u\n", st.st_size);

    time_t st_atime = st.st_atime;
    char time1[120] = { 0 };
    strcpy(time1, GetFileTime(&st_atime));

    time_t st_mtime = st.st_mtime;
    char time2[120] = { 0 };
    strcpy(time2, GetFileTime(&st_mtime));

    time_t st_ctime = st.st_ctime;
    char time3[120] = { 0 };
    strcpy(time3, GetFileTime(&st_ctime));

    printf("创建时间：%s\n", time3);
    printf("修改时间：%s\n", time2);
    printf("访问时间：%s\n", time1);
}