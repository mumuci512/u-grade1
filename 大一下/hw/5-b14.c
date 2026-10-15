/* 信12 2350222 盛曦 */
/* 2351880 郑淑涵 2351043 国芳铭 2352993 于伊莲 2352850 陈斯媛 2350223 戴昊晟 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_X 26
#define MAX_Y 10

int main()
{
	char mine[MAX_Y][MAX_X] = { '\0' };
	int i, j;

	char m;
	int count=0;//计算多少个雷
	for (i = 0; i < MAX_Y; i++)
	{
		j = 0;
		while (j < MAX_X)
		{
			m = getchar();
			if (m != '\n' && m != '\r' && m != ' ')
			{
				mine[i][j] = m;
				if (mine[i][j] == '*')
					count++;
				j++;
			}
		}
	}
	/*for (i = 0; i < MAX_Y; i++)
	{
		for (j = 0; j < MAX_X; j++)
			printf("%c ", mine[i][j]);
		printf("\n");
	}*/
	if (count != 50)
	{
		//printf("%d", count);
		printf("错误1\n");
		return 0;
	}
	int p, q;
	char count2 = 0;//计算一个格子周围有几个雷,因为要和mine中元素比较，所以为char型
	for (i = 0; i < MAX_Y; i++)
	{
		for (j = 0; j < MAX_X; j++)
		{
			if (mine[i][j] != '*')
			{
				count2 = '0';
				for (p = -1; p <= 1; p++)//周围九宫循环
				{
					for (q = -1; q <= 1; q++)
					{
						if ((p != 0 || q != 0) && 0 <= i + p && i + p < MAX_Y && 0 <= j + q && j + q < MAX_X)
						{
							if (mine[i + p][j + q] == '*')
							{
								count2++;
							}
						}
					}
				}
				if (count2 != mine[i][j])
				{
					//printf("mine[i][j]：%c i:%d j:%d count2:%c", mine[i][j], i, j,count2);
					printf("错误2\n");
					return 0;
				}
			}
		}
	}
	printf("正确\n");
	return 0;
}