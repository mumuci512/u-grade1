/*2350222 ÐÅ12 Ê¢êØ*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	double a;
	scanf("%lf", &a);
	int shiyi = (int)(a / 1e9);
	int yi = (int)(a / 1e8) % 10;
	int qianwan = (int)(a / 1e7) % 10;
	int baiwan = (int)(a / 1e6) % 10;
	int shiwan = (int)(a / 1e5) % 10;
	int wan = (int)(a / 1e4) % 10;
	int qian = (int)(a / 1e3) % 10;
	int bai = (int)(a / 1e2) % 10;
	int shi = (int)(a / 10) % 10;
	double b;
	b = (a - (double)((int)(a / 10)) * 10) * 100;
	int yuan = (int)((b + 0.5) / 100);
	int jiao = (int)(b + 0.5) % 100 / 10;
	int fen = (int)(b + 0.5) % 10;
	printf("´óÐ´½á¹ûÊÇ:\n");

	//Ê®ÒÚ-ÒÚ
	if (shiyi != 0)
	{
		switch (shiyi)
		{
			case 1:
				printf("Ò¼Ê°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 9:
				printf("¾ÁÊ°");
				break;
			default:
				break;
		}
	}
	if (yi != 0)
	{
		switch (yi)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
	}
	if (shiyi != 0 || yi != 0)
		printf("ÒÚ");

	//Ç§Íò-Íò
	if (qianwan != 0)
	{
		switch (qianwan)
		{
			case 1:
				printf("Ò¼Çª");
				break;
			case 2:
				printf("·¡Çª");
				break;
			case 3:
				printf("ÈþÇª");
				break;
			case 4:
				printf("ËÁÇª");
				break;
			case 5:
				printf("ÎéÇª");
				break;
			case 6:
				printf("Â½Çª");
				break;
			case 7:
				printf("ÆâÇª");
				break;
			case 8:
				printf("°ÆÇª");
				break;
			case 9:
				printf("¾ÁÇª");
				break;
			default:
				break;
		}
	}
	if (baiwan != 0)
	{
		if (0 == qianwan && (shiyi != 0 || yi != 0))
			printf("Áã");
		switch (baiwan)
		{
			case 1:
				printf("Ò¼°Û");
				break;
			case 2:
				printf("·¡°Û");
				break;
			case 3:
				printf("Èþ°Û");
				break;
			case 4:
				printf("ËÁ°Û");
				break;
			case 5:
				printf("Îé°Û");
				break;
			case 6:
				printf("Â½°Û");
				break;
			case 7:
				printf("Æâ°Û");
				break;
			case 8:
				printf("°Æ°Û");
				break;
			case 9:
				printf("¾Á°Û");
				break;
			default:
				break;
		}
	}
	if (shiwan != 0)
	{
		if (0 == baiwan && (shiyi != 0 || yi != 0 || qianwan != 0))
			printf("Áã");
		switch (shiwan)
		{
			case 1:
				printf("Ò¼Ê°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 9:
				printf("¾ÁÊ°");
				break;
			default:
				break;
		}
	}
	if (wan != 0)
	{
		if (0 == shiwan && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0))
			printf("Áã");
		switch (wan)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
	}
	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)
		printf("Íò");

	//Íòµ½¸÷Î»
	if (qian != 0)
	{
		switch (qian)
		{
			case 1:
				printf("Ò¼Çª");
				break;
			case 2:
				printf("·¡Çª");
				break;
			case 3:
				printf("ÈþÇª");
				break;
			case 4:
				printf("ËÁÇª");
				break;
			case 5:
				printf("ÎéÇª");
				break;
			case 6:
				printf("Â½Çª");
				break;
			case 7:
				printf("ÆâÇª");
				break;
			case 8:
				printf("°ÆÇª");
				break;
			case 9:
				printf("¾ÁÇª");
				break;
			default:
				break;
		}
	}
	if (bai != 0)
	{
		if (0 == qian && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0))
			printf("Áã");
		switch (bai)
		{
			case 1:
				printf("Ò¼°Û");
				break;
			case 2:
				printf("·¡°Û");
				break;
			case 3:
				printf("Èþ°Û");
				break;
			case 4:
				printf("ËÁ°Û");
				break;
			case 5:
				printf("Îé°Û");
				break;
			case 6:
				printf("Â½°Û");
				break;
			case 7:
				printf("Æâ°Û");
				break;
			case 8:
				printf("°Æ°Û");
				break;
			case 9:
				printf("¾Á°Û");
				break;
			default:
				break;
		}
	}
	if (shi != 0)
	{
		if (0 == bai && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0))
			printf("Áã");
		switch (shi)
		{
			case 1:
				printf("Ò¼Ê°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 9:
				printf("¾ÁÊ°");
				break;
			default:
				break;
		}
	}
	if (yuan != 0)
	{
		if (0 == shi && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0))
			printf("Áã");
		switch (yuan)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
	}
	if (!(0 == shiyi && 0 == yi && 0 == qianwan && 0 == baiwan && 0 == shiwan && 0 == wan && 0 == qian && 0 == bai && 0 == shi && 0 == yuan))
		printf("Ô²");
	else if (0 == jiao && 0 == fen)
			printf("ÁãÔ²");

	//½Ç·Ö
	if (jiao != 0)
	{
		switch (jiao)
		{
			case 1:
				printf("Ò¼½Ç");
				break;
			case 2:
				printf("·¡½Ç");
				break;
			case 3:
				printf("Èþ½Ç");
				break;
			case 4:
				printf("ËÁ½Ç");
				break;
			case 5:
				printf("Îé½Ç");
				break;
			case 6:
				printf("Â½½Ç");
				break;
			case 7:
				printf("Æâ½Ç");
				break;
			case 8:
				printf("°Æ½Ç");
				break;
			case 9:
				printf("¾Á½Ç");
				break;
			default:
				break;
		}
	}
	if (fen != 0)
	{
		if (0 == jiao && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0))
			printf("Áã");
		switch (fen)
		{
			case 1:
				printf("Ò¼·Ö");
				break;
			case 2:
				printf("·¡·Ö");
				break;
			case 3:
				printf("Èþ·Ö");
				break;
			case 4:
				printf("ËÁ·Ö");
				break;
			case 5:
				printf("Îé·Ö");
				break;
			case 6:
				printf("Â½·Ö");
				break;
			case 7:
				printf("Æâ·Ö");
				break;
			case 8:
				printf("°Æ·Ö");
				break;
			case 9:
				printf("¾Á·Ö");
				break;
			default:
				break;
		}
	}
	if (jiao != 0 && 0 == fen || 0 == jiao && 0 == fen)
		printf("Õû");

	printf("\n");
	return 0;
}
