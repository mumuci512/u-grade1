/*2350222 信12 盛曦*/
#include <stdio.h>

int zeller(int y, int m, int d)
{
	int w, y1, c, m1;
	if (m == 1 || m == 2)
	{
		y1 = (y - 1) % 100;
		c = (y - 1) / 100;
		m1 = 12 + m;
	}
	else
	{
		y1 = y % 100;
		c = y / 100;
		m1 = m;
	}
	w = y1 + y1 / 4 + c / 4 - 2 * c + 13 * (m1 + 1) / 5 + d - 1;
	for (; w < 0; w += 7)//weekday=(weekday%7+7)%7;
		;
	return w % 7;
}

int main()
{
	int y, m, d,max;
	while (1)
	{
		printf("请输入年[1900-2100]、月、日：\n");
		int ret1 = scanf("%d", &y);
		int ret2 = scanf("%d", &m);
		int ret3 = scanf("%d", &d);
		if (m <= 7 && m % 2 == 1 || 7 < m && m % 2 == 0)
			max = 31;
		else if (m != 2 && m < 7 && m % 2 == 0 || m>7 && m % 2 == 1)
			max = 30;
		else if ((0 == y % 4 && 0 != y % 100 || 0 == y % 400) && m == 2)
			max = 29;
		else
			max = 28;
		if (ret1 == 1 && ret2 == 1 && ret3 == 1)
		{
			if(y >= 1900 && y <= 2100 && m >= 1 && m <= 12 && d >= 1 && d <= max)
				break;
			else if (y < 1900 || y>2100)
				printf("年份不正确，请重新输入\n");
			else if (m < 1 || m>12)
				printf("月份不正确，请重新输入\n");
			else if (d<1 || d>max)
				printf("日不正确，请重新输入\n");
		}
		if (ret1 == 0 || ret2 == 0 || ret3 == 0)
		{
			printf("输入错误，请重新输入\n");
			while (getchar() != '\n')
				;
		}	
	}
	printf("星期");
	switch (zeller(y, m, d))
	{
		case 0:
			printf("日");
			break;
		case 1:
			printf("一");
			break;
		case 2:
			printf("二");
			break;
		case 3:
			printf("三");
			break;
		case 4:
			printf("四");
			break;
		case 5:
			printf("五");
			break;
		case 6:
			printf("六");
			break;
		default:
			break;
	}
	printf("\n");

	return 0;
}