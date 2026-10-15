/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a;
	printf("请输入找零值：\n");
	scanf("%lf",&a);
	int fift = 0, twen = 0, ten = 0, five = 0, one = 0, wuj = 0, yij = 0, wuf = 0, erf = 0, yif = 0;
	if (a >= 50)
	{
		fift++;
		a -= 50;
	}
	if (a >= 20)
	{
		twen++;
		a -= 20;
		if (a >= 20)
		{
			twen++;
			a -= 20;
		}
	}
	if (a >= 10)
	{
		ten++;
		a -= 10;
	}
	if (a >= 5)
	{
		five++;
		a -= 5;
	}
	one = (int)(a);
	int b = (int)((a - (double)(one)) * 100 + 0.5);
	if (b >= 50)
	{
		wuj++;
		b -= 50;
	}
	if (b >= 10)
	{
		yij++;
		b -= 10;
		if (b >= 10)
		{
			yij++;
			b -= 10;
			if (b >= 10)
			{
				yij++;
				b -= 10;
				if (b >= 10)
				{
					yij++;
					b -= 10;
				}
			}
		}
	}
	if (b >= 5)
	{
		wuf++;
		b -= 5;
	}
	if (b >= 2)
	{
		erf++;
		b -= 2;
		if (b >= 2)
		{
			erf++;
			b -= 2;
		}
	}
	yif = b;
	int s = fift + twen + ten + five + one + wuj + yij + wuf + erf + yif;
	printf("共%d张找零，具体如下：\n",s );
	if (fift != 0)
		printf("50元 : %d张\n",fift);
	if (twen != 0)
		printf("20元 : %d张\n",twen);
	if (ten != 0)
		printf("10元 : %d张\n",ten);
	if (five != 0)
		printf("5元  : %d张\n" ,five);
	if (one != 0)
		printf("1元  : %d张\n",one);
	if (wuj != 0)
		printf("5角  : %d张\n",wuj);
	if (yij != 0)
		printf("1角  : %d张\n",yij);
	if (wuf != 0)
		printf("5分  : %d张\n",wuf);
	if (erf != 0)
		printf("2分  : %d张\n",erf);
	if (yif != 0)
		printf("1分  : %d张\n",yif);
	return 0;
}
