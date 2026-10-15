/* 2350222 盛曦 信12 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10
void input(char xuehao[N][8],char name[N][9],int score[10])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", xuehao[i], name[i], &score[i]);
	}
}
void range(char xuehao[N][8], char name[N][9], int score[10])//只有选择排序是稳定排序，可以保持两个相同数本来的顺序，冒泡不可以
{
	int i, j, k, n;
	int m;
	char chm;
	for (i = 0; i < N - 1; i++)
	{
		k = i;
		for (j = i + 1;j<N;j++)
		{
			for (n = 0; n < 8; n++)
			{
				if (xuehao[j][n] > xuehao[k][n])
				{
					k = j;
					break;
				}
			}
		}
		m = score[i];
		score[i] = score[k];
		score[k] = m;
		for (n = 0; n < 9; n++)
		{
			chm = name[i][n];
			name[i][n] = name[k][n];
			name[k][n] = chm;
		}
		for (n = 0; n < 8; n++)
		{
			chm = xuehao[i][n];
			xuehao[i][n] = xuehao[k][n];
			xuehao[k][n] = chm;
		}
	}
}
void output(char xuehao[N][8], char name[N][9], int score[10])
{
	int i;
	printf("\n及格名单(学号降序): \n");
	for (i = 0; i < N; i++)
	{
		if(score[i]>=60)
			printf("%s %s %d\n", name[i], xuehao[i], score[i]);
	}
}
int main()
{
	char name[N][9] = { '\0' };
	char xuehao[N][8] = { '\0' };
	int score[N] = { 0 };
	input(xuehao, name, score);
	range(xuehao, name, score);
	output(xuehao, name, score);
	return 0;
}