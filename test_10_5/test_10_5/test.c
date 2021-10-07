#define _CRT_SECURE_NO_WARNINGS 1

//一、fseek
//根据文件指针的位置和偏移量来定位文件指针
//int fseek ( FILE * stream, long int offset, int origin );
#include <stdio.h>

int main()
{
	FILE* pf = fopen("data.txt", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return -1;
	}

	// 读文件 随机读写
	// 1、读a
	//int ch = fgetc(pf);
	//printf("%c\n", ch); // a

	// 2、如果第一次就要读取'c'
	fseek(pf, 2, SEEK_SET); // 从起始位置偏移2指向c
	int ch = fgetc(pf);
	printf("%c\n", ch); // c

	// 3、读'b'
	// 读完c 指向d 要读取b需要从当前位置开始偏移-2
	fseek(pf, -2, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch); // b

	fclose(pf);
	pf = NULL;

	return 0;
}



//二、ftell
//返回文件指针相对于起始位置的偏移量
//long int ftell ( FILE * stream );

// 计算文件指针相较于起始位置的偏移量
#include <stdio.h>

int main()
{
	FILE* pf = fopen("data.txt", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return -1;
	}

	// 读取'c'
	fseek(pf, 2, SEEK_SET);
	int ch = fgetc(pf);
	printf("%c\n", ch);

	// 读'b'
	fseek(pf, -2, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);

	// 计算偏移量
	// 读取b后指向c 偏移量较起始位置为2
	int ret = ftell(pf);
	printf("%d\n", ret); // 2

	fclose(pf);
	pf = NULL;

	return 0;
}



//三、rewind
//让文件指针的位置回到文件的起始位置
//void rewind ( FILE * stream );

#include <stdio.h>

int main()
{
	FILE* pf = fopen("data.txt", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return -1;
	}

	// 读取'c'
	fseek(pf, 2, SEEK_SET);
	int ch = fgetc(pf);
	printf("%c\n", ch);

	// 读'b'
	fseek(pf, -2, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);

	// 计算偏移量
	int ret = ftell(pf);
	printf("%d\n", ret); // 2

	// 让指针回到起始位置
	// 再次从起始位置打印 还是a
	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch); // a

	fclose(pf);
	pf = NULL;

	return 0;
}



// 四、文本文件和二进制文件
//00000000000000000010011100010000
// 十进制10000的二进制存储：
// ASCII形式 / 二进制形式
// 5字节       4字节
#include <stdio.h>

int main()
{
	FILE* pf = fopen("data.txt", "wb");
	if (NULL == pf)
	{
		perror("fopen");
		return -1;
	}

	// 以二进制形式写文件
	int a = 10000;
	fwrite(&a, 4, 1, pf);

	fclose(pf);
	pf = NULL;

	return 0;
}



// 五、文件结束判定
// 字符输入函数fgetc返回int，遇到错误或文件结束返回EOF
// 如果用fgetc读取文件，可以判断fgetc的返回值是否是EOF，来判定文件是否读取结束
#include <stdio.h>

int main()
{
	FILE* pf = fopen("data.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return -1;
	}

	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		printf("%c ", ch);
	}

	fclose(pf);
	pf = NULL;

	return 0;
}


// 文本行输入函数fgets返回起始地址，遇到错误或文件结束返回NULL


/*
1. 文本文件读取是否结束，判断返回值是否为EOF （fgetc），或者NULL（fgets）
例如：
fgetc判断是否为EOF.
fgets判断返回值是否为NULL.
2. 二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
例如：
fread判断返回值是否小于实际要读的个数。
*/

// feof 
// feof不是用来判断文件是否读取结束的

// 文本文件的例子：
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c; // 注意：int，非char，要求处理EOF
	FILE* fp = fopen("test.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return EXIT_FAILURE;
	}

	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
	{
		putchar(c);
	}

	//判断是什么原因结束的
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");

	fclose(fp);
	fp = NULL;
}

//// 二进制文件的例子：
#include <stdio.h>

enum { SIZE = 5 };

int main(void)
{
	double a[SIZE] = { 1.0,2.0,3.0,4.0,5.0 };
	double b = 0.0;
	size_t ret_code = 0;
	FILE* fp = fopen("test.bin", "wb"); // 必须用二进制模式

	fwrite(a, sizeof(*a), SIZE, fp); // 写 double 的数组
	fclose(fp);

	fp = fopen("test.bin", "rb");

	// 读 double 的数组
	while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
	{
		printf("%lf\n", b);
	}

	if (feof(fp))
		printf("Error reading test.bin: unexpected end of file\n");
	else if (ferror(fp)) {
		perror("Error reading test.bin");
	}

	fclose(fp);
	fp = NULL;
}

// 总结：feof是当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束
// ferror 用途：文件读取结束了，判断是不是遇到错误后读取结束



// 文件缓冲区
// 测试代码：
#include <stdio.h>
#include <windows.h>
//VS2013 WIN10环境测试

int main()
{
	FILE* pf = fopen("test.txt", "w");
	fputs("abcdef", pf); // 先将代码放在缓冲区

	printf("睡眠10s 已经写数据了 打开test.txt文件 发现文件没有内容\n");
	Sleep(10000);

	printf("刷新缓冲区\n");
	fflush(pf); // 刷新缓冲区时 才将输出缓冲区的数据写到文件（磁盘）

	printf("再睡眠10s 此时 再次打开test.txt文件 文件有内容了\n");
	Sleep(10000);
	// 注：fclose关闭文件的时候 也会刷新缓冲区
	pf = NULL;

	return 0;
}

// 结论：
// 因为有缓冲区的存在，C语言在操作文件时，需要做刷新缓冲区或者在文件操作结束时
// 关闭文件（fclose关闭文件的时候 也会刷新缓冲区），否则可能导致读写文件问题
