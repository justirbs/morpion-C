/*!
 * \file tableau.h
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 13 décembre 2019
 *
 * \brief header des fonctions pour créer des tableaux
 *
 *
 */


// Inclusion des entêtes de librairies

#ifndef __TABLEAU_H__
#define __TABLEAU_H__
#include <stdio.h>
#include <stdlib.h>

// Déclaration des fonctions

/**
 * \fn int** creerTabEntier2D(int ligne, int colonne)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 13 décembre 2019
 *
 * \brief permet de créer un tableau à deux dimensions
 *
 * \param ligne le nombre de ligne du tableau
 * \param colonne le nombre de colonne du tableau
 * \return tab l'adresse de la première case du tableau crée
 *
 *
 */
int** creerTabEntier2D(int ligne, int colonne);


/**
 * \fn void affichetab(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 janvier 2020
 *
 * \brief permet d'afficher un tableau à deux dimensions
 *
 * \param tab le tableau à afficher
 * \param n dimension du tableau
 *
 *
 */
void affichetab(int** tab, int n);


#endif
