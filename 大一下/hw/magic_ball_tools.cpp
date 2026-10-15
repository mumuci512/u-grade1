/* 2350222 盛曦 信12 */
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

void input(int* x, int* y)
{
	while (1)
	{
		cout << "请输入行数(5-9)" << endl;
		cin >> *y;
		if (*y >= YMIN && *y <= YMAX && cin.good() == 1)
			break;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1410065407, '\n');
		}
	}
	while (1)
	{
		cout << "请输入列数(5-9)" << endl;
		cin >> *x;
		if (*x >= XMIN && *x <= XMAX && cin.good() == 1)
			break;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1410065407, '\n');
		}
	}
	getchar();//吸收input的回车
}

void init_all(int array[XMAX][YMAX], int fill)
{
	int i, j;
	for (i = 0; i < XMAX; i++)
	{
		for (j = 0; j < YMAX; j++)
		{
			array[i][j] = fill;//全部初始化为-1
		}
	}
}

void exchange(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void print_bottom(int y, int line_parm,const char prompt[100],int x)
{
	cct_showch(x, y * line_parm + 3 - (line_parm - 1), ' ', COLOR_BLACK, COLOR_WHITE, 50);//覆盖上一次的prompt
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_gotoxy(x, y * line_parm + 3 - (line_parm - 1));
	cout << prompt;
}
void wait_for_enter(const char prompt[100],int y,int line_parm, int bottom)
{
	if (bottom != 0)
		print_bottom(y, line_parm,prompt);
	else
		cout << prompt;
	char enter = _getch();
	while (enter != '\n' && enter != '\r')
	{
		enter = _getch();
	}
}

int TF_eliminate(struct magic_ball& magic)//判断并记录可消除项
{
	int i, j, m;
	int flag = 0;//记录是否有可消除项
	init_all(magic.ball1, 0);
	for (i = 0; i < magic.y; i++)
	{
		for (j = 0; j < magic.x; j++)
		{
			for (m = -2; m <= 0; m++)
			{
				if (j + m >= 0 && j + m < magic.x - 2 && magic.ball[i][j + m] == magic.ball[i][j + m + 1] && magic.ball[i][j + m] == magic.ball[i][j + m + 2])
				{
					magic.ball1[i][j] = 1;
					flag = 1;
				}
				if (i + m >= 0 && i + m < magic.y - 2 && magic.ball[i + m][j] == magic.ball[i + m + 1][j] && magic.ball[i + m][j] == magic.ball[i + m + 2][j])
				{
					magic.ball1[i][j] = 1;
					flag = 1;
				}
			}
		}
	}
	return flag;
}

void fall(struct magic_ball& magic,char mode)//下落除0
{
	int i, j, k;
	int graph = (mode == '0' ? 0 : 1);//graph缺省为0，不绘制伪图形
	for (j = 0; j < magic.x; j++)
	{
		for (i = 0; i < magic.y; i++)
		{
			if (magic.ball1[i][j] == 1)
			{
				magic.ball[i][j] = 0;
			}
		}
		int flag = 0;//flag为1，表示当前位置的下方有0，即当前位置需要下落
		for (i = magic.y - 1; i >= 0; i--)
		{
			if (flag == 1 && magic.ball[i][j] != 0 && magic.ball[i + 1][j] == 0)//当前不为0，当前位置的下方一个为0，这时候才需要下落；因为刚进循环的时候flag为0，不可能进这个if，所以横坐标i+1不会越界
			{
				for (k = i; k + 1 < magic.y && magic.ball[k + 1][j] == 0; k++)
				{
					exchange(&magic.ball[k][j], &magic.ball[k + 1][j]);
					exchange(&magic.ball1[k][j], &magic.ball1[k + 1][j]);
					if (graph != 0)
					{
						int line_parm =2;
						cct_showch(2 + j * 2 * line_parm, 2 + k * line_parm, ' ', COLOR_HWHITE, COLOR_HWHITE, 2);
						cct_showstr(2 + j * 2 * line_parm, 2 + (k + 1) * line_parm-1, "〇", magic.ball[k + 1][j], COLOR_BLACK, 1);
						Sleep(20);//一个球掉下半个格子，停顿
						cct_showstr(2 + j * 2 * line_parm, 2 + k * line_parm+1, "═", COLOR_HWHITE, COLOR_BLACK,1 );
						cct_showstr(2 + j * 2 * line_parm, 2 + (k+1) * line_parm, "〇", magic.ball[k+1][j], COLOR_BLACK, 1);
						Sleep(20);//一个球掉下一个格子，停顿
					}
				}
				Sleep(40);//一个球的掉落过程完毕，停顿
			}
			if (magic.ball[i][j] == 0)
			{
				flag = 1;
			}
		}
	}
}
/*原本的fall用了冒泡，不适合graph*/
//for (j = 0; j < x; j++)
//{
//	for (i = 0; i < y; i++)
//	{
//		if (ball1[i][j] == 1)
//		{
//			ball[i][j] = 0;
//		}
//	}
//	for (i = 0; i < y - 1; i++)
//	{
//		for (k = 1; k < y - i; k++)
//		{
//			if (ball[k][j] == 0 && ball[k - 1][j] != 0)
//			{
//				exchange(&ball[k][j], &ball[k - 1][j]);
//				exchange(&ball1[k][j], &ball1[k - 1][j]);
//			}
//		}
//	}
//}

void FillBlank(struct magic_ball& magic,char mode)
{
	int i, j;
	int graph = (mode == '0' ? 0 : 1);//graph缺省为0，不绘制伪图形
	srand((unsigned int)(time(0)));
	for (i = 0; i < magic.y; i++)
	{
		for (j = 0; j < magic.x; j++)
		{
			if (magic.ball[i][j] == 0)
			{
				magic.ball[i][j] = rand() % 8 + 1;
				if (graph != 0)
				{
					int line_parm = (mode == '4' || mode == '6' ? 1 : 2);
					cct_showstr(2 + j * 2 * line_parm, 2 + i * line_parm, "〇", magic.ball[i][j], COLOR_BLACK, 1);
					Sleep(50);
				}
			}
		}
	}
}

void eliminate_middle(struct magic_ball& magic)
{
	int i, j;
	for (i = 0; i < magic.y; i++)
	{
		for (j = 0; j < magic.x; j++)
		{
			if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < magic.y && magic.ball[i - 1][j] == magic.ball[i + 1][j] && magic.ball[i - 1][j] == magic.ball[i][j - 1])
			{
				magic.ball1[i][j] = 2;
				magic.ball1[i][j - 1] = 2;
			}
			if (i - 1 >= 0 && j + 1 < magic.x && i + 1 < magic.y && magic.ball[i - 1][j] == magic.ball[i + 1][j] && magic.ball[i - 1][j] == magic.ball[i][j + 1])
			{
				magic.ball1[i][j] = 2;
				magic.ball1[i][j + 1] = 2;
			}
			if (i - 1 >= 0 && j + 1 < magic.x && j - 1 >= 0 && magic.ball[i - 1][j] == magic.ball[i][j + 1] && magic.ball[i - 1][j] == magic.ball[i][j - 1])
			{
				magic.ball1[i][j] = 2;
				magic.ball1[i - 1][j] = 2;
			}
			if (i + 1 < magic.y && j + 1 < magic.x && j - 1 >= 0 && magic.ball[i + 1][j] == magic.ball[i][j - 1] && magic.ball[i + 1][j] == magic.ball[i][j + 1])
			{
				magic.ball1[i][j] = 2;
				magic.ball1[i + 1][j] = 2;
			}
		}
	}

}
void eliminate_edge(struct magic_ball& magic)
{
	int i, j;
	for (i = 0; i < magic.y; i++){
		for (j = 0; j < magic.x; j++){
			if (i + 2 < magic.y && magic.ball[i + 1][j] == magic.ball[i + 2][j]){
				if (i - 1 >= 0 && magic.ball[i - 1][j] == magic.ball[i + 1][j]){
					magic.ball1[i][j] = 2;
					magic.ball1[i - 1][j] = 2;
				}
				if (j - 1 >= 0 && magic.ball[i][j - 1] == magic.ball[i + 1][j]){
					magic.ball1[i][j] = 2;
					magic.ball1[i][j - 1] = 2;
				}
				if (j + 1 < magic.x && magic.ball[i][j + 1] == magic.ball[i + 1][j]){
					magic.ball1[i][j] = 2;
					magic.ball1[i][j + 1] = 2;
				}
			}
			if (i - 2 >= 0 && magic.ball[i - 1][j] == magic.ball[i - 2][j]){
				if (i + 1 < magic.y && magic.ball[i + 1][j] == magic.ball[i - 1][j]){
					magic.ball1[i][j] = 2;
					magic.ball1[i + 1][j] = 2;
				}
				if (j - 1 >= 0 && magic.ball[i][j - 1] == magic.ball[i - 1][j]){
					magic.ball1[i][j] = 2;
					magic.ball1[i][j - 1] = 2;
				}
				if (j + 1 < magic.x && magic.ball[i][j + 1] == magic.ball[i - 1][j]){
					magic.ball1[i][j] = 2;
					magic.ball1[i][j + 1] = 2;
				}
			}
			if (j + 2 < magic.x && magic.ball[i][j + 1] == magic.ball[i][j + 2]){
				if (i - 1 >= 0 && magic.ball[i - 1][j] == magic.ball[i][j + 1]){
					magic.ball1[i][j] = 2;
					magic.ball1[i - 1][j] = 2;
				}
				if (j - 1 >= 0 && magic.ball[i][j - 1] == magic.ball[i][j + 1]){
					magic.ball1[i][j] = 2;
					magic.ball1[i][j - 1] = 2;
				}
				if (i + 1 < magic.y && magic.ball[i + 1][j] == magic.ball[i][j + 1]){
					magic.ball1[i][j] = 2;
					magic.ball1[i + 1][j] = 2;
				}
			}
			if (j - 2 >= 0 && magic.ball[i][j - 1] == magic.ball[i][j - 2]){
				if (i - 1 >= 0 && magic.ball[i - 1][j] == magic.ball[i][j - 1]){
					magic.ball1[i][j] = 2;
					magic.ball1[i - 1][j] = 2;
				}
				if (j + 1 >= 0 && magic.ball[i][j + 1] == magic.ball[i][j - 1]){
					magic.ball1[i][j] = 2;
					magic.ball1[i][j + 1] = 2;
				}
				if (i + 1 < magic.y && magic.ball[i + 1][j] == magic.ball[i][j - 1]){
					magic.ball1[i][j] = 2;
					magic.ball1[i + 1][j] = 2;
				}
			}
		}
	}
}

void generate_array(struct magic_ball& magic)
{
	srand((unsigned int)(time(0)));
	int i, j;
	for (i = 0; i < magic.y; i++)
	{
		for (j = 0; j < magic.x; j++)
		{
			magic.ball[i][j] = rand() % 8 + 1;//生成1-9
		}
	}
}

int TF_eliminateKey(int ball1[XMAX][YMAX])//是否有可消除提示项
{
	int i, j;
	int flag=0;
	for (i = 0; i < XMAX ; i++)
	{
		for (j = 0; j < YMAX; j++)
		{
			if (ball1[i][j] == 2)
				flag = 1;
		}
	}
	return flag;
}

void input_end()
{
	cout << "本小题结束，请输入End继续...";
	int X, Y,i;
	cct_getxy(X, Y);
	char end[4];
	while (1)
	{
		cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 20);//覆盖上一次输入的
		cct_gotoxy(X, Y);
		for (i = 0; i <4; i++)
		{
			end[i] = '\0';
		}
		for (i = 0; i <4; i++)
		{
			end[i] = _getche();
			if (end[i] == '\n' || end[i] == '\r')
			{
				break;
			}
		}
		if (i == 4)//说明没有读到回车,输入的超过了3个
		{
			continue;
		}
		/*cin.getline(end, 3, '\n');
		if (end[3] != '\n'&&end[3]!='\r')
			continue;*/
		/*fgets(end, 3, stdin);*/
		if (!((end[0] == 'E' || end[0] == 'e') && (end[1] == 'N' || end[1] == 'n') && (end[2] == 'D' || end[2] == 'd')))
		{
			cout << endl << "输入错误，请重新输入";
			continue;
		}
		else
			break;
	}
}
