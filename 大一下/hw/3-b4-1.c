/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	const double pi = 3.14159;
	printf("请输入三角形的两边及其夹角（角度）\n");
	int a, b, c;
	scanf("%d %d %d",&a,&b,&c);
	printf("三角形面积为 : %.3f\n", (float)(a * b * sin(c * pi / 180) / 2));
	
	return 0;
}