#include "hoge.h"

extern Table[SIZE][SIZE];
extern score[2];
extern line[SIZE];
extern columm[SIZE];

void init_Table(void)
{
  int i, j;
  score[SENTE] = 0;
  score[GOTE] = 0;
  for(i = 0; i < SIZE; i++){
    for (j = 0; j < SIZE; j++){
      Table[i][j] = rand() % 19 - 9;
    }
  }
}

void disp(int player, int no)
{
  int i, j;
  printf("\n");
  for (i = 0; i < SIZE; i++){
    if (i == 0){
      printf("   ");
      for (j = 0; j < SIZE; j++) {
        printf("  %d", j);
      }
      printf("\n   ");
      
      for (j = 0; j < SIZE; j++) {
        printf("---");
      }
      printf("\n");
      printf("   ");
      if (player == 0){
        for (j = 0; j < SIZE; j++){
          if (j == no){
            printf(" ##");
          }
          else {
            printf("   ");
          }
        }
        printf("\n");
      }
      else {
        printf("\n");
      }
    }
    printf("%d|", i);
    if (abs(player) == 1 && i == no){
      printf("[");
    }
    else {
      printf(" ");
    }
    for (j = 0; j < SIZE; j++){
      if (Table[i][j] == NO_VALUE){
        printf(" **");
      }
      else {
        printf("%3d", Table[i][j]);
      }
    }
    if (abs(player) == 1 && i == no){
      printf("  ]");
    }
    printf("\n");
  }
  if (player == 0){
    printf("   ");
    for (j = 0; j < SIZE; j++){
      if (j == no){
        printf(" ##");
      }
      else {
        printf("   ");
      }
    }
    printf("\n");
  }

  printf("\n");
  if (player == -1){
    return;
  }
  if (player == 1){
    printf("後手");
  }
  else {
    printf("先手");
  }
  printf("が%dを選択しました\n\n", no);
  printf("----------------\n");
  printf("先手：%d\n", score[0]);
  printf("後手：%d\n", score[1]);
  printf("----------------\n");
}

int select(int player, int no)
{
  char buf[10];
  int num, m;
  
  while (1){
    // if (player == 0){
    printf("先手");
    // }
    // else {
    //   printf("後手");
    // }
    printf(">>");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &num);
    if (((player == 0 && Table[no][num] != NO_VALUE) || (player == 1 && Table[num][no] != NO_VALUE)) && 0 <= num && num <= 7){
      break;
    }
    else {
      printf("もう一度\n");
    }
  }
  // if (player == 0){
  m = Table[no][num];
  Table[no][num] = NO_VALUE;
  line[no]--;
  columm[num]--;
  // }
  // else if (player == 1){
  //   m = Table[num][no];
  //   Table[num][no] = NO_VALUE;
  //   line[num]--;
  //   columm[no]--;
  
  // }
  score[player] += m;
  return (num);
}

int AI(int player, int no)
{
  int max = NO_VALUE, i, j, pos;
  int ct = 0, min = -NO_VALUE, pos1;
  for (i = 0; i < SIZE; i++){
    if (max < Table[no][i]){
      max = Table[no][i];
      pos = i;
    }
  }
  score[player] += Table[no][pos];
  Table[no][pos] = NO_VALUE;
  line[no]--;
  columm[pos]--;
  return (pos);
}

int AI39GO(int player, int no)
{
  int max = NO_VALUE, i, j, pos[10];
  int ct = 0, min = -NO_VALUE, pos1;
  int m = NO_VALUE;
  for (i = 0; i < SIZE; i++){
    if (Table[i][no] == NO_VALUE){
      continue;
    }
    for (j = 0; j < SIZE; j++){
      if (no == j){
        continue;
      }
      if (max < Table[i][j]){
        max = Table[i][j];
      }
    }
    if (m < Table[i][no] - max){
      m = Table[i][no] - max;
      pos1 = i;
    }
  }
  score[player] += Table[pos1][no];
  Table[pos1][no] = NO_VALUE;
  line[pos1]--;
  columm[no]--;
  return (pos1);
}

int check(void)
{
  int i;
  for (i = 0; i < 8; i++){
    if (line[i] == 0 || columm[i] == 0){
      return (1);
    }
  }
  return (0);
}