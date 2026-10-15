/*2350222 信12 盛曦*/
#include <limits>
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (x >= 0 && x <= 100 && cin.good()==1)
			break;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
		}//若此if在上一个if之前，则需加continue，或者将两个if合并成if&else if
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}
