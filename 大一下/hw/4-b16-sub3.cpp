/* 2350222 信12 盛曦 */
#include <iostream>
#include <cmath>
using namespace std;
#define acc 1e-6
void root_equal(double delta, double a, double b)
{
	if (fabs(delta) >= acc)
		return;
	double x1 = -b / (2 * a);
	if (fabs(x1) < acc)
		x1 = 0;
	double x2 = x1;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x1 << endl;
}