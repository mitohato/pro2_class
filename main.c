#include "hoge.h"

//変数
int score[2];              //得点
int Table[SIZE][SIZE];     //ゲーム盤
int line[SIZE];
int columm[SIZE];

int main(void)
{
  int sel = 0, i; 
  char res[10];
  int a, b, c, n = 1000;
  a = b = c = 0;
  while (n--){
    for (i = 0; i < SIZE; i++){
      line[i] = SIZE;
      columm[i] = SIZE;
    }
    srand(time(NULL));
    init_Table();
    disp(-1, 0);
    sel = donyoku2(SENTE, 0);
    while (1){
      if (sel == 11) break;
      disp(SENTE, sel);
      sel = AI39GO(GOTE, sel);
      printf("%d\n", sel);

      if (check()) {
        break;
      }
      if (sel == 11) break;
      disp(GOTE, sel);
      sel = donyoku2(SENTE, sel);
      printf("%d\n", sel);
      if (check()) {
        break;
      }
    }
    if (score[0] > score[1]){
      a++;
    }
    else if (score[1] > score[0]){
      b++;
    }
    else {
      c++;
    }
    // strcpy(res, (score[0] > score[1] ? "AI" : "AI39GO"));
    // printf("WINNER:%s\n", res);
  }
  printf("AI:%d AI39GO:%d DRAW:%d\n", a, b, c);
  return (0);
}
