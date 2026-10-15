/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int leap(int y)
{
	return (0 == y % 4 && 0 != y % 100 || 0 == y % 400) ? 29 : 28;
}

int days(int month[], int m, int d)
{
	int s=0;
	for (int i = 0; i < m - 1; i++)
		s += month[i];
	s += d;
	return s;
}

int main()
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, m, d;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &y, &m, &d);
	if (m <= 0 || m > 12)
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}
	month[1] = leap(y);
	if (d <= 0 || d > month[m-1])
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
	printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, days(month,m,d));
	return 0;
}