#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include "Chronometre.h"
#include "TimeChrono.h"

#include <ncurses.h>
#include <time.h>
#include <unistd.h>


/**
 * @brief Affiche l'interface général du Chronometre.
 * 
 * @param chrono (Chronometre)
 */
void afficher_interface(Chronometre chrono);

/**
 * @brief Affiche les tours du  Chronometre.
 * 
 * @param chrono (Chronometre)
 */
void afficher_tour(Chronometre chrono);

/**
 * @brief Affiche des sintillements sur l'interface, pour allerter
 * lors du dépassement de l'avertisseur.
 */
void afficher_flash();

/**
 * @brief Affiche un temps sous la forme h:m:s:c
 * 
 * @param y (int) Coordonnées de l'affichage.
 * @param x (int) Coordonnées de l'affichage.
 * @param nb_ms (int) temps en ms à afficher.
 */
void afficher_duree(int y, int x, int nb_ms);

/**
 * @brief Affiche un temps sous la forme h:m:s:c
 * 
 * @param touche (int) Touche pressé par l'utilisateur.
 * @param chrono (Chronometre*) Strucutre Chronometre pour y ajouter les modifications.
 * @param debut (timeval*) temps debut.
 * @param fin (timeval*) temps fin.
 * @param play (int*) Fin du programme si 0;
 */
void interaction_clavier(int touche, Chronometre * chrono, struct timeval * debut, struct timeval * fin, int * play);
#endif