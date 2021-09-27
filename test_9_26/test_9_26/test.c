#define _CRT_SECURE_NO_WARNINGS 1


// 文件
// 磁盘上的文件
// 以文件功能分类：
// 程序文件：源程序文件test.c 目标文件test.obj 可执行程序test.exe
// 数据文件：data.txt


// 每一个打开的文件都会后一个与它匹配的==文件信息区 struct FILE f;==，存储文件信息



// 打开文件 - fopen
// 关闭文件 - fclose

// "r" - 读
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 读文件
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
// fopen: No such file or directory
// 文件不存在


//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\Chloe\\Desktop\\data.txt", "r"); // 绝对路径
//	// FILE* pf = fopen("data.txt", "r"); // 相对路径
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 读文件
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



// "w" - 写
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\Chloe\\Desktop\\data.txt", "w"); // 会生成一个文件
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 读文件
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



// 顺序读写

 //fputc - 字符输出函数 写一个字符
 //fgetc - 字符输入函数 读一个字符

/* Read a character from a stream (fgetc, fgetwc) or stdin (_fgetchar, _fgetwchar).
int fgetc( FILE *stream );
 */
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen ("C:\\Users\\Chloe\\Desktop\\data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 写文件
//	fputc('b', pf); // 在data.txt中写入bit
//	fputc('i', pf);
//	fputc('t', pf);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//	 
//	return 0;
//}


// 
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen ("C:\\Users\\Chloe\\Desktop\\data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 读文件
//	int ch = fgetc(pf);                                            
//	printf("%c\n", ch); // a
//
//	ch = fgetc(pf);
//	printf("%c\n", ch); // b
//
//	ch = fgetc(pf);
//	printf("%c\n", ch); // c
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//	 
//	return 0;
//}

// 也可以从标准输入读，也就是键盘
//#include <stdio.h>
//
//int main()
//{
//	fputc('b', stdout);
//	// putchar printf("%c", ch);
//
//	int ch = fgetc(stdin);
//	// getchar scanf("%c", ch);
//	printf("%c\n", ch);
//}


// 流：高度抽象的概念
 //C语言的程序，只要运行起来，就默认打开了三个流：
 //stdout - 标准输出流
 //stdin  - 标准输入流
 //stderr - 标准错误流
 //类型都是 FILE*

//#include <stdio.h>
//
//int main()
//{
//	fputc('b', stdout);
//	fputc('i', stdout);
//	fputc('t', stdout);
//}


//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 写文件
//	// 写一行数据
//	fputs("hello world\n", pf);
//	fputs("hello bit\n", pf);
//
//	fclose(pf);
//	pf = NULL;
//}


//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 读文件
//	// 读一行数据
//	char arr[20] = { 0 };
//	fgets(arr, 20, pf); // 从流里读5个字符放进arr
//	printf("%s\n", arr);
//
//	fgets(arr, 20, pf); // 从流里读5个字符放进arr
//	printf("%s\n", arr);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//
//struct S
//{
//	int n;
//	double d;
//};
//
//int main()
//{
//	struct S s = { 0 };
//
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 读文件
//	fscanf(pf, "%d %lf", &(s.n), &(s.d));
//
//	printf("%d %lf", s.n, s.d);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//
//struct S
//{
//	int n;
//	double d;
//	char name[10];
//};
//
//int main()
//{
//	struct S s = { 100, 3.24, "zhangsan"};
//
//	FILE* pf = fopen("data.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 以二进制方式写
//	fwrite(&s, sizeof(s), 1, pf);
//
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//
//struct S
//{
//	int n;
//	double d;
//	char name[10];
//};
//
//int main()
//{
//	struct S s = { 100, 3.24, "zhangsan" };
//
//	FILE* pf = fopen("data.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 读文件 - 以二进制方式读
//	fwrite(&s, sizeof(s), 1, pf);
//
//	// 打印文件
//	printf("%d %lf %s\n", s.n, s.d, s.name); // 100 3.240000 zhangsan
//
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//
//struct S
//{
//	int n;
//	double d;
//	char name[10];
//};
//
//int main()
//{
//	char arr[100] = { 0 };
//	struct S s = { 100, 3.14, "zhangsan" };
//
//	// 把一个格式化的数据转换成字符串
//	sprintf(arr, "%d %lf %s\n", s.n, s.d, s.name);
//
//	//  打印
//	printf("%s\n", arr);
//
//	return 0;
//}


#include <stdio.h>

struct S
{
	int n;
	double d;
	char name[10];
};

int main()
{
	char arr[100] = { 0 };
	struct S s = { 100, 3.14, "zhangsan" };

	struct S tmp = { 0 };

	// 把一个格式化的数据转换成字符串
	sprintf(arr, "%d %lf %s\n", s.n, s.d, s.name);

	// 以字符串形式打印
	printf("%s\n", arr); // 100 3.140000 zhangsan

	// 从arr中的字符串中提取一个格式化的数据
	sscanf(arr, "%d %lf %s", &(tmp.n), &(tmp.d), tmp.name);

	// 按照格式化的形式打印的
	printf("%d %lf %s\n", tmp.n, tmp.d, tmp.name); // 100 3.140000 zhangsan
	
	return 0;
}