#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//int main()
//{
//	double a = 0;
//	double b = 0;
//	double c = 0;
//	while (~(scanf("%d %d %d", &a, &b, &c)))
//	{
//		if (a == 0) 
//		{
//			printf("Not quadratic equation\n");
//		}
//		else
//		{
//			double dis = pow(b, 2) - 4.0 * a * c;
//			if (dis == 0.0)
//			{
//				printf("x1=x2=%.2lf\n", (-b) / 2 * a);
//			}
//			else if (dis > 0.0)
//			{
//				printf("x1=%.2lf;x2=%.2lf\n", (-b - sqrt(dis)) / 2 * a, (-b + sqrt(dis)) / 2 * a);
//			}
//			else
//			{
//				double real = (-b) / 2 * a;
//				double image = sqrt(-dis) / (2 * a);
//				printf("x1=%.2lf-%.2lf;x2=%.2lf-%.2lf\n", real, image, real, image);
//			}
//		}
//	}
//
//	return 0;
//}
// printf("x1=%.2lf;x2=%.2lf\n", 1, 1);


//int main()
//{
//	/*int a = 0;
//	int b = 0;
//	a = (a=2, b = 5, b++, a + b);
//	printf("%d %d", a, b);*/
//
//	int a = 1;
//	//a = a + 4, a + 5;
//	//printf("a = %d\n", a);
//
//	printf("%d\n", (a=a+4,a+5));
//	//printf("%d\n", ((a=a+4,a+5), a+6));
//
//	return 0;
//}


//#include <stdio.h>
//
//void input(int* arr, int n) {
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//}
//
//void sort(int* arr, int n) {
//	int i = 0;
//	for (i = 0; i < n - 1; i++) {
//		int j = 0;
//		for (j = 0; j < n - 1 - i; j++) 
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void output(int* arr, int n) 
//{
//	int i = 0;
//	printf("输出成绩：\n");
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//double average(int* arr, int n)
//{
//	int i = 0;
//	double sum = 0.0;
//	for(i=0; i<n; i++)
//	{
//		sum += arr[i];
//	}
//	return sum / n;
//}
//
//int main()
//{
//	int n = 30;
//	int arr[30] = { 0 };
//	input(arr, n);
//	sort(arr, n);
//	output(arr, n);
//	double avg = average(arr, n);
//	printf("平均成绩：%.2lf\n", avg);
//}

//int main()
//{
//	int i = 2;
//	int j = 0;
//	//int k = 0;
//	j = (i++) + (i++) + (i++);
//	printf("%d %d\n", j, i);
//
//	return 0;
//}
