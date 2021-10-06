#define _CRT_SECURE_NO_WARNINGS 1

//一、fseek
//根据文件指针的位置和偏移量来定位文件指针
//int fseek ( FILE * stream, long int offset, int origin );
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
//	// 读文件 随机读写
//	// 1、读a
//	//int ch = fgetc(pf);
//	//printf("%c\n", ch); // a
//
//	// 2、如果第一次就要读取'c'
//	fseek(pf, 2, SEEK_SET); // 从起始位置偏移2指向c
//	int ch = fgetc(pf);
//	printf("%c\n", ch); // c
//
//	// 3、读'b'
//	// 读完c 指向d 要读取b需要从当前位置开始偏移-2
//	fseek(pf, -2, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch); // b
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//二、ftell
//返回文件指针相对于起始位置的偏移量
//long int ftell ( FILE * stream );

// 计算文件指针相较于起始位置的偏移量
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
//	// 读取'c'
//	fseek(pf, 2, SEEK_SET);
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	// 读'b'
//	fseek(pf, -2, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	// 计算偏移量
//	// 读取b后指向c 偏移量较起始位置为2
//	int ret = ftell(pf);
//	printf("%d\n", ret); // 2
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//三、rewind
//让文件指针的位置回到文件的起始位置
//void rewind ( FILE * stream );

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
//	// 读取'c'
//	fseek(pf, 2, SEEK_SET);
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	// 读'b'
//	fseek(pf, -2, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	// 计算偏移量
//	int ret = ftell(pf);
//	printf("%d\n", ret); // 2
//
//	// 让指针回到起始位置
//	// 再次从起始位置打印 还是a
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch); // a
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



// 四、文本文件和二进制文件
//00000000000000000010011100010000
// 十进制10000的二进制存储：
// ASCII形式 / 二进制形式
// 5字节       4字节
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	// 以二进制形式写文件
//	int a = 10000;
//	fwrite(&a, 4, 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



// 五、文件结束判定

