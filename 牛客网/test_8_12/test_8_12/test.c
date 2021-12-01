#define _CRT_SECURE_NO_WARNINGS 1

BC53 计算一元二次方程
描述
从键盘输入a, b, c的值，编程计算并输出一元二次方程ax2 + bx + c = 0的根，当a = 0时，输出“Not quadratic equation”，当a ≠ 0时，根据△ = b2 - 4 * a * c的三种情况计算并输出方程的根。
输入描述：
多组输入，一行，包含三个浮点数a, b, c，以一个空格分隔，表示一元二次方程ax2 + bx + c = 0的系数。
输出描述：
针对每组输入，输出一行，输出一元二次方程ax2 + bx + c = 0的根的情况。

如果a = 0，输出“Not quadratic equation”；

如果a ≠  0，分三种情况：

△ = 0，则两个实根相等，输出形式为：x1 = x2 = ...。

△ > 0，则两个实根不等，输出形式为：x1 = ...; x2 = ...，其中x1 <= x2。

△ < 0，则有两个虚根，则输出：x1 = 实部 - 虚部i; x2 = 实部 + 虚部i，即x1的虚部系数小于等于x2的虚部系数，实部为0时不可省略。实部 = -b / (2 * a), 虚部 = sqrt(-△) / (2 * a)

    所有实数部分要求精确到小数点后2位，数字、符号之间没有空格。

    示例1
    输入：
    2.0 7.0 1.0
    输出：
    x1 = -3.35; x2 = -0.15

    示例2
    输入：
    0.0 3.0 3.0
    输出：
    Not quadratic equation

    示例3
    输入：
    1 2 1
    输出：
    x1 = x2 = -1.00

    示例4
    输入：
    2 2 5
    输出：
    x1 = -0.50 - 1.50i; x2 = -0.50 + 1.50i

    示例5
    输入：
    1 0 1
    输出：
    x1 = 0.00 - 1.00i; x2 = 0.00 + 1.00i

    [题目链接](https://www.nowcoder.com/practice/7da524bb452441b2af7e64545c38dc26)

```c
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    while ((scanf("%f %f %f", &a, &b, &c)) != EOF)
    {
        float e = b * b - 4 * a * c;
        float s = sqrt(e);
        if (a == 0)
        {
            printf("Not quadratic equation\n");
        }
        if (a != 0)
        {
            if (e == 0)
            {
                printf("x1=x2=%.2f\n", (-b + s) / (2 * a));
            }
            if (e > 0)
            {
                printf("x1=%.2f;x2=%.2f\n", (-b - s) / (2 * a), (-b + s) / (2 * a));
            }
            if (e < 0)
            {
                printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi", -b / (2 * a), sqrt(-e) / (2 * a), -b / (2 * a), sqrt(-e) / (2 * a));
            }
        }

    }

    return 0;
}
```
-- -
## BC54 获得月份天数
描述
KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
输入描述：
多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
输出描述：
针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。
示例1
输入：
2008 2
输出：
29

[题目链接](https://www.nowcoder.com/practice/13aeae34f8ed4697960f7cfc80f9f7f6)

```c
#include <stdio.h>

int is_leap_year(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int year = 0;
    int month = 0;
    while ((scanf("%d %d", &year, &month)) != EOF)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31\n");
            break;
        case 2:
            if (is_leap_year(year))
            {
                printf("29\n");
                break;
            }
            else
            {
                printf("28\n");
                break;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30\n");
            break;
        default:
            break;
        }
    }

    return 0;
}
```
----
## BC56 线段图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“* ”组成的线段图案。

输入描述：
多组输入，一个整数（1~100），表示线段长度，即“ * ”的数量。
输出描述：
针对每行输入，输出占一行，用“ * ”组成的对应长度的线段。
示例1
输入：
10
2
输出：
\ * *********
\ * *

[题目链接](https://www.nowcoder.com/practice/a95744270f274a14a8a0dafe10421589)

```c
#include <stdio.h>

int main()
{
    int line = 0;
    while ((scanf("%d", &line)) != EOF)
    {
        if (line >= 1 && line <= 100)
        {
            while (line--)
            {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC57 正方形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的正方形图案。
输入描述：
多组输入，一个整数（1~20），表示正方形的长度，也表示输出行数。

输出描述：
针对每行输入，输出用“ * ”组成的对应边长的正方形，每个“ * ”后面有一个空格。

示例1
输入：
4
输出：
\ * ***
\ * ***
\ * ***
\ * ***
示例2
输入：
5
输出：
\ * ****
\ * ****
\ * ****
\ * ****
\ * ****

[题目链接](https://www.nowcoder.com/practice/1304bb23c2e344989d5c7a578d263e4c)

```c
#include <stdio.h>

int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC58 直角三角形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的直角三角形图案。
输入描述：
多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“ * ”的数量，也表示输出行数。
输出描述：
针对每行输入，输出用“ * ”组成的对应长度的直角三角形，每个“ * ”后面有一个空格。
示例1
输入：
4
复输出：
*
\ * *
\ * **
\ * ***
示例2
输入：
5
输出：
*
\ * *
\ * **
\ * ***
\ * ****

[题目链接](https://www.nowcoder.com/practice/00dd93f7c7074754b7511bf56d1f15ac)

```c
#include <stdio.h>

int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}
```

-- -
## BC59 翻转直角三角形图案
多组输入，一个整数（2~20），表示翻转直角三角形直角边的长度，即“ * ”的数量，也表示输出行数。
输出描述：
针对每行输入，输出用“ * ”组成的对应长度的翻转直角三角形，每个“ * ”后面有一个空格。
示例1
输入：
5
输出：
\ * ****
\ * ***
\ * **
\ * *
*
示例2
输入：
6
输出：
\ * *****
\ * ****
\ * ***
\ * **
\ * *
*

[题目链接](https://www.nowcoder.com/practice/2cdea429fa414fbba26e6c821724ca06)

```c
#include <stdio.h>

int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n - i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC60 带空格直角三角形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的带空格直角三角形图案。

输入描述：
多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“ * ”的数量，也表示输出行数。

输出描述：
针对每行输入，输出用“ * ”组成的对应长度的直角三角形，每个“ * ”后面有一个空格。
![在这里插入图片描述](https://img-blog.csdnimg.cn/e870550843ed4f80b7c5c6743b69c4fd.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/192d1039c3d44155bb868073f5482670)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n - 1 - i; j++)
            {
                printf("  ");
            }
            for (j = 0; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC61 金字塔图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的金字塔图案。
输入描述：
多组输入，一个整数（2~20），表示金字塔边的长度，即“ * ”的数量，，也表示输出行数。
输出描述：
针对每行输入，输出用“ * ”组成的金字塔，每个“ * ”后面有一个空格。
![在这里插入图片描述](https://img-blog.csdnimg.cn/a01d0eecedfa4f3a90f6c0f5930f0c33.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/d84e8339f9444bb6b29bd3f227c8e538)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n - 1 - i; j++)
            {
                printf(" ");
            }
            for (j = 0; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC62 翻转金字塔图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的翻转金字塔图案。
输入描述：
多组输入，一个整数（2~20），表示翻转金字塔边的长度，即“ * ”的数量，也表示输出行数。
输出描述：
针对每行输入，输出用“ * ”组成的金字塔，每个“ * ”后面有一个空格。
![在这里插入图片描述](https://img-blog.csdnimg.cn/efe354a109fb44f7a5a593b03b8f7fe0.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/c4775776e4464537bfb6a5ba37c596c6)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }
            for (j = 0; j < n - i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC63 菱形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的菱形图案。
输入描述：
多组输入，一个整数（2~20）。

输出描述：
针对每行输入，输出用“ * ”组成的菱形，每个“ * ”后面有一个空格。
![在这里插入图片描述](https://img-blog.csdnimg.cn/0ddeb2d39b324b8cad0dea5a98407e60.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)

[题目链接] (https ://www.nowcoder.com/practice/8b935f8ffe99445dbd42494febd13e45)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        int j = 0;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j < n - i; j++)
            {
                printf(" ");
            }
            for (j = 0; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                printf(" ");
            }
            for (j = 0; j < n - i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }

    }

    return 0;
}
```
-- -
## BC64 K形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的K形图案。
输入描述：
多组输入，一个整数（2~20）。

输出描述：
针对每行输入，输出用“ * ”组成的K形，每个“ * ”后面有一个空格。
示例1
输入：
2
输出：
\ * **
\ * *
*
\ * *
\ * **
示例2
输入：
3
输出：
\ * ***
\ * **
\ * *
*
\ * *
\ * **
\ * ***
示例3
输入：
4
输出：
\ * ****
\ * ***
\ * **
\ * *
*
\ * *
\ * **
\ * ***
\ * ****

[题目链接](https://www.nowcoder.com/practice/753cc2662d9949fe826a85f815db0ca4)

```c
#include <stdio.h>

int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        int j = 0;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n - i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i + 1; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC65 箭形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的箭形图案。
输入描述：
多组输入，一个整数（2~20）。
输出描述：
针对每行输入，输出用“ * ”组成的箭形。
![在这里插入图片描述](https://img-blog.csdnimg.cn/9203d385fb4a44de8928ee451da9dd21.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/a6d1081e0c9a42f19e42ed6cd91556c1)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        int j = 0;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j < n - i; j++)
            {
                printf("  ");
            }
            for (j = 0; j <= i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                printf("  ");
            }
            for (j = 0; j < n - i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC66 反斜线形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的反斜线形图案。
输入描述：
多组输入，一个整数（2~20），表示输出的行数，也表示组成反斜线的“ * ”的数量。

输出描述：
针对每行输入，输出用“ * ”组成的反斜线。
![在这里插入图片描述](https://img-blog.csdnimg.cn/3f019616c0c14d99ba6fe61118b03f0d.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/7b066963c4eb4d188becd18c37dfe22d)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("*");
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC67 正斜线形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的正斜线形图案。
输入描述：
多组输入，一个整数（2~20），表示输出的行数，也表示组成正斜线的“ * ”的数量。
输出描述：
针对每行输入，输出用“ * ”组成的正斜线。
![在这里插入图片描述](https://img-blog.csdnimg.cn/6ffd29039af14377830bf2e7f49a0056.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/61ef68d129534dfbb04b232e1244e447)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n - 1 - i; j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
    }

    return 0;
}
```
-- -
## BC68 X形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的X形图案。
输入描述：
多组输入，一个整数（2~20），表示输出的行数，也表示组成“X”的反斜线和正斜线的长度。
输出描述：
针对每行输入，输出用“ * ”组成的X形图案。
![在这里插入图片描述](https://img-blog.csdnimg.cn/2bd06a96fa634c46bb4a5f49cabaa3a4.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/83d6afe3018e44539c51265165806ee4)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n; j++)
            {
                if (j == i || j + i == n - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
```
-- -
## BC69 空心正方形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的“空心”正方形图案。
输入描述：
多组输入，一个整数（3~20），表示输出的行数，也表示组成正方形边的“ * ”的数量。
输出描述：
针对每行输入，输出用“ * ”组成的“空心”正方形，每个“ * ”后面有一个空格。
![在这里插入图片描述](https://img-blog.csdnimg.cn/5b9c7c46d1904b2bb3dbd492d4ccd944.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/72347ee949dc47399186ee183632f303)

    ```c
#include <stdio.h>

    /*
    int main()
    {
        int n = 0;
        while(scanf("%d", &n) != EOF)
        {
            int i = 0;
            for(i=0; i<=n; i++)
            {
                int j = 0;
                for(j=0; j<n; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }
        }

        return 0;
    }
    */
    int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0;
        for (i = 1; i <= n; i++)
        {
            int j = 0;
            for (j = 1; j <= n; j++)
            {
                if (i == 1 || i == n || j == 1 || j == n)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
```
-- -
## BC70 空心三角形图案
描述
KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“ * ”组成的“空心”三角形图案。
输入描述：
多组输入，一个整数（3~20），表示输出的行数，也表示组成三角形边的“ * ”的数量。
输出描述：
针对每行输入，输出用“ * ”组成的“空心”三角形，每个“ * ”后面有一个空格。
![在这里插入图片描述](https://img-blog.csdnimg.cn/1e8c8a43cd6f4576a5ff9fbc0a6e9187.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzU2ODg0MDIz,size_16,color_FFFFFF,t_70#pic_center)
[题目链接] (https ://www.nowcoder.com/practice/2ccc5fca423e47f0b622fe6f151cfab4)

    ```c
#include <stdio.h>

    int main()
{
    int n = 0;
    while ((scanf("%d", &n)) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n; j++)
            {
                if (j == 0 || i == n - 1 || i == j)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}