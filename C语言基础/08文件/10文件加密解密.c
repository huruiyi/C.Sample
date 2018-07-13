#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // 标准输入输出函数

#include <stdlib.h>  // 标准库函数
#include <string.h>  // 字符串处理函数


void printMenu(void);
int checkPwd(int type);
int encryptFile(char *sourcefile, char *secretKey, char *targetFile);
char redo(void);

 
int  password = 123456;  

int main() {
	/**
	* 不像 password 变量，下面这些变量只在main()函数内部使用
	* 所以可以定义为局部变量，即定义在mian()函数内部
	**/
	int newpwd, newpwda;  // 更改密码时，用户两次输入的新密码
	char sourcefile[30],  // 加密/解密的文件名
		targetFile[30],  // 解密/加密后要保存的文件名
		secretKey[21],  // 文件加密的密钥
		action; // 要进行的操作

				// 操作前先校验密码
	if (!checkPwd(1)) {
		printf("抱歉，3次输入密码错误。按任意键退出程序...");
		getchar();
		exit(1);
	}

	while (1) {
		system("cls");  // 清屏
		printMenu();  // 显示菜单
		scanf("%c", &action);  // 输入要执行的操作
		fflush(stdin);  // 清空stdin缓冲区
		system("cls");

		switch (action) {
			// 退出系统
		case 'z':
			exit(0);

		case 'a':
			while (1) 
			{
				printf("输入要加密的文件名(含路径)：");
				scanf("%s", sourcefile);
				printf("输入密钥：");  //密钥是用户自己定义的，可以随意给需要加密的文件添加密钥
				scanf("%s", secretKey);
				printf("加密后的文件名(含路径)：");  //给加密后的文件命名，并保存
				scanf("%s", targetFile);
				if (encryptFile(sourcefile, secretKey, targetFile)) {
					printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", sourcefile, targetFile);
				}

				if (redo() == 'a')
				{  // 继续加密文件
					system("cls");
				}
				else 
				{  // 回到主菜单
					break;
				}
			}
			break;

			// 文件解密
		case 'b':
			while (1) {
				printf("输入要解密的文件名(含路径)：");
				scanf("%s", sourcefile);
				printf("输入密钥：");
				scanf("%s", secretKey);
				printf("解密后的文件名(含路径)：");  //对解密的文件系统又可以提供保存路径
				scanf("%s", targetFile);
				if (encryptFile(sourcefile, secretKey, targetFile)) 
				{
					printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", sourcefile, targetFile);
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
					printf("抱歉，3次输入密码错误。按任意键退出程序...");
					getchar();
					exit(0);
				}

				printf("请输入新密码：");
				scanf("%d", &newpwd);
				printf("请再次输入新密码：");
				scanf("%d", &newpwda);
				if (newpwd == newpwda)
				{  
					password = newpwd;
					printf("恭喜你，修改密码成功！\n");
				}
				else 
				{
					printf("两次输入密码不相同，修改失败！\n");
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
			printf("没有相应的菜单！按任意键回到主菜单...");
			getchar();
		}
	}
}

/**
* 显示程序菜单
**/
void printMenu() {
	printf("***************** 文本加密解密软件 *****************\n");
	printf("*                                                  *\n");
	printf("*      **************************************      *\n");
	printf("*      *                                    *      *\n");
	printf("*      *  版权所有：C语言中文网             *      *\n");
	printf("*      *  作者：棍哥                        *      *\n");
	printf("*      *  PS：不要问我为什么叫棍哥          *      *\n");
	printf("*      *                                    *      *\n");
	printf("*      **************************************      *\n");
	printf("*                                                  *\n");
	printf("*                                                  *\n");
	printf("*      请从下面的菜单中选择你要进行的操作：        *\n");
	printf("*      a. 文件加密                                 *\n");
	printf("*      b. 文件解密                                 *\n");
	printf("*      c. 更改密码                                 *\n");
	printf("*      z. 退出系统                                 *\n");
	printf("*                                                  *\n");
	printf("****************************************************\n");
}

 
int checkPwd(int type) {
	int pwd;  
	if (type == 1) {
		printf("程序设置了密码，验证通过后才能使用。请输入6位数字密码：");
	}
	else {
		printf("重置密码前必须验证原密码。请输入6位数字原密码：");
	}
	// 可以输入三次
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
		printf("抱歉，密码错误，您还有%d次机会：", 3 - trytimes);
	}

	return 0;
}

 
int encryptFile(char *sourcefile, char *secretKey, char *targetFile)
{
	char buffer[21];  // 缓冲区，用于存放从文件读取的数据
	int readCount,  // 每次从文件中读取的字节数

		i;  // 循环次数
			// 密钥的长度
	const int keyLen = strlen(secretKey);

	// 以二进制方式读取/写入文件
	FILE *fpSource = fopen(sourcefile, "rb");
	if (fpSource == NULL) {
		printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", sourcefile);
		return 0;
	}
	FILE *fpTarget = fopen(targetFile, "wb");
	if (fpTarget == NULL) {
		printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", fpTarget);
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

	printf("\n接下来你希望：\n");
	printf("a. 继续当前操作\n");
	printf("b. 回到主菜单\n");

	while (1)
	{
		fflush(stdin);
		scanf("%c", &action);
		fflush(stdin);
		if (action != 'a' && action != 'b') {
			printf("没有相应的菜单，请重新选择。\n");
		}
		else 
		{
			return action;
		}
	}
}