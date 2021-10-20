#include <stdio.h>
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

/*
Fonction vérification:
  Argument `player`: caractère du joueur à verifier ('o' ou 'x')
  Retourne 0 si aucun gagnant, 1 si le joueur `player` est gagnant.

  Vérifie le contenu de `table` pour vérifier si un jouer a gagné.
*/
int verification(char player) {
  int count_h, count_v, count_dd, count_dg;
  for (int x = 0; x < nbc-3; x++) {
    for (int y = 0; y < nbl-3; y++) {
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
	if (x > 3 && table[y+n][x-n] == player) count_dg++;
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
  for (int i = 0; i < nbl; i++) {
    for (int j = 0; j < nbc; j++) {
      table[i][j] = ' ';
    }
  }
 
  // Affichage initial (grille vide)
  affiche();

  for (int turn = 0; turn < 21; turn++) {
    for (int player = 0; player = 0; player++) {
      printf("%d", player+1);
      }
 
      affiche();
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
  while (1) {
    puis4();
    char reponse;
    printf("Voulez-vous rejouer ? \n (o/n) \n");
    scanf("%c", &reponse);

    if (reponse == 'o') printf("Nouvelle partie initialisée");
    else if (reponse == 'n') {
	printf("Dommage à une prochaine fois");
	return 0;
      }
  }
  
  return 0;
}
