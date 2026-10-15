/* 2350222 盛曦 信12 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	gets_s(str);
	is_num = false;
	pa = a;
	p = str;
	while ( *p != '\0'&&pa-10<a)
	{
		if (*p >= '0' && *p <= '9')
		{
			if (is_num == true)//上一个是数字,这一个也是数字
			{
				*pa = (*pa) * 10 + *p-'0';				
			}
			else//上一个不是数字，这一个是数字
			{
				*pa = *p - '0';
			}
			is_num = true;
			p++;
			if (*p < '0' || *p > '9')//这一个是数字，下一个不是（包括下一个是\0）,pa要移动
			{
				pa++;
			}
		}
		else
		{
			is_num = false;
			p++;
		}
	}//退出循环时pa指向a中最后一个数字的下一个位置
	cout << "共有" << pa - a << "个整数" << endl;
	for (pnum = a; pnum < pa; pnum++)
	{
		cout << *pnum << " ";
	}
	cout << endl;
	return 0;
}