/*!
 * \file jeu.h
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 janvier 2020
 *
 * \brief déclaration des fonctions et procédures relative au déroulement d'une partie
 *
 *
 */

#ifndef __JEU_H__
#define __JEU_H__

 // Inclusion des entêtes de librairies
 #include "saisie.h"
 #include "tableau.h"
 #include <time.h>

 // Déclaration des structures
 /*! \struct s_choix
  *  \structure pour stockerles le numéro de la ligne, colonne, diagonale ainsi que le nombre de X qu'elle contient
  */
 typedef struct {
 	int numero; /*!< la plus petite fréquence */
 	int nombre; /*!< la deuxième plus petite fréquence */
} s_choix;


 // Déclaration des fonctions

/**
 * \fn void deroulerPartie(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 04 février 2020
 *
 * \brief fonction qui permet de dérouler une partie
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 *
 *
 */
void deroulerPartie(int** tab, int n);



 /**
  * \fn void joueurJoue(int** tab, int n)
  *
  * \author Justine Ribas <ribasjusti@eisti.eu>
  * \version 0.1
  * \date 27 janvier 2020
  *
  * \brief fonction qui permet au joueur de choisir une case pour jouer
  *
  * \param tab la matrice de jeu
  * \param n dimenssion du tableau
  *
  *
  */
void joueurJoue(int** tab, int n);

/**
 * \fn void ordiJoue(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 28 janvier 2020
 *
 * \brief fonction qui permet à l'ordi de choisir une case aléatoirement pour jouer
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 *
 *
 */
void ordiJoue(int** tab, int n);

/**
 * \fn int aGagne(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 28 janvier 2020
 *
 * \brief fonction qui permet de vérifier si il y a une victoire
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 * \return 1 s'il y a une victoire, 0 sinon
 *
 *
 */
int aGagne(int** tab, int n);

/**
 * \fn int aGagneLigne(int** tab, int n, int indice)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 28 janvier 2020
 *
 * \brief fonction qui permet de vérifier si toutes les cases d'une ligne sont identiques
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 * \param indice l'indice de la ligne
 * \return 1 si toutes les cases sont identiques, 0 sinon
 *
 *
 */
 int aGagneLigne(int** tab, int n, int indice);

 /**
  * \fn int aGagneColonne(int** tab, int n, int indice)
  *
  * \author Justine Ribas <ribasjusti@eisti.eu>
  * \version 0.1
  * \date 28 janvier 2020
  *
  * \brief fonction qui permet de vérifier si toutes les cases d'une colonne sont identiques
  *
  * \param tab la matrice de jeu
  * \param n dimenssion du tableau
  * \param indice l'indice de la colonne
  * \return 1 si toutes les cases sont identiques, 0 sinon
  *
  *
  */
int aGagneColonne(int** tab, int n, int indice);

/**
 * \fn int aGagneDiagonale(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 28 janvier 2020
 *
 * \brief fonction qui permet de vérifier si toutes les cases d'une des diagonales sont identiques
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 * \return 1 si toutes les cases sont identiques dans une des diagonals, 0 sinon
 *
 *
 */
int aGagneDiagonale(int** tab, int n);

/**
 * \fn s_choix choixLigne(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 28 janvier 2020
 *
 * \brief fonction qui permet de trouver la ligne dans laquelle le joueur à placer le plus de X
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 * \return le numéro de la ligne et le nombre de X
 *
 *
 */
s_choix choixLigne(int** tab, int n);

/**
* \fn s_choix choixColonne(int** tab, int n)
*
* \author Justine Ribas <ribasjusti@eisti.eu>
* \version 0.1
* \date 28 janvier 2020
*
* \brief fonction qui permet de trouver la colonne dans laquelle le joueur à placer le plus de X
*
* \param tab la matrice de jeu
* \param n dimenssion du tableau
* \return le numéro de la colonne et le nombre de X
*
*
*/
s_choix choixColonne(int** tab, int n);

/**
 * \fn s_choix choixDiagonale(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 février 2020
 *
 * \brief fonction qui permet de trouver la diagonale dans laquelle le joueur à placer le plus de X
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 * \return le numéro de la diagonale et le nombre de X
 *
 *
 */
s_choix choixDiagonale(int** tab, int n);


/**
 * \fn void choixJeu(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 février 202007 février 202007 février 202007 février 202007 février 2020
 *
 * \brief fonction qui permet de choisir dans quelle case jouer
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 *
 *
 */
void choixJeu(int** tab, int n);

/**
  * \fn void jouerLigne(int** tab, int n, int indice)
  *
  * \author Justine Ribas <ribasjusti@eisti.eu>
  * \version 0.1
  * \date 07 février 202007 février 202007 février 202007 février 2020
  *
  * \brief fonction qui joue dans la bonne ligne
  * \param tab la matrice de jeu
  * \param n dimenssion du tableau
  * \param indice le numéro de la ligne
  *
  *
  */
void jouerLigne(int** tab, int n, int indice);


/**
  * \fn void jouerColonne(int** tab, int n, int indice)
  *
  * \author Justine Ribas <ribasjusti@eisti.eu>
  * \version 0.1
  * \date 07 février 202007 février 202007 février 2020
  *
  * \brief fonction qui joue dans la bonne colonne
  * \param tab la matrice de jeu
  * \param n dimenssion du tableau
  * \param indice le numéro de la colonne
  *
  *
  */
void jouerColonne(int** tab, int n, int indice);

/**
  * \fn void jouerDiagonale(int** tab, int n, int indice)
  *
  * \author Justine Ribas <ribasjusti@eisti.eu>
  * \version 0.1
  * \date 07 février 202007 février 2020
  *
  * \brief fonction qui joue dans la bonne diagonale
  * \param tab la matrice de jeu
  * \param n dimenssion du tableau
  * \param indice le numéro de la diagonale
  *
  *
  */
void jouerDiagonale(int** tab, int n, int indice);

/**
 * \fn void deroulerPartie2(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 février 2020
 *
 * \brief fonction qui permet de dérouler une partie avec le mode intelligent
 *
 * \param tab la matrice de jeu
 * \param n dimenssion du tableau
 *
 *
 */
void deroulerPartie2(int** tab, int n); 

#endif
