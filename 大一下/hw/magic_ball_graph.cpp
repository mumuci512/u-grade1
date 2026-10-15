/* 2350222 盛曦 信12 */
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

void graph_prepare_end(int flag, int line_parm, int y)//flag为1，表示prepare，flag为2，表示end
{
	if (flag == 1)
	{
		cct_setconsoleborder(COLMAX, LINEMIN + y * line_parm - (line_parm - 1), 1000, 1000);
		cct_cls();
		cct_setfontsize("新宋体", 52 - (y - YMIN) * 4 - (line_parm - 1) * 4);
	}
	else
	{
		cct_showch(0, y * line_parm + 3 - (line_parm - 1), ' ', COLOR_BLACK, COLOR_WHITE, 50);//覆盖上一次的prompt
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_gotoxy(0, y * line_parm + 3 - (line_parm - 1));
	}
}

void print_frame_line(const char srt[3], const char end[3], int x, int y, char mode)//x表示这一行的宽度，y表示这一行所在的行数
{
	int line_parm = (mode == '4' || mode == '6' ? 1 : 2);
	cct_showstr(0, y, srt, COLOR_HWHITE, COLOR_BLACK, 1);
	if (line_parm == 1)
	{
		cct_showstr(2, y, "═", COLOR_HWHITE, COLOR_BLACK, x);
	}
	else
	{
		if (y == 1)
			cct_showstr(2, y, "═╦", COLOR_HWHITE, COLOR_BLACK, x - 1);
		else
			cct_showstr(2, y, "═╩", COLOR_HWHITE, COLOR_BLACK, x - 1);
		cct_showstr(2 * line_parm * x - (line_parm - 1) * 2, y, "═", COLOR_HWHITE, COLOR_BLACK, 1);
	}
	cct_showstr(2 + 2 * line_parm * x - (line_parm - 1) * 2, y, end, COLOR_HWHITE, COLOR_BLACK, 1);
	if (mode == '4' || mode == '5')
		Sleep(20);//打完一行停顿
}
void print_frame_col(int x, int y, char mode)//x表示这一行所在的列数，y表示这一行的高度
{
	int line_parm = (mode == '4' || mode == '6' ? 1 : 2);
	int i, j;
	for (i = 0; i < y * line_parm - (line_parm - 1); i++)
	{
		if (line_parm == 2)
		{
			if (i % 2 == 0)
			{
				cct_showstr(0, 2 + i, "║", COLOR_HWHITE, COLOR_BLACK, 1);//该行第一个
				for (j = 2; j <= 2 + (x - 1) * 4; j += 4)
				{
					cct_showch(j, 2 + i, ' ', COLOR_HWHITE, COLOR_HWHITE, 2);
					if (j != 2 + (x - 1) * 4)
						cct_showstr(j + 2, 2 + i, "║", COLOR_HWHITE, COLOR_BLACK, 1);
					else
						cct_showstr(j + 2, 2 + i, "║", COLOR_HWHITE, COLOR_BLACK, 1);//该行最后一个
				}
			}
			else
			{
				cct_showstr(0, 2 + i, "╠", COLOR_HWHITE, COLOR_BLACK, 1);//该行第一个
				for (j = 2; j <= 2 + (x - 1) * 4; j += 4)
				{
					cct_showstr(j, 2 + i, "═", COLOR_HWHITE, COLOR_BLACK, 1);
					if (j != 2 + (x - 1) * 4)
						cct_showstr(j + 2, 2 + i, "╬", COLOR_HWHITE, COLOR_BLACK, 1);
					else
						cct_showstr(j + 2, 2 + i, "╣", COLOR_HWHITE, COLOR_BLACK, 1);//该行最后一个
				}

			}
		}
		else
		{
			cct_showstr(0, 2 + i, "║", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(2 * x + 2, 2 + i, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		if (mode == '4' || mode == '5')
			Sleep(20);//打完一行停顿
	}
}

void print_current_select(int y, int line_parm, struct location& loc)
{
	print_bottom(y, line_parm, "当前选择");
	print_bottom(y, line_parm, "", 11);
	cout << char('A' + loc.i) << "行" << 1 + loc.j << "列";
	Sleep(250);
}

void print_one_ball(const char circle[3], int ball[XMAX][YMAX], struct location loc, int line_parm, int fgcolor = COLOR_BLACK)
{
	cct_showstr(2 + loc.j * 2 * line_parm, 2 + loc.i * line_parm, circle, ball[loc.i][loc.j], fgcolor, 1);
}

void print_ball(struct magic_ball& magic, char mode)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int line_parm = (mode == '4' || mode == '6' ? 1 : 2);
	struct location loc;
	for (loc.i = 0; loc.i < magic.y; loc.i++)
	{
		for (loc.j = 0; loc.j < magic.x; loc.j++)
		{
			if (magic.ball1[loc.i][loc.j] == 1)//可消除
				print_one_ball("●", magic.ball, loc, line_parm);
			else if (magic.ball1[loc.i][loc.j] == 0)//普通
				print_one_ball("〇", magic.ball, loc, line_parm);
			else if (magic.ball1[loc.i][loc.j] == 2)//消除提示
				print_one_ball("◎", magic.ball, loc, line_parm);
			if (mode == '4' || mode == '5')
				Sleep(20);//打完一行停顿
		}
	}
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

void print_window()
{
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
	cct_gotoxy(0, 0);
	cout << "屏幕：" << lines << "行" << cols << "列";
}

void print_graph(struct magic_ball& magic, char mode)
{
	int line_parm = (mode == '4' || mode == '6' ? 1 : 2);
	cct_setcursor(CURSOR_INVISIBLE);
	print_frame_line("╔", "╗", magic.x, 1, mode);
	print_frame_col(magic.x, magic.y, mode);
	print_frame_line("╚", "╝", magic.x, magic.y * line_parm + 2 - (line_parm - 1), mode);
	print_ball(magic, mode);
	print_window();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

void eliminate_graph(struct magic_ball& magic, char mode, int& score, int TF_add_score)
{
	int line_parm = (mode == '4' || mode == '6' ? 1 : 2);
	int k;
	struct location loc;
	cct_setcursor(CURSOR_INVISIBLE);
	for (loc.i = 0; loc.i < magic.y; loc.i++)
	{
		for (loc.j = 0; loc.j < magic.x; loc.j++)
		{
			if (magic.ball1[loc.i][loc.j] == 1)
			{
				if (TF_add_score)
					score++;
				for (k = 0; k < 7; k++)
				{
					print_one_ball("〇", magic.ball, loc, line_parm);
					Sleep(30);
					print_one_ball("¤", magic.ball, loc, line_parm);
					Sleep(30);
				}
				cct_showch(2 + loc.j * 2 * line_parm, 2 + loc.i * line_parm, ' ', COLOR_HWHITE, COLOR_HWHITE, 2);
				Sleep(50);
			}

		}
	}
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

int TF_pos_legal(int X, int Y, struct magic_ball& magic, int line_parm)//判断左键单击位置是否合法
{
	print_bottom(magic.y, line_parm, "[当前光标] ");
	int i = Y / 2 - 1;
	int j = X / 4;
	if (Y % 2 == 0 && Y!=0&&i < magic.y && (X % 4 == 2 || X % 4 == 3) && j < magic.x)
	{
		print_bottom(magic.y, line_parm, "", 11);
		cout << char('A' + i) << "行" << 1 + j << "列";
		return 1;
	}
	else
	{
		cout << "位置非法";
		return 0;
	}
}

void EliminateKey_and_draw(struct magic_ball& magic, char mode)
{
	eliminate_middle(magic);
	eliminate_edge(magic);
	print_ball(magic, mode);
}

int pre_oneball(struct location& preloc, struct location& loc, struct magic_ball& magic, int line_parm, char mode)//上一次有选中一个ball
{
	if (loc.i == preloc.i && loc.j == preloc.j)//和上次选中的一样
	{
		print_one_ball("◎", magic.ball, loc, line_parm);
		preloc.i = -1;
		preloc.j = -1;
	}
	else//和上次选中不一样
	{
		if (fabs(preloc.i - loc.i) == 1 && fabs(preloc.j - loc.j) == 0 || fabs(preloc.i - loc.i) == 0 && fabs(preloc.j - loc.j) == 1)//相邻
		{
			exchange(&magic.ball[loc.i][loc.j], &magic.ball[preloc.i][preloc.j]);
			if (TF_eliminate(magic) == 0)
			{
				exchange(&magic.ball[loc.i][loc.j], &magic.ball[preloc.i][preloc.j]);
				EliminateKey_and_draw(magic, mode);//每次交换ball中元素后，都应该调用一下，保证ball1中的元素不要错位
				print_one_ball("◎", magic.ball, loc, line_parm, COLOR_HWHITE);
				print_one_ball("◎", magic.ball, preloc, line_parm);
				print_bottom(magic.y, line_parm, "不能交换");
				cout << char('A' + loc.i) << "行" << 1 + loc.j << "列" << "<=>" << char('A' + preloc.i) << "行" << 1 + preloc.j << "列";
				Sleep(250);
				preloc.i = loc.i;
				preloc.j = loc.j;
			}
			else//可以消除
			{
				print_current_select(magic.y, line_parm, loc);
				preloc.i = -1;
				preloc.j = -1;
				return 1;
			}
		}
		else//选中的和上次不相邻
		{
			print_one_ball("◎", magic.ball, loc, line_parm, COLOR_HWHITE);
			print_one_ball("◎", magic.ball, preloc, line_parm);
			print_current_select(magic.y, line_parm, loc);
			preloc.i = loc.i;
			preloc.j = loc.j;
		}
	}
	return 0;
}

void cursor_cmd(struct magic_ball& magic, int line_parm, char mode, struct location& preloc, int& end)
{
	cct_enable_mouse();
	int X = 0, Y = 0;
	int maction, keycode1, keycode2;
	while (1) {
		if (cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2) == CCT_MOUSE_EVENT) {
			int flag_pos = TF_pos_legal(X, Y, magic, line_parm);//记录位置是否合法,1表示合法
			struct location loc;
			loc.i = Y / 2 - 1;
			loc.j = X / 4;
			if (flag_pos == 1) {//合法位置
				if (maction == MOUSE_LEFT_BUTTON_CLICK) {//左键
					if (magic.ball1[loc.i][loc.j] != 2)
					{
						print_bottom(magic.y, line_parm, "不能选择");
						print_bottom(magic.y, line_parm, "", 11);
						cout << char('A' + loc.i) << "行" << 1 + loc.j << "列";
						Sleep(250);
						continue;
					}
					else {
						if (mode == '9') {
							if (preloc.i != -1){//上一次有选择一个ball
								if (pre_oneball(preloc, loc, magic, line_parm, mode))
									break;
							}
							else {//上次没有选中一个ball
								print_one_ball("◎", magic.ball, loc, line_parm, COLOR_HWHITE);
								print_current_select(magic.y, line_parm, loc);
								preloc.i = loc.i;
								preloc.j = loc.j;
							}
						}
						if (mode == '8') {
							print_current_select(magic.y, line_parm, loc);
							Sleep(250);
							break;
						}
					}
				}
				else if (maction == MOUSE_RIGHT_BUTTON_CLICK) {//右键
					Sleep(100);//不加这个右键就会有弹窗
					end = 1;
					break;
				}//其余键（双击等）不管
			}
		}//键盘操作不管
	}//end of while(1)
	cct_enable_mouse();//不加这个右键就会有弹窗
	cct_disable_mouse();
}

void eliminate_and_fill(struct magic_ball& magic, char mode, int& score, int TF_add_score, int line_parm)
{
	while (TF_eliminate(magic) != 0)//下落除0，新值填充
	{
		print_ball(magic, mode);
		if (mode == '7')
			wait_for_enter("按回车键进行消除及下落除0操作...", magic.y, line_parm, 1);
		eliminate_graph(magic, mode, score, TF_add_score);
		fall(magic, mode);
		if (mode == '7')
			wait_for_enter("按回车键进行新值填充...", magic.y, line_parm, 1);
		FillBlank(magic, mode);
	}
}

void game_mode(struct magic_ball& magic, char mode, int line_parm)
{
	int score = 0;
	int TF_add_score = 0;//用于记录当前是否为初始消除，若为初始消除则不加score
	while (1)
	{
		int end = 0;//用于记录右键退出
		eliminate_and_fill(magic, mode, score, TF_add_score, line_parm);
		if (mode >= '8')
		{
			cct_showstr(15, 0, "(当前分数:", COLOR_BLACK, COLOR_WHITE, 1);
			cout << score << " 右键退出)";
			TF_add_score = 1;
		}
		struct location preloc;
		preloc.i = -1;
		preloc.j = -1;//用于记录上一次选中的ball，初始为-1表示没有选中，因此放在下落除0后初始化
		if (mode == '7')
			wait_for_enter("按回车键显示消除提示...", magic.y, line_parm, 1);
		EliminateKey_and_draw(magic, mode);//消除提示，画新球
		if (mode == '9' && TF_eliminateKey(magic.ball1) == 0)
		{
			cct_showstr(15, 0, "(无可消除项，游戏结束！)", COLOR_BLACK, COLOR_WHITE, 1);
			break;
		}
		if (mode >= '8')
		{
			cct_setcursor(CURSOR_INVISIBLE);
			cursor_cmd(magic, line_parm, mode, preloc, end);
			if (mode == '9' && TF_eliminate(magic) == 1)
				continue;
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
		}//end of if(mode>='8')
		if (mode != '9' || mode == '9' && end == 1)
			break;
	}//end of while(1)
}

void menu456789(char mode)
{
	int line_parm = (mode == '4' || mode == '6' ? 1 : 2);
	cct_cls();
	struct magic_ball magic;
	init_all(magic.ball, -1);
	init_all(magic.ball1, 0);
	input(&magic.x, &magic.y);
	generate_array(magic);
	if (mode == '4' || mode == '5')
	{
		output_init_array(magic);
		wait_for_enter("按回车键显示图形...");
	}
	graph_prepare_end(1, line_parm, magic.y);//1代表prepare
	if (mode > '5' && mode < '8')
	{
		if (TF_eliminate(magic) == 0)
			cct_showstr(15, 0, "(未找到初始可消除项)", COLOR_BLACK, COLOR_WHITE, 1);
	}
	print_graph(magic, mode);
	if (mode > '6')
		game_mode(magic, mode, line_parm);
	graph_prepare_end(2, line_parm, magic.y);//2代表end
}
