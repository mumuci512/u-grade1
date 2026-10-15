/*2350222 信12 盛曦*/
#include <limits>
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

void calender(int year, int month)
{
	int max;

	if (month <= 7 && month % 2 == 1 || 7 < month && month % 2 == 0)
		max = 31;
	else if (month != 2 && month < 7 && month % 2 == 0 || month>7 && month % 2 == 1)
		max = 30;
	else if ((0 == year % 4 && 0 != year % 100 || 0 == year % 400) && month == 2)
		max = 29;
	else
		max = 28;
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	int s = 8 - zeller(year, month, 1);
	for (int j = 0; j < zeller(year, month, 1); j++)
		cout << "        ";
	for (int t = 1; t <= (7 - zeller(year, month, 1)); t++)
		cout << setw(4) << t << "    ";
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			cout << setw(4) << s << "    ";
			s++;
			if (s == max + 1)
				break;
		}
		cout << endl;
		if (s == max + 1)
			break;
	}

	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main()
{
	int y, m;
	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m ;
		if (cin.good() == 1)
		{
			if (y >= 1900 && y <= 2100 && m >= 1 && m <= 12)
				break;
			else if (y < 1900 || y>2100)
				cout << "年份不正确，请重新输入" << endl;
			else if (m < 1 || m>12)
				cout << "月份不正确，请重新输入" << endl;
		}
		if (cin.good() == 0)
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
		}
	}

	calender(y, m);
	return 0;
}
