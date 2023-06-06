#include "../include/TimeChrono.h"
#include "../include/Graphique.h"
#include "../include/Chronometre.h"


int main(void){
    Chronometre chrono = initialiser_chronometre();
    int touche;
    struct timespec ts;
    struct timeval temps_debut, temps_fin;
    int  difference;
    int play = 1;
    ts.tv_sec = 0;
    ts.tv_nsec = 5000000;

    initscr();
    cbreak();
    //Initialisation des couleurs.
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    
    afficher_interface(chrono);
    gettimeofday(&temps_debut, NULL);
    while (play) {
        touche = getch();
        interaction_clavier(touche, &chrono, &temps_debut, &temps_fin, &play);
        nanosleep(&ts, NULL);
        if(chrono.avert < chrono.duration)
        	afficher_flash();// si il est superieur que avertisement, on flash

        if(chrono.etat) {
           	gettimeofday(&temps_fin, NULL);
            difference = intervalle_ms(temps_debut, temps_fin);
            chrono.duration += difference; 
            gettimeofday(&temps_debut, NULL);
        }// si etat est active, on enregistrer le temp final, et calculer l'intervelle entre debut et la fin et l;ajoute dans la duration
        
        afficher_tour(chrono);//affiche les tours
        refresh();
    }
    refresh();
    getch();
    endwin();
    return 0;
}