#include <stdio.h>
#include <stdlib.h>
// #define WHITE "\033[00;37m"

int NBL = 6, NBC = 7, NBP = 2;
char graphics[] = {'x', 'o', 'm', 'z', 'u', 'v', 's', 'i', '%', '#'};
// char* colors[] = {"\033[00;31m", "\033[00;32m", "\033[00;33m", "\033[00;34m", "\033[00;35m", "\033[00;36m"};
char** table = NULL;

/*
Fonction affichage:
  Ne prends aucun argument.
  Retourne 0.
  
  Affiche le tableau `table` dynamiquement.1
*/
int affiche(void) {
  printf("\n\n");
  for (int i = 0; i < NBC; i++) {
    printf("%3d ", i + 1);
  }
  printf("\n_");
  for (int i = 0; i < NBC; i++) {
    printf("_v__");
  }
  printf("\n");
  for (int i = 0; i < NBL; i++) {
    printf("|");
    for (int j = 0; j < NBC; j++) {
      printf(" %c |", table[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < NBC; i++) {
    printf("¯¯¯¯");
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
  for (int x = 0; x < NBC; x++) {
    for (int y = 0; y < NBL; y++) {
      if (table[y][x] == player) {
	count_h = 0, count_v = 0, count_dd = 0, count_dg = 0;
	for (int n = 0; n < 4; n++) {
	  // Horizontal
	  if (x < NBC - 3 && table[y][x+n] == player) count_h++;
	  // Vertical
	  if (y < NBL - 3 && table[y+n][x] == player) count_v++;
	  // Diagonal
	  if (x < NBC - 3 && y < NBL - 3 && table[y+n][x+n] == player) count_dd++;
	  if (x > 3 && y < NBL - 3 && table[y+n][x-n] == player) count_dg++;
	}
	if (count_h == 4 || count_v == 4 || count_dd == 4 || count_dg == 4) return 1;
      }
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

  int winner = 0, player = 0, token;
  for (int turn = 0; turn < NBL * NBC && !winner; turn++) {
    // Saisie et getsion des erreurs:
    do {
      printf("\nEntrez un nombre entre 1 et %d:\n", NBC);
      int ret = scanf("%d", &token);
      if (ret != 1) {
	char tmp;
	scanf("%c", &tmp);
      }
    } while (token > NBC || token < 1);

    // Ajout des tokens à la grille
    for (int i = NBL; i > 0; i--) {
      if (table[i-1][token-1] == ' ') {
	table[i-1][token-1] = graphics[player];
	break;
      }
    }
 
    affiche();
    winner = verification(graphics[player]);
    player = (turn + 1) % NBP;
  }
  if (winner) printf("Félicitation ! Joueur '%c' a gagné !\n", graphics[!player]);
  else printf("Égalité !\n");
  return 0;
}

/*
Fonction allocMalloc:
  Ne prends aucun argument.
  Retourne table avec mémoire allouée

  Alloue la mémoire nécessaire au tableau dynamiquement.
*/
char **allocMalloc() {
  char **table = (char**)malloc(NBL * sizeof(char*));
  for (int i = 0; i < NBL; i++) 
    table[i] = (char*)malloc(NBC * sizeof(char));
  return table;
}

/*
Fonction main:
  Ne prends aucun argument.
  Retourne 0 ou 1 si erreur.

  Gère les lancements du jeu.
*/
int main(int argc, char *argv[]) {
  // Récupération arguments programme
  if (argc == 3 || argc == 4) {
    NBL = atoi(argv[1]);
    NBC = atoi(argv[2]);
  } else {
    NBL = 6;
    NBC = 7;
  } if (argc == 4) {
    NBP = atoi(argv[3]);
    if (NBP < 2 || NBP > 10) NBP = 2;
  }
  printf("Lancement en %dx%d.\n", NBL, NBC);

  // Allocation mémoire pour `table`
  table = allocMalloc();
  if (table == NULL) {
    printf("Allocation de %d octets impossible. Arrêt du programme.\n", NBL * NBC * sizeof(char));
    return 1;
  }
  // Execution du programme puis libération de la mémoire
  puis4();
  free(table);
  return 0;
}
