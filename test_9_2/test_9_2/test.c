#define _CRT_SECURE_NO_WARNINGS 1

int main()
{
	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	
	printf("%d\n", sizeof(arr)); // 6 单独放在sizeof 整个数组

	printf("%d\n", sizeof(arr + 0)); // 4/8 首元素地址

	printf("%d\n", sizeof(*arr)); // 1 char*解引用一字节

	printf("%d\n", sizeof(arr[1])); // 1 

	printf("%d\n", sizeof(&arr)); // 4/8

	printf("%d\n", sizeof(&arr + 1)); // 4/8 跳过整个数组，还是地址

	printf("%d\n", sizeof(&arr[0] + 1)); // 4/8 b的地址


	// strlen - 库函数
	// 求字符串长度

	// sizeof - 操作符，单位字节
	// 求变量所占空间的大小
	// 求类型创建的变量所占空间的大小

	printf("%d\n", strlen(arr)); // 随机值

	printf("%d\n", strlen(arr + 0)); // 随机值-1

	printf("%d\n", strlen(*arr)); // err
	// *arr - 'a' - 97    strlen以为传进来的'a'得ascii码值就是地址

	printf("%d\n", strlen(arr[1])); // err  'b' - 98

	printf("%d\n", strlen(&arr)); // 随机值
	// &arr类型是char(*)[6]，strlen的类型是char*，类型不匹配，但还是指向首元素，值一样，类型转换a的地址往后找

	printf("%d\n", strlen(&arr + 1)); // 随机值-6

	printf("%d\n", strlen(&arr[0] + 1)); // 随机值-1

	return 0;
}



int main()
{
	char arr[] = "abcdef";

	printf("%d\n", sizeof(arr)); // 7

	printf("%d\n", sizeof(arr + 0)); // 4/8  arr是首元素地址

	printf("%d\n", sizeof(*arr)); // 1  arr是首元素的地址，*arr就是首元素

	printf("%d\n", sizeof(arr[1])); // 1  第二个元素

	printf("%d\n", sizeof(&arr)); // 4/8  数组的地址，数组的地址也是地址

	printf("%d\n", sizeof(&arr + 1)); // 4/8  &arr是数组的地址，&arr+1是跳过整个数组后的地址

	printf("%d\n", sizeof(&arr[0] + 1)); // 4/8  第二个元素的地址


	printf("%d\n", strlen(arr)); // 6
	
	printf("%d\n", strlen(arr + 0)); // 6  首元素地址+0还是首元素地址
	
	printf("%d\n", strlen(*arr)); // err
	
	printf("%d\n", strlen(arr[1])); // err
	
	printf("%d\n", strlen(&arr)); // 6  类型不匹配，但还是以char*找
	
	printf("%d\n", strlen(&arr + 1)); // 随机值
	
	printf("%d\n", strlen(&arr[0] + 1)); // 5
	
	return 0;
}



int main()
{
	const char* p = "abcdef";

	printf("%d\n", sizeof(p)); // 4/8  p是一个指针变量，存放地址
	
	printf("%d\n", sizeof(p + 1)); // p类型chat* 加1跳过1字节 指向字符b的地址
	
	printf("%d\n", sizeof(*p)); // 1  通过地址找到a
	
	printf("%d\n", sizeof(p[0])); // 1  p[0]--> *(p+0)--> *p
	
	printf("%d\n", sizeof(&p)); // 4/8  取出指针p的地址
	
	printf("%d\n", sizeof(&p + 1)); // 4/8
	// &p 一级指针&是二级指针 
	// char** ptr = &p
	// &p+1
	// ptr+1
	// 跳过p指向指针变量p后面，还是地址
	
	printf("%d\n", sizeof(&p[0] + 1)); // 4/8  b的地址


	printf("%d\n", strlen(p)); // 6
	
	printf("%d\n", strlen(p + 1)); // 5
	
	printf("%d\n", strlen(*p)); // err
	
	printf("%d\n", strlen(p[0])); // err
	
	printf("%d\n", strlen(&p)); // 随机值  
	// 指针变量的地址，不是字符串首元素的地址

	printf("%d\n", strlen(&p + 1)); // 随机值
	// 与&p没有关系，因为p里的4字节可能有\0 提前结束

	printf("%d\n", strlen(&p[0] + 1)); // 5

	return 0;
}



int main()
{
	//二维数组
	int a[3][4] = { 0 };

	printf("%d\n", sizeof(a)); // 48
	
	printf("%d\n", sizeof(a[0][0])); // 4  第一行第一列元素 int
	
	printf("%d\n", sizeof(a[0])); // 16   a[0]第一行数组名，数组名单独放在sizeof
	
	printf("%d\n", sizeof(a[0] + 1)); // 4/8
	// a[0]是第一行的数组的数组名，数组名没有单独放在sizeof，也没有&，所以arr[0]是首元素的地址
	// 第一行数组第一个元素的地址
	// a[0] + 1 就是第一行，第二个元素的地址

	printf("%d\n", sizeof(*(a[0] + 1))); // 4 第一行第二个元素 int
	
	printf("%d\n", sizeof(a + 1)); // 4/8
	// 数组名a，没有单独放在sizeof内部，也没有&，所以a表示首元素（第一行）的地址
	// 二维数组的数组名，表示首元素（第一行）的地址
	// +1 跳过一行 指向第二行地址
	// a+1 --> &a[1]

	printf("%d\n", sizeof(*(a + 1))); // 16  a首元素地址，第一行地址+1第二行地址，第二行地址* 就是第二行
	// *(a + 1)) - 第二行数组名 单独放在sizeof 整个数组大小 16

	printf("%d\n", sizeof(&a[0] + 1)); // 4/8
	// a[0]第一行数组名
	// 数组名没有单独放在sizeof内部，但是&，表示首元素地址
	// &a[0] 拿到的是第一行的地址
	// &a[0]+1 就是第二行的地址
	
	printf("%d\n", sizeof(*(&a[0] + 1))); // 16  第二行的地址* 拿到第二行
	// *(&a[0] + 1) --> *(&a[1]) --> a[1]
	// 数组名单独放在sizeof内部求大小

	printf("%d\n", sizeof(*a)); // 16
	// a表示首元素（第一行）的地址
	// *a - 第一行 - 第一行的数组名
	// *a --> *(a+0) --> a[0]
	
	printf("%d\n", sizeof(a[3])); // 16
	// sizeof内部表达式不参与运算
	// a[3]假设存在，就是第四行的数组名，sizeof(a[3])就相当于把第四行
	//  的数组名单独放在sizeof内部

	return 0;
}



int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };

	int* ptr = (int*)(&a + 1);
	// int(*)[5] --强制类型转换 (int*)
	// ptr指向5后 减1减一个int 指向5 解引用取出5

	printf("%d,%d", *(a + 1), *(ptr - 1));
	// *(a + 1) -- 数组名表示首元素地址，+1第二个元素地址，*是第二个元素
	
	// 2 5
	return 0;
}



//由于还没学习结构体，这里告知结构体的大小是20个字节
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p; // 结构体指针
int main()
{
	// p的类型是struct Test*   -- 0x100000的类型是int    
	// 强制类型转换成结构体指针类型
	p = (struct Test*)0x100000;

	printf("%p\n", p + 0x1); //0x1 十六进制1就是1
	// 结构体指针+1 跳过一个结构体 大小20
	// 0x00100014
	// 1*16^1 + 4*16^0 = 20

	printf("%p\n", (unsigned long)p + 0x1);
	// p强制类型转化成整型  
	// 整型+1  
	// 0x100000 + 1
	// 转化成10进制计算  1*16^5 + 1

	printf("%p\n", (unsigned int*)p + 0x1);
	// 强制类型转化成整型指针，整型指针+1，跳过一个整型4字节
	// 0x00100004

	// 00100014  00100001  00100004
	// %#xp  默认打印0x

	return 0;
}
