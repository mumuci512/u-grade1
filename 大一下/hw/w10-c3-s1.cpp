/* 盛曦 2350222 信12 */
#include <iostream>
using namespace std;

int main() {
    cout << "请输入数据的个数[1..10000]" << std::endl;
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符，以便后续使用getchar

    char num[999999]; 
    int total = 0; 

    cout << "请输入" << n << "个正整数" << endl;
    char ch;
    int jishu = 0;

    while (jishu < n && total < 999999) 
    {
        ch = getchar();
        if (ch == ' ' || ch == '\n') 
        {
            jishu++; 
        }
        else 
        {
            num[total++] = ch; 
        }
    }

    cout << "请输入数码[0..9]" << std::endl;
    char d = getchar(); 

    int s = 0;
    for (int i = 0; i < total; i++) {
        if (num[i] == d) {
            s++;
        }
    }
    cout << n << "个数中含有" << d << "的个数 : " << s << endl;
    return 0;
}
