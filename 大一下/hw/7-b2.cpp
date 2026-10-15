/* 2350222 信12 盛曦 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "7-b2.h"
#include "cmd_console_tools.h"
using namespace std;

/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */
#define NUM 10//菜单数量

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */
struct menu_parm {
    int height;
    int width;
    int sel;
    int start;
    int end;
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static int draw_frame(const struct PopMenu* original_para, const struct menu_parm parm)
{
    int len = strlen(original_para->title) + strlen(original_para->title) % 2;
    cct_showstr(original_para->start_x, original_para->start_y, "╔", original_para->bg_color, original_para->fg_color, 1);
    cct_showstr(original_para->start_x + 2, original_para->start_y, "═", original_para->bg_color, original_para->fg_color, parm.width / 2);
    int X, Y;
    cct_getxy(X, Y);
    cct_showstr(X,Y, "╗", original_para->bg_color, original_para->fg_color, 1);
    
    int i;
    for (i = 0; i < parm.height; i++)
    {
        cct_showstr(original_para->start_x, original_para->start_y + 1 + i, "║", original_para->bg_color, original_para->fg_color, 1);
        //cct_gotoxy(original_para->start_x + 2 + width * 2, original_para->start_y + 1 + i);
        //cout << setw(width*4+2)<<"║";
        cct_showstr(X, Y+ 1 + i, "║", original_para->bg_color, original_para->fg_color, 1);
    }
    cct_showstr(original_para->start_x, original_para->start_y + 1 + parm.height, "╚", original_para->bg_color, original_para->fg_color, 1);
    cct_showstr(original_para->start_x + 2, original_para->start_y + 1 + parm.height, "═", original_para->bg_color, original_para->fg_color, parm.width / 2);
    cct_showstr(X, Y + 1 + parm.height, "╝", original_para->bg_color, original_para->fg_color, 1);

    cct_showstr(original_para->start_x + (parm.width - len) / 2+2, original_para->start_y, original_para->title, original_para->bg_color, original_para->fg_color, 1);
    if (strlen(original_para->title) % 2 != 0)
        cout << " ";

    return 0;
    ; //仅为示例，不需要可删除
}

static int zero_all(char m[MAX_ITEM_LEN])
{
    int k;
    for (k = 0; k < MAX_ITEM_LEN; k++)
        m[k] = '\0';
    return 0;
}

static int assign_array(char m[MAX_ITEM_LEN], int srt, int width,const char menu[MAX_ITEM_LEN])//返回值为1表示最后覆盖空格，为0表示没有覆盖
{
    zero_all(m);
    int count = 0;
    int k;
    for (k = srt; k < srt+width; k++)
    {
        if (menu[k] >= char(0xA1) && menu[k] <= char(0xFE))
            count++;
    }
    if (count % 2 != 0)
    {
        for (k = srt; k < srt + width - 1; k++)
            m[k - srt] = menu[k];
        m[width] = ' ';
        return 1;
    }
    else
    {
        for (k = srt; k < srt + width; k++)
            m[k - srt] = menu[k];
        return 0;
    }
}

static int print_array(char m[], int width)
{
    cout << m;
    if (width - strlen(m) != 0)
        cout << setw(width - strlen(m)) << " ";
    return 0;
}

static int print_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para,struct menu_parm& parm)
{
    int i,j;
    int width = original_para->width;
    if (unsigned int(width) < strlen(original_para->title) + strlen(original_para->title) % 2)
        width = strlen(original_para->title) + strlen(original_para->title) % 2;
    width += (width % 2);
    char m[MAX_ITEM_LEN] = { "\0" };
    for (i = parm.start,j=0; j<parm.height; i++,j++)
    {
        if (strlen(menu[i]) > unsigned int(width))
        {
            assign_array(m, 0, width, menu[i]);
        }
        else
            strcpy(m, menu[i]);
        cct_gotoxy(original_para->start_x + 2, original_para->start_y + 1 + j);
        if(i== parm.sel)
            cct_setcolor(original_para->fg_color, original_para->bg_color);
        else
            cct_setcolor(original_para->bg_color, original_para->fg_color);
        int cols, lines, buffer_cols, buffer_lines;
        cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
        if (cols - original_para->start_x < original_para->width + 4)
        {
            char m1[MAX_ITEM_LEN] = { '\0' };
            int w1 = cols - (original_para->start_x + 2);//前半句的宽度
            char m2[MAX_ITEM_LEN] = { '\0' };
            int w2 = width - w1;
            assign_array(m2, w1 - assign_array(m1, 0, w1, menu[i]), w1, menu[i]);
            print_array(m1, w1);
            print_array(m2, w2);
        }
        else
            print_array(m, width);
    }
    return 0;
}

static int keyboard_cmd(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para, struct menu_parm& parm)
{
    int cmd = _getch();
    while (cmd != '\n' && cmd != '\r')
    {
        if (cmd == 224)
        {
            cmd = _getch();
            switch (cmd)
            {
                case 72:
                    if (parm.sel != parm.start)
                    {
                        parm.sel--;//up
                    }
                    else if (parm.start > 0)
                    {
                        parm.start--;
                        parm.end--;
                        parm.sel--;
                    }
                    print_menu(menu, original_para, parm);
                    break;
                case 80:
                    if (parm.sel != parm.end)
                    {
                        parm.sel++;//down
                    }
                    else if (parm.end < NUM - 1)
                    {
                        parm.start++;
                        parm.end++;
                        parm.sel++;
                    }
                    print_menu(menu, original_para, parm);
                    break;
                default:
                    break;
            }
        }
        cmd = _getch();
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    cct_setcursor(CURSOR_INVISIBLE);
    struct menu_parm parm;
    parm.height = (original_para->high < NUM ? original_para->high : NUM);
    parm.width = original_para->width;
    parm.width += (parm.width % 2);
    int len = strlen(original_para->title) + strlen(original_para->title) % 2;
    if (parm.width < len)
        parm.width = len;
    draw_frame(original_para,parm);
    parm.sel = 0,parm.start=0,parm.end= parm.height-1;
    print_menu(menu, original_para, parm);
    keyboard_cmd(menu, original_para, parm);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    return parm.sel+1;
}
