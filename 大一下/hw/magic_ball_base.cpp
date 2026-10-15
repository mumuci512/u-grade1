/* 2350222 盛曦 信12 */
#include <iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

void output_prompt(int x, int y)
{
	int i;
	//第一行
	cout << setw(3) << "|";
	for (i = 0; i < x; i++)
		cout << setw(3) << i + 1;
	cout << endl;
	//第二行
	cout << "--+";
	for (i = 0; i < x; i++)
		cout << setw(3) << setfill('-') << "-";
	cout << setfill(' ') << "-";
	cout << endl;
}

void output_array(struct magic_ball &magic)
{
	int i, j;
	for (i = 0; i <magic.y; i++)
	{
		cout << char('A' + i) << " |";
		for (j = 0; j <magic.x; j++)
		{
			cout << "  ";
			if (magic.ball1[i][j] !=0)
				cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
			cout << magic.ball[i][j];
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		}
		cout << endl;
	}
	cout << endl;
}

void output_init_array(struct magic_ball& magic)
{
	cout << endl << "初始数组" << endl;
	output_prompt(magic.x, magic.y);
	output_array(magic);
}

void output_init_eliminate(struct magic_ball& magic,char mode)
{
	wait_for_enter("按回车键进行寻找初始可消除项的操作...");
	if (TF_eliminate(magic) == 0)
	{
		cout << "初始已无可消除项";
		if (mode == '2')
			cout << "，本小题无法测试，请再次运行";
		cout << endl;
	}
	else
	{
		do
		{
			cout << "初始可消除项（不同色标识）：" << endl;
			output_prompt(magic.x, magic.y);
			output_array(magic);
			if (mode == '1')
				break;
			wait_for_enter("按回车键进行数组下落除0操作...");
			cout << "下落除0后的数组(不同色标识)：" << endl;
			fall(magic);
			output_array(magic);
			FillBlank(magic);
			wait_for_enter("按回车键进行新值填充...");
			cout << "新值填充后的数组(不同色标识)" << endl;
			output_prompt(magic.x, magic.y);
			output_array(magic);
		} while (TF_eliminate(magic) != 0);//循环完一次后，ball内的数组是新值填充过的，没有0
		cout << "初始已无可消除项" << endl;//ball1内全为0
	}
}

void menu123(char mode)
{
	cct_cls();
	struct magic_ball magic;
	init_all(magic.ball, -1);
	init_all(magic.ball1, 0);
	input(&magic.x, &magic.y);
	generate_array(magic);
	output_init_array(magic);
	output_init_eliminate(magic,mode);
	if (mode == '3')
	{
		cout <<endl<< "可选择的消除提示（不同色标识）：" << endl;
		eliminate_middle(magic);
		eliminate_edge(magic);
		output_prompt(magic.x, magic.y);
		output_array(magic);
	}
}

//void eliminate_middle(int ball[XMAX][YMAX], int ball1[XMAX][YMAX], int x, int y, int* count)
//{
//	int i, j;
//	for (i = 0; i < y; i++)
//	{
//		for (j = 0; j < x; j++)
//		{
//			if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < y && ball[i - 1][j] == ball[i + 1][j] && ball[i - 1][j] == ball[i][j - 1])
//			{
//				ball1[i][j] = *count;
//				ball1[i][j - 1] = *count;
//				(*count)++;
//			}
//			if (i - 1 >= 0 && j + 1 < x && i + 1 < y && ball[i - 1][j] == ball[i + 1][j] && ball[i - 1][j] == ball[i][j + 1])
//			{
//				ball1[i][j] = *count;
//				ball1[i][j + 1] = *count;
//				(*count)++;
//			}
//			if (i - 1 >= 0 && j + 1 < x && j - 1 >= 0 && ball[i - 1][j] == ball[i][j + 1] && ball[i - 1][j] == ball[i][j - 1])
//			{
//				ball1[i][j] = *count;
//				ball1[i - 1][j] = *count;
//				(*count)++;
//			}
//			if (i + 1 < y && j + 1 < x && j - 1 >= 0 && ball[i + 1][j] == ball[i][j - 1] && ball[i + 1][j] == ball[i][j + 1])
//			{
//				ball1[i][j] = *count;
//				ball1[i + 1][j] = *count;
//				(*count)++;
//			}
//		}
//	}
//}
//void eliminate_edge(int ball[XMAX][YMAX], int ball1[XMAX][YMAX], int x, int y, int* count)
//{
//	int i, j;
//	for (i = 0; i < y; i++)
//	{
//		for (j = 0; j < x; j++)
//		{
//			if (i + 2 < y && ball[i + 1][j] == ball[i + 2][j])
//			{
//				if (i - 1 >= 0 && ball[i - 1][j] == ball[i + 1][j])
//				{
//					ball1[i][j] = *count;
//					ball1[i - 1][j] = *count;
//					(*count)++;
//				}
//				if (j - 1 >= 0 && ball[i][j - 1] == ball[i + 1][j])
//				{
//					ball1[i][j] = *count;
//					ball1[i][j - 1] = *count;
//					(*count)++;
//				}
//				if (j + 1 < x && ball[i][j + 1] == ball[i + 1][j])
//				{
//					ball1[i][j] = *count;
//					ball1[i][j + 1] = *count;
//					(*count)++;
//				}
//			}
//			if (i - 2 >= 0 && ball[i - 1][j] == ball[i - 2][j])
//			{
//				if (i + 1 < y && ball[i + 1][j] == ball[i - 1][j])
//				{
//					ball1[i][j] = *count;
//					ball1[i + 1][j] = *count;
//					(*count)++;
//				}
//				if (j - 1 >= 0 && ball[i][j - 1] == ball[i - 1][j])
//				{
//					ball1[i][j] = *count;
//					ball1[i][j - 1] = *count;
//					(*count)++;
//				}
//				if (j + 1 < x && ball[i][j + 1] == ball[i - 1][j])
//				{
//					ball1[i][j] = *count;
//					ball1[i][j + 1] = *count;
//					(*count)++;
//				}
//			}
//			if (j + 2 < x && ball[i][j + 1] == ball[i][j + 2])
//			{
//				if (i - 1 >= 0 && ball[i - 1][j] == ball[i][j + 1])
//				{
//					ball1[i][j] = *count;
//					ball1[i - 1][j] = *count;
//					(*count)++;
//				}
//				if (j - 1 >= 0 && ball[i][j - 1] == ball[i][j + 1])
//				{
//					ball1[i][j] = *count;
//					ball1[i][j - 1] = *count;
//					(*count)++;
//				}
//				if (i + 1 < y && ball[i + 1][j] == ball[i][j + 1])
//				{
//					ball1[i][j] = *count;
//					ball1[i + 1][j] = *count;
//					(*count)++;
//				}
//			}
//			if (j - 2 >= 0 && ball[i][j - 1] == ball[i][j - 2])
//			{
//				if (i - 1 >= 0 && ball[i - 1][j] == ball[i][j - 1])
//				{
//					ball1[i][j] = *count;
//					ball1[i - 1][j] = *count;
//					(*count)++;
//				}
//				if (j + 1 >= 0 && ball[i][j + 1] == ball[i][j - 1])
//				{
//					ball1[i][j] = *count;
//					ball1[i][j + 1] = *count;
//					(*count)++;
//				}
//				if (i + 1 < y && ball[i + 1][j] == ball[i][j - 1])
//				{
//					ball1[i][j] = *count;
//					ball1[i + 1][j] = *count;
//					(*count)++;
//				}
//			}
//		}
//	}
//}