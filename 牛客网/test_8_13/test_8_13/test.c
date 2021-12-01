#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//BC33
#include <stdio.h>
 
int main()
{
	int num[5] = { 0 };

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
	}

	int sum = 0;
	for (i = 0; i < 5; i++)
	{
		sum += num[i];
	}

	printf("%.1lf", sum / 5.0);

	return 0;
}

/*
int main()
{
	int a,b,c,d,e;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%.1f", (a+b+c+d+e)/5.0);

	return 0;
}
*/


//BC30
#include <stdio.h>

int main()
{
    int n = 0;
    int h = 0;
    int m = 0;
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


//BC23
#include <stdio.h>
/*
int main()
{
    int seconds = 0;
    scanf("%d", &seconds);
    int h = seconds/3600;
    int m = seconds%3600/60;
    int s = seconds%3600%60;
    printf("%d %d %d", h, m, s);
    return 0;
}
*/

int main()
{
    int seconds = 0;
    int h = 0;
    int m = 0;
    int s = 0;
    scanf("%d", &seconds);

    h = seconds / 60 / 60;
    m = seconds / 60 % 60;
    s = seconds % 60;

    printf("%d %d %d\n", h, m, s);

    return 0;
}


//BC24
#include <stdio.h>

int main()
{
	double socre = 0.0;
	double sum = 0.0;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		scanf("%lf", &socre);
		sum += socre;
	}
	printf("%.2lf %.2lf", sum, sum / 3);
	return 0;
}

/*
int main()
{
	double socre[3] = { 0 };
	scanf("%lf %lf %lf", &socre[0], &socre[1], &socre[2]);
	double sum = socre[0] + socre[1] + socre[2];
	double avg = sum / 3.0;
	printf("%.2lf %.2lf", sum, avg);

	return 0;
}
*/

/*
int main()
{
	float m,c,e;
	scanf("%f %f %f", &m, &c, &e);
	printf("%.2f %.2f", m+c+e, (m+c+e)/3);

	return 0;
}
*/


//BC26
#include <stdio.h>
#include <math.h>

int main()
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    scanf("%lf %lf %lf", &a, &b, &c);


    double circumference = a + b + c;
    double p = circumference / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("circumference=%.2lf area=%.2lf\n", circumference, area);

    return 0;
}


//BC27
#include <stdio.h>

int main()
{
    double r = 0.0;
    double v = 0.0;
    double pi = 3.1415926;

    scanf("%lf", &r);
    v = 4.0 / 3 * pi * r * r * r;
    printf("%.3lf", v);

    return 0;
}

/*
#include <stdio.h>
#include <math.h>

int main()
{
    int n = (int)pow(2, 6);
    printf("%d\n", n);
    return 0;
}
*/


//BC34
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    scanf("0x%x 0%o", &a, &b);
    printf("%d\n", a + b);

    return 0;
}


//BC37
#include <stdio.h>

int main()
{
    double price = 0.0;
    int month = 0;
    int day = 0;
    int flag = 0; //是否有优惠券
    double cut = 1.0; //折扣
    double last = 0.0;

    scanf("%lf %d %d %d", &price, &month, &day, &flag);
    if (month == 11 && day == 11)
    {
        cut = 0.7;
    }
    else if (month == 12 && day == 12)
    {
        cut = 0.8;
    }

    last = price * cut - flag * 50;

    if (last < 0.0)
        printf("%.2lf\n", 0.0);
    else
        printf("%.2lf\n", last);

    return 0;
}

int main()
{
    double price = 0.0;
    int month = 0;
    int day = 0;
    int flag = 0; //是否有优惠券
    double cut = 1.0; //折扣
    double last = 0.0;

    scanf("%lf %d %d %d", &price, &month, &day, &flag);
    if (month == 11 && day == 11)
    {
        price *= 0.7;
        if (flag == 1)
            price -= 50;
    }
    else if (month == 12 && day == 12)
    {
        price *= 0.8;
        if (flag == 1)
            price -= 50;
    }

    if (last < 0.0)
        printf("%.2lf\n", 0.0);
    else
        printf("%.2lf\n", last);

    return 0;
}

int main()
{
    double price = 0.0;
    int month = 0;
    int day = 0;
    int flag = 0; //是否有优惠券
    double cut = 1.0; //折扣
    double last = 0.0;

    scanf("%lf %d %d %d", &price, &month, &day, &flag);
    if (month == 11 && day == 11)
    {
        cut = 0.7;
        if (flag == 1)
        {
            last = price * cut - 50;
        }
        else
        {
            last = price * cut;
        }
    }
    else if (month == 12 && day == 12)
    {
        cut = 0.8;
        if (flag == 1)
        {
            last = price * cut - 50;
        }
        else
        {
            last = price * cut;
        }
    }

    if (last < 0.0)
    {
        printf("%.2lf\n", 0.0);
    }
    else
    {
        printf("%.2lf\n", last);
    }

    return 0;
}

/*
int main()
{
    float price;
    int month,day,c;
    scanf("%f %d %d %d", &price, &month, &day, &c);
    if(month==11 && day==11)
    {
        if(c==1)
        {
            price = price*0.7-50;
        }
        else{
                price = price*0.7;
            }
    }
    if(month==12 && day==12)
    {
        if(c==1)
        {
            price = price*0.8-50;
        }
        else{
                price = price*0.8;
            }
    }

    if(price <= 0)
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
*/


//BC39
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    int arr[40] = { 0 };
    scanf("%d", &n);
    //元素个数（要排序的个数） 每个元素的大小
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, cmp_int);
    //冒泡 升序 后5元素
    for (i = n - 1; i >= n - 5; i--)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

//
int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    int arr[40] = { 0 };
    scanf("%d", &n);
    //元素个数（要排序的个数） 每个元素的大小
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++)//趟数
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    //冒泡 升序 后5元素
    for (i = n - 1; i >= n - 5; i--)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}


//BC40
#include <stdio.h>

int main()
{
    char buf[100] = { 0 };
    get(buf);
    int count_a = 0;
    int count_b = 0;
    int i = 0;
    while (buf[i] != '0')
    {
        if (buf[i] == 'A')
            count_a++;
        if (buf[i] == 'B')
            count_b++;
        i++;
    }
    if (count_a > count_b)
    {
        printf("B\n");
    }
    else if (count_a < count_b)
    {
        printf("B\n");
    }
    else
    {
        printf("E\n");
    }

    return 0;
}


//BC41
 ~按位取反
~EOF 
~-1
-1补码全1 整数在内存中存的是补码
~-1是全0 为假

#include <stdio.h>

int main()
{
    int iq = 0;
    while (~scanf("%d", &iq))
    {
        if (iq >= 140)
        {
            printf("Genius\n");
        }
    }

    return 0;
}


//BC45
int main()
{
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    while (~scanf("%d%d%d", &n1, &n2, &n3))
    {
        int max = n1 > n2 ? n1 : n2;
        max = max > n3 ? max : n3;
        printf("%d\n", max);
    }
    return 0;
}

//
int main()
{
    int num[3] = { 0 };
    while (~scanf("%d%d%d", &num[0], &num[1], &num[2]))
    {
        int max = 0;
        int i = 0;
        for (i = 0; i < 3; i++)
        {
            if (num[i] > max)
            {
                max = num[i];
            }
        }
        printf("%d\n", max);
    }
   
    return 0;
}


//
#include <string.h>

int main()
{
    int ch = 0;
    char vowel[] = "aeiouAEIOU";

    while ((ch = getchar()) != EOF)
    {
        if(strchr(vowel, ch))
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

//
int main()
{
    int ch = 0;
    char vowel[] = "aeiouAEIOU";

    //在%c的前面加上空格，会消化掉前面所有的空白字符，然后读取下一个字符
    while (scanf(" %c", &ch) != EOF)
    {
        if (strchr(vowel, ch))
        {
            printf("Vowel\n");
        }
        else
        {
            printf("Consonant\n");
        }
    }

    return 0;
}

//
int main()
{
    int ch = 0;
    char vowel[] = "aeiouAEIOU";

    //在%c的后面加上'\n'，其实在输入时就会消化掉这个\n字符
    //不会为下次留下空白字符的隐患
    while (scanf("%c\n", &ch) != EOF)
    {
        if (strchr(vowel, ch))
        {
            printf("Vowel\n");
        }
        else
        {
            printf("Consonant\n");
        }
    }

    return 0;
}