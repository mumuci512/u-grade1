/* 2350222 信12 盛曦 */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	int w, y1, c, m1;
	if (m == 1 || m == 2)
	{
		y1 = (y - 1) % 100;
		c = (y - 1) / 100;
		m1 = 12 + m;
	}
	else
	{
		y1 = y % 100;
		c = y / 100;
		m1 = m;
	}
	w = y1 + y1 / 4 + c / 4 - 2 * c + 13 * (m1 + 1) / 5 + d - 1;
	for (; w < 0; w += 7)
		;
	return w % 7;
}

void print_day(int month,int day[12][42])//month代表本次打印的起始月份
{
	int i, j,k;
	for (i = 0; i < 6; i++)//i表示当前打印的是第几行
	{
		int flag = 0;//flag用于记录当前这一行是否全是空格，flag为1则不是，flag为0则全是空格
		for (j = month - 1; j < month - 1 + 3; j++)//j表示当前打印的是第几月
		{
			for (k = i*7; k < i*7 + 7; k++)
			{
				if (day[j][k] != 0)
				{
					flag = 1;
				}
			}
		}
		if (flag == 1)
		{
			for (j = month - 1; j < month - 1 + 3; j++)//j表示当前打印的是第几月
			{
				for (k = i*7; k < i*7 + 7; k++)
				{
					if (day[j][k] == 0)
					{
						cout << setw(4) << " ";
					}
					else
					{
						cout << setiosflags(ios::left) << setw(4) << day[j][k];
					}
				}
				cout << setw(4) << " ";//打印完一个月的一行以后空4格继续打印下一个月的这一行
			}
			cout << endl;//打印完一整行后，换行
		}
	}
	cout << endl;
}

int main()
{
	int y;
	cout << "请输入年份[1900-2100]" << endl;
	cin >> y;
	int i, j, m;

	int max[12];
	for (i = 0; i < 12; i++)
	{
		m = i + 1;
		if (m <= 7 && m % 2 == 1 || 7 < m && m % 2 == 0)
			max[i] = 31;
		else if (m != 2 && m < 7 && m % 2 == 0 || m>7 && m % 2 == 1)
			max[i] = 30;
		else if ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) && m == 2)
			max[i] = 29;
		else
			max[1] = 28;
	}

	int day[12][42];
	//第一个坐标表示这个day属于哪个月，第二个坐标表示当前day是星期几，存储的元素表示day本身是几号（或者空格）。因为一个月最多6行，所以6*7=42
	for (i = 0; i < 12; i++)//i+1为月份值
	{
		for (j = 0; j < 42; j++)
		{
			day[i][j] = 0;//0代表空格,先全部赋值为空格
		}
		for (j = zeller(y, i+1, 1); j < zeller(y, i+1, 1) + max[i]; j++)//再将日期赋值
		{
			day[i][j] = j - zeller(y, i+1, 1) + 1 ;
		}
	}

	cout << y << "年的日历:" << endl;
	cout << endl;
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	print_day(1, day);
	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	print_day(4, day);
	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	print_day(7, day);
	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	print_day(10, day);
	cout << endl;
	return 0;
}