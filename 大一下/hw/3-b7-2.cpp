/*2350222 信12 盛曦*/
#include <iostream>
using namespace std;

int main()
{
	double a;
	cout << "请输入找零值：" << endl;
	cin >> a;
	int fift=0, twen=0, ten=0, five=0, one=0, wuj=0, yij=0, wuf=0, erf=0, yif=0;
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
	one = int(a);
	int b= int((a - double(one)) * 100+0.5);
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
	int s= fift + twen + ten + five + one + wuj + yij + wuf + erf + yif ;
	cout << "共" << s << "张找零，具体如下：" << endl;
	if(fift!=0)
		cout << "50元 : " << fift << "张" << endl;
	if (twen != 0)
		cout << "20元 : " << twen << "张" << endl;
	if (ten != 0)
		cout << "10元 : " << ten << "张" << endl;
	if (five != 0)
		cout << "5元  : " << five << "张" << endl;
	if (one != 0)
		cout << "1元  : " << one << "张" << endl;
	if (wuj != 0)
		cout << "5角  : " << wuj << "张" << endl;
	if (yij != 0)
		cout << "1角  : " << yij << "张" << endl;
	if (wuf != 0)
		cout << "5分  : " << wuf << "张" << endl;
	if (erf != 0)
		cout << "2分  : " << erf << "张" << endl;
	if (yif != 0)
		cout << "1分  : " << yif << "张" << endl;
	return 0;
}