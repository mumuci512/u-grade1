/* 2350222 盛曦 信12 */
#include <iostream>
using namespace std;

int main()
{
	while (getchar() != '\n')//清空第一行
		;
	int len, cap, low, num, oth;
	cin >> len>> cap>> low>> num>> oth;
	if (len < 12 || len>16)
	{
		cout << "错误" << endl;
		return 0;
	}
	if (cap<2 || cap>len)
	{
		cout << "错误" << endl;
		return 0;
	}
	if (low<2 || low>len)
	{
		cout << "错误" << endl;
		return 0;
	}
	if (num<2 || num>len)
	{
		cout << "错误" << endl;
		return 0;
	}
	if (oth<2 || oth>len)
	{
		cout << "错误" << endl;
		return 0;
	}
	if (cap + low + num + oth > len)
	{
		cout << "错误" << endl;
		return 0;
	}
	int i,j,k;
	int capi=0, lowe=0, numb=0, othe=0;
	char code[16] = { '\0' };//不考虑长度超过16
	char m;
	//int flag=0;//用于记录是否有非法字符出现,0表示有非法字符
	static const char other[] = "!@#$%^&*-_=+,.?";
	getchar();//吸收上一行的回车
	for (i = 0; i < 10; i++)//10行
	{
		m = getchar();
		j = 0;
		capi = 0;
		lowe = 0;
		numb = 0;
		othe = 0;
		while (m != '\n' && m != '\r')
		{
			code[j] = m;
			if (code[j] >= 'A' && code[j] <= 'Z')
			{
				capi++;
			}
			else if (code[j] >= 'a' && code[j] <= 'z')
			{
				lowe++;
			}
			else if (code[j] >= '0' && code[j] <= '9')
			{
				numb++;
			}
			else
			{
				for (k = 0; k < 15; k++)
				{
					if (code[j] == other[k])
					{
						othe++;
						/*flag = 1;*/
					}
				}
				/*if (flag == 0)
				{
					cout << "错误" << endl;
					return 0;
				}*/
			}
			if(code[j]!='\0')
				j++;//不论字符是否合法，j都要++，因为j表示字符串总长度
			m = getchar();
		}
		if (j!=len)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (capi<cap || capi>len-low-num-oth)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (lowe<low || lowe>len-cap-num-oth)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (numb<num || numb>len-cap-low-oth)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (othe<oth || othe>len-cap-low-num)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (capi + lowe + numb + othe != len)
		{
			cout << "错误" << endl;
			return 0;
		}
	}
	cout << "正确" << endl;
	return 0;
}