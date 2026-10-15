/*2350222 信12 盛曦*/
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入[0-100亿)之间的数字：" << endl;
	double a;
	cin >> a;
	cout << "十亿位 : " << int(a / 1e9) << endl;
	cout << "亿位   : " << int(a / 1e8) % 10 << endl;
	cout << "千万位 : " << int(a / 1e7) % 10 << endl;
	cout << "百万位 : " << int(a / 1e6) % 10 << endl;
	cout << "十万位 : " << int(a / 1e5) % 10 << endl;
	cout << "万位   : " << int(a / 1e4) % 10 << endl;
	cout << "千位   : " << int(a / 1e3) % 10 << endl;
	cout << "百位   : " << int(a / 1e2) % 10 << endl;
	cout << "十位   : " << int(a/10) % 10 << endl;
	double b;
	b = (a -double(int(a / 10))*10) * 100;
	cout << "圆     : " << int((b+0.5)/100) << endl;
	cout << "角     : " << int(b+0.5)%100/10 << endl;
	cout << "分     : " << int(b+0.5)%10 << endl;
	return 0;
}
