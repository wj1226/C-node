#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// Ñî»ÔÈý½Ç
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
			if (j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
			else if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
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


//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct S4));
//	return 0;
//}

//int main(){
//
//	//printf("%d %d", 100 % 3.1, 100 % 3);
//	int i = 0;
//	int s = 1;
//	int m = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		s = s * 2 % 10000;
//	}
//	do
//	{
//		m += s % 10;
//		s = s / 10;
//	} while (s);
//	printf("%d\n", m);
//
//	return 0;
//}
