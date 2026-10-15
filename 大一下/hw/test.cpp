#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	for (int i = 2; i <= 201; i++)
	{
		cout << "get_input_data td5-10.txt " << i << " | 5-b10 >> rst.txt" << endl;
	}
	return 0;
}
//void input_pure_decimal(int pure_decimal[])
//{
//	int flag, i;
//	char ch_pure_decimal[N_NUM + 1];
//	cout << "请输入一个二进制纯小数，小数点开头，小数点后不超过112位(例：.101101)" << endl;
//	while (1)
//	{
//		for (i = 0; i < N_NUM; i++)
//			pure_decimal[i] = 0;
//		flag = 1;//用于记录当前状态是否需要重新输入，输入不是0/1时，flag置零，需回到这里重新输入
//		ch_pure_decimal[0] = _getche();
//		if (ch_pure_decimal[0] == '.')
//		{
//			ch_pure_decimal[1] = _getche();
//			if (ch_pure_decimal[1] == '\n' || ch_pure_decimal[1] == '\r')
//			{
//				cout << "." << endl;//人工回显
//				cout << "输入数据为空，请重输" << endl;
//				continue;
//			}
//			else if (ch_pure_decimal[1] != '0' && ch_pure_decimal[1] != '1')
//			{
//				while (getchar() != '\n')
//					;
//				cout << "输入的不是0/1，请重输" << endl;
//				continue;
//			}
//			else
//			{
//				pure_decimal[0] = int(ch_pure_decimal[1]) - '0';
//				for (i = 2; i <= N_NUM; i++)
//				{
//					ch_pure_decimal[i] = getchar();
//					if (ch_pure_decimal[i] != '\n' && ch_pure_decimal[i] != '\r')
//					{
//						if (ch_pure_decimal[i] != '0' && ch_pure_decimal[i] != '1')
//						{
//							cout << "输入的不是0/1，请重输" << endl;
//							flag = 0;
//							while (getchar() != '\n')
//								;
//							break;
//						}
//						pure_decimal[i - 1] = int(ch_pure_decimal[i]) - '0';
//					}
//					else
//						break;
//				}
//			}
//			if (flag == 0)
//				continue;
//			break;
//		}
//		else
//		{
//			if (ch_pure_decimal[0] != '\n' && ch_pure_decimal[0] != '\r')
//			{
//				while (getchar() != '\n')
//					;
//			}
//			else
//				cout << endl;//若直接输入回车，需要人工回显
//			cout << "不是以.开头，请重输" << endl;
//		}
//	}
//}