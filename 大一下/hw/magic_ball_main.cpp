/* 2350222 盛曦 信12 */
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

int main()
{
	while (1)
	{
		cct_setconsoleborder(120, 30, 1000, 1000);
		cct_cls();
		cct_setfontsize("新宋体", 16);
		//cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		char mode = menu();
		cout << mode;//因为menu中用了无回显的getch(为了不显示除了0-9意外输入的错误字符），这里需要人工回显
		Sleep(100);

		if (mode == '0')
			return 0;
		else if (mode >= '1' && mode <= '3')
			menu123(mode);
		else if (mode >= '4' && mode <= '9')
			menu456789(mode);
		input_end();
	}
	return 0;
}