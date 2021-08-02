#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//初阶指针 + 结构体

//一、指针运算
//1、指针+-整数

//把数组每个元素赋成0
#define N_VALUES 5
float values[N_VALUES];
float* vp;
for (vp = &values[0]; vp < &values[N_VALUES];) //指针比较大小
{
    //由下标的增长 地址由低到高
    *vp++ = 0; //++优先级高于* 但是后置++ 所以先解引用vp
    //指针=- float指针+1跳过一个float类型的变量 跳的是一个元素
}


//指针大小
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = &arr[9];

	printf("%p\n", p);
	printf("%p\n", p-1); //差4 整形指针 4个字节
}


//2、指针-指针
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]); //9
	printf("%d\n", &arr[0] - &arr[9]); //=9
	//下标0-9之间有9个元素
	//指针-指针 得到的数字的绝对值是指针和指针之间元素的个数

	//指针-指针的前提是两个指针指向同一个区域
	return 0;
}


//指针求元素个数
int my_strlen(char* s)
{
	char* start = s;

	while (*s != '\0')
	{
		s++;
	}

	return s - start; //等找\0时是指向\0 减起始位置
}

int main()
{
	char arr[] = "abcdef";

	int len = my_strlen(arr);

	printf("%d\n", len);

	return 0;
}


//3、指针的运算关系
//代码1 从后往前改
for (vp = &values[N_VALUES]; vp > &values[0];) //下标为5的地址放进vp
{
    *--vp = 0;
    //先-- 指向下标4 最后一个元素改成0
    //从最后一个元素向前改
}

//代码2 从前往后改
for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
{
    *vp = 0;
    //最后一次把第一个元素改成0 vp-- 指向第一个元素之前一个float类型的位置 
}

//避免使用代码2的方法
//标准规定：
//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，
//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
////////////////


//二、指针和数组
//数组和指针的区别：

//数组 - 是一块连续的空间，放的是相同类型的元素
//数组大小和元素类型，元素个数有关
//int arr[10]

//指针（变量） - 是一个变量，放地址
//指针变量的大小 是4(32bit)/8(64bit)个byte


//数组名
int main()
{
	int arr[10];

	//int* p = &arr[5]; //取出下标为5的元素的地址
	//int* q = &arr; //数组名 首元素的地址

	printf("%p\n", arr); //数组是首元素的地址
	printf("%p\n", &arr[0]); //首元素的地址

	int sz = sizeof(arr); //数组是首元素的地址 那为什么不是4/8 而是40
	//数组名确实是首元素的地址 但有两个例外
	//1. sizeof(数组名) - 这里的数字名不是首元素的地址，是表示整个数组的，这里计算的是是整个数组的大小，单位还是字节
	//2. &数组名 - 这里的数字名不是首元素的地址，是表示整个数组的，拿到的这个数组的地址
	
	return 0;
}


//数组名地址 数组地址
int main()
{
	int arr[10] = { 0 };
	//arr - 数组名是首元素的地址
	//&arr[0] - 第一个数组的地址
	//&arr - 取出整个数组的地址

	//值一样 但意义不一样 
	//首元素地址和数组地址起始位置是一样
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr);

	printf("%p\n", arr);
	printf("%p\n", arr + 1); //整形指针+1 跳过一个整形
	
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0] + 1);

	printf("%p\n", &arr);
	printf("%p\n", &arr + 1); //数组的地址+1 整形数组10元素 40字节

	return 0;
}



//三、二级指针
//指针变量也是变量，是变量就有地址，那指针变量的地址存放在哪里？这就是二级指针
//二级指针：用来存放一级指针变量的地址
//三级指针：用来存放二级指针变量的地址
////////////////////////////
int main()
{
	int a = 10;
	int* p = &a;

	int* * pp = &p; //pp就是二级指针
	//第二个*：pp是指针
	//int*：pp指向的p的类型是int*

	int** * ppp = &pp; //ppp就是三级指针
	//最后一个*：ppp是指针
	//int**：ppp指向的pp的类型是int**

	return 0;
}


//二级指针的运算 两层解引用
int main()
{
	int a = 10;
	int* p = &a;
	int** pp = &a;
	**pp = 20; //*pp解引用找到p **pp找到a
	printf("%d\n", a);

	return 0;
}



//四、指针数组
//指针数组指针还是数组：数组
int main()
{
	int arr[10]; //整形数组 - 存放整形的数组就是整形数组
	char ch[5]; //字符数组 - 存放字符的数组就是字符数组
	//指针数组 - 存放指针的数组就是指针数组
	//int* 整形指针的数组
	//char* 字符指针的数组

	int* parr[5]; 
	char* pc[6]; //6个元素 每个元素类型是char* 

	return 0;
}


//地址解引用
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int* arr[3] = { &a, &b, &c };

	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;

	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", *(arr[i]));
		//对一个地址解引用 拿到的是这个地址指向的元素
	}

	return 0;
}




//结构体
//一、结构体的声明
//1、结构的基础知识
//结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。

//结构体：为了可以描述复杂对象
//复杂对象的属性不止一个 所以就有了不同的成员变量


//2、结构的声明
struct Book //结构体类型
{
	//成员变量 可以是不同类型
	char name[20];
	char author[15];
	float price;
};


//3、结构成员的类型
//结构的成员可以是标量、数组、指针，甚至是其他结构体。


//4、结构体变量的定义和初始化
//4.1、创建结构体类型变量
struct Book 
{
	char name[20];
	char author[15];
	float price;
}; b1, b2; //b1 b2是全局变量 - 内存的静态区

struct Point
{
	int x;
	int y;
}; p1, p2; //p1 p2是全局变量

int main()
{
	//创建结构体类型变量
	struct Book b; //局部变量 - 栈区
	struct Point p; //局部变量

	return 0;
}


//4.2、结构体类型重命名
typedef struct Stu
{
	char name[20];
	int age;
	char id[20];
}Stu; //对struct Stu重命名 是类型 与struct Stu一样

int main()
{
	struct Stu s1; //用struct Stu
	Stu s2; //更加简洁

	return 0;
}


//4.3、初始化
int main()
{
	struct Stu s1 = { "张三", 20, "2020080205" };
	Stu s2 = { "李四", 30, "2020080216" };

	struct Book b;
	struct Point p = { 10, 20 };

	return 0;
}


//结构体嵌套初始化
struct S
{
	int a;
	char c;
	double d;
};

struct T
{
	struct S s; //用struct S类型 创建了struct S s变量
	char name[20];
	int num；
};

int main()
{
	struct T t = { {100, 'c', 3.14}, "lisi", 30 };
	return 0;
}



//二、结构体成员的访问
struct S
{
	int a;
	char c;
	double d;
};

struct T
{
	struct S s; //用struct S类型 创建了struct S s变量
	char name[20];
	int num;
};

int main()
{
	//初始化
	struct T t = { {100, 'c', 3.14}, "lisi", 30 };
	//访问
	printf("%d %c %f %s %d\n", t.s.a, t.s.c, t.s.d, t.name, t.num);

	//用结构体指针访问
	struct T* pt = &t;
	printf("%d %c %f %s %d\n", pt->s.a, pt->s.c, pt->s.d, pt->name, pt->num);

	//结构体变量本身用.找 
	//结构体指针用->   当找到它的成员s是结构体变量时，用.找成员a

	return 0;
}



//三、结构体传参
struct S
{
	int arr[100];
	int num;
	char ch;
	double d;
};

//结构体传参
void print1(struct S ss) //传值调用
{
	printf("%d %d %d %d %c %lf", ss.arr[0], ss.arr[1], ss.arr[2], ss.num, ss.ch, ss.d);

}

//结构体地址传参
void print2(struct S* ps)
{
	printf("%d %d %d %d %c %lf", ps->arr[0], ps->arr[1], ps->arr[2], ps->num, ps->ch, ps->d);
}

int main()
{
	struct S s = { {1,2,3,4,5}, 100, 'w', 3.14 };
	print1(s); //传结构体
	print2(&s); //传地址 4个字节 
	//只传了地址 减少空间浪费 传参压力减小
	return 0;
}
//首选print2 
//函数传参的时候，参数是需要压栈的
//函数传参的时候，参数是需要压栈的。 如果传递一个结构体对象的时候，结构体过大，
//参数压栈的系统开销比较大，所以会导致性能的下降。

//结论：
//结构体传参的时候，要传结构体的地址


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

	return 0;
}
//形参x y是在传参的瞬间开辟空间
//栈区先使用高地址空间再使用低地址空间
























