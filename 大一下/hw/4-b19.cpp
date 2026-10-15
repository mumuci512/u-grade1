/* 2350222 信12 盛曦 */
#include <iostream>
using namespace std;
int min(int a,int b,int c=0,int d=0)
{
	if (c + d == 0)
		return a < b ? a : b;
	else if (d == 0)
	{
		int m = a < b ? a : b;
		return m < c ? m : c;
	}
	else
	{
		int m1= a < b ? a : b;
		int m2 = c < d ? c : d;
		return m1 < m2 ? m1 : m2;
	}
}
int main()
{
	int num, a, b;
	int c = 1, d = 1;
	while (1)
	{
		cout << "请输入个数num及num个正整数： " << endl;
		cin >> num;
		if (cin.good() == 1)
		{
			if (num < 2 || num>4)
			{
				cout << "个数输入错误" << endl;
				return 0;
			}
			else
			{
				cin >> a >> b;
				if (num > 2)
				{
					cin >> c;
					if (num > 3)
						cin >> d;
				}
				if (cin.good() == 0 || a <= 0 || b <= 0 || c <= 0 || d <= 0)
				{
					cin.clear();
					cin.ignore(1410065407, '\n');
					continue;
				}
				else
					break;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1410065407, '\n');
			continue;
		}
	}
	cout << "min=";
	switch (num)
	{
		case 2:
			cout << min(a, b);
			break;
		case 3:
			cout << min(a, b, c);
			break;
		case 4:
			cout << min(a, b, c, d);
			break;
		default:
			break;
	}
	cout << endl;
	return 0;
}