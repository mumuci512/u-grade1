/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int y, m, d;

	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		int ret1=scanf("%d", &y);
		int ret2=scanf("%d", &m);
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12 && ret1 == 1 && ret2==1)
			break;
		printf("输入非法，请重新输入\n");
		if (ret1 == 0 || ret2 ==0)
			while (getchar() != '\n')
				;
	}
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",y,m);
		int ret3=scanf("%d",&d);
		if (d >= 0 && d <= 6 && ret3 == 1)
			break;
		printf("输入非法，请重新输入\n");
		if (ret3 == 0)
			while (getchar() != '\n')
				;
	}
	printf("\n%d年%d月的月历为:\n星期日  星期一  星期二  星期三  星期四  星期五  星期六\n",y,m);
	int max;

	if (m <= 7 && m % 2 == 1 || 7 < m && m % 2 == 0)
		max = 31;
	else if (m != 2 && m < 7 && m % 2 == 0 || m>7 && m % 2 == 1)
		max = 30;
	else if ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) && m == 2)
		max = 29;
	else
		max = 28;

	int s = 8 - d;
	for (int j = 0; j < d; j++)
		printf("        ");
	for (int t = 1; t <= (7 - d); t++)
		printf("%4d    ",t);
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			printf("%4d    ", s);
			s++;
			if (s == max + 1 && k != 6)
				break;
			else if (s == max + 1 && k == 6)
			{
				printf("\n");
				break;
			}
		}
		printf("\n");
		if (s == max + 1)
			break;
	}
	return 0;
}