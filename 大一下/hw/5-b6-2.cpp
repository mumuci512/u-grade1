/* 2350222 信12 盛曦 */
#include <iostream>
#include <iomanip>
using namespace std;
int num = 0;
int top[3] = { 0 }, plate[3][11] = { 0 };

void print_line()
{
    int i, k;
    for (i = 0; i < 3; i++)
    {
        cout << char(i + 65) << ":";
        for (k = 0; k < 11; k++)
        {
            if (plate[i][k] == 0)
            {
                cout << setw(21 - 2 * k) << " ";
                break;
            }
            cout << setw(2) << plate[i][k];
        }
    }
    cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    plate[dst-65][top[dst-65]++] = plate[src - 65][--top[src - 65]];
    plate[src - 65][top[src - 65]] = 0;
    cout << "第" <<setw(4) << ++num << " 步(" << setw(2) << plate[dst - 65][top[dst - 65] - 1] << "): " << src << "-->" << dst << " ";
    print_line();
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n, i;
    char src, dst, tmp;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (n >= 1 && n <= 10 && cin.good() == 1)
            break;
    }

    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (src > 90)
            src = char(src - 32);
        if ((src == 'A' || src == 'B' || src == 'C' ) && cin.good() == 1)
            break;
    }

    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(1410065407, '\n');
        if (dst > 90)
            dst = char(dst - 32);
        if ((dst == 'A' || dst == 'B' || dst == 'C' ) && dst != src && cin.good() == 1)
            break;
        else if (dst == src)
            cout << "目标柱(" << src << ")不能与起始柱(" << dst << ")相同" << endl;
    }

    tmp = 'A' + 'B' + 'C' - src - dst;

    for (i = 0; i < n; i++)
        plate[src - 65][i] = n - i;
    top[src - 65] = n;
    cout << "初始:" << setw(16) << " ";
    print_line();
    hanoi(n, src, tmp, dst);
    return 0;
}
