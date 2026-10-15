/* 2350222 信12 盛曦 */
#include <iostream>
using namespace std;

int main()
{
	int sudoku[9][9];
	int i, k,j;
	int flag = 2;//记录输入错误的状态.2:正常；0:cin.good为0，从头开始输入；1：输入范围错，从错的那一个开始输入
	int x, y;//记录输入错误的位置
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	while (1)
	{
		for (i = 0; i < 9; i++)
		{
			if (flag != 2)
			{
				i = x;
			}
			for (k = 0; k < 9; k++)
			{
				if (flag != 2)
				{
					k = y;
				}
				cin >> sudoku[i][k];
				if (cin.good() == 1 && sudoku[i][k] >= 1 && sudoku[i][k] <= 9)
				{
					flag = 2;
				}
				else
				{
					if (cin.good() == 0)
					{
						cin.clear();
						cin.ignore(1410065407, '\n');
						flag = 0;
					}
					else
					{
						flag = 1;
					}
					x = i;
					y = k;
					cout << "请重新输入第" << i + 1 << "行" << k + 1 << "列(行列均从1开始计数)的值" << endl;
					break;//不会执行k++
				}
			}
			if (flag == 0)
			{
				break;
			}
			if (flag == 1)
			{
				continue;
			}
		}
		if (flag == 0)
		{
			continue;
		}
		if (flag == 2)
		{
			break;
		}
	}
	int vertical[9][9] = { 0 }, level[9][9] = { 0 }, square[9][9] = { 0 };//以vertical为例，vertical[x][y]存储的是第x列内数字y出现的个数
	for (i = 0; i < 9; i++)//i表示当前列数
	{
		for (k = 0; k < 9; k++)
		{
			vertical[i][sudoku[k][i]-1]++;
		}
		for (j = 0; j < 9; j++)//每做完一列就判断一下，减少计算量
		{
			if (vertical[i][j] != 1)
			{
				cout << "不是数独的解" << endl;
				return 0;
			}
		}
	}
	for (i = 0; i < 9; i++)//i表示当前行数
	{
		for (k = 0; k < 9; k++)
		{
			level[i][sudoku[i][k]-1]++;
		}
		for (j = 0; j < 9; j++)
		{
			if (level[i][j] != 1)
			{
				cout << "不是数独的解" << endl;
				return 0;
			}
		}
	}
	int m, n;
	for (i = 0; i < 3; i++)//i,j共同表示当前九宫格数(3*i+j)
	{
		for (j = 0; j < 3; j++)
		{
			for (m = i * 3; m < i * 3 + 3; m++)
			{
				for (n = j * 3; n < j * 3 + 3; n++)
				{
					square[3*i+j][sudoku[m][n]-1]++;
				}
			}
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (square[i][j] != 1)
			{
				cout << "不是数独的解" << endl;
				return 0;
			}
		}
	}
	cout << "是数独的解" << endl;
	return 0;
}