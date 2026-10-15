/* 2350222 信12 盛曦 */
#include <iostream>
#include <cmath>
using namespace std;
#define acc 1e-6

void root_unequal(double delta, double a, double b)
{
	if (delta < acc)
		return;
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < acc)
		x1 = 0;
	if (fabs(x2) < acc)
		x2 = 0;
	if (x1 < x2)
	{
		double medium = x1;
		x1 = x2;
		x2 = medium;
	}
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}