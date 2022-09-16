#define _CRT_SECURE_NO_WARNINGS 1

//三子棋游戏框架


#include "game.h"

void menu()//菜单函数
{
	printf("**************************\n");
	printf("***  1.play    0.exit  ***\n");
	printf("**************************\n");
}

void game()//游戏函数
{
	char ret = 0;
	char board[ROW][COL] = { 0 };

	Initboard(board, ROW, COL);

	Displayboard(board, ROW, COL);

	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑走
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	//跳出循环后，有三种情况
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}

void test()//框架函数
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择(1/0))>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}