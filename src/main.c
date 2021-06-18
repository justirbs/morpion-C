/*!
 * \file main.c
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 janvier 2020
 *
 * \brief fonction principale
 *
 *
 */

// Inclusion des entêtes de librairies
#include "tableau.h"
#include "jeu.h"

int main(void){
  int** tab; //matrice de jeu
  int n; //dimension de la matrice de jeu
  int choix; //le mode du jeu choisi
  printf("Quelle est la dimension du plateau de jeu ? \n");
  n=saisirEntier();
  while(n<=1){
    printf("il faut une dimension suppérieure à 1 pour pouvoir jouer\nVeuillez ressaisir la demenssion : \n");
    n=saisirEntier();
  }
  tab=creerTabEntier2D(n, n);
  printf("Que choisissez vous ?\n 1- Mode facile\n 2- Mode dificile\n");
  choix=saisirEntier();
  switch (choix){
    case 1 : deroulerPartie(tab, n);
    break;
    case 2 : deroulerPartie2(tab, n);
    break;
    default : printf("Ce choix n'est pas possible...\n");
    break;
  }
  affichetab(tab, n);
  printf("Fin de la partie.\n");
  return(0);
}
