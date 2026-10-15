/*2350222 信12 盛曦*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu()
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)（允许按左箭头键时向下移动）" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)（允许按左箭头键时向下移动）" << endl;
	cout << "3.用箭头键控制上下左右，边界停止（按大写HPKM时不准移动）" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕（按大写HPKM时不准移动）" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止)（按左箭头键不准向下移动）" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界停止)（按左箭头键不准向下移动）" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6] ";
	int choice=_getch();
	while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4'&& choice != '5' && choice != '6')
		choice = _getch();
	cout << choice - 48;
	return choice;
}

void move(char mode,int x,int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int cmd = _getch();
	while (cmd != 'q' && cmd != 'Q')
	{
		if (cmd == '\40')
			showch(hout, x, y, '\40');
		if (mode == '1' || mode == '2')
		{
			switch (cmd)
			{
				case 105:
				case 73:
					if (y != 1)
						gotoxy(hout, x, --y);//up
					else if (mode == '2')
						gotoxy(hout, x, (y += 16));//y=17
					break;
				case 75:
				case 107:
					if (y != 17)
						gotoxy(hout, x, ++y);//down
					else if (mode == '2')
						gotoxy(hout, x, (y -= 16));
					break;
				case 74:
				case 106:
					if (x != 1)
						gotoxy(hout, --x, y);//left
					else if (mode == '2')
						gotoxy(hout, (x += 68), y);//x=69
					break;
				case 76:
				case 108:
					if (x != 69)
						gotoxy(hout, ++x, y);//right
					else if (mode == '2')
						gotoxy(hout, (x -= 68), y);
					break;
				default:
					break;
			}
		}
		else if (mode == '3' || mode == '4')
		{
			switch (cmd)
			{
				case 38:
					if (y != 1)
						gotoxy(hout, x, --y);//up
					else if (mode == '4')
						gotoxy(hout, x, (y += 14));//y=18
					break;
				case 39:
					if (y != 17)
						gotoxy(hout, x, ++y);//down
					else if (mode == '4')
						gotoxy(hout, x, (y -= 14));
					break;
				case 40:
					if (x != 1)
						gotoxy(hout, --x, y);//left
					else if (mode == '4')
						gotoxy(hout, (x += 66), y);
					break;
				case 37:
					if (x != 69)
						gotoxy(hout, ++x, y);//right
					else if (mode == '4')
						gotoxy(hout, (x -= 66), y);
					break;
				default:
					break;
			}
		}
		cmd = _getch();
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	while (1)
	{
		cls(hout);
		int mode = menu();
		if (mode == '0')
			return 0;
		cls(hout);
		init_border(hout);
		int x=35, y=9;
		gotoxy(hout, x, y);

		move(mode, x, y);
		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键返回菜单.";
		while (1)
		{
			int ch = _getch();
			if (ch == '\n' || ch == '\r')
				break;
		}
		continue;
	}

	return 0;
}
