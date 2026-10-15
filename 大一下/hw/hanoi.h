/* 班级 学号 姓名 */
#pragma once

#define DS 32	//32为相邻两个底座/柱子之间的距离
#define BASE_Y 16 //底座的纵坐标
#define POLELEN 12//柱子的高度
#define BASELEN 23//底座的长度
#define SPACE 18//打印图形汉诺后，文字汉诺塔需要下移18个单位
char menu();
void hanoi_basic();
void hanoi_StepRecord();
void hanoi_array_level();
void hanoi_array_level_vertical();
void draw_poles();
void hanoi_draw_plates();
void hanoi_MoveOnePlate();
void hanoi_AutoMove();
void hanoi_game();
/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

