/* 2350222 信12 盛曦 */
#include <iostream>
#include <cmath>
using namespace std;
#define acc 1e-6
void root_imaginary(double delta, double a, double b)
{
	if (delta > -acc)
		return;
	double real = -b / (2 * a);
	double imaginary = fabs(sqrt(-delta) / (2 * a));
	if (fabs(real) < acc)
		real = 0;
	if (fabs(imaginary) < acc)
		imaginary = 0;
	cout << "有两个虚根：" << endl;
	cout << "x1=";
	if (fabs(real) >= acc)
		cout << real << "+";
	if (fabs(imaginary) >= acc)
	{
		if (fabs(imaginary - 1) >= acc)
			cout << imaginary;
		cout << "i" << endl;
	}
	cout << "x2=";
	if (fabs(real) >= acc)
		cout << real;
	if (fabs(imaginary) >= acc)
	{
		cout << "-";
		if (fabs(imaginary - 1) >= acc)
			cout << imaginary;
		cout << "i" << endl;
	}
}