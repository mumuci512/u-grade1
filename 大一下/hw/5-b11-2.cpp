/* 信12 2350222 盛曦 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int daxie(int num, int flag_of_zero, int weishu)//返回值为位数变化步长
{
	if (num == 0)
	{
		if (flag_of_zero)
		{
			result[weishu] = chnstr[num * 2];
			result[weishu + 1] = chnstr[num * 2 + 1];
		}
		else
			return 0;
	}
	else
	{
		result[weishu] = chnstr[num * 2];
		result[weishu + 1] = chnstr[num * 2 + 1];
	}
	return 2;
}
int prompt(int i, int weishu)//返回值为2，位数步长
{
	char prom[] = "拾佰仟万亿圆角分整";//长度18，每二个对应一个汉字
	result[weishu] = prom[i];
	result[weishu + 1] = prom[i + 1];
	return 2;
}
int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double a;
	cin >> a;
	int shiyi = (int)(a / 1e9);
	int yi = (int)(a / 1e8) % 10;
	int qianwan = (int)(a / 1e7) % 10;
	int baiwan = (int)(a / 1e6) % 10;
	int shiwan = (int)(a / 1e5) % 10;
	int wan = (int)(a / 1e4) % 10;
	int qian = (int)(a / 1e3) % 10;
	int bai = (int)(a / 1e2) % 10;
	int shi = (int)(a / 10) % 10;
	double b;
	b = (a - (double)((int)(a / 10)) * 10) * 100;
	int yuan = (int)((b + 0.5) / 100);
	int jiao = (int)(b + 0.5) % 100 / 10;
	int fen = (int)(b + 0.5) % 10;

	int flag_of_zero = 0;
	
	result.resize(256, '\0');
	int weishu = 0;
	//十亿-亿
	if (shiyi != 0)
	{
		weishu += daxie(shiyi, flag_of_zero, weishu);
		weishu += prompt(0, weishu);//拾
	}
	if (yi != 0)
		weishu += daxie(yi, flag_of_zero, weishu);
	if (shiyi + yi != 0)
		weishu += prompt(8, weishu);//亿

	//千万-万
	if (qianwan != 0 || qianwan == 0 && baiwan == 0)
		flag_of_zero = 0;
	else if (qianwan == 0 && baiwan != 0 && shiyi + yi != 0)
		flag_of_zero = 1;
	weishu += daxie(qianwan, flag_of_zero, weishu);
	if (qianwan != 0)
		weishu += prompt(4, weishu);//仟


	if (baiwan != 0 || baiwan == 0 && shiwan == 0)
		flag_of_zero = 0;
	else if (baiwan == 0 && shiwan != 0 && shiyi + yi + qianwan != 0)
		flag_of_zero = 1;
	weishu += daxie(baiwan, flag_of_zero, weishu);
	if (baiwan != 0)
		weishu += prompt(2, weishu);//佰

	if (shiwan != 0 || shiwan == 0 && wan == 0)
		flag_of_zero = 0;
	else if (shiwan == 0 && wan != 0 && shiyi + yi + qianwan + baiwan != 0)
		flag_of_zero = 1;
	weishu += daxie(shiwan, flag_of_zero, weishu);
	if (shiwan != 0)
		weishu += prompt(0, weishu);//拾

	flag_of_zero = 0;
	weishu += daxie(wan, flag_of_zero, weishu);

	if (qianwan + baiwan + shiwan + wan != 0)
		weishu += prompt(6, weishu);//万

	//万到各位
	if (qian != 0 || qian == 0 && bai == 0)
		flag_of_zero = 0;
	else if (qian == 0 && bai != 0 && shiyi + yi + qianwan + baiwan + wan != 0)
		flag_of_zero = 1;
	weishu += daxie(qian, flag_of_zero, weishu);
	if (qian != 0)
		weishu += prompt(4, weishu);//仟

	if (bai != 0 || bai == 0 && shi == 0)
		flag_of_zero = 0;
	else if (bai == 0 && shi != 0 && shiyi + yi + qianwan + baiwan + wan + qian != 0)
		flag_of_zero = 1;
	weishu += daxie(bai, flag_of_zero, weishu);
	if (bai != 0)
		weishu += prompt(2, weishu);//佰

	if (shi != 0 || shi == 0 && yuan == 0)
		flag_of_zero = 0;
	else if (shi == 0 && yuan != 0 && shiyi + yi + qianwan + baiwan + wan + qian + bai != 0)
		flag_of_zero = 1;
	weishu += daxie(shi, flag_of_zero, weishu);
	if (shi != 0)
		weishu += prompt(0, weishu);//拾

	flag_of_zero = 0;
	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan + jiao + fen == 0)
		flag_of_zero = 1;
	weishu += daxie(yuan, flag_of_zero, weishu);

	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan != 0 || shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan + jiao + fen == 0)
		weishu += prompt(10, weishu);//圆

	//角分
	if (jiao != 0 || jiao == 0 && fen == 0)
		flag_of_zero = 0;
	else if (jiao == 0 && fen != 0 && shiyi + yi + qianwan + baiwan + wan + qian + bai + shi + yuan != 0)
		flag_of_zero = 1;
	weishu += daxie(jiao, flag_of_zero, weishu);
	if (jiao != 0)
		weishu += prompt(12, weishu);//角

	flag_of_zero = 0;
	weishu += daxie(fen, flag_of_zero, weishu);
	if (fen != 0)
		weishu += prompt(14, weishu);//分

	//
	if (0 == fen)
		weishu += prompt(16, weishu);//整

	cout << "大写结果是:" << endl;
	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}