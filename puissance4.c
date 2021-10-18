#include <stdio.h>
#include <stdlib.h>
#define nbl 6
#define nbc 7

char table[nbl][nbc];

/*
Fonction affichage:
  Ne prends aucun argument.
  Retourne 0.
  
  Affiche le tableau `table` dynamiquement.
*/
int affiche(void) {
  for (int i = 0; i < nbc; i++) {
    printf(" %d", i + 1);
  }
  printf("\n_");
  for (int i = 0; i < nbc; i++) {
    printf("v_");
  }
  printf("\n");
  for (int i = 0; i < nbl; i++) {
    printf("|");
    for (int j = 0; j < nbc; j++) {
      printf("%c|", table[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < nbc; i++) {
    printf("¯¯");
  }
  printf("¯\n");
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
