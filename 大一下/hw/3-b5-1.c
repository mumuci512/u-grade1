/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int y, m, d;
	printf("请输入年，月，日\n");
	scanf("%d %d %d",&y,&m,&d);
	int s = 0;
	if (0 < m && m <= 12)
	{
		if (1 == m % 2)
		{
			if (1 <= d && d <= (m <= 7 ? 31 : 30))
				s = (m - 1) / 2 * (30 + 31) + (m <= 7 ? 0 : 1) + d;
			else
				printf("输入错误-日与月的关系非法\n");
		}
		else
		{
			if (2 == m)
			{
				if (1 <= d && d <= ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) ? 29 : 28))
					s = 31 + d;
				else
					printf("输入错误-日与月的关系非法\n");
			}
			else
			{
				if (1 <= d && d <= (30 + (m <= 6 ? 0 : 1)))
					s = m / 2 * (31 + 30) - 30 + d;
				else
					printf("输入错误-日与月的关系非法\n");
			}
		}
		if (m > 2)
			s = s - ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) ? 1 : 2);
		if (s > 0)
			printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, s);
	}
	else
		printf("输入错误-月份不正确\n");
	return 0;
}