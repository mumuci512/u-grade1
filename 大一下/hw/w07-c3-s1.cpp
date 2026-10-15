/*2350222 信12 盛曦*/
#include <limits>
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：输出位数、正序、逆序
  输入参数：
  返 回 值：
  说    明：不准修改函数名、返回类型、形参
***************************************************************************/
void output(int k)
{
	int wan = k / 10000;
	int qian = (k % 10000) / 1000;
	int bai = (k % 1000) / 100;
	int shi = (k % 100) / 10;
	int ge = k % 10;

	int weishu;
	if (wan == 0)
	{
		if (qian != 0)
			weishu = 4;
		else
		{
			if (bai != 0)
				weishu = 3;
			else
			{
				if (shi != 0)
					weishu = 2;
				else
					weishu = 1;
			}
		}
	}
	else
		weishu = 5;
	cout << weishu << "位数" << endl;
	cout << "每位数字分别是 : " << endl;
	int d;
	bool sign = true;
	for (sign = 1, d = 10000; d >= 1; d /= 10)
	{
		if (k / d % 10 != 0 || !sign ||d==1)
		{
			cout << k / d % 10 << " ";
			sign = false;
		}
	}
	cout << endl;

	cout << "逆序输出的每位数字分别是 : " << endl;
	int l = 1;
	int t = k;
	while (t / 10 != 0) 
	{
		l *= 10;
		t /= 10;
	}
	bool sign2 = true;
	for (d = 1; d <= l; d *= 10) 
	{
		if ((k / d) % 10 != 0 || !sign2 || d == l)
		{
			cout << (k / d) % 10 << " ";
			sign2 = false;
		}
	}
	cout << endl;
	
}

/***************************************************************************
  函数名称：
  功    能：重复输入，直到取得[0..99999]之间的整数后返回
  输入参数：
  返 回 值：
  说    明：不准修改函数名、返回类型、形参
***************************************************************************/
int input(void)
{
	int a;
	while (1) {
		cout << "请输入一个[0..99999]间的整数" << endl;
		cin >> a;
		if (a >= 0 && a <= 99999 && cin.good() == 1)
			break;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
		}//若此if在上一个if之前，则需加continue，或者将两个if合并成if&else if
	}
	return a;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int k;

	k = input();
	output(k);

	return 0;
}
