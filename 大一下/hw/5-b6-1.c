/*2350222 信12 盛曦*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num=0;
int topA=0, topB=0, topC=0;//top是栈中的第一个0
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };

void print_plate(char abc,int pole[], int top)
{
    printf("%c:",abc);
    for (int i = 0; i < top; i++)
        printf("%2d", pole[i]);
    int x = 21 - 2 * top;
    for(int i=0;i<x;i++)
        printf(" ");
}

void print_line()
{
    print_plate('A', A, topA);
    print_plate('B', B, topB);
    print_plate('C', C, topC);
    printf("\n");
}

int change_plate(char src,char dst)
{
    int m;
    switch ((int)(src))
    {
        case 'A':
        {
            m = A[--topA];
            A[topA] = 0;
            break;
        }
        case 'B':
        {
            m = B[--topB];
            B[topB] = 0;
            break;
        }
        case 'C':
        {
            m = C[--topC];
            C[topC] = 0;
            break;
        }
        default:
            m = -1;
            break;
    }
    switch ((int)(dst))
    {
        case 'A':
        {
            A[topA++] = m;
            break;
        }
        case 'B':
        {
            B[topB++] = m;
            break;
        }
        case 'C':
        {
            C[topC++] = m;
            break;
        }
        default:
            break;
    }
    return m;
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    printf("第%4d 步(%2d): %c-->%c ",++num, change_plate(src, dst),src,dst);
    print_line();
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n,ret,i;
    char src, dst, tmp;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret=scanf("%d",&n);
        while (getchar() != '\n')
            ;
        if (n >= 1 && n <= 10 && ret == 1)
            break;
    }

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
        while (getchar() != '\n')
            ;
        if (src > 90)
            src = (char)(src - 32);
        if ((src == 'A' || src == 'B' || src == 'C') && ret == 1)
            break;
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        while (getchar() != '\n')
            ;
        if (dst > 90)
            dst = (char)(dst - 32);
        if ((dst == 'A' || dst == 'B' || dst == 'C') && dst != src && ret == 1)
            break;
        else if (dst == src)
            printf("目标柱(%c)不能与起始柱(%c)相同\n",src,dst);
    }
    tmp = 'A' + 'B' + 'C' - src - dst;

    switch ((int)(src))
    {
        case 'A':
        {
            topA = n;
            for (i = 0; i < n; i++)
                A[i] = n - i;
            break;
        }
        case 'B':
        {
            topB = n;
            for (i = 0; i < n; i++)
                B[i] = n - i;
            break;
        }
        case 'C':
        {
            topC = n;
            for (i = 0; i < n; i++)
                C[i] = n - i;
            break;
        }
        default:
            break;
    }
    printf("初始:%16c", ' ');
    print_line();
    hanoi(n, src, tmp, dst);
    return 0;
}
