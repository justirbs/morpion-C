/*!
 * \file jeu.c
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 janvier 2020
 *
 * \brief fonctions et procédures relative au déroulement d'une partie
 *
 *
 */

// Inclusion des entêtes de librairies
 #include "jeu.h"

// Code des fonctions

// Fonction pour dérouler une partie en mode facil
void deroulerPartie(int** tab, int n){
  int victoire; //variable booléenne qui indique s'il y a une victoire ou non
  int compteur; //compe le nombre de tour pour que la partie s'arrête quand toutes les cases sont pleines
  victoire=0;
  compteur=0;
  system("clear");
  //tant qu'il ny a pas eu de victoire et que toutes les cases ne sont pas pleines, on déroule une partie
  while(victoire==0 && compteur<n*n){
    affichetab(tab,n);
    printf("\nC'est à vous de jouer :\n");
    joueurJoue(tab, n);
    compteur++;
    if(aGagne(tab, n)){
      system("clear");
      printf("\n\nBravo, vous avez gagné !\n\n");
      victoire=1;
    }
    //si le joueur n'a pas gagné et que toutes les cases ne sont pas pleines, alors l'ordi peut jouer
    if(victoire==0 && compteur<n*n){
      system("clear");
      printf("\nL'ordinateur a joué :\n");
      ordiJoue(tab, n);
      compteur++;
      if(aGagne(tab, n)){
        victoire=1;
        system("clear");
        printf("\n\nDommage... Vous avez pardu.\n\n");
      }
    }
  }
}

// Fonction pour que le joueur joue
void joueurJoue(int** tab, int n){
  int ligne; //l'indice de la ligne
  int colonne; //l'indice de la colonne
  printf("Dans quelle case voulez-vous jouer ?\nVeuillez saisir la ligne, puis la colonne.\n");
  ligne=saisirEntier();
  colonne=saisirEntier();
  //il faute que la ligne et la colonne soient deux entiers compris entre 0 et n
  while ((ligne>=n && ligne<0) || (colonne>=n && colonne<0)){
    printf("Cette case n'existe pas, veuillez saisir à nouveau la ligne puis la colonne\n");
    ligne=saisirEntier();
    colonne=saisirEntier();
  }
  //on vérifie que la case choisie par le joueur est vide
  while (tab[ligne][colonne]!=' '){
    printf("Cette case est déjà occupée... Il faut en choisir une autre\nVeuillez saisir la ligne, puis la colonne.\n");
    ligne=saisirEntier();
    colonne=saisirEntier();
    while (ligne>=n || colonne>=n){
      printf("Cette case n'existe pas, veuillez saisir à nouveau la ligne puis la colonne\n");
      ligne=saisirEntier();
      colonne=saisirEntier();
    }
  }
  tab[ligne][colonne]='X';
}

// Fonction pour que l'ordi joue
void ordiJoue(int** tab, int n){
  srand(time(NULL)); //on initialise la fonction rand
  int ligne; //l'indice de la ligne
  int colonne; //l'indice de la colonne
  //la fonction rand génère un entier aléatoie compris entre 0 et n-1
  ligne = (rand()%n);
  colonne = (rand()%n);
  //on vérifie que la case prise aléatoirement soit vide
  while (tab[ligne][colonne]!=' '){
    ligne = (rand()%n);
    colonne = (rand()%n);
  }
  tab[ligne][colonne]='O';
}

// Fonction qui vérifie s'il y a une victoire
int aGagne(int** tab, int n){
  int i; //ittérateur de boucle
  int victoireLigne; //variable bouléenne qui indique s'il y a une victoire dans une ligne
  int victoireColonne; //variable bouléenne qui indique s'il y a une victoire dans une colonne
  i=0;
  //on part du principe qu'il n'y a pas de victoire
  victoireLigne=0;
  victoireColonne=0;
  //tant qu'il n'y a pas pas eu de victoire et que l'on a pas testé toutes les lignes, on teste la ligne
  while(victoireLigne==0 && i<n){
    if(aGagneLigne(tab, n, i)){
      victoireLigne=1;
    }
    i++;
  }
  i=0;
  //tant qu'il n'y a pas pas eu de victoire et que l'on a pas testé toutes les colonnes, on teste la colonne
  while(victoireColonne==0 && i<n){
    if(aGagneColonne(tab, n, i)){
      victoireColonne=1;
    }
    i++;
  }
  //il y a victoire s'il  a victoire dans une ligne, une colonne ou une diagonale
  return(victoireColonne || victoireLigne || aGagneDiagonale(tab, n));
}

// Fonction qui vérifie s'il y a victoire dans une ligne
int aGagneLigne(int** tab, int n, int indice){
  int i; //iterrateur de boucle
  int identique; //variable bouléenne qui indique si deux cases sont identiques
  //on part du principe qu'il y a une vicoire sur cette ligne
  identique=1;
  for(i=0; i<n-1; i++){
    //si cette case et la suivante ne sont pas idtiques ou si la case est vide, alors il ne peut pas y avoir de victoire dans cette ligne
    if((tab[indice][i] != tab[indice][i+1]) || tab[indice][i]==' '){
      identique=0;
    }
  }
  return(identique);
}

// Fonction qui vérifie s'il y a victoire dans une colonne
int aGagneColonne(int** tab, int n, int indice){
  int i; //iterrateur de boucle
  int identique; //variable bouléenne qui indique si deux cases sont identiques
  //on part du principe qu'il y a une victoire sur cette colonne
  identique=1;
  for(i=0; i<n-1; i++){
    //si cette case et la suivante ne sont pas idtiques ou si la case est vide, alors il ne peut pas y avoir de victoire dans cette colonne
    if((tab[i][indice] != tab[i+1][indice]) || (tab[i][indice]==' ')){
      identique=0;
    }
  }
  return(identique);
}

// Fonction qui vérifie s'il y a victoire dans une diagonale
int aGagneDiagonale(int** tab, int n){
  int i; //iterrateur de boucle
  int identique; //variable bouléenne qui indiqu si deux cases sont identiques
  //on part du principe quil y a victoire dans la première diagonale
  identique=1;
  for(i=0; i<n-1; i++){
    //si cette case et la suivante ne sont pas idtiques ou si la case est vide, alors il ne peut pas y avoir de victoire dans cette diagonale
    if((tab[i][i] != tab[i+1][i+1]) || (tab[i][i]==' ')){
      identique=0;
    }
  }
  //s'il n'y a pas eu victoire dans la première diagonale, alors on teste dans la deuxième
  if (identique!=1){
    identique=1;
    for(i=0; i<n-1; i++){
      //si cette case et la suivante ne sont pas idtiques ou si la case est vide, alors il ne peut pas y avoir de victoire dans cette diagonale
      if((tab[n-1-i][i] != tab[n-i-2][i+1]) || (tab[n-1-i][i]==' ')){
        identique=0;
      }
    }
  }
  return(identique);
}

//Fonction pour choisir la ligne où il y a le plus de X
s_choix choixLigne(int** tab, int n){
  int i; //iterrateur de boucle
  int j; //ittérateur de boucle
  int estLibre; //variable bouléenne qui indique s'il reste une case vide dans la ligne
  s_choix res; //l'indice de la ligne ainsi que le nombre de X
  int max; //le max de X
  max=0;
  for(i=0; i<n; i++){
    //on initialise le nombre de X et on part du principe que la ligne est pleine
    res.nombre=0;
    estLibre=0;
    for(j=0; j<n; j++){
      //on compte les X
      if(tab[i][j]=='X'){
        res.nombre++;;
      }
      //on regarde s'il y a au moins une case de libre
      if(tab[i][j]==' '){
        estLibre=1;
      }
    }
    //on compare le nombre de X avec le max si la ligne est libre
    if(res.nombre>max && estLibre){
      max=res.nombre;
      res.numero=i;
    }
    res.nombre=max;
  }
  return(res);
}

//Fonction pour choisir la colonne où il y a le plus de X
s_choix choixColonne(int** tab, int n){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int estLibre; //variable bouléenne qui indique s'il reste une case vide dans la colonne
  s_choix res; //l'indice de la colonne ainsi que le nombre de X
  int max; //le max de X
  max=0;
  for(i=0; i<n; i++){
    //on initialise le nombre de X et on part du principe que la colonne est pleine
    res.nombre=0;
    estLibre=0;
    for(j=0; j<n; j++){
      //on compte les X
      if(tab[j][i]=='X'){
        res.nombre++;
      }
      //on regarde s'il y a au moins une case de libre
      if(tab[j][i]==' '){
        estLibre=1;
      }
    }
    //on compare le nombre de X avec le max si la colonne est libre
    if(res.nombre>max && estLibre){
      max=res.nombre;
      res.numero=i;
    }
    res.nombre=max;
  }
  return(res);
}

//Fonction pour choisir la diagonale où il y a le plus de X
s_choix choixDiagonale(int** tab, int n){
  int i; //iterrateur de boucle
  int estLibre1; //variable bouléenne qui indique s'il reste une case vide dans la première diagonale
  int estLibre2; //variable bouléenne qui indique s'il reste une case vide dans la deuxième diagonale
  s_choix res; //l'indice de la diagonale ainsi que le nombre de X
  int max; //le max de X
  //on part du principe que les diagonales sont pleines
  estLibre1=0;
  estLibre2=0;
  max=0;
  res.nombre=0;
  //on part du principe que la deuxième diagonale a plus de X
  res.numero=1;
  for(i=0; i<n; i++){
    //on compte les X
    if(tab[i][i]=='X'){
      max++;
    }
    //on regarde s'il y a au moins une case de libre
    if(tab[i][i]==' '){
      estLibre1=1;
    }
  }
  for(i=0; i<n; i++){
    //on compte les X
    if(tab[n-1-i][i]=='X'){
      res.nombre++;
    }
    //on regarde s'il y a au moins une case de libre
    if(tab[n-1-i][i]==' '){
      estLibre2=1;
    }
  }
  //si la deuxième diagonale est pleine, alors on la "disqualifie" en lui indiquant 0 X
  if(!estLibre2){
    res.nombre=0;
  }
  //on compare le nombe de X de la première et de la deuxième diagonale si la première diagonale est libre
  if(max>res.nombre && estLibre1){
    res.nombre=max;
    res.numero=0;
  }
  return(res);
}

// Fonction qui effectue le choix du jeu stratégique de l'ordi
void choixJeu(int** tab, int n){
  s_choix ligne; //l'indice de la ligne choisie ainsi que son nombre de X
  s_choix colonne; //l'indice de la colonne choisie ainsi que son nombre de X
  s_choix diagonale; //l'indice de la diagonale choisie ainsi que son nombre de X
  int jeu;
  int max;
  ligne=choixLigne(tab, n);
  colonne=choixColonne(tab, n);
  diagonale=choixDiagonale(tab, n);
  if(ligne.nombre>colonne.nombre){
    jeu=0;
    max=ligne.nombre;
  } else {
    jeu=1;
    max=colonne.nombre;
  }
  if (max<diagonale.nombre){
    jeu=2;
  }
  switch (jeu){
    case 0 : jouerLigne(tab, n, ligne.numero);
    break;
    case 1 : jouerColonne(tab, n, colonne.numero);
    break;
    case 2 : jouerDiagonale(tab, n, diagonale.numero);
    break;
    default : printf("erreur");
    break;
  }
}

void jouerLigne(int** tab, int n, int indice){
  int i;
  int jeu;
  i=0;
  jeu=0;
  while(i<n && jeu==0){
    if(tab[indice][i]==' '){
      tab[indice][i]='O';
      jeu=1;
    }
    i++;
  }
}


void jouerColonne(int** tab, int n, int indice){
  int i;
  int jeu;
  i=0;
  jeu=0;
  while(i<n && jeu==0){
    if(tab[i][indice]==' '){
      tab[i][indice]='O';
      jeu=1;
    }
    i++;
  }
}


void jouerDiagonale(int** tab, int n, int indice){
  int i;
  int jeu;
  i=0;
  jeu=0;
  if(indice==0){
    while(i<n && jeu==0){
      if(tab[i][i]==' '){
        tab[i][i]='O';
        jeu=1;
      }
      i++;
    }
    i=0;
  } else {
    while(i<n && jeu==0){
      if(tab[n-1-i][i]==' '){
        tab[n-1-i][i]='O';
        jeu=1;
      }
      i++;
    }
  }
}

void deroulerPartie2(int** tab, int n){
  int victoire;
  int compteur;
  victoire=0;
  compteur=0;
  system("clear");
  while(victoire==0 && compteur<n*n){
    affichetab(tab,n);
    printf("\nC'est à vous de jouer :\n");
    joueurJoue(tab, n);
    compteur++;
    if(aGagne(tab, n)){
      system("clear");
      printf("\n\nBravo, vous avez gagné !\n\n");
      victoire=1;
    }
    if(victoire==0 && compteur<n*n){
      system("clear");
      printf("\nL'ordinateur a joué :\n");
      choixJeu(tab, n);
      compteur++;
      if(aGagne(tab, n)){
        victoire=1;
        system("clear");
        printf("\n\nDommage... Vous avez pardu.\n\n");
      }
    }
  }
}
