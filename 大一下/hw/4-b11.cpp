/*2350222 信12 盛曦*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */
void print_line(char ch, int order, int n)//ch为end_ch，order控制同一行内的正序or逆序输出，n控制逆序输出长度（为ch-64）
{
	if (order == 1)
	{
		if (ch > 64)
		{
			cout << ch;
			print_line(char(ch - 1), 1, n);
		}
		else
			print_line(char(65), 0, n);
	}
	else if (ch != n + 64)
	{
		cout << char(ch + 1);
		print_line(char(ch + 1), 0, n);
	}
}
   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/

//void print_tower(char standard,char ch,int order,char staticn)
//{
//	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
//	static int n =ch-64;
//	if (ch != standard)
//		n--;//用于打出下半个菱形
//	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
//	if (n != 0)
//	{
//		if (order == 1)
//		{
//			n--;
//			print_tower(char(ch - 1),char(ch - 1), order, staticn);
//			if(staticn!=ch)
//				cout << setw(int(staticn - ch)) << " ";
//			print_line(ch, 1, ++n);
//			cout << endl;
//		}
//		else
//		{
//			if (staticn != ch)
//				cout << setw(int(staticn - ch)) << " ";
//			print_line(ch, 1, n);
//			cout << endl;
//			n--;
//			print_tower(char(ch - 1),char(ch - 1), order, staticn);
//			n++;//每打印一个完整图案都要让n恢复原来的值,以便打印下一个图案
//		}
//	}
//	return;
//}
void print_tower(char ch, int order, int n)//ch为end_ch,n控制单次调用时输出塔的层数（为ch-64），N用于记住整个塔的总层数
{//其实n没必要作为形参，可以在函数内定义
	static int N = ch;
	if (n != 0)
	{
		if (order == 1)
		{
			print_tower(char(ch - 1), order, --n);
			cout << setw(N - ch+1) << setfill(' ');//setfill更新,本行用于接下来print_line的时候填充
			print_line(ch, 1, ++n);
			cout << endl;
		}
		else
		{
			cout << setw(N - ch+1) << setfill(' ');
			print_line(ch, 1, n);
			cout << endl;
			print_tower(char(ch - 1), order, --n);
		}
	}
	return;
}
//char separator(int x)
//{
//	if (x==0)
//		return ' ';
//	else
//	{
//		cout << "=";
//		separator(x - 1);
//	}
//	return ' ';
//}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=' ) <<setw(2*(end_ch-64)-1) << "=" <<endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=' ) <<setw(2*(end_ch-64)-1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,1, end_ch-64); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') << setw(2 * (end_ch - 64) - 1) << "=" << endl;  /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=' ) <<setw(2*(end_ch-64)-1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 0, end_ch-64); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') << setw(2 * (end_ch - 64) - 1) << "=" << endl; /* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 64) - 1) << "=" << endl; /* 按字母塔最大宽度输出= */
	print_tower(end_ch, 1, end_ch-64);   //打印 A~结束字符的正三角 
	print_tower(char(end_ch-1), 0, end_ch-65);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}