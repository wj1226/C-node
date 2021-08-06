#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//IO型 - 自己写输入，输出
//接口型 - 只要完成指定接口就可以了

/*统计二进制中1的个数
题目内容：
写一个函数返回参数二进制中 1 的个数。
比如： 15    0000 1111    4 个 1 */
//C++
class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};



/*求两个数二进制中不同位的个数
题目内容：
编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
输入例子 :
1999 2299
输出例子 : 7 */

//循环
int main()
{
	int n1 = 0;
	int n2 = 0;
	scanf("%d %d", &n1, &n2);
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n1 >> i) & 1) != ((n2 >> i) & 1))
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}


//函数
int count_diff_bit(int n1, int n2)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n1 >> i) & 1) != ((n2 >> i) & 1))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n1 = 0;
	int n2 = 0;
	scanf("%d %d", &n1, &n2);

	int count = count_diff_bit(n1, n2);
	printf("%d\n", count);

	return 0;
}


//对应的二进制位^ 同为0异为1
int NumberOf1(int n) //求一个数二进制有多少个1
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int count_diff_bit(int n1, int n2)
{
    int count = 0;
    int t = n1 ^ n2;
    count = NumberOf1(t);
    return count;

}

int main()
{
	int n1 = 0;
	int n2 = 0;
	scanf("%d %d", &n1, &n2);

	int count = count_diff_bit(n1, n2);
	printf("%d\n", count);

	return 0;
}



/* 打印整数二进制的奇数位和偶数位
题目内容：
获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列 */
//偶数位 1 3 5 7。。。31
//奇数位 0 2 4 6 。。。30
//倒着打印 所以从后开循环
int main()
{
	int num = 0;
	scanf("%d", &num);
	int i = 0;
	printf("偶数位：");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n奇数位：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");

	return 0;
}



/*判断是元音还是辅音
多组输入，每行输入一个字母。
输出描述：
针对每组输入，输出为一行，如果输入字母是元音（包括大小写），
输出“Vowel”，如果输入字母是非元音，输出“Consonant”。*/

//循环判断
int main()
{
    int ch = 0;
    //循环判断部分其实是在读取字符
    while ((ch = getchar()) != EOF)
    {
        //判断是否为元音字母
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            printf("Vowel\n");
        }
        else
        {
            printf("Consonant\n");
        }
        getchar(); //清理 \n
    }

    return 0;
}


//字符数组判断
int main()
{
    int ch = 0;
    char vowel[] = "aeiouAEIOU";

    while ((ch = getchar()) != EOF)
    {
        int i = 0;
        int flag = 0;
        for (i = 0; i < 10; i++)
        {
            if (ch == vowel[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("Vowel\n");
        }
        else
        {
            printf("Consonant\n");
        }
        getchar(); //清理 \n
    }

    return 0;
}

//3.改大小写
//4.strstr



/*矩阵相等判断
第一行包含两个整数n和m，表示两个矩阵包含n行m列，用空格分隔。

从2到n + 1行，每行输入m个整数（范围 - 231~231 - 1），用空格分隔，共输入n * m个数，表示第一个矩阵中的元素。

从n + 2行到2n + 1，每行输入m个整数（范围 - 231~231 - 1），用空格分隔，共输入n * m个数，表示第二个矩阵中的元素。
1 < n, m < 10
	输出描述：
	一行，如果两个矩阵相等输出"Yes"并换行，否则输出"No"并换行。*/
int main()
{
	int arr1[10][10] = { 0 };
	int arr2[10][10] = { 0 };
	int n = 0;
	int m = 0;

	scanf("%d %d", &n, &m);
	int i = 0;
	int j = 0;
	//输入了矩阵1
	//n行
	for (i = 0; i < n; i++)
	{
		//m列
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	//输入了矩阵2
	for (i = 0; i < n; i++)
	{
		//m列
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}
	//判断
	int flag = 1; //默认相同
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}


//优化	读一个判断一个
int main()
{
	int arr1[10][10] = { 0 };
	int arr2[10][10] = { 0 };
	int n = 0;
	int m = 0;

	scanf("%d %d", &n, &m);
	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}

	int flag = 1; //默认相同
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr2[i][j]);
			if (arr1[i][j] != arr2[i][j])
			{
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}



/* 矩阵转置
第一行包含两个整数n和m，表示一个矩阵包含n行m列，用空格分隔。 (1≤n≤10,1≤m≤10)
从2到n+1行，每行输入m个整数（范围-231~231-1），用空格分隔，共输入n*m个数，表示第一个矩阵中的元素。
输出描述：
输出m行n列，为矩阵转置后的结果。每个数后面有一个空格。*/
int main()
{
	int n = 0;
	int m = 0;
	int arr[10][10] = { 0 };

	scanf("%d %d", &n, &m);
	int i = 0;
	int j = 0;
	//输入
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	//转置输出
	for (i = 0; i < m; i++) //打印3行2列
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}

	return 0;
}



//short解引用
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5 };
	short* p = (short*)arr;
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		*(p + i) = 0;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
// 1  2  3  4  5
//short 解引用每次访问2个字节
// 00 00 3  3  5



//VS小端存储
#include <stdio.h>
int main()
{
    int a = 0x11223344;
    char* pc = (char*)&a;
    *pc = 0;
    printf("%x\n", a);
    return 0;
}
//低位放在低地址 高位放在高地址
// 44 33 22 11
// %d - 10进制
// %o - 8进制
// %x - 16进制



//sizeof
#include <stdio.h>
int i; //全局变量，没有给初始值时，编译其会默认将其初始化为0
int main()
{
    i--; // -1
    if (i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}
//sizeof - 返回的是无符号整数
//i和sizeof(i)比较 算术转换 int强制类型转化为size_t
//-1对应的无符号整形是一个非常大的数字



/*使用指针打印数组内容
写一个函数打印arr数组的内容，不使用数组下标，使用指针。
arr是一个整形一维数组 */
#include <assert.h>

void print(const int* p, int sz)
{
	int i = 0;
	assert(p);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//数组在内存中是连续存放的 只要知道起始位置 就能找到数组
	print(arr, sz);

	return 0;
}



/* 计算求和
求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
例如：2+22+222+2222+22222 */
int main()
{
	int i = 0;
	int a = 0;
	int tmp = 0;
	int Sn = 0;
	scanf("%d", &a);
	for (i = 0; i < 5; i++)
	{
		tmp = tmp * 10 + a;
		Sn = Sn + tmp;
	}
	printf("%d\n", Sn);

	return 0;
}


//求a的n项
int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int k = 0;
	scanf("%d %d", &a, &n);

	for (i = 0; i < n; i++)
	{
		k = k * 10 + a;
		sum += k;
	}
	printf("%d\n", sum);

	return 0;
}



/* 打印水仙花数
求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数” */
//判断i是否是自幂数
#include <math.h>

int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{	
		int tmp = i; //计算位数后i会改变 用tmp求
		//1. 计算i的位数 - n
		int cnt = 1;
		int sum = 0;
		while (tmp /= 10)
		{
			cnt++;
		}
		//2. 计算i的每一位的n次方之后
		tmp = i;
		while (tmp)
		{
			sum += (int)pow(tmp % 10, cnt);
			tmp /= 10;
		}
		//3. 判断
		if (sum == i)
		{
			printf("%d ", i);
		}
	}

	return 0;
}


//求位数函数
#include <math.h>

int count(int tmp)
{
	int cnt = 1;
	while (tmp /= 10)
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		int tmp = i;
		//1. 计算i的位数 - n
		int sum = 0;
		int cnt = count(i);

		//2. 计算i的每一位的n次方之后
		while (tmp)
		{
			sum += (int)pow(tmp % 10, cnt);
			tmp /= 10;
		}
		//3. 判断
		if (sum == i)
		{
			printf("%d ", i);
		}
	}

	return 0;
}



//函数栈帧的创建和销毁
//VS2013 越高级的编译器函数栈帧的封装越不容易看

//1. 寄存器
//eax ebx ecx edx
//ebp esp

//ebp和esp这2个寄存器中存放的是地址，这两个地址是用来维护函数栈帧的

//每一次函数调用，都要在栈区创建一块空间

int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;

	c = Add(a, b);

	printf("%d\n", c);
	
	return 0;
}