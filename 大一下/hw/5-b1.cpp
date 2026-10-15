/* 2350222 信12 盛曦 */
#include <iostream>
using namespace std;
#define NUM 20
void output_array(int a[], int n)//n为输出的元素个数
{
	for (int i = 0; i <n ; i++)
		cout << a[i] << " ";
}

int main()
{
	int a[NUM+1];
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	int n=0;
	int m;
	while (n < NUM)
	{
		cin >> m;
		if (m <= 0)
		{
			if (n == 0)
			{
				cout << "无有效输入" << endl;
				return 0;
			}
			break;
		}
		else
			a[n] = m;
		n++;
	}//n为a中正数个数
	cin.clear();
	cin.ignore(1410065407, '\n');

	cout << "原数组为：" << endl;
	output_array(a, n);
	cout << endl;
	
	int insert;
	cout << "请输入要插入的正整数" << endl;
	cin >> insert;
	for (int j = 0; j < n; j++)
	{
		if (a[j] > insert)
		{
			for (int k = n; k > j; k--)
				a[k] = a[k - 1];
			a[j] = insert;
			break;
		}
	}
	cout << "插入后的数组为：" << endl;
	output_array(a, n + 1);
	cout << endl;
		
	return 0;
}
//从后往前比比较好，因为后面的肯定要后移