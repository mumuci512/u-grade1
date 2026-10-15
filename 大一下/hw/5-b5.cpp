/* 2350222 信12 盛曦 */
#include <iostream>
using namespace std;
#define NUM 1000

int main()
{
	int a[NUM] = { 0 };
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int n, i,j;
	for (n = 0; n < NUM; n++)
	{
		cin >> a[n];
		if (a[n] < 0)
			break;
	}//n表示a中分数的个数
	if (a[0] < 0)
	{
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] <<" ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	if (i % 10 != 0)
		cout << endl;

	int score[101] = { 0 };
	for (i = 0; i < n; i++)
		score[a[i]]++;//score[x]存储的是分数x的个数

	int rank=0;
	cout << "分数与名次的对应关系为:" << endl;
	for (i = 100; i >= 0; i--)
	{
		if (score[i] != 0)
		{
			for(j=0;j<score[i];j++)
				cout << i << " " << rank + 1 << endl;
			rank += score[i];
		}
	}

	return 0;
}
//法一：定义两个变量，一个rank用于记录名次，一个count用于记录人数（可记录同名次的人数）
//法二：先不管同名次的，就这么排，然后再从高到低依次与上一个比，若和上一个成绩一样则名次等于上一个