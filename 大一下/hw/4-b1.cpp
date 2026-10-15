/*2350222 信12 盛曦*/
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double a;
	cin >> a;
	int shiyi = int(a / 1e9);
	int yi = int(a / 1e8) % 10;
	int qianwan = int(a / 1e7) % 10;
	int baiwan = int(a / 1e6) % 10;
	int shiwan = int(a / 1e5) % 10;
	int wan = int(a / 1e4) % 10;
	int qian = int(a / 1e3) % 10;
	int bai = int(a / 1e2) % 10;
	int shi = int(a / 10) % 10;
	double b;
	b = (a - double(int(a / 10)) * 10) * 100;
	int yuan = int((b + 0.5) / 100);
	int jiao = int(b + 0.5) % 100 / 10;
	int fen = int(b + 0.5) % 10;
	cout << "大写结果是:" << endl;
	int flag_of_zero=0;

	//十亿-亿
	if (shiyi != 0)
	{
		daxie(shiyi, flag_of_zero);
		cout << "拾";
	}
	if (yi != 0)
		daxie(yi, flag_of_zero);
	if (shiyi + yi != 0)
		cout << "亿";

	//千万-万
	if (qianwan != 0 || qianwan==0 && baiwan==0)
		flag_of_zero = 0;
	else if(qianwan==0 && baiwan!=0 && shiyi+yi!=0)
		flag_of_zero = 1;
	daxie(qianwan, flag_of_zero);
	if (qianwan != 0)
		cout << "仟";
	
	if (baiwan != 0 || baiwan == 0 && shiwan == 0)
		flag_of_zero = 0;
	else if (baiwan == 0 && shiwan != 0 && shiyi+yi+qianwan!=0)
		flag_of_zero = 1;
	daxie(baiwan, flag_of_zero);
	if (baiwan != 0)
		cout << "佰";

	if (shiwan != 0 || shiwan == 0 && wan == 0)
		flag_of_zero = 0;
	else if (shiwan == 0 && wan != 0 && shiyi + yi + qianwan+baiwan != 0)
		flag_of_zero = 1;
	daxie(shiwan, flag_of_zero);
	if (shiwan != 0)
		cout << "拾";

	flag_of_zero = 0;
	daxie(wan, flag_of_zero);

	if(qianwan+baiwan+shiwan+wan!=0)
		cout << "万";

	//万到各位
	if (qian != 0 || qian == 0 && bai == 0)
		flag_of_zero = 0;
	else if (qian == 0 && bai != 0 && shiyi + yi + qianwan+baiwan +wan != 0)
		flag_of_zero = 1;
	daxie(qian, flag_of_zero);
	if (qian != 0)
		cout << "仟";

	if (bai != 0 || bai == 0 && shi == 0)
		flag_of_zero = 0;
	else if (bai == 0 && shi != 0 && shiyi + yi + qianwan + baiwan + wan+qian != 0)
		flag_of_zero = 1;
	daxie(bai, flag_of_zero);
	if (bai != 0)
		cout << "佰";

	if (shi!= 0 || shi == 0 && yuan == 0)
		flag_of_zero = 0;
	else if (shi == 0 && yuan != 0 && shiyi + yi + qianwan + baiwan + wan + qian+bai != 0)
		flag_of_zero = 1;
	daxie(shi, flag_of_zero);
	if (shi != 0)
		cout << "拾";

	flag_of_zero = 0;
	if(shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan+jiao+fen== 0)
		flag_of_zero = 1;
	daxie(yuan, flag_of_zero);

	if (shiyi +yi +qianwan +baiwan +shiwan +wan +qian +bai +shi +yuan !=0 || shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan + jiao + fen == 0)
		cout << "圆";

	//角分
	if (jiao != 0 || jiao == 0 && fen == 0)
		flag_of_zero = 0;
	else if (jiao == 0 && fen != 0 && shiyi + yi + qianwan + baiwan + wan + qian + bai+shi+yuan != 0)
		flag_of_zero = 1;
	daxie(jiao, flag_of_zero);
	if (jiao != 0)
		cout << "角";
	
	flag_of_zero = 0;
	daxie(fen, flag_of_zero);
	if (fen != 0)
		cout << "分";
	
	//
	if (0 == fen)
		cout << "整";

	cout << endl;
	return 0;
}