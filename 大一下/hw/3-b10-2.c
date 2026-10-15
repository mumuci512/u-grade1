/*2350222 信12 盛曦*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int s = 0;
	for (int a1 = 1; a1 < 10; a1++)
	{
		for (int a2 = 1; a2 < 10; a2++)
		{
			if (a2 != a1)
			{
				for (int a3 = 1; a3 < 10; a3++)
				{
					if ((a3 != a2) && (a3 != a1))
					{
						for (int b1 = a1 + 1; b1 < 10; b1++)
						{
							if ((b1 != a2) && (b1 != a3))
							{
								for (int b2 = 1; b2 < 10; b2++)
								{
									if ((b2 != a1) && (b2 != a2) && (b2 != a3) && (b2 != b1))
									{
										for (int b3 = 1; b3 < 10; b3++)
										{
											if ((b3 != b2) && (b3 != a1) && (b3 != a2) && (b3 != a3) && (b3 != b1))
											{
												for (int c1 = b1 + 1; c1 < 10; c1++)
												{
													if ((c1 != b3) && (c1 != b2) && (c1 != a3) && (c1 != a2))
													{
														for (int c2 = 1; c2 < 10; c2++)
														{
															if ((c2 != c1) && (c2 != b3) && (c2 != b2) && (c2 != b1) && (c2 != a3) && (c2 != a2) && (c2 != a1))
															{
																for (int c3 = 1; c3 < 10; c3++)
																{
																	if ((c3 != c2) && (c3 != c1) && (c3 != b3) && (c3 != b2) && (c3 != b1) && (c3 != a3) && (c3 != a2) && (c3 != a1))
																	{
																		if ((a1 + b1 + c1) * 100 + (a2 + b2 + c2) * 10 + a3 + b3 + c3 == 1953)
																		{
																			s++;
																			if (s < 10)
																				printf("No.  %d : %d+%d+%d=1953\n", s, a1 * 100 + a2 * 10 + a3, b1 * 100 + b2 * 10 + b3, c1 * 100 + c2 * 10 + c3);
																			else if (s < 100)
																				printf("No. %d : %d+%d+%d=1953\n", s, a1 * 100 + a2 * 10 + a3, b1 * 100 + b2 * 10 + b3, c1 * 100 + c2 * 10 + c3);
																			else
																				printf("No.%d : %d+%d+%d=1953\n", s, a1 * 100 + a2 * 10 + a3, b1 * 100 + b2 * 10 + b3, c1 * 100 + c2 * 10 + c3);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("total=%d\n", s);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}