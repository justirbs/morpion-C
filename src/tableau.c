/*!
 * \file tableau.c
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 13 décembre 2019
 *
 * \brief fonctions pour créer des tableau
 *
 *
*/

#include"tableau.h"



int** creerTabEntier2D(int ligne, int colonne)
{
  int** tab; //tableau d'entiers
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  tab = malloc(ligne*sizeof(int*));
  if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }
  for(i=0; i<ligne; i++){
    tab[i] = malloc(colonne*sizeof(int));
    if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
    }
    for(j=0; j<colonne; j++){
      tab[i][j]=' ';
    }
  }
  return(tab);
}

void affichetab(int** tab, int n){
  int i;
  int j;
  int k;
  printf("  ");
  for(i=0; i<n; i++){
    printf(" %d  ", i);
  }
  printf("\n");
  for(i=0; i<n; i++){
    printf(" ");
    for(k=0; k<n; k++){
      printf("----");
    }
    printf("-\n%d|", i);
    for(j=0; j<n; j++){
      printf(" %c |", tab[i][j]);
    }
    printf("\n");
  }
  printf(" ");
  for(k=0; k<n+1; k++){
    printf("---");
  }
  printf("-\n");
}
