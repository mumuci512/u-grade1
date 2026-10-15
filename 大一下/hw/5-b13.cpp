/* ÐÅ12 2350222 Ê¢êØ */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
#define MAX_X 26
#define MAX_Y 10

void edge(char mine[MAX_Y][MAX_X],char drc)
{
	int x, y, i, j;
	int imin=-1, imax=1, jmin=-1, jmax=1;
	switch (drc)
	{
		case'l'://×ó±ßÔµ
			x = 0;
			jmin = 0;
			break;
		case 'r'://ÓÒ±ßÔµ
			x = MAX_X-1;
			jmax = 0;
			break;
		case 'u'://ÉÏ±ßÔµ
			y = 0;
			imin = 0;
			break;
		case 'd'://ÏÂ±ßÔµ
			y = MAX_Y-1;
			imax = 0;
			break;
		default:
			break;
	}
	if (drc == 'l' || drc == 'r')
	{
		for (y = 1; y < MAX_Y - 1; y++)
		{
			if (mine[y][x] == '*')
			{
				continue;
			}
			else
			{
				mine[y][x] = '0';
				for (i = imin; i <= imax; i++)
				{
					for (j = jmin; j <= jmax; j++)
					{
						if (j == 0 && i == 0)
						{
							continue;
						}
						else
						{
							if (mine[y + i][x + j] == '*')
							{
								mine[y][x]++;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		for (x = 1; x < MAX_X - 1; x++)
		{
			if (mine[y][x] == '*')
			{
				continue;
			}
			else
			{
				mine[y][x] = '0';
				for (i = imin; i <= imax; i++)
				{
					for (j = jmin; j <= jmax; j++)
					{
						if (j == 0 && i == 0)
						{
							continue;
						}
						else
						{
							if (mine[y + i][x + j] == '*')
							{
								mine[y][x]++;
							}
						}
					}
				}
			}
		}
	}
}
void corner(char mine[MAX_Y][MAX_X], int drc)
{
	int x = 0, y = 0;
	int i, j;
	int imin = -1, imax = 1, jmin = -1, jmax = 1;
	switch (drc)
	{
		case 1://×óÉÏ½Ç
			imin = 0; 
			jmin = 0;
			break;
		case 2://ÓÒÉÏ½Ç
			x = MAX_X-1;
			imin = 0;
			jmax = 0;
			break;
		case 3://×óÏÂ½Ç
			y = MAX_Y-1;
			imax = 0;
			jmin = 0;
			break;
		case 4://ÓÒÏÂ½Ç
			x = MAX_X-1;
			y = MAX_Y-1;
			imax = 0;
			jmax = 0;
			break;
		default:
			break;
	}
	if (mine[y][x] != '*')
	{
		mine[y][x] = '0';
		for (i = imin; i <= imax; i++)
		{
			for (j = jmin; j <= jmax; j++)
			{
				if (i == 0 && j == 0)
					continue;
				if (mine[y+i][x + j] == '*')
					mine[y][x]++;
			}
		}
	}
}
int main()
{
	char mine[MAX_Y][MAX_X] = { '\0' };
	int i,j,x,y;
	srand((unsigned int)(time(0)));
	for (i = 0; i < 50; i++)
	{
		x = rand() % MAX_X;
		y = rand() % MAX_Y;
		if (mine[y][x] != '*')
		{
			mine[y][x] = '*';
		}
		else
		{
			i--;
		}
	}
	//ÏÈÅÐ¶Ï²»ÊÇ±ßÔµµÄ
	for (y = 1; y < MAX_Y-1; y++)
	{
		for (x = 1; x < MAX_X-1; x++)
		{
			if (mine[y][x] == '*')
			{
				continue;
			}
			else
			{
				mine[y][x] = '0';
				for (i = -1; i <= 1; i++)
				{
					for (j = -1; j <= 1; j++)
					{
						if (j == 0 && i == 0)
						{
							continue;
						}
						else
						{
							if (mine[y + i][x + j] == '*')
							{
								mine[y][x]++;
							}
						}
					}
				}
			}
		}
	}
	//±ßÔµ
	edge(mine, 'l');
	edge(mine, 'r');
	edge(mine, 'u');
	edge(mine, 'd');
	//ËÄ¸ö½Ç
	corner(mine, 1);
	corner(mine, 2);
	corner(mine, 3);
	corner(mine, 4);

	for (i = 0; i < MAX_Y; i++)
	{
		for (j = 0; j < MAX_X; j++)
		{
			cout << mine[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
