/* 2350222 信12 盛曦 */
#include <iostream>
#include <cmath>
using namespace std;
#define acc 1e-6
double a, b, c;

double condition1();
void root_unequal();
void root_equal();
void root_imaginary();


int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a;
	if (fabs(a) < acc)
		a = 0;
	if (condition1() == 0)
		return 0;
	cin >> b >> c;
	if (fabs(b) < acc)
		b = 0;
	if (fabs(c) < acc)
		c = 0;
	root_unequal();
	root_equal();
	root_imaginary();

	return 0;
}