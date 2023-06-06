#ifndef __TIMECHRONO__
#define __TIMECHRONO__

#include <sys/time.h>

/**
 * @brief Return l'écart entre debut et fin
 * 
 * @param debut (timeval)
 * @param fin (timeval)
 * @return (int)
 */
int intervalle_ms(struct timeval debut, struct timeval fin);

/**
 * @brief Convertit des ms en centieme de secondes.
 * 
 * @param nb_ms (int)
 * @return (int)
 */
int nb_ms_vers_centiemes(int nb_ms);

/**
 * @brief Convertit des ms en secondes.
 * 
 * @param nb_ms (int)
 * @return (int)
 */
int nb_ms_vers_secondes(int nb_ms);

/**
 * @brief Convertit des ms en minutes.
 * 
 * @param nb_ms (int)
 * @return (int)
 */
int nb_ms_vers_minutes(int nb_ms);

/**
 * @brief Convertit des ms en heures.
 * 
 * @param nb_ms (int)
 * @return (int)
 */
int nb_ms_vers_heures(int nb_ms);

#endif