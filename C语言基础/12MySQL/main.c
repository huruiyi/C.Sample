#include <stdio.h>
#include<stdlib.h>
#include<winsock.h>
#include<mysql.h>
#include<limits.h>
/*
����:
1:VC++Ŀ¼:
����Ŀ¼:C:\Program Files\MySQL\MySQL Server 5.7\include
��Ŀ¼:C:\Program Files\MySQL\MySQL Server 5.7\lib
2:������==>����==>����������:libmysql.lib
3:����libmysql.dll �ļ�����ǰԴ�ļ�Ŀ¼
ע������:
Ŀ��汾ע����32λ����64λ
*/
const char *host = "localhost";
const char *user = "root";
const char *passwd = "mima!";
const char *db = "test";
const unsigned int port = 3306;
void InsertData()
{
    MYSQL *mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, host, user, passwd, db, 3306, 0, 0);
    if (!mysql)
    {
        printf("���ݿ�����ʧ��");
        return;
    }
    char *insertSql = "INSERT into userinfo (username,password,login_time,login_ip,login_counts) VALUES('huhu','fe01ce2a7fbac8fafaed7c982a04e229','1427869253','127.0.0.1',5)";
    int insertresult = mysql_query(mysql, insertSql);//����һ������
    if (insertresult == 0)
    {
        my_ulonglong identyid = mysql_insert_id(mysql);//��ȡ�������ݺ���������Id
        printf("������ӳɹ�:��������Id:%d\n\n", identyid);
    }
    else
    {
        printf("�������ʧ��\n");
    }
    //mysql_free_result(mysql);//�Ž���ڴ�
    mysql_close(mysql);//�ر����ݿ�����
    mysql_library_end();
}
void SelectData1()
{
    MYSQL *mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, host, user, passwd, db, 3306, 0, 0);
    if (!mysql)
    {
        printf("���ݿ�����ʧ��");
        return;
    }
    mysql_query(mysql, "UNLOCK TABLES");
    const char *selectSql = "select * from test.userinfo";
    int queryResult = mysql_query(mysql, selectSql);
    if (queryResult == 0)//��ѯ������
    {
        MYSQL_RES *result = mysql_store_result(mysql);
        MYSQL_ROW row;
        while (row = mysql_fetch_row(result))
        {
            char *id = row[0];
            char *userName = row[1];
            char *password = row[2];
            printf("id=%s\tusername=%s\tpassword=%s\t\n", id, userName, password);
        }
    }
    else
    {
        printf("δ��ѯ���������\n");
    }
    //mysql_free_result(mysql);//�Ž���ڴ�
    mysql_close(mysql);//�ر����ݿ�����
    mysql_library_end();
}
void Select_data_filed()
{
    MYSQL *mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, host, user, passwd, db, 3306, 0, 0);
    if (!mysql)
    {
        printf("���ݿ�����ʧ��");
        return;
    }
    int queryResult = mysql_query(mysql, "select * from test.userinfo limit 1");
    MYSQL_RES *result = mysql_store_result(mysql);
    unsigned int num_fields;
    unsigned int i;
    MYSQL_FIELD *fields;
    if (queryResult == 0)
    {
        num_fields = mysql_num_fields(result);
        fields = mysql_fetch_fields(result);
        for (i = 0; i < num_fields; i++)
        {
            printf("Field %u is %s\n", i, fields[i].name);
        }
        printf("\n");
        MYSQL_FIELD *field;
        for (i = 0; i < num_fields; i++)
        {
            field = mysql_fetch_field(result);
            printf("Field %u is %s\n", i, field[0].name);
        }
    }
    //mysql_free_result(mysql);//�Ž���ڴ�
    mysql_close(mysql);//�ر����ݿ�����
    mysql_library_end();
}
void main()
{
    //InsertData();
    //SelectData1();
    Select_data_filed();
    getchar();
}