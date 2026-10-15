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
		y1 = (y-1) % 100;
		c = (y-1) / 100;
		m1 = 12 + m;
	}
	else
	{
		y1 = y % 100;
		c = y / 100;
		m1 = m;
	}
	w = y1 + y1 / 4 + c / 4 - 2*c + 13*(m1 + 1) / 5 + d - 1;
	for (; w < 0; w += 7)
		;
	return w%7;
}

int main()
{
	int y, m, d;
	int max;

	while (1)
	{
		cout << "请输入年[1900-2100]、月、日："<< endl;
		cin >> y >> m >> d;
		if (m <= 7 && m % 2 == 1 || 7 < m && m % 2 == 0)
			max = 31;
		else if (m != 2 && m < 7 && m % 2 == 0 || m>7 && m % 2 == 1)
			max = 30;
		else if ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) && m == 2)
			max = 29;
		else
			max = 28;
		if (cin.good() == 1)
		{
			if (y >= 1900 && y <= 2100 && m >= 1 && m <= 12 && 1 <= d && d <= max)
				break;
			else if (y < 1900 || y>2100)
				cout << "年份不正确，请重新输入" << endl;
			else if (m < 1 || m>12)
				cout << "月份不正确，请重新输入" << endl;
			else if (d<1 || d>max)
				cout << "日不正确，请重新输入" << endl;
		}
		if (cin.good() == 0)
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
		}
	}
	cout << "星期";
	switch (zeller(y, m, d))
	{
		case 0:
			cout << "日";
			break;
		case 1:
			cout << "一";
			break;
		case 2:
			cout << "二";
			break;
		case 3:
			cout << "三";
			break;
		case 4:
			cout << "四";
			break;
		case 5:
			cout << "五";
			break;
		case 6:
			cout << "六";
			break;
		default:
			break;
	}
	cout << endl;
	return 0;
}