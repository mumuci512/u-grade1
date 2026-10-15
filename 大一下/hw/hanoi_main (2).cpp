/* 信12 2350222 盛曦 */
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1)
	{
		char mode = menu();
		cout << mode;//因为menu中用了无回显的getch(为了不显示除了0-9意外输入的错误字符），这里需要人工回显
		cct_gotoxy(0, 14);
		switch (int(mode))
		{
			case '0':
				return 0;
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '8':
			case '9':
				hanoi123489(mode);
				break;
			case '5':
				cct_cls();
				draw_poles();
				break;
			case '6':
				hanoi_draw_plates();
				break;
			case '7':
				hanoi_MoveOnePlate();
				break;
			default:
				continue;
		}
		if (mode != '1' && mode!='2'&&mode!='3')
		{
			cct_showch(0, 39, ' ', COLOR_BLACK, COLOR_WHITE, 1);
		}
		cout << "按回车继续";
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		char enter = _getch();
		while (enter != '\n' && enter != '\r')
		{
			enter = _getch();
		}
	}
	

	return 0;
}
