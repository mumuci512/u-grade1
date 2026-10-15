/*2350222 信12 盛曦*/
#include <iostream>
using namespace std;

int main()
{
	int y, m, d;
	cout << "请输入年，月，日" << endl;
	cin >> y >> m >> d;
	int s=0;
	if (0 < m && m <= 12)
	{
		if (1 == m % 2)
		{
			if (1 <= d && d <= (m <= 7 ? 31 : 30))
				s = (m - 1) / 2 * (30 + 31) + (m <= 7 ? 0 : 1) + d;
			else
				cout << "输入错误-日与月的关系非法" << endl;
		}
		else
		{
			if (2 == m)
			{
				if (1 <= d && d <= ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) ? 29 : 28))
					s = 31 + d;
				else
					cout << "输入错误-日与月的关系非法" << endl;
			}
			else
			{
				if (1 <= d && d <= (30+(m<=6?0:1)))
					s = m / 2 * (31 + 30) - 30 +d;
				else
					cout << "输入错误-日与月的关系非法" << endl;
			}
		}
		if (m > 2)
			s = s - ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) ? 1 : 2);
		if(s>0)
		cout << y << "-" << m << "-" << d << "是" << y << "年的第" << s << "天" << endl;
	}
	else
		cout << "输入错误-月份不正确" << endl;
	
	return 0;
}