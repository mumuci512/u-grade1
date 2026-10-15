/*2350222 信12 盛曦*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int x;
    int n = 1;
    bool a = true;
    double t = 1, m=0, e = 1,mi;
    while (a)
    {
        cout << "请输入x的值[-10 ~ +65]" << endl;
        cin >> x;
        if (x >= -10 && x <= 65)
        {
            a = false;
            mi = 1;
            while (fabs(mi*x / t) >= 1e-6)
            {
                mi = 1;
                for (int i = 1; i <= n; i++)//不好，从头乘一边效率太低，误差大
                    mi *= x;
                m = mi / t;
                e = e + m;
                t*=++n;
            }
            cout << "e^" << x << "=" << setprecision(10) << e << endl;
        }
        else
        {
            cout << "输入非法，请重新输入" << endl;
        }
    }
    return 0;
}
