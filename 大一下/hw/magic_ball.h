#pragma once

#define YMIN 5
#define YMAX 9
#define XMIN 5
#define XMAX 9
#define COLMAX 40
#define LINEMIN 6
struct magic_ball
{
	int ball[XMAX][YMAX];
	int ball1[XMAX][YMAX];//ball1用于记录ball中哪些位置可以消去
	int x, y;
};
struct location {
	int i;
	int j;
};
char menu();
void menu123(char mode);
void input(int* x, int* y);
void exchange(int* a, int* b);
void wait_for_enter(const char prompt[100], int y = 0, int line_parm = 0, int bottom = 0);
void init_all(int array[XMAX][YMAX], int fill);
int TF_eliminate(struct magic_ball& magic);
void fall(struct magic_ball& magic,char mode='0');
void FillBlank(struct magic_ball& magic,char mode='0');
void eliminate_middle(struct magic_ball& magic);
void eliminate_edge(struct magic_ball& magic);
void generate_array(struct magic_ball& magic);
void output_init_array(struct magic_ball& magic);
void menu456789(char mode);
void print_bottom(int y, int line_parm,const char prompt[100],int x=0);
int TF_eliminateKey(int ball1[XMAX][YMAX]);
void input_end();