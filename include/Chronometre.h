#ifndef __CHRONOMETRE__
#define __CHRONOMETRE__

#include <stdio.h>
#include <stdlib.h>

typedef struct Chronometre {
    int etat; //1 en acitivé 0 sinon
    int duration; //millisecondes
    int avert;
    int indice_tour;
    int total_tour;
    int tours[6];
}Chronometre;

/**
 * @brief Modifie chrono pour y ajouter un tour. Prend duration et l'ajoute
 * dans l'un des epàlacements de tours.
 * 
 * @param chrono (Chronometre*)
 */
void ajouter_tour(Chronometre *chrono);


/**
 * @brief Initialise les valeurs d'un chronomètre.
 * 
 * @return (Chronometre)
 */
Chronometre initialiser_chronometre();
#endif