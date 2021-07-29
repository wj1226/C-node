#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// 初始化成空格
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	// 只能打印3*3棋盘
	//int i = 0;
	//for (i = 0; i < row; i++)
	//{
	//	 打印数据
	//	printf(" %c | %c | %c \n", board[i][0], board[i][2], board[i][2]);
	//	 打印分割行
	//	if (i < row - 1) // 只用2行
	//	{
	//		printf("---|---|---\n");
	//	}
	//}

	// 用循环 可以控制 分项打印
	int i = 0;
	for (i = 0; i < row; i++)
	{
		// 打印数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			// 分项打印
			printf(" %c ", board[i][j]); 
			if (j < col - 1) // " %c "比|多一次
				printf("|");
		}
		printf("\n"); // 打完一行" %c | %c | %c "换行打印"---|---|---"
		// 打印分割行
		if (i < row - 1) // 分割行的打印少一次 用判断
		{
			for (j = 0; j < col; j++)
			{
				printf("---"); // ---比|多一次
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n"); // 打完一行分割行换行
	}
}


// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家走：\n");

	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);  // 用户输入2 1 在数组里其实是1 0
		// 让用户在合法范围内输入
		if (x >= 1 && x <= row && y >= 1 && y <= col) // 判断是否在合法范围
		{
			// 判断该坐标是否下过了
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，超出范围\n");
		}
	}
}


// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");

	while (1)
	{
		// 生成随机坐标（主函数里调用srand 头文件stdlib.h time.h）
		x = rand() % row; // row是3  x是0-2范围
		y = rand() % col;
		if (board[x][y] == ' ') // 判断该坐标是否下过了 电脑不用提醒 不用减1 直接循环
		{
			board[x][y] = '#';
			break;
		}
	}
}


// 判断游戏输赢
IsFull(char board[ROW][COL], int row, int col) // 判断平局
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ') // 判断是否有空格
			{
				return 0; // 不满
			}
		}
	}
	return 1; // 棋盘满了 返回1
}

char IsWin(char board[ROW][COL], int row, int col)
{
	// 三行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		// 判断是否相等 且不能是空格 如果相等返回
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	// 三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	// 两条对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	
	// 判断平局（当前面判断没有人赢）
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	// 游戏继续（没有人赢没有平局）
	return 'C';

}