/* 信12 2350222 盛曦 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
int num = 0;//步数记录
int top[3] = { 0 }, plate[3][11] = { 0 };
int delay;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
//基本
void input(char *src, char *dst, char *tmp, int *n,char mode)
{
    int i, j;
    //以防上一次游戏对下一次产生影响，必须先对全局变量置零
    for (i = 0; i < 3; i++)
    {
        top[i] = 0;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 11; j++)
        {
            plate[i][j] = 0;
        }
    }
    num = 0;

    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (*n >= 1 && *n <= 10 && cin.good() == 1)
            break;
    }

    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> *src;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (*src > 90)
            *src = char(*src - 32);
        if ((*src == 'A' || *src == 'B' || *src == 'C') && cin.good() == 1)
            break;
    }

    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> *dst;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (*dst > 90)
            *dst = char(*dst - 32);
        if ((*dst == 'A' || *dst == 'B' || *dst == 'C') && *dst != *src && cin.good() == 1)
            break;
        else if (*dst == *src)
            cout << "目标柱(" << *src << ")不能与起始柱(" << *dst << ")相同" << endl;
    }

    *tmp = 'A' + 'B' + 'C' - *src - *dst;

    if (mode == '4'|| mode=='8')
    {
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
            cin >> delay;
            if (delay >= 0 && delay <= 5 && cin.good() == 1)
                break;
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1410065407, '\n');
            }
        }
    }
    if (mode == '9')
        delay = 1;

    for (i = 0; i < *n; i++)
        plate[*src - 65][i] = *n - i;
    top[*src - 65] = *n;
}
void pause()
{
    if (delay == 0)
    {
        int m;
        do
        {
            m = _getch();
        } while (m != '\n' && m != '\r');
    }
    else
        Sleep(6000 - 1000 * delay);
}
void change_top(char src, char dst)
{
    plate[dst - 65][top[dst - 65]++] = plate[src - 65][--top[src - 65]];
    plate[src - 65][top[src - 65]] = 0;
}
void print_plate()
{
    for (char ch = 'A'; ch < 'D'; ch++)
    {
        cout << ch << ":";
        for (int i = 0; i < top[ch - 'A']; i++)
            cout << setw(2) << plate[ch - 'A'][i];
        cout << setw(21 - 2 * top[ch - 'A']) << " ";
    }

}
void print_line(char mode)
{
    int space = ((mode == '8' || mode=='9') ? SPACE : 0);
    if (mode != '3')
    {
        cct_gotoxy(42, 18 + space);
    }
    print_plate();
    cout << endl;
}//space是为了后面给伪图形的打印预留空间
void print_vertical(char mode)
{
    int space = ((mode == '8' || mode == '9') ? SPACE : 0);
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < top[j]; i++)
        {
            cct_gotoxy(12 + j * 3, 15 - i - 1 + space);
            cout << plate[j][i];
        }
}
void print_tower(char mode)
{
    int space = ((mode == '8' || mode == '9') ? SPACE : 0);
    //打印塔底部
    cct_gotoxy(10, 15 + space);
    cout << setw(11) << setfill('=') << "=";//"="分割线：x为10到20，y为15
    cct_gotoxy(10, 16 + space);
    cout << setw(3) << setfill(' ') << 'A' << setw(3) << 'B' << setw(3) << 'C';//ABC：x为12，15,18，y为16

    for (int i = 0; i < 3; i++)
    {
        cct_gotoxy(12 + 3 * i, 15 - top[i] - 1 + space);
        cout << " ";
    }

    print_vertical(mode);
}
void move(char src, char dst)//因为历史残留原因，move函数实际上是回退到上一次状态，（重新）执行本次move，故num取1而不是0
{
    change_top(dst, src);
    cct_setcursor(CURSOR_INVISIBLE);
    int steplen;
    int w = plate[src - 'A'][top[src - 'A'] - 1] * 2 + 1;//当前打印盘子的宽度
    int X = POLELEN + (src - 'A') * DS;//盘子的横坐标
    int Y = BASE_Y - top[src - 'A'];//当前盘子的纵坐标
    cct_gotoxy(X, Y);
    int color = plate[src - 'A'][top[src - 'A'] - 1];//当前盘子颜色

    //竖直上移
    steplen = -1;//步长为-1
    for (; Y != 3; Y += steplen)
    {
        cct_showch(X - (w - 1) / 2, Y + steplen, ' ', color, COLOR_WHITE, w);//打印下一次移动
        cct_showch(X - (w - 1) / 2, Y, ' ', COLOR_BLACK, COLOR_WHITE, w);//覆盖上一个盘子
        cct_showch(X, Y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);//重新画柱子
        Sleep(400 - 50 * delay);
    }

    //水平移动
    steplen = (src > dst ? -1 : 1);//步长的正负取决于src和dst的相对位置
    for (; X != POLELEN + (dst - 'A') * DS; X += steplen)
    {
        cct_showch(X + steplen - (w - 1) / 2, Y, ' ', color, COLOR_WHITE, w);//打印下一次移动
        cct_showch(X - steplen * (w - 1) / 2, Y, ' ', COLOR_BLACK, COLOR_WHITE, 1);//覆盖上一个盘子的尾部的一个字符，因为步长的绝对值为1
        Sleep(80 - 10 * delay);
    }

    //竖直下移
    steplen = 1;//步长为1
    for (; Y != BASE_Y - top[dst - 'A'] - 1; Y += steplen)
    {
        cct_showch(X - (w - 1) / 2, Y + steplen, ' ', color, COLOR_WHITE, w);//打印下一次移动
        if (Y != BASE_Y - top[dst - 'A'])//终点处不用覆盖上一个
        {
            cct_showch(X - (w - 1) / 2, Y, ' ', COLOR_BLACK, COLOR_WHITE, w);//覆盖上一个盘子
            if (Y == 3)
            {

                cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 1);//最高处用黑色覆盖上一次
            }
            else
            {
                cct_showch(X, Y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);//其他位置用黄色覆盖，重新画柱子
            }
        }
        Sleep(400 - 50 * delay);
    }
    change_top(src, dst);
}
void prompt(char mode, char src, char dst)
{
    int space = ((mode == '8' || mode == '9') ? SPACE : 0);
    if (mode == '8' || mode == '4')
        cct_showch(20, 18 + space, ' ', COLOR_BLACK, COLOR_WHITE, 0);
    if (mode != '1')
        cout << "第" << setw(4) << ++num << " 步: ";
    cout << setw(2) << plate[dst - 65][top[dst - 65] - 1] << "#:" << src << "-->" << dst << " ";
    if (mode == '1' || mode == '2')
        cout << endl;
}
void input9(char src, char tmp)
{
    int i, j;
    char mode = '9';
    char cmd[20] = { '\0' };
    char m;
    cct_showch(0, 19 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 0);//颜色回复默认
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";//这一行文字长度为60
    while (1)
    {
        cct_showch(60, 19 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 20);//把上一次打出来的东西删了
        cct_gotoxy(60, 19 + SPACE);
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        for (i = 0; i < 20; i++)
        {
            cmd[i] = '\0';
        }
        for (i = 0; i < 20; i++)
        {
            m = _getch();
            if (m != ' ')
            {
                cmd[i] = m;
                cout << m;
            }
            else
            {
                i--;
            }
            if (m == '\n' || m == '\r')
            {
                break;
            }
        }
        if (i == 20)
        {
            continue;
        }
        if (cmd[0] != 'q' && cmd[0] != 'Q')
        {
            if (cmd[3] != '\0')//输入超过3个(2个字母+回车），直接重输
            {
                continue;
            }
            for (j = 0; j < 2; j++)//输入了两个，把这两个小写化大写
            {
                if ('a' <= cmd[j] && cmd[j] <= 'c')
                {
                    cmd[j] += ('A' - 'a');
                }
            }
            if (cmd[0] >= 'A' && cmd[0] <= 'C' && cmd[1] >= 'A' && cmd[1] <= 'C' && cmd[1] != cmd[0])
            {
                if (top[cmd[0] - 'A'] == 0)
                {
                    cct_gotoxy(0, 20 + SPACE);
                    cout << "源柱为空！";
                    Sleep(1000);
                    cct_showch(0, 20 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 30);
                    continue;
                }
                else
                {
                    if (top[cmd[1] - 'A'] != 0)
                    {
                        if (plate[cmd[0] - 'A'][top[cmd[0] - 'A'] - 1] > plate[cmd[1] - 'A'][top[cmd[1] - 'A'] - 1])
                        {
                            cct_gotoxy(0, 20 + SPACE);
                            cout << "大盘压小盘，非法移动！";
                            Sleep(1000);
                            cct_showch(0, 20 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 30);
                            continue;
                        }
                    }
                }
                plate[cmd[1] - 'A'][top[cmd[1] - 'A']++] = plate[cmd[0] - 'A'][--top[cmd[0] - 'A']];
                plate[cmd[0] - 'A'][top[cmd[0] - 'A']] = 0;
                cct_showch(0, 38, ' ', COLOR_BLACK, COLOR_WHITE, 1);
                cct_gotoxy(20, 18 + SPACE);
                cout << "第" << setw(4) << ++num << " 步(" << setw(2) << plate[cmd[1] - 65][top[cmd[1] - 65] - 1] << "): " << cmd[0] << "-->" << cmd[1] << " ";
                print_line(mode);
                print_tower(mode);
                move(cmd[0], cmd[1]);
                if (top[tmp - 'A'] == 0 && top[src - 'A'] == 0)
                {
                    cct_showch(0, 20 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 0);//颜色回复默认
                    cout << "游戏终止！！！";
                    break;
                }
            }
            continue;
        }
        else//输了q
        {
            if (cmd[2] != '\0')//输入超过一个（1个字母+回车），直接重新输
            {
                continue;
            }
            cct_gotoxy(0, 20 + SPACE);
            cout << "游戏终止！！！";
            break;
        }
    }
}
//画柱子mode=5
void draw_poles()
{
    cct_setcursor(CURSOR_INVISIBLE);
    int i, j;
    //打印三个底座
    for (i = 0; i < 3; i++)
    {
        cct_showch(1 + i * DS, BASE_Y, ' ', COLOR_HYELLOW, COLOR_WHITE, BASELEN);//DS为两个底座的左端点的距离，第一个底座的左端点的x坐标值为1
        Sleep(50);
    }

    //打印柱子
    for (i = 1; i <= 12; i++)//每个柱子12层，一层一层打印
    {
        for (j = 0; j < 3; j++)//每层打印3个柱子
        {
            cct_showch(POLELEN + j * DS, BASE_Y - i, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);//第一个柱子的最底下一层的坐标（12,15-1）
            Sleep(50);
        }
    }
}
//画盘子mode=6
void draw_plates(char pole)//在pole柱子上画盘子。
{
    cct_setcursor(CURSOR_INVISIBLE);
    int i, k, w;
    const int X = POLELEN + (pole - 'A') * DS;//X为pole的x坐标
    for (i = 1; i <= top[pole - 'A']; i++)
    {
        w = plate[pole - 'A'][i - 1] * 2 + 1;//当前打印盘子的宽度
        for (k = X - (w - 1) / 2; k <= X + (w - 1) / 2; k++)
        {
            cct_showch(k, BASE_Y - i, ' ', plate[pole - 'A'][i - 1], COLOR_WHITE, 1);//盘子是几号，颜色就是几号色
        }
        Sleep(22);
    }
}
void hanoi_draw_plates()//画一串盘子
{
    char mode = '6';
    int n;
    char src, dst, tmp;
    input(&src, &dst, &tmp, &n, mode);
    cct_cls();
    cout << "从" << src << "移动到" << dst << ", 共" << n << "层" << endl;
    draw_poles();
    draw_plates(src);
}

//递归
void hanoi_recur(int n, char src, char tmp, char dst,char mode)
{
    if (n == 0)
        return;
    hanoi_recur(n - 1, src, dst, tmp,mode);
    change_top(src, dst);
    prompt(mode,src,dst);
    if (mode != '1'&& mode != '2') {
        print_line(mode);
        if (mode != '3') {
            print_tower(mode);
            if (mode == '8')
                move(src, dst);
            pause();
        }
    }
    hanoi_recur(n - 1, tmp, src, dst,mode);
}

//主函数
//mode=1,2,3,4,8,9
void hanoi123489(char mode)
{
    int n;
    char src, dst, tmp;
    input(&src, &dst, &tmp, &n,mode);
    if (mode == '1'|| mode=='2')
    {
        cout << "移动步骤为:" << endl;
    }
    if (mode == '4'||mode=='8'||mode=='9')
    {
        int space= ((mode == '8' || mode == '9') ? SPACE : 0);
        cct_cls();
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
        if (mode != 9)
        {
            cout <<"，延时设置为 " << delay << "。";
        }
        cct_gotoxy(20, 18+space);
        cout << "初始:" << setw(16) << " ";
        cct_setcursor(CURSOR_INVISIBLE);
        print_line(mode);
        print_tower(mode);
        if (mode == '8'||mode=='9')
        {
            draw_poles();
            draw_plates(src);
        }
        if (mode != '9')
        {
            pause();
        }
        else
        {
            input9(src,tmp);
        }
    }
    if (mode != '9')
    {
        hanoi_recur(n, src, tmp, dst, mode);
    }
}

//mode=7
void hanoi_MoveOnePlate()
{
    char mode = '7';
    int n;
    char src, dst, tmp;
    input(&src, &dst, &tmp, &n,mode);
    cct_cls();
    cout << "从" << src << "移动到" << dst << ", 共" << n << "层" << endl;
    draw_poles();
    draw_plates(src);
    Sleep(3000);
    if (n % 2 != 0)//n为奇数
    {
        change_top(src, dst);//消除move函数中回退到移动前状态的影响
        move(src, dst);
    }
    else
    {
        change_top(src, tmp);//消除move函数中回退到移动前状态的影响
        move(src, tmp);
    }
}

//自动移动
//void hanoi_AutoMove()
//{
//    char mode = '8';
//    int n;
//    char src, dst, tmp;
//    input(&src, &dst, &tmp, &n,mode);
//
//    cct_cls();
//    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << "。";
//    cct_gotoxy(20, 18+SPACE);
//    cout << "初始:" << setw(16) << " ";
//    cct_setcursor(CURSOR_INVISIBLE);
//    print_line(mode);
//    print_tower(mode);
//    draw_poles();
//    draw_plates(src);
//    pause();
//    hanoi_recur(n, src, tmp, dst,mode);
//}

//游戏
//void hanoi_game()
//{
//    char mode = '9';
//    int n, i, j;
//    char src, dst, tmp;
//    input(&src, &dst, &tmp, &n,mode);
//
//    cct_cls();
//    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
//    cct_gotoxy(20, 18 + SPACE);
//    cout << "初始:" << setw(16) << " ";
//    cct_setcursor(CURSOR_INVISIBLE);
//    print_line(mode);
//    print_tower(mode);
//    draw_poles();
//    draw_plates(src);
//    char cmd[20] = { '\0'};
//    char m;
//    cct_showch(0, 19 + SPACE,' ',COLOR_BLACK,COLOR_WHITE,0);//颜色回复默认
//    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";//这一行文字长度为60
//    while (1)
//    {
//        cct_showch(60, 19 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 20);//把上一次打出来的东西删了
//        cct_gotoxy(60, 19 + SPACE);
//        cct_setcursor(CURSOR_VISIBLE_NORMAL);
//        for (i = 0; i < 20; i++)
//        {
//            cmd[i] = '\0';
//        }
//        for (i = 0; i < 20; i++)
//        {
//            m =_getch();
//            if (m != ' ')
//            {
//                cmd[i] = m;
//                cout << m;
//            }
//            else
//            {
//                i--;
//            }
//            if (m == '\n' || m == '\r')
//            {
//                break;
//            }
//        }
//        if (i == 20)
//        {
//            continue;
//        }
//        if (cmd[0] != 'q' && cmd[0] != 'Q')
//        {
//            if (cmd[3] != '\0')//输入超过3个(2个字母+回车），直接重输
//            {
//                continue;
//            }
//            for (j = 0; j < 2; j++)//输入了两个，把这两个小写化大写
//            {
//                if ('a' <= cmd[j] && cmd[j] <= 'c')
//                {
//                    cmd[j] += ('A' - 'a');
//                }
//            }
//            if (cmd[0] >= 'A' && cmd[0] <= 'C' && cmd[1] >= 'A' && cmd[1] <= 'C' && cmd[1] != cmd[0])
//            {
//                if (top[cmd[0] - 'A'] == 0)
//                {
//                    cct_gotoxy(0, 20 + SPACE);
//                    cout << "源柱为空！";
//                    Sleep(1000);
//                    cct_showch(0, 20 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 30);
//                    continue;
//                }
//                else
//                {
//                    if (top[cmd[1] - 'A'] != 0)
//                    {
//                        if (plate[cmd[0] - 'A'][top[cmd[0] - 'A'] - 1] > plate[cmd[1] - 'A'][top[cmd[1] - 'A'] - 1])
//                        {
//                            cct_gotoxy(0, 20 + SPACE);
//                            cout << "大盘压小盘，非法移动！";
//                            Sleep(1000);
//                            cct_showch(0, 20 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 30);
//                            continue;
//                        }
//                    }
//                }
//                plate[cmd[1] - 'A'][top[cmd[1] - 'A']++] = plate[cmd[0] - 'A'][--top[cmd[0] - 'A']];
//                plate[cmd[0] - 'A'][top[cmd[0] - 'A']] = 0;
//                cct_showch(0, 38, ' ', COLOR_BLACK, COLOR_WHITE, 1);
//                cct_gotoxy(20, 18 + SPACE);
//                cout << "第" << setw(4) << ++num << " 步(" << setw(2) << plate[cmd[1] - 65][top[cmd[1] - 65] - 1] << "): " << cmd[0] << "-->" << cmd[1] << " ";
//                print_line(mode);
//                print_tower(mode);
//                move(cmd[0], cmd[1]);
//                if (top[tmp - 'A'] == 0 && top[src - 'A'] == 0)
//                {
//                    cct_showch(0, 20 + SPACE, ' ', COLOR_BLACK, COLOR_WHITE, 0);//颜色回复默认
//                    cout << "游戏终止！！！";
//                    break;
//                }
//            }
//            continue;
//        }
//        else//输了q
//        {
//            if (cmd[2] != '\0')//输入超过一个（1个字母+回车），直接重新输
//            {
//                continue;
//            }
//            cct_gotoxy(0, 20 + SPACE);
//            cout << "游戏终止！！！";
//            break;
//        }
//    }
//}