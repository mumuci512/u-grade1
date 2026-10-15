/* 2350222 信12 盛曦 */
#include <iostream>
#include <cmath>
#include "4-b16.h"
using namespace std;
#define acc 1e-6

int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a;
	if (fabs(a) < acc)
		a = 0;
	if (condition1(a) == 0)
		return 0;
	cin >> b >> c;
	if (fabs(b) < acc)
		b = 0;
	if (fabs(c) < acc)
		c = 0;
	double delta = b * b - 4 * a * c;
	if (fabs(delta) < acc)
		delta = 0;
	root_unequal(delta, a, b);
	root_equal(delta, a, b);
	root_imaginary(delta, a, b);

	return 0;
}