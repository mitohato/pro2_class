#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//マクロ
#define SIZE 8          //ゲーム盤のサイズ
#define SENTE 0         //先手
#define GOTE 1          //後手
#define NO_VALUE -999   //取得済み箇所

//プロトタイプ宣言
void init_table(void);
void disp(int player, int no);
int select(int player, int no);