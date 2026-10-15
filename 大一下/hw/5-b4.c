/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 1000

int main()
{
	int a[NUM] = { 0 };
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int n,m,i;
	for (n = 0; n < NUM; n++)
	{
		scanf("%d", &m);
		if (m >= 0)
			a[n] = m;
		else
			break;
	}//n表示a中分数的个数
	if (a[0] < 0)
	{
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	if(i%10!=0)
		printf("\n");

	int score[101] = { 0 };
	for (i = 0; i <n; i++)
		score[a[i]]++;//score[x]存储的是分数x的个数

	printf("分数与人数的对应关系为:\n");
	for (i = 100; i >= 0; i--)
	{
		if(score[i]!=0)
			printf("%d %d\n", i, score[i]);
	}

	return 0;
}