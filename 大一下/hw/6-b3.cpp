/* 2350222 盛曦 信12 */
#include <iostream>
using namespace std;

unsigned int B_to_D(char *p)
{
	unsigned int x = 0;
	for (; *p != '\0'; p++)
	{
		x = x * 2 + (*p) - '0';
	}
	return x;
}
int main()
{
	char str[33];
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	cout << B_to_D(str) << endl;
	return 0;
}