/* 2350222 信12 盛曦 */
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a,int b, int c)
{
	int m = max(a, b);
	return m > c ? m : c;
}

int max(int a, int b, int c, int d)
{
	int m = max(a, b, c);
	return m > d ? m : d;
}

int main()
{
	int num, a, b;
	int c=1, d=1;
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
	cout << "max=";
	switch (num)
	{
		case 2:
			cout << max(a, b);
			break;
		case 3:
			cout << max(a, b, c);
			break;
		case 4 :
			cout << max(a, b, c, d);
			break;
		default:
			break;
	}
	cout << endl;
	return 0;
}
