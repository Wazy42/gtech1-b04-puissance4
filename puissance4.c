#include <stdio.h>
#include <stdlib.h>
#define nbl 6
#define nbc 7

char table[nbl][nbc];


int affiche(void) {
  printf(" 1 2 3 4 5 6 7 \n");
  printf("-v-v-v-v-v-v-v-\n");
  for (int i = 0; i < nbl; i++) {
    printf("|");
    for (int j = 0; j < nbc; j++) {
      printf("%c|", table[i][j]);
    }
    printf("\n");
  }
  printf("---------------\n");
  return 0;
}


int puis4(void) {
  int turn, player;
  for (int i = 0; i < nbl; i++) {
    for (int j = 0; j < nbc; j++) {
      table[i][j] = ' ';
    }
  }

  // Affichage initial (grille vide)
  affiche();

  for (turn=0; turn<21; turn++) {
    for (player=0; player=0; player++) {
      // Tour des joueurs
      }
  }
  return 0;
}


int main(void) {
  puis4();
  return 0;
}
