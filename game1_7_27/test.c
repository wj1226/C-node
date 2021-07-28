// 三子棋
// test.c - 测试游戏
// game.h - 游戏函数的声明
// game.c - 游戏的实现

#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


// 打印菜单
void menu()
{
	printf("*********************************\n");
	printf("*********    1. play    *********\n");
	printf("*********    0. exit    *********\n");
	printf("*********************************\n");
}

// 三子棋的过程
void game()
{
	char board[ROW][COL]; // 棋盘数组

	// 初始化棋盘 - board的元素都给空格
	InitBoard(board, ROW, COL);

	// 打印棋盘
	DisplayBoard(board, ROW, COL);

	// 下棋
	char ret = 0;
	while (1)
	{
		// 玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL); // 玩家下完一步 打印出来

		// 判断游戏输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') // 不是C继续 出来判断
		{
			break;
		}

		// 电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL); // 打印电脑下完

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);

	return 0;
}