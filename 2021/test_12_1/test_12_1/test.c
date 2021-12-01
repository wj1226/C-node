#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int x = 0;
	scanf("%d", &x);
	if (x-- < 5)
		printf("%d", x);
	else
		printf("%d", x++);
	return 0;
}

//int main()
//{
//	int x = 0;
//	int y = 0;
//	int cnt = 0;
//
//	for (x = 0, y = 0; (y = 123) && (x < 4); x++) 
//	{
//		cnt++;
//	}
//
//	printf("%d\n", cnt);
//
//	return 0;
//}
