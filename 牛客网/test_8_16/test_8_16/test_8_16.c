#define _CRT_SECURE_NO_WARNINGS 1

//BC109
#include <stdio.h>

int main()
{
	int n = 0;
	int arr[30][30] = { 0 };
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				arr[i][j] = 1;
			if (i == j)
				arr[i][j] = 1;
			if (i >= 2 && j >= 1)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}


//BC110
#include <stdio.h>

int main()
{
	char arr[3][3] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf(" %c", &arr[i][j]); //字符 读取空格
			//getchar();
		}
	}
	//判断输赢
	char flag = 'o';
	for (i = 0; i < 3; i++)
	{
		//3行
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != 'o')
		{
			flag = arr[i][1];
			break;
		}
		//3列
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != 'o')
		{
			flag = arr[1][i];
			break;
		}
	}
	//2条对角线
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != 'o')
	{
		flag = arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != 'o')
	{
		flag = arr[1][1];
	}

	if (flag == 'K')
	{
		printf("KiKi wins!\n");
	}
	else if (flag == 'B')
	{
		printf("BoBo wins!\n");
	}
	else
	{
		printf("No winner!\n");
	}

	return 0;
}


//BC112
#include <stdio.h>
//1-n的和
int main()
{
	int n = 0;
	long long sum = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}
	printf("%lld\n", sum);

	return 0;
}

/*
int main()
{
	long long n = 0;
	long long sum = 0;
	scanf("%d", &n);
	sum = (1+n)*n/2;
	printf("%lld\n", sum);

	return 0;
}
*/


//BC113
#include <stdio.h>

int main()
{
	int h = 0;
	int m = 0;
	int k = 0;
	scanf("%d:%d %d", &h, &m, &k);

	h = ((m + k) / 60 + h) % 24;
	m = (m + k) % 60;

	printf("%02d:%02d\n", h, m);

	return 0;
}


//BC115
#include <stdio.h>
/*
int main()
{
	long long n = 0;
	long long m = 0;
	scanf("%lld %lld", &n, &m);

	long long max = n > m ? m : n; //假设n和m的较小值为最大公约数
	long long min = n > m ? n : m; //假设n和m的较大值为最小公倍数

	while (1)
	{
		if (n % max == 0 && m % max == 0)
		{
			break;
		}
		max--;
	}
	while (1)
	{
		if (min % n == 0 && min % m == 0)
		{
			break;
		}
		min++;
	}

	printf("%lld\n", max + min);

	return 0;
}
*/

/*
int main()
{
	long long n = 0;
	long long m = 0;
	scanf("%lld %lld", &n, &m);
	long long n2 = n;
	long long m2 = m;

	long long c = 0;
	while (c = m2 % n2)
	{
		m2 = n2;
		n2 = c;
	}

	long long min = m * n / n2;

	long long sum = min + n2;

	printf("%lld", sum);

	return 0;
}
*/

//辗转相除法
int main()
{
	long long n = 0;
	long long m = 0;
	scanf("%lld %lld", &n, &m);

	long long tmp = 0;
	long long max = 0;
	long long min = 0;
	long long n2 = n;
	long long m2 = m;
	//24 % 18 = 6
	//18 % 6 = 0
	while (tmp = n % m)
	{
		n = m;
		m = tmp;
	}
	max = m;
	//最小公倍数= n*m/max
	min = n2 * m2 / max;

	printf("%lld\n", max + min);

	return 0;
}


//BC116
#include <stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int sum = 0;
	scanf("%d", &n);
	while (n)
	{
		int m = n % 10;
		if (m % 2 == 1) //奇数 变1
			m = 1;
		else
			m = 0;
		sum += m * pow(10, i++); //个位乘10^0 百位乘20^2
		n /= 10;
	}
	printf("%d\n", sum);

	return 0;
}


//BC117
#include <stdio.h>

int Fib(int n)
{
	if (n <= 2)
		return n;
	else
		return Fib(n - 1) + Fib(n - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	int ret = Fib(n);

	printf("%d\n", ret);

	return 0;
}


//BC118
#include <stdio.h>

int main()
{
	int n = 0;
	int arr[100001] = { 0 };
	scanf("%d", &n);
	int i = 0;
	int tmp = 0;
	for (i = 0; i < n; i++)
	{
		//1 ≤ k ≤ n
		//把每个数字放到对应数字的下标
		scanf("%d", &tmp);
		arr[tmp] = tmp;
	}
	for (i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}


//BC119
#include <stdio.h>

int main()
{
	char arr[8000] = { 0 }; //CCHNCHN
	scanf("%s", arr);
	//统计子串CHN的个数
	long long c = 0;
	long long ch = 0;
	int chn = 0;

	char* p = arr;
	while (*p)
	{
		if (*p == 'C')
			c++;
		else if (*p == 'H')
			ch += c;
		else if (*p == 'N')
			chn += ch;
		p++;
	}
	printf("%lld\n", chn);

	return 0;
}


//BC129
#include <stdio.h>

int max3(int a, int b, int c)
{
	int max = a > b ? a : b;
	max = max > c ? max : c;
	return max;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);

	float m = (float)max3(a + b, b, c) / (max3(a, b + c, c) + max3(a, b, b + c));
	printf("%.2f\n", m);

	return 0;
}

/*
float max3(int a, int b, int c)
{
	float max = a;
	if(max < b)
	{
		max = b;
	}
	if(max < c)
	{
		max = c;
	}
	return max;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);

	float m = max3(a+b, b, c) / (max3(a, b+c, c) + max3(a, b, b+c));
	printf("%.2f\n", m);

	return 0;
}
*/


//BC135
#include <stdio.h>
/*
int main()
{
	int i = 0;
	int count = 0;
	for(i=100; i<1000; i++)
	{
		int j = 0;
		for(j=2; j<i; j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(i == j)
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}
*/

int is_prime(int n)
{
	int j = 0;
	for (j = 2; j <= n - 1; j++)
	{
		if (n % j == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 999; i++)
	{
		if (is_prime(i) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}


//BC136
#include <stdio.h>
// 暴力求解
int main()
{
	int n = 0;
	int arr[1000] = {0};
	scanf("%d", &n);
	//接收n个数字
	int i = 0;
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//处理
	//1. 排序（冒泡排序）
	for(i=0; i<n-1; i++) //趟数 假设10个元素9趟
	{
		int j = 0;
		for(j=0; j<n-1-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	//2. 去重
	//去重比较的对数n-1
	for(i=0; i<n-1; i++)
	{
		if(arr[i] == arr[i+1])
		{
			//把从i+1下标往后的元素全部往前覆盖
			int k = 0;
			for(k=i; k<n-1; k++) //n-1最大n-2个元素 +1是n-1 就是最后
			{
				arr[k] = arr[k+1];
			}
			n--;
			i--;
		}
	}
	//3. 打印
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


//每个整数大于等于1，小于等于1000
int main()
{
	int n = 0;
	int arr[1001] = { 0 }; //下标1000
	scanf("%d", &n);
	int i = 0;
	int m = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		arr[m] = m;
	}
	for (i = 0; i <= 1000; i++) //遍历所有元素 而不是n个
	{
		if (arr[i] != 0)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}


//BC138
#include <stdio.h>

//链表结点的定义
struct Node
{
	int date; //数据域
	struct Node* next; //指针域
};

int main()
{
	struct Node* list = NULL; //指向链表的指针
	struct Node* tail = NULL; //指向链表尾部元素的指针
	//输入n
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int m = 0;
	int d = 0; //要删除的元素

	//接收n个数字并尾插到链表中
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		struct Node* pn = (struct Node*)malloc(sizeof(struct Node));
		pn->date = m;
		pn->next = NULL;

		//插入第一个元素
		if (list == NULL)
		{
			list = pn;
			tail = pn;
		}
		else
		{
			tail->next = pn;
			tail = pn;
		}
	}
	//接收要删除的元素
	scanf("%d", &d);

	//删除链表中指定的元素
	struct Node* cur = list;
	struct Node* prev = NULL;

	while (cur)
	{
		//找到了要删除的元素
		if (cur->date == d)
		{
			//删除
			//删除的如果是第一个结点
			struct Node* pd = cur;
			if (cur == list)
			{
				list = list->next;
				cur = list;
			}
			else
			{
				prev->next = cur->next;
				cur = prev->next;
			}
			free(pd);
			n--;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

	//输出
	printf("%d\n", n);
	cur = list;
	while (cur)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	//释放链表
	cur = list;
	struct Node* del = NULL;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}
	list = NULL;

	return 0;
}


//BC139
//C++
#include <iostream>
using namespace std;

class TDate
{
private:
	int Year;
	int Month;
	int Day;
public:
	TDate(int y = 0, int m = 0, int d = 0)
	{
		Year = y;
		Month = m;
		Day = d;
	}
	void print()
	{
		cout << Day << '/' << Month << '/' << Year << endl;
	}
};

int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	//输入
	cin >> year >> month >> day;
	TDate d(year, month, day);
	//输出
	d.print();

	return 0;
}