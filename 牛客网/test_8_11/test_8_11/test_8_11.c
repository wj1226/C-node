@[TOC](目录)

-- -
## BC7 缩短二进制
描述
我们处理的整数通常用十进制表示，在计算机内存中是以二进制补码形式存储，但通常二进制表示的整数比较长，为了便于在程序设计过程中理解和处理数据，通常采用八进制和十六进制，缩短了二进制补码表示的整数，但保持了二进制数的表达特点。请输出十进制整数1234对应的八进制和十六进制。

输入描述：
无
输出描述：
十进制整数1234对应的八进制和十六进制（字母大写），用空格分开，并且要求，在八进制前显示前导0，在十六进制数前显示前导0X。
备注：
printf可以使用使用格式控制串“ % o”、“ % X”分别输出八进制整数和十六进制整数，并使用修饰符“#”控制前导显示

[题目链接](https://www.nowcoder.com/practice/4ffcc9f206b949ddb057ee0099b34d51)


#include <stdio.h>

int main()
{
    printf("0%o 0X%X", 1234, 1234);
    return 0;
}


## BC8 十六进制转十进制
描述
BoBo写了一个十六进制整数ABCDEF，他问KiKi对应的十进制整数是多少。

输入描述：
无
输出描述：
十六进制整数ABCDEF对应的十进制整数，所占域宽为15。
备注：
printf可以使用使用格式控制串“ % md”输出域宽为m的十进制整数。

[题目链接](https://www.nowcoder.com/practice/33e148570d5c4e728116e2f861638c9c)


#include <stdio.h>

int main()
{
    printf("%15d", 0xABCDEF);

    return 0;
}


## BC9 printf的返回值
描述
KiKi写了一个输出“Hello world!”的程序，BoBo老师告诉他printf函数有返回值，你能帮他写个程序输出printf(“Hello world!”)的返回值吗？
输入描述：
无
输出描述：
包括两行：
第一行为“Hello world!”
第二行为printf(“Hello world!”)调用后的返回值。

[题目链接](https://www.nowcoder.com/practice/a19ef1d8e55c4cc786f11cbf6b2fde61)


#include <stdio.h>

int main()
{
    int ret = printf("Hello world!");
    printf("\n");
    printf("%d", ret);

    return 0;
}



## BC11 学生基本信息输入输出
依次输入一个学生的学号，以及3科（C语言，数学，英语）成绩，在屏幕上输出该学生的学号，3科成绩。
输入描述：
学号以及3科成绩，学号和成绩之间用英文分号隔开，成绩之间用英文逗号隔开。
输出描述：
学号，3科成绩，输出格式详见输出样例。
示例1
输入：
17140216; 80.845, 90.55, 100.00

输出：
The each subject score of  No. 17140216 is 80.85, 90.55, 100.00.

[题目链接](https://www.nowcoder.com/practice/58b6a69b4bf943b49d2cd3c15770b9fd)


#include <stdio.h>

int main()
{
    int id = 0;
    float c = 0;
    float math = 0;
    float english = 0;

    scanf("%d;%f,%f,%f", &id, &c, &math, &english);
    printf("The each subject score of  No. %d is %.2f, %.2f, %.2f.", id, c, math, english);

    return 0;
}


## BC12 字符金字塔
描述
输入一个字符，用它构造一个三角形金字塔。
输入描述：
输入只有一行，一个字符。
输出描述：
该字符构成的三角形金字塔。
示例1
输入：
1
输出：
1
1 1
1 1 1
1 1 1 1
1 1 1 1 1

[题目链接](https://www.nowcoder.com/practice/0fae60c3b5c64699b7c0f031c2187dde)


#include <stdio.h>

int main()
{
    char ch;
    scanf("%c", &ch);
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        int j = 0;
        for (j = 0; j < 5 - 1 - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("%c ", ch);
        }
        printf("\n");
    }

    return 0;
}



## BC13 ASCII码
描述
BoBo教KiKi字符常量或字符变量表示的字符在内存中以ASCII码形式存储。BoBo出了一个问题给KiKi，转换以下ASCII码为对应字符并输出他们。

73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33

输入描述：
无
输出描述：
转换输出题目中给出的所有ASCII到对应的字符。

[题目链接](https://www.nowcoder.com/practice/4280d330fe314e8f98cd5c593e3e9190)


#include <stdio.h>

int main()
{
    int arr[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 };

    int i = 0;
    for (i = 0; i < 12; i++)
    {
        printf("%c", arr[i]);
    }

    return 0;
}



## BC14 出生日期输入输出
描述
输入一个人的出生日期（包括年月日），将该生日中的年、月、日分别输出。
输入描述：
输入只有一行，出生日期，包括年月日，年月日之间的数字没有分隔符。
输出描述：
三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。
示例1
输入：
20130225
输出：
year = 2013
month = 02
date = 25

[题目链接](https://www.nowcoder.com/practice/4a4a9dd1edb6453ba4a0432319200743)


#include <stdio.h>

int main()
{
    int y = 0;
    scanf("%d", &y);

    int year = y / 10000;
    int month = y % 10000 / 100;
    int date = y % 100;

    printf("year=%d\n", year);
    printf("month=%02d\n", month);
    printf("date=%02d\n", date);

    return 0;
}


## BC16 字符转ASCII码
描述
BoBo教KiKi字符常量或字符变量表示的字符在内存中以ASCII码形式存储。BoBo出了一个问题给KiKi，输入一个字符，输出该字符相应的ASCII码。
输入描述：
一行，一个字符。
输出描述：
一行，输出输入字符对应的ASCII码。
示例1
输入：
c
输出：
99

[题目链接](https://www.nowcoder.com/practice/93f4d05a02d9468db424ed4316bfc8fd)


#include <stdio.h>

int main()
{
    char ch = 0;
    scanf("%c", &ch);
    printf("%d", ch);
    return 0;
}


## BC17 计算表达式的值
描述
请计算表达式“(-8 + 22)×a - 10 + c÷2”，其中，a = 40，c = 212。

输入描述：
无。
输出描述：
(-8 + 22)×a - 10 + c÷2计算之后的结果，为一个整数。

[题目链接](https://www.nowcoder.com/practice/58457d27f91043edaf95b6591bb64fd6)


#include <stdio.h>

int main()
{
    int a = 40;
    int c = 212;
    int b = (-8 + 22) * a - 10 + c / 2;
    printf("%d", b);

    return 0;
}



## BC18 计算带余除法
描述
给定两个整数a和b(－10, 000 < a, b < 10, 000)，计算a除以b的整数商和余数。
    输入描述：
    一行，包括两个整数a和b，依次为被除数和除数（不为零），中间用空格隔开。
    输出描述：
    一行，包含两个整数，依次为整数商和余数，中间用一个空格隔开。
    示例1
    输入：
    15 2
    输出：
    7 1

    [题目链接](https://www.nowcoder.com/practice/34d3911bf2fd48a285f6396e886a1259)

#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    printf("%d %d", a / b, a % b);

    return 0;
}



## BC19 反向输出一个四位数
描述
将一个四位数，反向输出。


输入描述：
一行，输入一个整数n（1000 <= n <= 9999）。
输出描述：
针对每组输入，反向输出对应四位数。
示例1
输入：
1234
输出：
4321

[题目链接](https://www.nowcoder.com/practice/1f7c1d67446e4361bf4af67c08e0b8b0)


#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    while (n)
    {
        printf("%d", n % 10);
        n /= 10;
    }

    return 0;
}



## BC20 kiki算数
描述
问题：KiKi今年5岁了，已经能够认识100以内的非负整数，并且并且能够进行 100 以内的非负整数的加法计算。不过，BoBo老师发现KiKi在进行大于等于100的正整数的计算时，规则如下：

1.只保留该数的最后两位，例如：对KiKi来说1234等价于34；

2.如果计算结果大于等于 100， 那么KIKI也仅保留计算结果的最后两位，如果此两位中十位为0，则只保留个位。

例如：45 + 80 = 25

要求给定非负整数 a和 b，模拟KiKi的运算规则计算出 a + b 的值。

输入描述：
一行，输入两个非负整数a和b，用一个空格分隔。（0 <= a, b <= 231 - 1）。
输出描述：
针对每组输入，输出按照KiKi的运算规则计算出 a + b 的值。
示例1
输入：
45 80
输出：
25

[题目链接](https://www.nowcoder.com/practice/bcaf710fb58a44e1b678a890e6e90d7c)


#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;
    if (c / 10 % 10 == 0)
    {
        if (c % 10 == 0)
        {
            printf("0");
        }
        else
        {
            printf("%d", c % 10);
        }
    }
    else
        printf("%d%d", c / 10 % 10, c % 10);

    return 0;
}


## BC21 浮点数的个位数字
描述
给定一个浮点数，要求得到该浮点数的个位数。

输入描述：
一行，包括一个浮点数。
输出描述：
一行，包含一个整数，为输入浮点数对应的个位数。
示例1
输入：
13.141
输出：
3

[题目链接](https://www.nowcoder.com/practice/ffa94d27c6534396aef38813535c279f)


#include <stdio.h>

int main()
{
    float n = 0;
    scanf("%f", &n);
    printf("%d", (int)n % 10);

    return 0;
}


## BC22 你能活多少秒
描述
问题：一年约有3.156×107s，要求输入您的年龄，显示该年龄合多少秒。


输入描述：
一行，包括一个整数age(0 < age <= 200)。
    输出描述：
    一行，包含一个整数，输出年龄对应的秒数。
    示例1
    输入：
    20
    输出：
    631200000

    [题目链接](https://www.nowcoder.com/practice/e1d1bd99fee34b66ae3c777b74d555c8)


#include <stdio.h>

int main()
{
    long long age = 0;
    scanf("%d", &age);
    printf("%lld", age * 3156 * 10000);

    return 0;
}



## BC23 时间转换
描述
给定秒数seconds(0 < seconds < 100, 000, 000)，把秒转化成小时、分钟和秒。

    输入描述：
    一行，包括一个整数，即给定的秒数。
    输出描述：
    一行，包含三个整数，依次为输入整数对应的小时数、分钟数和秒数（可能为零），中间用一个空格隔开。
    示例1
    输入：
    3661
    输出：
    1 1 1

    [题目链接](https://www.nowcoder.com/practice/c4ae7bcac7f9491b8be82ee516a94899)


#include <stdio.h>

int main()
{
    int seconds = 0;
    scanf("%d", &seconds);
    int h = seconds / 3600;
    int m = seconds % 3600 / 60;
    int s = seconds % 3600 % 60;
    printf("%d %d %d", h, m, s);
    return 0;
}


## BC24 总成绩和平均分计算
描述
依次输入一个学生的3科成绩，在屏幕上输出该学生的总成绩以及平均成绩。
输入描述：
一行，3科成绩，成绩之间用一个空格隔开。
输出描述：
一行，总成绩和平均成绩（小数点后保留两位），用一个空格隔开。
示例1
输入：
79.5 80.0 98.0
输出：
257.50 85.83

[题目链接](https://www.nowcoder.com/practice/0fa5132c156b434da4347ad051c4be22)


#include <stdio.h>

int main()
{
    float m, c, e;
    scanf("%f %f %f", &m, &c, &e);
    printf("%.2f %.2f", m + c + e, (m + c + e) / 3);

    return 0;
}


## BC25 计算体重指数
描述
问题：计算BMI指数（身体质量指数）。BMI指数（即身体质量指数，简称体质指数又称体重，英文为Body Mass Index，简称BMI），是用体重公斤数除以身高米数平方得出的数字，是目前国际上常用的衡量人体胖瘦程度以及是否健康的一个标准。主要用于统计用途，当我们需要比较及分析一个人的体重对于不同高度的人所带来的健康影响时，BMI值是一个中立而可靠的指标。

输入描述：
一行，两个整数，分别表示体重（公斤），身高（厘米），中间用一个空格分隔。
输出描述：
一行，BMI指数（保留两位小数）。
示例1
输入：
70 170
输出：
24.22

[题目链接](https://www.nowcoder.com/practice/422f6341cf1b4212a7f8c703df111389)


#include <stdio.h>

int main()
{
    float a, b;
    scanf("%f %f", &a, &b);
    b /= 100;
    printf("%.2f", a / (b * b));

    return 0;
}



## BC27 计算球体的体积
描述
给定一个球体的半径，计算其体积。其中球体体积公式为 V = 4 / 3 * πr3，其中 π = 3.1415926。
输入描述：
一行，用浮点数表示的球体的半径。
输出描述：
一行，球体的体积，小数点后保留3位。
示例1
输入：
3.0
输出：
113.097

[题目链接](https://www.nowcoder.com/practice/0f5d9bfcd63b47fda2052a583b1fbd1f)


#include <stdio.h>

int main()
{
    float r;
    scanf("%f", &r);
    printf("%.3f", 4.0 / 3 * 3.1415926 * r * r * r);

    return 0;
}


## BC28 大小写转换
描述
实现字母的大小写转换。多组输入输出。
输入描述：
多组输入，每一行输入大写字母。
输出描述：
针对每组输入输出对应的小写字母。
示例1
输入：
A
B
输出：
a
b

[题目链接](https://www.nowcoder.com/practice/4e089ee8966a4ed4b306f64e68d45264)


#include <stdio.h>

int main()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        printf("%c\n", ch + 32);
        getchar();
    }

    return 0;
}


## BC29 2的n次方计算
描述
不使用累计乘法的基础上，通过移位运算（ << ）实现2的n次方的计算。

输入描述：
多组输入，每一行输入整数n（0 <= n < 31）。
    输出描述：
    针对每组输入输出对应的2的n次方的结果。
    示例1
    输入：
    2
    10
    输出：
    4
    1024

    [题目链接](https://www.nowcoder.com/practice/35a1e8b18658411388bc1672439de1d9)


#include <stdio.h>

int main()
{
    int n = 0;
    while ((scanf("%d", &n) != EOF))
    {
        printf("%d\n", 1 << n);
    }

    return 0;
}
```
-- -
## BC30 KiKi和酸奶
描述
BoBo买了一箱酸奶，里面有n盒未打开的酸奶，KiKi喜欢喝酸奶，第一时间发现了酸奶。KiKi每h分钟能喝光一盒酸奶，并且KiKi在喝光一盒酸奶之前不会喝另一个，那么经过m分钟后还有多少盒未打开的酸奶？

输入描述：
多组输入，每组输入仅一行，包括n，h和m（均为整数）。输入数据保证m <= n * h。
输出描述：
针对每组输入，输出也仅一行，剩下的未打开的酸奶盒数。
示例1
输入：
8 5 16
输出：
4

[题目链接](https://www.nowcoder.com/practice/c7721f3a1b1a47a783974453e82cadbb)

```c
#include <stdio.h>

int main()
{
    int n, h, m;
    while ((scanf("%d %d %d", &n, &h, &m)) != EOF)
    {
        if (m % h)
        {
            printf("%d\n", n - m / h - 1);
        }
        else
        {
            printf("%d\n", n - m / h);
        }
    }

    return 0;
}
```
-- -
## BC32 输出学生信息
描述
学生信息管理系统是学校教学管理的重要工具，现有一名学生基本信息如下：姓名 - Jack，年龄 - 18，性别 - Man，请按照输出样例的格式输出该学生的信息。
输入描述：
无
输出描述：
输出分为三行，分别为标题行，分隔行，信息行。
第一行，标题行，每个标题之间间隔4个空格。
第二行，分隔行，一共21个减号"-"。
第三行，信息行，每列输出信息和标题首字母对齐。输出样例如下：
Name Age Gender
\-------------------- -
Jack 18 man

[题目链接](https://www.nowcoder.com/practice/8e94458049eb4e838f711bbd1be0045e)

```c
#include <stdio.h>

int main()
{
    printf("Name    Age    Gender\n");
    printf("---------------------\n");
    printf("Jack    18     man\n");

    return 0;
}
```
-- -
## BC33 计算平均成绩
描述
从键盘输入5个学生的成绩（整数），求他们的平均成绩（浮点数，保留一位小数）。

输入描述：
一行，连续输入5个整数（范围0~100），用空格分隔。
输出描述：
一行，输出5个数的平均数（保留一位小数）。
示例1
输入：
75 80 43 67 96
输出：
72.2

[题目链接](https://www.nowcoder.com/practice/30a28eb88c3f4e87be1a5b397ddd6fe2)

```c
#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("%.1f", (a + b + c + d + e) / 5.0);

    return 0;
}
```
-- -
## BC34 进制A + B
描述
输入一个十六进制数a，和一个八进制数b，输出a + b的十进制结果（范围 - 231~231 - 1）。
输入描述：
一行，一个十六进制数a，和一个八进制数b，中间间隔一个空格。
输出描述：
一行，a + b的十进制结果。
示例1
输入：
0x12 05
复制
输出：
23
备注：
十六进制Hexadecimal一般以0x开头，例如0xFF。八进制Octal，一般以0开头，例如07。

[题目链接](https://www.nowcoder.com/practice/6187581174ac48278ca3bccf8d534897)

```c
#include <stdio.h>

int main()
{
    int a, b;
    scanf("0x%x 0%o", &a, &b);
    printf("%d", a + b);

    return 0;
}
```
-- -
## BC35 判断字母
描述
从键盘任意输入一个字符，编程判断是否是字母（包括大小写）。
输入描述：
多组输入，每行输入包括一个字符。
输出描述：
针对每行输入，输出该字符是字母（YES）或不是（NO）。
示例1
输入：
H
9
输出：
YES
NO

[题目链接](https://www.nowcoder.com/practice/44d2d63103664913bc243d3836b4f341)

```c
#include <stdio.h>

int main()
{
    // 多组输入
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch >= 'A' && ch <= 'Z' || (ch >= 'a' && ch <= 'x'))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        getchar(); // 处理\n
    }

    return 0;
}
```

-- -
## BC36 健康评估
描述
BMI指数（即身体质量指数）是用体重公斤数除以身高米数平方得出的数字，是目前国际上常用的衡量人体胖瘦程度以及是否健康的一个标准。例如：一个人的身高为1.75米，体重为68千克，他的BMI = 68 / (1.75 ^ 2) = 22.2（千克 / 米 ^ 2）。当BMI指数为18.5～23.9时属正常，否则表示身体存在健康风险。编程判断人体健康情况。
输入描述：
一行，输入一个人的体重（千克）和身高（米），中间用一个空格分隔。
输出描述：
一行，输出身体Normal(正常)或Abnormal(不正常)。
示例1
输入：
68 1.75
输出：
Normal

示例2
输入：
67.5 1.65
输出：
Abnormal

[题目链接](https://www.nowcoder.com/practice/08b28e61ff6345febf09969b3a167f7e)

```c
#include <stdio.h>

int main()
{
    float h, w, BMI;
    scanf("%f %f", &h, &w);
    BMI = h / (w * w);
    if (BMI >= 18.5 && BMI <= 23.9)
    {
        printf("Normal");
    }
    else
    {
        printf("Abnormal");
    }


    return 0;
}
```
-- -
## BC37 网购
描述
KiKi非常喜欢网购，在一家店铺他看中了一件衣服，他了解到，如果今天是“双11”（11月11日）则这件衣服打7折，“双12” （12月12日）则这件衣服打8折，如果有优惠券可以额外减50元（优惠券只能在双11或双12使用），求KiKi最终所花的钱数。
输入描述：
一行，四个数字，第一个数表示小明看中的衣服价格，第二和第三个整数分别表示当天的月份、当天的日期、第四个整数表示是否有优惠券（有优惠券用1表示，无优惠券用0表示）。
输出描述：
一行，小明实际花的钱数（保留两位小数）。（提示：不要指望商家倒找你钱）
示例1
输入：
1000.0 11 11 1
输出：
650.00
示例2
输入：
999.8 12 12 0
输出：
799.84
示例3
输入：
66.6 11 11 1
输出：
0.00

[题目链接](https://www.nowcoder.com/practice/5d7dfd405e5f4e4fbfdff6862c46b751)

```c
#include <stdio.h>

int main()
{
    float price;
    int month, day, c;
    scanf("%f %d %d %d", &price, &month, &day, &c);
    if (month == 11 && day == 11)
    {
        if (c == 1)
        {
            price = price * 0.7 - 50;
        }
        else {
            price = price * 0.7;
        }
    }
    if (month == 12 && day == 12)
    {
        if (c == 1)
        {
            price = price * 0.8 - 50;
        }
        else {
            price = price * 0.8;
        }
    }

    if (price <= 0)
    {
        price = 0;
        printf("%.2f", price);
    }
    else
    {
        printf("%.2f", price);
    }

    return 0;
}
```
-- -
## BC40 竞选社长
描述
假设你们社团要竞选社长，有两名候选人分别是A和B，社团每名同学必须并且只能投一票，最终得票多的人为社长.
输入描述：
一行，字符序列，包含A或B，输入以字符0结束。
输出描述：
一行，一个字符，A或B或E，输出A表示A得票数多，输出B表示B得票数多，输出E表示二人得票数相等。
示例1
输入：
ABBABBAAB0
输出：
B

[题目链接](https://www.nowcoder.com/practice/45a30e3ef51040ed8a7674984d6d1553)

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char arr[100] = { 0 };
    scanf("%s", &arr);
    int len = strlen(arr);
    int a = 0;
    int b = 0;
    int e = 0;
    int i = 0;
    for (i = 0; i < len - 1; i++)
    {
        if (arr[i] == 'A')
        {
            a++;
        }
        if (arr[i] == 'B')
        {
            b++;
        }
    }
    if (a > b)
    {
        printf("A");
    }
    else if (a < b)
    {
        printf("B");
    }
    else if (a == b)
    {
        printf("E");
    }

    return 0;
}
```
-- -
## BC41 你是天才吗？
描述
据说智商140以上者称为天才，KiKi想知道他自己是不是天才，请帮他编程判断。输入一个整数表示一个人的智商，如果大于等于140，则表明他是一个天才，输出“Genius”。
输入描述：
多组输入，每行输入包括一个整数表示的智商。
输出描述：
针对每行输入，输出“Genius”。
示例1
输入：
160
输出：
Genius

[题目链接](https://www.nowcoder.com/practice/557cc54704bb4d56b73b62d1a5455331)

```c
#include <stdio.h>

int main()
{
    int IQ = 0;
    while ((scanf("%d", &IQ) != EOF))
    {
        if (IQ >= 140)
        {
            printf("Genius\n");
        }
    }

    return 0;
}
```
-- -
## BC42 完美成绩
描述
KiKi想知道他的考试成绩是否完美，请帮他判断。从键盘输入一个整数表示的成绩，编程判断成绩是否在90~100之间，如果是则输出“Perfect”。

输入描述：
多组输入，每行输入包括一个整数表示的成绩（90~100）。
输出描述：
针对每行输入，输出“Perfect”。
示例1
输入：
98
输出：
Perfect

[题目链接](https://www.nowcoder.com/practice/8312e497509a450f968d9a6a2381ce32)

```c
#include <stdio.h>

int main()
{
    int score = 0;
    while ((scanf("%d", &score) != EOF))
    {
        if (score >= 90 && score <= 100)
        {
            printf("Perfect\n");
        }
    }

    return 0;
}
```
-- -
## BC43 及格分数
描述
KiKi想知道他的考试分数是否通过，请帮他判断。从键盘任意输入一个整数表示的分数，编程判断该分数是否在及格范围内，如果及格，即：分数大于等于60分，是输出“Pass”，否则，输出“Fail”。
输入描述：
多组输入，每行输入包括一个整数表示的分数（0~100）。
输出描述：
针对每行输入，输出“Pass”或“Fail”。
示例1
输入：
94
输出：
Pass
示例2
输入：
44
输出：
Fail

[题目链接](https://www.nowcoder.com/practice/56513524333148b38945e1989bc7df4e)

```c
#include <stdio.h>

int main()
{
    int socre = 0;
    while ((scanf("%d", &socre) != EOF))
    {
        if (socre >= 60)
        {
            printf("Pass\n");
        }
        else
        {
            printf("Fail\n");
        }
    }

    return 0;
}
```
-- -
## BC44 判断整数奇偶性
描述
KiKi想知道一个整数的奇偶性，请帮他判断。从键盘任意输入一个整数（范围 - 231~231 - 1），编程判断它的奇偶性。
输入描述：
多组输入，每行输入包括一个整数。
输出描述：
针对每行输入，输出该数是奇数（Odd）还是偶数（Even）。
示例1
输入：
4
7
输出：
Even
Odd

[题目链接](https://www.nowcoder.com/practice/a8b018667e274af29b5f76a6673450fc)

```c
#include <stdio.h>

int main()
{
    int num = 0;
    while ((scanf("%d", &num) != EOF))
    {
        if (num & 2 != 0)
        {
            printf("Odd\n");
        }
        else
        {
            printf("Even\n");
        }
    }

    return 0;
}
```
-- -
## BC46 判断是元音还是辅音
描述
KiKi开始学习英文字母，BoBo老师告诉他，有五个字母A(a), E(e), I(i), O(o), U(u)称为元音，其他所有字母称为辅音，请帮他编写程序判断输入的字母是元音（Vowel）还是辅音（Consonant）。
输入描述：
多组输入，每行输入一个字母。
输出描述：
针对每组输入，输出为一行，如果输入字母是元音（包括大小写），输出“Vowel”，如果输入字母是非元音，输出“Consonant”。
示例1
输入：
A
b
输出：
Vowel
Consonant

[题目链接](https://www.nowcoder.com/practice/7eb4df4d52c44d309081509cf52ecbc4)

逐一判断
```c
#include <stdio.h>

int main()
{
    int ch = 0;

    while ((ch = getchar()) != EOF)
    {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            printf("Vowel\n");
        }
        else
        {
            printf("Consonant\n");
        }
        getchar();
    }

    return 0;
}
```

用数组存储
```c
#include <stdio.h>

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
```
-- -
## BC47 判断是不是字母
描述
KiKi想判断输入的字符是不是字母，请帮他编程实现。

输入描述：
多组输入，每一行输入一个字符。
输出描述：
针对每组输入，输出单独占一行，判断输入字符是否为字母，输出内容详见输出样例。
示例1
输入：
A
6
输出：
A is an alphabet.
6 is not an alphabet.

[题目链接](https://www.nowcoder.com/practice/91a588dd4cd244bfa616f17603ec123c)

```c
#include <stdio.h>

int main()
{
    int ch = 0;
    while ((scanf("%c\n", &ch)) != EOF)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            printf("%c is an alphabet.\n", ch);
        }
        else
        {
            printf("%c is not an alphabet.\n", ch);
        }
    }

    return 0;
}
```
-- -
## BC48 字母大小写转换
描述
KiKi想完成字母大小写转换，有一个字符，判断它是否为大写字母，如果是，将它转换成小写字母；反之则转换为大写字母。
输入描述：
多组输入，每一行输入一个字母。
输出描述：
针对每组输入，输出单独占一行，输出字母的对应形式。
示例1
输入：
a
A
Z
输出：
A
a
z

[题目链接](https://www.nowcoder.com/practice/850ebd30a2a34cfc87199da3fc15786a)

```c
#include <stdio.h>

int main()
{
    int ch;
    while ((scanf("%c", &ch)) != EOF)
    {
        getchar();
        if (ch >= 'A' && ch <= 'Z')
        {
            printf("%c\n", ch + 32);
        }
        if (ch >= 'a' && ch <= 'z')
        {
            printf("%c\n", ch - 32);
        }
    }

    return 0;
}
```
-- -
## BC49 判断两个数的大小关系
描述
KiKi想知道从键盘输入的两个数的大小关系，请编程实现。
输入描述：
题目有多组输入数据，每一行输入两个整数（范围（1 ~231 - 1），用空格分隔。
输出描述：
针对每行输入，输出两个整数及其大小关系，数字和关系运算符之间没有空格，详见输入输出样例。
示例1
输入：
1 1
输出：
1 = 1
示例2
输入：
1 0
输出：
1 > 0
示例3
输入：
0 1
输出：
0 < 1

    [题目链接](https://www.nowcoder.com/practice/f05358b9e8164b27871c87d3097f4dab)

```c
#include <stdio.h>

int main()
{
    int num1, num2;
    while ((scanf("%d %d", &num1, &num2)) != EOF)
    {
        if (num1 == num2)
        {
            printf("%d=%d\n", num1, num2);
        }
        if (num1 > num2)
        {
            printf("%d>%d\n", num1, num2);
        }
        if (num1 < num2)
        {
            printf("%d<%d\n", num1, num2);
        }
    }

    return 0;
}
```
-- -
## BC50 计算单位阶跃函数
描述
KiKi最近学习了信号与系统课程，这门课里有一个非常有趣的函数，单位阶跃函数，其中一种定义方式为：
![在这里插入图片描述](https://img-blog.csdnimg.cn/21cc32d39e0c4b61b509209ce2f1ba62.png#pic_center)
现在试求单位冲激函数在时域t上的值。

输入描述：
题目有多组输入数据，每一行输入一个t(-1000 < t < 1000)表示函数的时域t。
    输出描述：
    输出函数的值并换行。
    示例1
    输入：
    11
    0
    - 11
    输出：
    1
    0.5
    0

    [题目链接](https://www.nowcoder.com/practice/0b23793ae48a4e6cb7dfff042c959a04)

```c
#include <stdio.h>

int main()
{
    int t = 0;
    while ((scanf("%d", &t)) != EOF)
    {
        if (t > 0)
        {
            printf("1\n");
        }
        if (t == 0)
        {
            printf("0.5\n");
        }
        if (t < 0)
        {
            printf("0\n");
        }
    }

    return 0;
}
```
-- -
## BC51 三角形判断
描述
KiKi想知道已经给出的三条边a，b，c能否构成三角形，如果能构成三角形，判断三角形的类型（等边三角形、等腰三角形或普通三角形）。
输入描述：
题目有多组输入数据，每一行输入三个a，b，c(0 < a, b, c < 1000)，作为三角形的三个边，用空格分隔。
    输出描述：
    针对每组输入数据，输出占一行，如果能构成三角形，等边三角形则输出“Equilateral triangle!”，等腰三角形则输出“Isosceles triangle!”，其余的三角形则输出“Ordinary triangle!”，反之输出“Not a triangle!”。
    示例1
    输入：
    2 3 2
    3 3 3
    输出：
    Isosceles triangle!
    Equilateral triangle!

    [题目链接](https://www.nowcoder.com/practice/689ec1e742394e09b1059556fc167b65)

```c
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            // 判断边
            if (a == b && b == c)
            {
                printf("Equilateral triangle!\n");
            }
            else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
            {
                printf("Isosceles triangle!\n");
            }
            else
            {
                printf("Ordinary triangle!\n");
            }
        }
        else
        {
            printf("Not a triangle!\n");
        }
    }

    return 0;
}
```
-- -
## BC52 衡量人体胖瘦程度
描述
在计算BMI（BodyMassIndex ，身体质量指数）的案例基础上，判断人体胖瘦程度。BMI中国标准如下表所示。
![在这里插入图片描述](https://img-blog.csdnimg.cn/f9243b20687448639510c0f92428a328.png#pic_center)
输入描述：
多组输入，每一行包括两个整数，用空格隔开，分别为体重（公斤）和身高（厘米）。
输出描述：
针对每行输入，输出为一行，人体胖瘦程度，即分类。
示例1
输入：
80 170
60 170
90 160
50 185
输出：
Overweight
Normal
Obese
Underweight

[题目链接](https://www.nowcoder.com/practice/4d604603fae94a26b59b7bc18f363bc0)

```c
#include <stdio.h>

int main()
{
    int w, h;
    float BMI;
    while ((scanf("%d %d", &w, &h)) != EOF)
    {
        BMI = w / (h / 100.00) / (h / 100.00);
        if (BMI < 18.5)
        {
            printf("Underweight\n");
        }
        if (BMI >= 18.5 && BMI <= 23.9)
        {
            printf("Normal\n");
        }
        if (BMI > 23.9 && BMI <= 27.9)
        {
            printf("Overweight\n");
        }
        if (BMI > 27.9)
        {
            printf("Obese\n");
        }
    }

    return 0;
}