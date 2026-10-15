/* 2350222 盛曦 信12 */
#include <iostream>
using namespace std;

int main()
{
	char str[81],*psrt,*pend;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 81, stdin);
	for (pend = str; *pend != '\0'; pend++)
		;
	if (pend - str > 2)//非空串或单字符
	{
		pend = pend - 2;//跳过\0,回车
	}
	else
	{
		cout << "yes" << endl;
		return 0;
	}
	for (psrt=str; psrt < pend; psrt++, pend--)
	{
		if (*psrt != *pend)
		{
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;

	return 0;
}