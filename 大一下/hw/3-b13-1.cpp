/*2350222 信12 盛曦*/
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int y, m, d;
	
	while (1) 
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12 && cin.good() == 1)
			break;
		cout << "输入非法，请重新输入" << endl;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
		}
	}
	while (1)
	{
		cout << "请输入" << y << "年" << m << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> d; 
		if (d >= 0 && d <= 6 && cin.good() == 1)
			break;
		cout << "输入非法，请重新输入" << endl;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
		}
	}
	cout << endl << y << "年" << m << "月的月历为:" << endl << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	int max;

	if (m <= 7 && m % 2 == 1 || 7 < m && m % 2 == 0)
		max = 31;
	else if (m != 2 && m < 7 && m % 2 == 0 || m>7 && m % 2 == 1)
		max = 30;
	else if ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) && m == 2)
		max = 29;
	else
		max = 28;

	int s = 8 - d;
	for (int j = 0; j < d; j++)
		cout << "        ";
	for (int t = 1; t <= (7 - d); t++)
		cout << setw(4) << t << "    ";
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			cout << setw(4) << s << "    ";
			s++;
			if (s == max+1 && k!=6)
				break;
			else if (s == max + 1 && k == 6)
			{
				cout << endl;
				break;
			}
		}
		cout << endl; 
		if (s == max+1)
			break;
	}
	return 0;
}
