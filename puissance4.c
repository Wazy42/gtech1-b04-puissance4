#include <stdio.h>
#define NBL 6
#define NBC 7
#define P1 'x'
#define P2 'o'

char table[NBL][NBC];

/*
Fonction affichage:
  Ne prends aucun argument.
  Retourne 0.
  
  Affiche le tableau `table` dynamiquement.
*/
int affiche(void) {
  for (int i = 0; i < NBC; i++) {
    printf(" %d", i + 1);
  }
  printf("\n_");
  for (int i = 0; i < NBC; i++) {
    printf("v_");
  }
  printf("\n");
  for (int i = 0; i < NBL; i++) {
    printf("|");
    for (int j = 0; j < NBC; j++) {
      printf("%c|", table[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < NBC; i++) {
    printf("¯¯");
  }
  printf("¯\n");
  return 0;
}

/*
Fonction vérification:
  Argument `player`: caractère du joueur à verifier ('o' ou 'x')
  Retourne 0 si aucun gagnant, 1 si le joueur `player` est gagnant.

  Vérifie le contenu de `table` pour vérifier si un jouer a gagné.
*/
int verification(char player) {
  int count_h, count_v, count_dd, count_dg;
  for (int x = 0; x < NBC-3; x++) {
    for (int y = 0; y < NBL-3; y++) {
      if (table[y][x] != player)
      count_h = 0, count_v = 0, count_dd = 0, count_dg = 0;
      for (int n = 0; n < 4; n++) {
	// Horizontal
	if (table[y][x+n] == player) count_h++;
	// Vertical
	if (table[y+n][x] == player) count_v++;
	// Diagonal (droite)
	if (table[y+n][x+n] == player) count_dd++;
	// diagonal (gauche)
	if (table[y+n][NBC-x-n] == player) count_dg++;
      }
      if (count_h == 4 || count_v == 4 || count_dd == 4 || count_dg == 4) return 1;
    }
  }
  return 0;
}

/*
Fonction puis4:
  Ne prends aucun argument.
  Retourne 0.

  Gère la partie en cours (alternation entre les jouers, mise a jour de `table`, lancement des vérifications...).
*/
int puis4(void) {
  // Initialisation grille
  for (int i = 0; i < NBL; i++) {
    for (int j = 0; j < NBC; j++) {
      table[i][j] = ' ';
    }
  }
 
  // Affichage initial (grille vide)
  affiche();

  int winner = 0, player = 0;
  char graphics[] = {P1, P2};
  for (int turn = 0; turn < 42 && !winner; turn++) {
    /* Faire inserer jeton */
    winner = verification(graphics[player]);
    player = !player;
  }
  return 0;
}

/*
Fonction main:
  Ne prends aucun argument.
  Retourne 0.

  Gère les lancements du jeu.
*/
int main(void) {
  puis4();
}
