#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int func(int a, int b)
{
    int c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    int n = 0;
    int a = 0;
    while (~scanf("%d %d", &n, &a))
    {
        while (n-- != 0)
        {
            int abilityValue = 0;
            scanf("%d", &abilityValue);
            if (abilityValue <= a)
            {
                a += abilityValue;
            }
            else {
                a += func(a, abilityValue);
            }
            printf("%d\n", a);
        }
    }
    return 0;
}

//int main()
//{
//	int a = 105;
//	int b = 200;
//	int c = a % b; // 24 % 18 = 6
//	while (c != 0) {
//		a = b;
//		b = c;
//		c = a % b;
//	}
//	printf("%d\n", b);
//
//	return 0;
//}