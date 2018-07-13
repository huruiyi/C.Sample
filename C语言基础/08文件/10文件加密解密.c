#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // ��׼�����������

#include <stdlib.h>  // ��׼�⺯��
#include <string.h>  // �ַ���������


void printMenu(void);
int checkPwd(int type);
int encryptFile(char *sourcefile, char *secretKey, char *targetFile);
char redo(void);

 
int  password = 123456;  

int main() {
	/**
	* ���� password ������������Щ����ֻ��main()�����ڲ�ʹ��
	* ���Կ��Զ���Ϊ�ֲ���������������mian()�����ڲ�
	**/
	int newpwd, newpwda;  // ��������ʱ���û����������������
	char sourcefile[30],  // ����/���ܵ��ļ���
		targetFile[30],  // ����/���ܺ�Ҫ������ļ���
		secretKey[21],  // �ļ����ܵ���Կ
		action; // Ҫ���еĲ���

				// ����ǰ��У������
	if (!checkPwd(1)) {
		printf("��Ǹ��3������������󡣰�������˳�����...");
		getchar();
		exit(1);
	}

	while (1) {
		system("cls");  // ����
		printMenu();  // ��ʾ�˵�
		scanf("%c", &action);  // ����Ҫִ�еĲ���
		fflush(stdin);  // ���stdin������
		system("cls");

		switch (action) {
			// �˳�ϵͳ
		case 'z':
			exit(0);

		case 'a':
			while (1) 
			{
				printf("����Ҫ���ܵ��ļ���(��·��)��");
				scanf("%s", sourcefile);
				printf("������Կ��");  //��Կ���û��Լ�����ģ������������Ҫ���ܵ��ļ������Կ
				scanf("%s", secretKey);
				printf("���ܺ���ļ���(��·��)��");  //�����ܺ���ļ�������������
				scanf("%s", targetFile);
				if (encryptFile(sourcefile, secretKey, targetFile)) {
					printf("��ϲ�㣬�ļ�[%s]���ܳɹ���������[%s]��\n", sourcefile, targetFile);
				}

				if (redo() == 'a')
				{  // ���������ļ�
					system("cls");
				}
				else 
				{  // �ص����˵�
					break;
				}
			}
			break;

			// �ļ�����
		case 'b':
			while (1) {
				printf("����Ҫ���ܵ��ļ���(��·��)��");
				scanf("%s", sourcefile);
				printf("������Կ��");
				scanf("%s", secretKey);
				printf("���ܺ���ļ���(��·��)��");  //�Խ��ܵ��ļ�ϵͳ�ֿ����ṩ����·��
				scanf("%s", targetFile);
				if (encryptFile(sourcefile, secretKey, targetFile)) 
				{
					printf("��ϲ�㣬�ļ�[%s]���ܳɹ���������[%s]��\n", sourcefile, targetFile);
				}

				if (redo() == 'a') 
				{   
					system("cls");
				}
				else 
				{
					break;   
				}
			}
			break;

		case 'c':
			while (1) {
				if (!checkPwd(2)) 
				{
					printf("��Ǹ��3������������󡣰�������˳�����...");
					getchar();
					exit(0);
				}

				printf("�����������룺");
				scanf("%d", &newpwd);
				printf("���ٴ����������룺");
				scanf("%d", &newpwda);
				if (newpwd == newpwda)
				{  
					password = newpwd;
					printf("��ϲ�㣬�޸�����ɹ���\n");
				}
				else 
				{
					printf("�����������벻��ͬ���޸�ʧ�ܣ�\n");
				}
				if (redo() == 'a') {   
					system("cls");
				}
				else 
				{  
					break;
				}
			}
			break;

		default:
			printf("û����Ӧ�Ĳ˵�����������ص����˵�...");
			getchar();
		}
	}
}

/**
* ��ʾ����˵�
**/
void printMenu() {
	printf("***************** �ı����ܽ������ *****************\n");
	printf("*                                                  *\n");
	printf("*      **************************************      *\n");
	printf("*      *                                    *      *\n");
	printf("*      *  ��Ȩ���У�C����������             *      *\n");
	printf("*      *  ���ߣ�����                        *      *\n");
	printf("*      *  PS����Ҫ����Ϊʲô�й���          *      *\n");
	printf("*      *                                    *      *\n");
	printf("*      **************************************      *\n");
	printf("*                                                  *\n");
	printf("*                                                  *\n");
	printf("*      �������Ĳ˵���ѡ����Ҫ���еĲ�����        *\n");
	printf("*      a. �ļ�����                                 *\n");
	printf("*      b. �ļ�����                                 *\n");
	printf("*      c. ��������                                 *\n");
	printf("*      z. �˳�ϵͳ                                 *\n");
	printf("*                                                  *\n");
	printf("****************************************************\n");
}

 
int checkPwd(int type) {
	int pwd;  
	if (type == 1) {
		printf("�������������룬��֤ͨ�������ʹ�á�������6λ�������룺");
	}
	else {
		printf("��������ǰ������֤ԭ���롣������6λ����ԭ���룺");
	}
	// ������������
	for (int trytimes = 1; trytimes <= 3; trytimes++) {
		scanf("%d", &pwd);
		fflush(stdin);
		if (pwd == password) {
			return 1;
		}
		if (trytimes == 3)
		{
			return 0;
		}
		printf("��Ǹ���������������%d�λ��᣺", 3 - trytimes);
	}

	return 0;
}

 
int encryptFile(char *sourcefile, char *secretKey, char *targetFile)
{
	char buffer[21];  // �����������ڴ�Ŵ��ļ���ȡ������
	int readCount,  // ÿ�δ��ļ��ж�ȡ���ֽ���

		i;  // ѭ������
			// ��Կ�ĳ���
	const int keyLen = strlen(secretKey);

	// �Զ����Ʒ�ʽ��ȡ/д���ļ�
	FILE *fpSource = fopen(sourcefile, "rb");
	if (fpSource == NULL) {
		printf("�ļ�[%s]��ʧ�ܣ������ļ�·���������Ƿ�������ȷ��\n", sourcefile);
		return 0;
	}
	FILE *fpTarget = fopen(targetFile, "wb");
	if (fpTarget == NULL) {
		printf("�ļ�[%s]����/д��ʧ�ܣ������ļ�·���������Ƿ�������ȷ��\n", fpTarget);
		return 0;
	}
	while ((readCount = fread(buffer, 1, keyLen, fpSource)) > 0)
	{
		for (i = 0; i < readCount; i++) {
			buffer[i] ^= secretKey[i];
		}
		fwrite(buffer, 1, readCount, fpTarget);
	}

	fclose(fpSource);
	fclose(fpTarget);

	return 1;
}

char redo() {
	char action;

	printf("\n��������ϣ����\n");
	printf("a. ������ǰ����\n");
	printf("b. �ص����˵�\n");

	while (1)
	{
		fflush(stdin);
		scanf("%c", &action);
		fflush(stdin);
		if (action != 'a' && action != 'b') {
			printf("û����Ӧ�Ĳ˵���������ѡ��\n");
		}
		else 
		{
			return action;
		}
	}
}