/*2350222 信12 盛曦*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) << float(a * b * sin(c * pi / 180) / 2) << endl;

	return 0;
}