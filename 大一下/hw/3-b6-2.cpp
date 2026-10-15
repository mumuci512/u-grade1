/*2350222 ĞÅ12 Ê¢êØ*/
#include <iostream>
using namespace std;

int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	double a;
	cin >> a;
	int shiyi=int(a / 1e9);
	int yi=int(a / 1e8) % 10;
	int qianwan =int(a / 1e7) % 10;
	int baiwan=int(a / 1e6) % 10;
	int shiwan=int(a / 1e5) % 10;
	int wan=int(a / 1e4) % 10;
	int qian=int(a / 1e3) % 10;
	int bai=int(a / 1e2) % 10;
	int shi=int(a / 10) % 10;
	double b;
	b = (a - double(int(a / 10)) * 10) * 100;
	int yuan=int((b + 0.5) / 100);
	int jiao=int(b + 0.5) % 100 / 10;
	int fen=int(b + 0.5) % 10;
	cout << "´óĞ´½á¹ûÊÇ:" << endl;

	//Ê®ÒÚ-ÒÚ
	if (shiyi != 0)
	{
		switch (shiyi)
		{
			case 1:
				cout << "Ò¼" << "Ê°";
				break;
			case 2:
				cout << "·¡" << "Ê°";
				break;
			case 3:
				cout << "Èş" << "Ê°";
				break;
			case 4:
				cout << "ËÁ" << "Ê°";
				break;
			case 5:
				cout << "Îé" << "Ê°";
				break;
			case 6:
				cout << "Â½" << "Ê°";
				break;
			case 7:
				cout << "Æâ" << "Ê°";
				break;
			case 8:
				cout << "°Æ" << "Ê°";
				break;
			case 9:
				cout << "¾Á" << "Ê°";
				break;
			default:
				break;
		}
	}
	if (yi!=0)
	{
		switch (yi)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
	}
	if (shiyi != 0 || yi != 0)
		cout << "ÒÚ";

	//Ç§Íò-Íò
	if (qianwan != 0)
	{
		switch (qianwan)
		{
			case 1:
				cout << "Ò¼" << "Çª";
				break;
			case 2:
				cout << "·¡" << "Çª";
				break;
			case 3:
				cout << "Èş" << "Çª";
				break;
			case 4:
				cout << "ËÁ" << "Çª";
				break;
			case 5:
				cout << "Îé" << "Çª";
				break;
			case 6:
				cout << "Â½" << "Çª";
				break;
			case 7:
				cout << "Æâ" << "Çª";
				break;
			case 8:
				cout << "°Æ" << "Çª";
				break;
			case 9:
				cout << "¾Á" << "Çª";
				break;
			default:
				break;
		}
	}
	if (baiwan != 0)
	{
		if (0 == qianwan &&(shiyi != 0 || yi != 0))
			cout << "Áã";
		switch (baiwan)
		{
			case 1:
				cout << "Ò¼" << "°Û";
				break;
			case 2:
				cout << "·¡" << "°Û";
				break;
			case 3:
				cout << "Èş" << "°Û";
				break;
			case 4:
				cout << "ËÁ" << "°Û";
				break;
			case 5:
				cout << "Îé" << "°Û";
				break;
			case 6:
				cout << "Â½" << "°Û";
				break;
			case 7:
				cout << "Æâ" << "°Û";
				break;
			case 8:
				cout << "°Æ" << "°Û";
				break;
			case 9:
				cout << "¾Á" << "°Û";
				break;
			default:
				break;
		}
	}
	if (shiwan != 0)
	{
		if(0==baiwan && (shiyi != 0 || yi != 0 || qianwan !=0))
			cout << "Áã";
		switch (shiwan)
		{
			case 1:
				cout << "Ò¼" << "Ê°";
				break;
			case 2:
				cout << "·¡" << "Ê°";
				break;
			case 3:
				cout << "Èş" << "Ê°";
				break;
			case 4:
				cout << "ËÁ" << "Ê°";
				break;
			case 5:
				cout << "Îé" << "Ê°";
				break;
			case 6:
				cout << "Â½" << "Ê°";
				break;
			case 7:
				cout << "Æâ" << "Ê°";
				break;
			case 8:
				cout << "°Æ" << "Ê°";
				break;
			case 9:
				cout << "¾Á" << "Ê°";
				break;
			default:
				break;
		}
	}
	if (wan != 0)
	{
		if(0==shiwan &&(shiyi != 0 || yi != 0 || qianwan!=0 || baiwan!=0))
			cout << "Áã";
		switch (wan)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
	}
	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)
		cout << "Íò";

	//Íòµ½¸÷Î»
	if (qian != 0)
	{
		switch (qian)
		{
			case 1:
				cout << "Ò¼" << "Çª";
				break;
			case 2:
				cout << "·¡" << "Çª";
				break;
			case 3:
				cout << "Èş" << "Çª";
				break;
			case 4:
				cout << "ËÁ" << "Çª";
				break;
			case 5:
				cout << "Îé" << "Çª";
				break;
			case 6:
				cout << "Â½" << "Çª";
				break;
			case 7:
				cout << "Æâ" << "Çª";
				break;
			case 8:
				cout << "°Æ" << "Çª";
				break;
			case 9:
				cout << "¾Á" << "Çª";
				break;
			default:
				break;
		}
	}
	if (bai != 0)
	{
		if (0 == qian &&(shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0))
			cout << "Áã";
		switch (bai)
		{
			case 1:
				cout << "Ò¼" << "°Û";
				break;
			case 2:
				cout << "·¡" << "°Û";
				break;
			case 3:
				cout << "Èş" << "°Û";
				break;
			case 4:
				cout << "ËÁ" << "°Û";
				break;
			case 5:
				cout << "Îé" << "°Û";
				break;
			case 6:
				cout << "Â½" << "°Û";
				break;
			case 7:
				cout << "Æâ" << "°Û";
				break;
			case 8:
				cout << "°Æ" << "°Û";
				break;
			case 9:
				cout << "¾Á" << "°Û";
				break;
			default:
				break;
		}
	}
	if (shi != 0)
	{
		if (0 == bai && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian!=0))
			cout << "Áã";
		switch (shi)
		{
			case 1:
				cout << "Ò¼" << "Ê°";
				break;
			case 2:
				cout << "·¡" << "Ê°";
				break;
			case 3:
				cout << "Èş" << "Ê°";
				break;
			case 4:
				cout << "ËÁ" << "Ê°";
				break;
			case 5:
				cout << "Îé" << "Ê°";
				break;
			case 6:
				cout << "Â½" << "Ê°";
				break;
			case 7:
				cout << "Æâ" << "Ê°";
				break;
			case 8:
				cout << "°Æ" << "Ê°";
				break;
			case 9:
				cout << "¾Á" << "Ê°";
				break;
			default:
				break;
		}
	}
	if (yuan != 0)
	{
		if (0 == shi && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian!=0 || bai!=0))
			cout << "Áã";
		switch (yuan)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
	}
	if (!(0 == shiyi && 0 == yi && 0 == qianwan && 0 == baiwan && 0 == shiwan && 0 == wan && 0 == qian && 0 == bai && 0 == shi && 0 == yuan))
		cout << "Ô²";
	else if(0==jiao && 0==fen)
		cout << "ÁãÔ²";

	//½Ç·Ö
	if (jiao != 0)
	{
		switch (jiao)
		{
			case 1:
				cout << "Ò¼" << "½Ç";
				break;
			case 2:
				cout << "·¡" << "½Ç";
				break;
			case 3:
				cout << "Èş" << "½Ç";
				break;
			case 4:
				cout << "ËÁ" << "½Ç";
				break;
			case 5:
				cout << "Îé" << "½Ç";
				break;
			case 6:
				cout << "Â½" << "½Ç";
				break;
			case 7:
				cout << "Æâ" << "½Ç";
				break;
			case 8:
				cout << "°Æ" << "½Ç";
				break;
			case 9:
				cout << "¾Á" << "½Ç";
				break;
			default:
				break;
		}
	}
	if (fen!= 0)
	{
		if (0 == jiao && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi!=0 || yuan!=0))
			cout << "Áã";
		switch (fen)
		{
			case 1:
				cout << "Ò¼" << "·Ö";
				break;
			case 2:
				cout << "·¡" << "·Ö";
				break;
			case 3:
				cout << "Èş" << "·Ö";
				break;
			case 4:
				cout << "ËÁ" << "·Ö";
				break;
			case 5:
				cout << "Îé" << "·Ö";
				break;
			case 6:
				cout << "Â½" << "·Ö";
				break;
			case 7:
				cout << "Æâ" << "·Ö";
				break;
			case 8:
				cout << "°Æ" << "·Ö";
				break;
			case 9:
				cout << "¾Á" << "·Ö";
				break;
			default:
				break;
		}
	}
	if (jiao != 0 && 0 == fen || 0 == jiao && 0 == fen)
		cout << "Õû";
	
	cout << endl;
	return 0;
}