#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <assert.h>

#include "../include/TimeChrono.h"

int intervalle_ms(struct timeval debut, struct timeval fin) {
    assert(fin.tv_sec >= debut.tv_sec); 
    return (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_usec - debut.tv_usec) / 1000;
}

int nb_ms_vers_centiemes(int nb_ms) {
    assert(nb_ms >= 0); 
    return (nb_ms / 10) % 100;
}

int nb_ms_vers_secondes(int nb_ms) {
    assert(nb_ms >= 0); 
    return (nb_ms / 1000) % 60;
}

int nb_ms_vers_minutes(int nb_ms) {
    assert(nb_ms >= 0); 
    return (nb_ms / 60000) % 60;
}

int nb_ms_vers_heures(int nb_ms) {
    assert(nb_ms >= 0); 
    return (nb_ms / 3600000) % 24;
}
