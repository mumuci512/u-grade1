/* 2350222 盛曦 信12 */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void code(int len,int cap,int low,int num,int oth)
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	int i;
	int capi = 0, lowe = 0, numb = 0, othe = 0;
	int m;
	char code[17] = { '\0' };
	while (capi < cap || lowe < low || numb < num || othe < oth)
	{
		capi = 0;
		lowe = 0;
		numb = 0;
		othe = 0;
		for (i = 0; i < len;)//另一种方法：while（大写还不够&&code[pos]==0）pos=rand（），code[pos]=‘A’+rand（）%xx，
		{
			m = rand() % 127;//ascii码在33-126之间,other的角标为0-14
			if (m >= 'A' && m <= 'Z' && capi <= len - low - num - oth)
			{
				code[i] = char(m);
				i++;
				capi++;
			}
			else if (m >= 'a' && m <= 'z' && lowe <= len - cap - num - oth)
			{
				code[i] = char(m);
				i++;
				lowe++;
			}
			else if (m >= '0' && m <= '9' && numb <= len - low - cap - oth)
			{
				code[i] = char(m);
				i++;
				numb++;
			}
			else if (m >= 0 && m < 15 && othe <= len - low - num - cap)
			{
				code[i] = other[m];
				i++;
				othe++;
			}
		}
	}
	cout << code<<endl;
}
int main()
{
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int len, cap, low, num, oth;
	cin >> len >> cap >> low >> num >> oth;
	if (cin.good() == 0)
	{
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (cap<2 || cap>len)
	{
		cout << "大写字母个数[" << cap << "]不正确" << endl;
		return 0;
	}
	if (low<2 || low>len)
	{
		cout << "小写字母个数[" << low << "]不正确" << endl;
		return 0;
	}
	if (num<2 || num>len)
	{
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	if (oth<2 || oth>len)
	{
		cout << "其它符号个数[" << oth << "]不正确" << endl;
		return 0;
	}
	int sum = cap + low + num + oth;
	if (sum > len)
	{
		cout << "所有字符类型之和[" << cap << "+" << low << "+" << num << "+" << oth << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
	cout << len << " " << cap << " " << low << " " << num << " " << oth << endl;
	int i;
	srand((unsigned int)(time(0)));
	for (i = 0; i < 10; i++)
		code(len,cap, low, num, oth);
	return 0;
}