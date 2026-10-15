/* 2350222 盛曦 信12 */
#include <iostream>
#include <cstring>
using namespace std;
#define N 10

void input(string xuehao[N], string name[N], int score[10])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> xuehao[i];
		cin >> name[i];
		cin >> score[i];
	}
}
void range(string xuehao[N], string name[N], int score[10])
{
	int i, j;
	int m;
	string chm;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (xuehao[j] > xuehao[j + 1])
			{
				m = score[j];
				score[j] = score[j + 1];
				score[j + 1] = m;
				chm = name[j];
				name[j] = name[j + 1];
				name[j + 1] = chm;
				chm = xuehao[j];
				xuehao[j] = xuehao[j + 1];
				xuehao[j + 1] = chm;
			}
		}
	}
}
void output(string xuehao[N], string name[N], int score[10])
{
	int i;
	cout << endl << "全部学生(学号升序): " << endl;
	for (i = 0; i < N; i++)
	{
		cout << name[i] << " " << xuehao[i] << " " << score[i] << endl;
	}
}
int main()
{
	string name[N];
	string xuehao[N];
	int score[N] = { 0 };
	input(xuehao, name, score);
	range(xuehao, name, score);
	output(xuehao, name, score);
	return 0;
}