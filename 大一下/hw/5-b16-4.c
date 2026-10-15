/* 2350222 盛曦 信12 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10
void input(char xuehao[N][8], char name[N][9], int score[10])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", xuehao[i], name[i], &score[i]);
	}
}
void range(char xuehao[N][8], char name[N][9], int score[10])
{
	int i, j,n;
	int m;
	char chm;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (score[j] < score[j + 1])
			{
				m = score[j];
				score[j] = score[j + 1];
				score[j + 1] = m;
				for (n = 0; n < 9; n++)
				{
					chm = name[j][n];
					name[j][n] = name[j+1][n];
					name[j+1][n] = chm;
				}
				for (n = 0; n < 8; n++)
				{
					chm = xuehao[j][n];
					xuehao[j][n] = xuehao[j+1][n];
					xuehao[j+1][n] = chm;
				}
			}
		}
	}
}
void output(char xuehao[N][8], char name[N][9], int score[10])
{
	int i;
	printf("\n全部学生(成绩降序): \n");
	for (i = 0; i < N; i++)
	{
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