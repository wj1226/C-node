// 数组

// 一、一维数组的创建和初始化
// 1. 数组的创建
// 数组是一组相同类型元素的集合

#include <stdio.h>

int main()
{
	int arr[20];

	return 0;
}

// 数组创建 []中要给一个常量才可以 不能使用变量


// 2. 数组初始化
int main()
{
	int arr1[20] = { 1, 2, 3 }; // 不完全初始化，剩余的默认初始化为0
	int arr2[] = { 1, 2, 3 }; // 没有指定大小 根据初始化内容确定

	char arr3[] = "abc"; // a b c \0  -- 4个字节
	char arr4[] = { 'a', 'b', 'c' }; // a b c
	char arr5[] = { 'a', 98, 'c' }; // a b c

	return 0;
}



// 不初始化
int arr[5]; // // 全局变量不初始化 默认放0

int main()
{
	int arr1[5];
	// 局部变量不初始化 放的是随机值

	return 0;
}



// 3. 一维数组的使用
// 对于数组的使用我们之前介绍了一个操作符： [] ，下标引用操作符。它其实就数组访问的操作符。

// 用下标打印1-10
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i = 0; //做下标

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


// sizeof 计算数组的元素个数
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

// 总结：
// 1. 数组是使用下标来访问的，下标是从0开始。
// 2. 数组的大小可以通过计算得到。


// float sc[5] = { 0.0f, 3.0f };
// 结构体数组业可以创建



// 4. 一维数组在内存中的存储
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		printf("%p\n", &arr[i]); // 连续递增4  一个int4个字节的地址 10个
		// 随着数组下标的增长，元素的地址，也在有规律的递增。 由此可以得出结论：数组在内存中是连续存放的
		// 数组随着下标的增长，地址是由低到高变化的
	}

	return 0;
}



// 整形指针加1是4个字节
int main()
{
	int a = 10;
	int* p = &a;

	printf("%p\n", p);
	printf("%p\n", p + 1);

	return 0;
}




// 二、二维数组的创建和初始化

// 1. 二维数组的创建
int main()
{
	int arr[3][4];
	char arr[3][5];
	double arr[2][4];

	return 0;
}



// 2. 二维数组的初始化

int main()
{
	int arr1[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 三行五列 一行放满换下一行
	int arr2[3][5] = { {1, 2}, {3, 4}, {5, 6} }; // 第一行1 2 0 0 0  第二行3 4 0 0 0  第三行5 6 0 0 0

	return 0;
}



int main()
{
	int arr3[][5] = { {1, 2}, {3, 4}, {5, 6} };
	// 二维数组初始化可以省略行，但必须有列

	return 0;
}



int main()
{
	char ch1[4][6] = { 'a', 'b' }; // 第一行"ab" 而三行没有
	char ch2[4][6] = { {'a'}, {'b'} }; // 第一行"a" 第二行"b" 第三四行没有
	char ch3[4][6] = { "abc", "def", "qwe" }; // 第一行"abc" 第二行"def" 第三行"qwe" 第四行没有

	return 0;
}



// 3. 二维数组的使用
// 二维数组的使用也是通过下标的方式
int main()
{
	int arr[3][5] = { {1, 2, 3}, {4, 5}, {6, 7, 8, 9, 10} };
	int i = 0;
	for (i = 0; i < 3; i++) // 0~2
	{
		int j = 0;
		for (j = 0; j < 5; j++) // 0~4
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	// 1 2 3 0 0
	// 4 5 0 0 0
	// 6 7 8 9 10
	return 0;
}



// 4. 二维数组在内存中的存储

// 打印第i行第j列的地址
int main()
{
	int arr[3][5] = { {1, 2, 3}, {4, 5}, {6, 7, 8, 9, 10} };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
	// 相差4  ->  通过结果我们可以分析到，其实二维数组在内存中也是连续存储的。

	return 0;
}



// 连续存放
// 一维数组
// 指针和下标都可以 因为数组在内存中是连续存放的
int mian()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* p = arr; // arr数组名是首元素的地址
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *p);
		p++;
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


// 二维数组也是连续存放的
int main()
{
	int arr[3][5] = { {1, 2, 3}, {4, 5}, {6, 7, 8, 9, 0} };
	int* p = &arr[0][0]; // 第一行第一列的数组
	int i = 0;
	for (i = 0; i < 15; i++)
	{
		printf("%d ", *p); // 1 2 3 0 0 4 5 0 0 0 6 7 8 9 0
		p++;
	}

	return 0;
}




// 三、数组越界

// 数组的下标是有范围的，规定从0开始，假设有n个元素，最后一个元素的下标就是n-1
// 数组的下标如果小于0，或大于n-1，就是越界访问，超出了数组合法空间的访问
// C语言本身是不做数组下标的越界检查，编译器也不一定会报错，所以写代码时，最好自己做越界的检查
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int i = 0;
	for (i = 0; i <= 5; i++)
	{
		printf("%d ", arr[i]); // 1 2 3 4 5 -858993460 
		// 超出了0-4的范围 随机值
	}

	return 0;
}




// 四、数组作为函数参数

// 1、冒泡排序
// 冒泡排序的核心思想：两两相邻的元素进行比较 排成升序
// 一趟冒泡排序 可以搞定一个数字 让它来到最终应该出现的位置上
// 10个元素最多进行9趟冒泡排序可以完成升序  -> n个元素n-1趟

// 冒泡排序函数的错误设计
void Sort(int arr[])
{
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	// 冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		// a一趟冒泡排序的过程
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) // 第一次9趟 第二次8趟
		{
			if (arr[j] > arr[j + 1]) // 升序
			{
				// 交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 2, 6, 9, 4, 8, 7, 0 };
	// 数组传参
	// 排序
	Sort(arr);

	//Print(arr);

	return 0;
}
// 数组传参拿指针接收，void Sort(int arr[])本质上是void Sort(int* arr)整形指针
// arr是指针，那么sizeof(arr)算出的指针大小是4。sizeof(arr[0])第一个元素是整形，大小是4。4/4=1



// 冒泡排序函数的正确设计
// void Sort(int arr[], int sz)
void Sort(int* arr, int sz)
{
	int i = 0;
	// 冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		// a一趟冒泡排序的过程
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) // 第一次9趟 第二次8趟
		{
			if (arr[j] > arr[j + 1]) // 升序
			{
				// 交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 2, 6, 9, 4, 8, 7, 0 };
	// 数组传参
	// 排序

	// 数组名如果没有传参，单独放在sizeof内部的时候，如：sizeof(arr)，这里的arr表示整个数组，不是首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]); // 此时sizeof(arr)计算的是整个数组的大小 40 / 4

	// 传参在传递给函数的时候 ==数组名会降级变成首元素地址==
	Sort(arr, sz);

	Print(arr, sz);

	return 0;
}
// 当数组传参的时候，实际上只是把数组的首元素的地址传递过去了。
// 所以即使在函数参数部分写成数组的形式： int arr[] 表示的依然是一个指针： int* arr 。
// 那么，函数内部的 sizeof(arr) 结果是4。



// 加上print函数
void Print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", p[i]);
		// printf("%d ", *(p + i));
		// printf("%d ", *p++); // 先简引用再++
	}
}

void Sort(int* arr, int sz)
{
	int i = 0;
	// 冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		// a一趟冒泡排序的过程
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) // 第一次9趟 第二次8趟
		{
			if (arr[j] > arr[j + 1]) // 升序
			{
				// 交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 2, 6, 9, 4, 8, 7, 0 };
	// 数组传参
	// 排序

	// 数组名如果没有传参，单独放在sizeof内部的时候，如：sizeof(arr)，这里的arr表示整个数组，不是首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]); // 此时sizeof(arr)计算的是整个数组的大小 40 / 4

	// 传参在传递给函数的时候 ==数组名会降级变成首元素地址==
	Sort(arr, sz);

	Print(arr, sz);

	return 0;
}



// 优化 flag 提高效率
void Print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", p[i]);
		// printf("%d ", *(p + i));
		// printf("%d ", *p++); // 先简引用再++
	}
}

void Sort(int* arr, int sz)
{
	int i = 0;
	// 冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		// a一趟冒泡排序的过程
		int j = 0;

		int flag = 1; // 假设已有序

		for (j = 0; j < sz - 1 - i; j++) // 第一次9趟 第二次8趟
		{
			if (arr[j] > arr[j + 1]) // 升序
			{
				// 交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0; // 如果发现有交换 就把flag设为0 本次排序无序
			}
		}

		if (flag == 1) // 如果没有交换 说明已有序 break跳出 提高效率
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 2, 6, 9, 4, 8, 7, 0 };
	// 数组传参
	// 排序

	// 数组名如果没有传参，单独放在sizeof内部的时候，如：sizeof(arr)，这里的arr表示整个数组，不是首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]); // 此时sizeof(arr)计算的是整个数组的大小 40 / 4

	// 传参在传递给函数的时候 ==数组名会降级变成首元素地址==
	Sort(arr, sz);

	Print(arr, sz);

	return 0;
}



// 数组名是什么？
// 结论：
// 数组名是数组首元素的地址。（有两个例外）

// 如果数组名是首元素地址，那么：
// int arr[10] = { 0 };
// printf("%d\n", sizeof(arr));
// 为什么输出的结果是：40？

// 补充：
// 1. sizeof(数组名)，这里的数组名表示整个数组，sizeof(数组名)计算的是整个数组的大小。
// 2. &数组名，这里的数组名表示整个数组，取出的是数组的地址。


int main()
{
	int arr[10] = { 1, 2, 3, 4, 5 };

	printf("%p\n", arr); // 首元素的地址
	printf("%p\n", &arr[0]); // 首元素的地址
	printf("%p\n", &arr); // 数组的地址

	printf("------------------------------------------\n");

	printf("%p\n", arr + 1); // 差4
	printf("%p\n", &arr[0] + 1); // 差4
	printf("%p\n", &arr + 1); //差40  因为此数组是10个元素 一个元素是一个整形 10个元素就是10个整形 大小是40 

	return 0;
}
// 指向元素的指针+1会跳过一个元素
// 指向数组的指针+1会跳过一个数组


// 数组的应用实例1：三子棋