/* 2350222 信12 盛曦 */
#include <iostream>
using namespace std;
#define NUM 100

int main()
{
	int a[NUM];//可以定义为NUM+1，0不用，更方便
	int i, j, k;
	for (i = 0; i < NUM; i++)
		a[i] = -1;
	for (j = 1; j < NUM+1; j++)//j是人的编号
	{
		for (k = 0; k < NUM; k++)
		{
			if ((k+1) % j == 0)//k+1是灯的编号
				a[k] = -a[k];
		}
	}
	for (i = 0; i < NUM; i++)
	{
		if (a[i] == 1)
		{
			cout << i + 1;
			break;
		}	
	}
	i++;
	for (; i < NUM; i++)
	{
		if (a[i] == 1)
		{
			cout << " " << i + 1;
		}
	}
	cout << endl;
	return 0;
}