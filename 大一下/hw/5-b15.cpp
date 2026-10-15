/* 2350222 盛曦 信12 */
#include <iostream>
using namespace std;

void fuzhi(char ch[128])
{
	char m = getchar();
	int n = 0;
	while (m != '\n' && m != '\r'&&n<127)
	{
		ch[n] = m;
		m = getchar();
		n++;
	}
}
int main()
{
	char str[3][128] = { '\0' };
	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "请输入第"<<i+1<<"行" << endl;
		fuzhi(str[i]);
	}
	
	int j;
	int capital=0, xiaoxie=0, num=0, space=0, qita=0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 127; j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				capital++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				xiaoxie++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				num++;
			else if (str[i][j] == ' ')
				space++;
			else if(str[i][j]!='\0')
				qita++;
		}
	}
	cout << "大写 : " << capital << endl;
	cout << "小写 : " << xiaoxie << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << qita << endl;
	return 0;
}