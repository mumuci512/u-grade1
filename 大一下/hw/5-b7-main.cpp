/* 2350222 信12 盛曦 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "5-b7.h"
using namespace std;

int in_array;//是否显示内部数组
int delay;
int num = 0;
int topA = 0, topB = 0, topC = 0;//top是栈中的第一个0
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };

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
        Sleep(5000 - 5 * delay);
}

//打印内部数组
void print_plate(char abc, int pole[], int top)
{
    cout << abc << ":";
    for (int i = 0; i < top; i++)
        cout << setw(2) << pole[i];
    cout << setw(21 - 2 * top) << " ";
}

void print_line()
{
    cct_gotoxy(42,20);
    print_plate('A', A, topA);
    print_plate('B', B, topB);
    print_plate('C', C, topC);
    cout << endl;
}

//打印塔
void print_vertical(int top,char ch,int array[])
{
    int x;
    switch (int(ch))
    {
        case 'A':
            x = 12;
            break;
        case 'B':
            x = 12+3;
            break;
        case 'C':
            x = 12 + 3 + 3;
            break;
        default:
            x = -1;
            break;
    }
    for (int i = 0; i < top; i++)
    {
        cct_gotoxy(x, 15 - i - 1);
        cout << array[i];
    }
}
void print_tower()
{
    //打印塔底部
    cct_gotoxy(10, 15);
    cout << setw(11) << setfill('=' ) << "=";//"="分割线：x为10到20，y为15
    cct_gotoxy(10, 16);
    cout << setw(3) << setfill(' ') << 'A' << setw(3) << 'B' << setw(3) << 'C';//ABC：x为12，15,18，y为16

    cct_gotoxy(12, 15 - topA - 1);
    cout << " ";
    cct_gotoxy(12 + 3, 15 - topB - 1);
    cout << " ";
    cct_gotoxy(12 + 3 + 3, 15 - topC - 1);
    cout << " ";
    
    print_vertical(topA, 'A',A);
    print_vertical(topB, 'B',B);
    print_vertical(topC, 'C',C);
}

int change_plate(char src, char dst)
{
    int m;
    switch ((int)(src))
    {
        case 'A':
        {
            m = A[--topA];
            A[topA] = 0;
            break;
        }
        case 'B':
        {
            m = B[--topB];
            B[topB] = 0;
            break;
        }
        case 'C':
        {
            m = C[--topC];
            C[topC] = 0;
            break;
        }
        default:
            m = -1;
            break;
    }
    switch ((int)(dst))
    {
        case 'A':
        {
            A[topA++] = m;
            break;
        }
        case 'B':
        {
            B[topB++] = m;
            break;
        }
        case 'C':
        {
            C[topC++] = m;
            break;
        }
        default:
            break;
    }
    return m;
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);

    int m = change_plate(src, dst);
    cct_gotoxy(20, 20);
    cout << "第" << setw(4) << ++num << "步(" << m << "#：" << src << "-->" << dst <<") ";
    if (in_array)
    {
        print_line();
        pause();
    }
    print_tower();
    pause();
    
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n,i;
    char src, dst, tmp;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (n >= 1 && n <= 10 && cin.good() == 1)
            break;
    }

    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (src > 90)
            src = char(src - 32);
        if ((src == 'A' || src == 'B' || src == 'C') && cin.good() == 1)
            break;
    }

    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (dst > 90)
            dst = char(dst - 32);
        if ((dst == 'A' || dst == 'B' || dst == 'C') && dst != src && cin.good() == 1)
            break;
        else if (dst == src)
            cout << "目标柱(" << src << ")不能与起始柱(" << dst << ")相同" << endl;
    }

    tmp = 'A' + 'B' + 'C' - src - dst;

    switch ((int)(src))
    {
        case 'A':
        {
            topA = n;
            for (i = 0; i < n; i++)
                A[i] = n - i;
            break;
        }
        case 'B':
        {
            topB = n;
            for (i = 0; i < n; i++)
                B[i] = n - i;
            break;
        }
        case 'C':
        {
            topC = n;
            for (i = 0; i < n; i++)
                C[i] = n - i;
            break;
        }
        default:
            break;
    }

    while (1)
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> delay;
        if (delay >= 0 && delay <= 5 && cin.good() == 1)
            break;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
        }
    }
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> in_array;
        if ((in_array == 0 || in_array == 1) && cin.good() == 1)
            break;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
        }
    }
  
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << "，";
    if (!in_array)
        cout << "不";
    cout << "显示内部数组值" << endl;
    if (in_array)
    {
        cct_gotoxy(20, 20);
        cout << "初始:" << setw(16) << " ";
        print_line();
        pause();
    }
    print_tower();
    pause();
    hanoi(n, src, tmp, dst);
    cct_gotoxy(0, 25);
    system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
    return 0;
}