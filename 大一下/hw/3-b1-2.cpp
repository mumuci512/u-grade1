/*2350222 信12 盛曦*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	cout << "请输入半径和高度" << endl;
	double r, h;
	cin >> r >> h;
	cout << "圆周长     : " << setiosflags(ios::fixed) << setprecision(2) << 2 * pi * r << endl;
	cout << "圆面积     : " << pi * r * r << endl;
	cout << "圆球表面积 : " << 4 * pi * r * r << endl;
	cout << "圆球体积   : " << pi * r * r * r * 4 / 3 << endl;
	cout << "圆柱体积   : " << pi * r * r * h << endl;

	return 0;
}