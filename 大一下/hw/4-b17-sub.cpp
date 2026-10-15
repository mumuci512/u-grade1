/* 2350222 信12 盛曦 */
#include <iostream>
#include <cmath>
using namespace std;
#define acc 1e-6

extern double a, b, c;

double condition1()
{
	if (a == 0)
		cout << "不是一元二次方程" << endl;
	return a;
}

void root_unequal()
{
	double delta = b * b - 4 * a * c;
	if (fabs(delta) < acc)
		delta = 0;
	if (delta > 0)
	{
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
}

void root_equal()
{
	double delta = b * b - 4 * a * c;
	if (fabs(delta) < acc)
		delta = 0;
	if (delta == 0)
	{
		double x1 = -b / (2 * a);
		if (fabs(x1) < acc)
			x1 = 0;
		double x2 = x1;
		cout << "有两个相等实根：" << endl;
		cout << "x1=x2=" << x1 << endl;
	}
}

void root_imaginary()
{
	double delta = b * b - 4 * a * c;
	if (fabs(delta) < acc)
		delta = 0;
	if (delta < 0)
	{
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
}
