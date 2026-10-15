/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入[0-100亿)之间的数字：\n");
	double a;
	scanf("%lf",&a);
	printf("十亿位 : %d\n", (int)(a / 1e9));
	printf("亿位   : %d\n", (int)(a / 1e8) % 10);
	printf("千万位 : %d\n", (int)(a / 1e7) % 10);
	printf("百万位 : %d\n", (int)(a / 1e6) % 10);
	printf("十万位 : %d\n", (int)(a / 1e5) % 10);
	printf("万位   : %d\n", (int)(a / 1e4) % 10);
	printf("千位   : %d\n", (int)(a / 1e3) % 10);
	printf("百位   : %d\n", (int)(a / 1e2) % 10);
	printf("十位   : %d\n", (int)(a / 10) % 10);
	double b;
	b = (a - (double)((int)(a / 10)) * 10) * 100;
	printf("圆     : %d\n", (int)((b + 0.5) / 100));
	printf("角     : %d\n", (int)(b + 0.5) % 100 / 10);
	printf("分     : %d\n", (int)(b + 0.5) % 10);

	return 0;
}
