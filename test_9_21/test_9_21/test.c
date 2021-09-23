#define _CRT_SECURE_NO_WARNINGS 1

// 1���޸�Ĭ�϶�����

// ��Ԥ����ָ��#pragma����Ĭ�϶����� ��ȡ�����ã���ԭĬ��
#include <stdio.h>

// �����ŷ� û�пռ��˷� Ч�ʵ�
#pragma pack(1)
struct S1
{
	char c1;
	int i;
	char c2;
};
#pragma pack()

int main()
{
	struct S1 s[] = { 0 };
	printf("%d\n", sizeof(s)); // 6

	return 0;
}


// 2����offsetof������ʱ���Դ����ͣ�
// ����һ���ṹ���Ա����ڽṹ�����ڴ��д洢����ʼλ�õ�ƫ����
// size_t offsetof( structName, memberName );
#include <stdio.h>
#include <stddef.h>

struct S1
{
	char c1;
	int i;
	char c2;
};

int main()
{
	printf("%d\n", offsetof(struct S1, c1)); // 0
	printf("%d\n", offsetof(struct S1, i)); // 4
	printf("%d\n", offsetof(struct S1, c2)); // 8

	return 0;
}


// 3���ṹ�崫��
#include <stdio.h>

struct S
{
	int data[1000];
	int num;
};

// �ṹ�崫��
void print1(struct S tmp)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", tmp.data[i]);
	}
	printf("\nnum = %d\n", tmp.num);
}

// �ṹ���ַ����
void print2(struct S* ps)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\nnum = %d\n", ps->num);
}

int main()
{
	struct S s = { {1,2,3,4,5,6,7,8,9,10}, 100 };
	
	print1(s); // ���ṹ��
	print2(&s); // ����ַ

	return 0;
}
/* �������ε�ʱ�򣬲�������Ҫѹջ������ʱ��Ϳռ��ϵ�ϵͳ������
�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ�ĵ�ϵͳ�����Ƚϴ����Իᵼ�����ܵ��½��� */


// ����λ��
// �ṹ�彲��͵ý����ṹ��ʵ�� λ�� ��������

// λ���ǿ��Խ�ʡ�ռ��
// λ�� - ������λ
#include <stdio.h>

struct A
{
	int _a : 2; // _a - 2��bitΪλ
	int _b : 5; // _b - 5��bitΪλ
	int _c : 10; 
	int _d : 30;
};

int main()
{
	printf("%d\n", sizeof(struct A)); // 8
	return 0;
}


// λ�ε��ڴ����
/* 1. λ�εĳ�Ա������ int unsigned int signed int ������ char ���������μ��壩����
2. λ�εĿռ����ǰ�����Ҫ��4���ֽڣ� int ������1���ֽڣ� char ���ķ�ʽ�����ٵġ�
3. λ���漰�ܶ಻ȷ�����أ�λ���ǲ���ƽ̨�ģ�ע�ؿ���ֲ�ĳ���Ӧ�ñ���ʹ��λ�Ρ� */

//һ������
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

int main()
{
	struct S s = { 0 };
	s.a = 10; // 1010 - 010
	s.b = 12; // 00001100 - 1100
	s.c = 3; // 00000011 - 00011
	s.d = 4; // 00000100 - 0100
}
//�ռ�����ο��ٵģ�

// �Ʋ⣺
// char-> �ȿ���1�ֽ� 00000000
// a-3bit    010
// b-4bit    1100
// ʣ�µĿռ䲻���� �ٿ���1�ֽ�
// c-5bit    00011
// ʣ�µĿռ䲻���� �ٿ���1�ֽ�
// d-4bit    0100
// ��<-��   ��
// 0(1100)(010)  000(00011)  0000(0100)
// 62 03 04


// λ�εĿ�ƽ̨����
/* 1. int λ�α������з����������޷������ǲ�ȷ���ġ�
2. λ�������λ����Ŀ����ȷ������16λ�������16��32λ�������32��д��27����16λ����������⡣
3. λ���еĳ�Ա���ڴ��д������ҷ��䣬���Ǵ�����������׼��δ���塣
4. ��һ���ṹ��������λ�Σ��ڶ���λ�γ�Ա�Ƚϴ��޷������ڵ�һ��λ��ʣ���λʱ��������ʣ���λ�������ã����ǲ�ȷ���ġ� */

// �ܽ᣺
// ���ṹ��ȣ�λ�ο��Դﵽͬ����Ч�������ǿ��ԺܺõĽ�ʡ�ռ䣬�����п�ƽ̨��������ڡ�



// ����ö��
#include <stdio.h>
// enum Colorö�����͡�{}�е�������ö�����͵Ŀ���ȡֵ��Ҳ�� ö�ٳ���
enum Color
{
	RED = 2, // ����ֵ
	GREEN,
	BLUE,
};

int main()
{
	enum  Color c = GREEN; // ö�����͸�����ȡֵ

	if (c == GREEN)
	{
		printf("��ɫ\n");
	}

	return 0;
}


// ö�ٵ��ŵ�
/* ���ǿ���ʹ�� #define ���峣����Ϊʲô��Ҫʹ��ö��
1. ���Ӵ���Ŀɶ��ԺͿ�ά����
2. ��#define����ı�ʶ���Ƚ�ö�������ͼ�飬�����Ͻ���
3. ��ֹ��������Ⱦ����װ��
4. ���ڵ���
5. ʹ�÷��㣬һ�ο��Զ���������*/

// �� ʵ�ּ�������������
enum Option
{
	EXIT, // 0
	ADD, // 1
	SUB,
	MUL,
	DIV,
};

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>\n");
		switch (input)
		{
		case ADD:
			break;
		case SUB:
			break;
		case MUL:
			break;
		case DIV:
			break;
		case EXIT:
			break;
		}
	} while (input);
	
	return 0;
}


// �����壨�����壩
// �������͵Ķ���
// ����Ҳ��һ��������Զ������� �������Ͷ���ı���Ҳ����һϵ�еĳ�Ա����������Щ��Ա����ͬһ��ռ䣨��������Ҳ�й����壩
#include <stdio.h>

//�������͵�����
union Un
{
	char c;
	int i;
};

int main()
{
	//���ϱ����Ķ���
	union Un u = { 0 };

	// ��ַһ��
	printf("%p\n", &u);
	printf("%p\n", &(u.c));
	printf("%p\n", &(u.i));

	return 0;
}

// ���ϵ��ص�
// ���ϵĳ�Ա�ǹ���ͬһ���ڴ�ռ�ģ�����һ�����ϱ����Ĵ�С������������Ա�Ĵ�С����Ϊ�������ٵ����������������Ǹ���Ա��


// �жϵ�ǰ������Ĵ�С�˴洢
#include <stdio.h>

// 1
int main()
{
	int a = 1;//0x 00 00 00 01
	//��---------------------> ��
	//01 00 00 00 - С�˴洢
	//00 00 00 01 - ��˴洢

	char* pc = (char*)&a;
	if (*pc == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}

// 2
int check_sys()
{
	union U
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}

int main()
{
	if (check_sys() == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	return 0;
}


// ���ϴ�С�ļ���
/* ���ϵĴ�С����������Ա�Ĵ�С��
������Ա��С����������������������ʱ�򣬾�Ҫ���뵽������������������ */

//�����������´�����
union Un1
{
	char c[5]; // 5    1
	int i; // 4  8     4 
	// ��������ܴ�С������4�ı��� ��c���˷�3���ֽ� �����8
};
union Un2
{
	short c[7]; // 14    2
	int i; // 4  8       4
	// 14����4�ı��� �����16
};

int main()
{
	printf("%d\n", sizeof(union Un1)); // 8
	printf("%d\n", sizeof(union Un2)); // 16
}


// ͨѶ¼����