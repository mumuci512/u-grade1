/* 盛曦 2350222 信12 */
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入数据的个数[1..10000]" << endl;
	int n;
	cin >> n;
	cin.ignore();
	char num[100000] = { '\0'};
	cout << "请输入" << n << "个正整数" << endl;
	int i = 0;
	int j;
	int jishu=0;
	/*int end = 0;*/
	/*for (i = 0; i < n; i++)
	{
		num[i] = getchar();

		if (jishu == n && (num[i] == '\n' || num[i] == '\r'))
			break;
		if (num[i] == '\n' || num[i] == '\r' || num[i] == ' ')
		{
			if (jishu != n)
			{

				jishu++;
			}
		}
		if (jishu == n)
		{
			end = i;
		}
	}*/
	char ch;
	while (jishu < n && i < 100000) {
		ch = getchar();
		if (ch == ' ' || ch == '\n' ) {
			jishu++; // 完成一个数的输入
		}
		else {
			num[i++] = ch; // 存储字符
		}
	}
	cout << "请输入数码[0..9]" << endl;/*
	while (getchar() != '\n')
		;*/
	char d;//等待检测数码
	d=getchar();
	int s=0;
	for (j = 0; j < i; i++)
	{
		if (num[i] == d)
		{
			s++;
		}
	}
	cout << n << "个数中含有" << d << "的个数 :" << s << endl;
	return 0;
}