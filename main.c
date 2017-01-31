#include "hoge.h"

//変数
int score[2];              //得点
int table[SIZE][SIZE];     //ゲーム盤
int line[SIZE];
int columm[SIZE];

int main(void)
{
  int sel = 0, i; 
  char res[10];

  for (i = 0; i < SIZE; i++){
    line[i] = SIZE;
    columm[i] = SIZE;
  }
  srand(time(NULL));
  init_table();
  disp(-1, 0);
  sel = select(SENTE, 0);
  while (1){
    if (sel == 11) break;
    disp(SENTE, sel);
    sel = sol(GOTE, sel);
    printf("%d\n", sel);

    if (check()) {
      break;
    }
    if (sel == 11) break;
    disp(GOTE, sel);
    sel = select(SENTE, sel);
    printf("%d\n", sel);
    if (check()) {
      break;
    }
  }
  
  strcpy(res, (score[0] > score[1] ? "player" : "CPU"));
  printf("WINNER:%s\n", res);
  return (0);
}
