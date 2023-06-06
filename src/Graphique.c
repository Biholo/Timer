#include "../include/Graphique.h"
#include "../include/Chronometre.h"

//affiche l'interface.
void afficher_interface(Chronometre chrono){
    mvprintw(0, (COLS/2) - 9, "== Chronometre ==");
    mvprintw(LINES -1, 0, "q : quitter");
    mvprintw(LINES - 2, 0, "F5/F6 : incrementer / decrementer seconde avertissement");
    mvprintw(LINES - 3, 0, "F3/F4 : incrementer / decrementer minute avertissement");
    mvprintw(LINES - 4, 0, "F1/F2 : incrementer / decrementer heure avertissement");
    mvprintw(LINES - 5, 0, "t : marquer tour");
    mvprintw(LINES - 6, 0, "r : reinitialiser");
    mvprintw(LINES - 7, 0, "Espace : lancer / mettre en pause");
    for(int i = 0; i < COLS; i++){
        mvprintw(LINES - 8, i, "-");
    }
}

//affiche le tour
void afficher_tour(Chronometre chrono) {
    afficher_duree(LINES - 9, (COLS / 2) - 6, chrono.avert );
    mvprintw(LINES - 9, (COLS / 2) - 25, "Avertissement");
    afficher_duree(LINES - 10, (COLS / 2) - 6, chrono.duration );
    int n = chrono.total_tour;
    for(int i = chrono.indice_tour-1, j = 0; i >= 0; i--, j++){
        mvprintw(LINES - 11 - j, (COLS / 2) - 25, "Tour %d", n-j);
        afficher_duree(LINES - 11 - j, (COLS / 2) - 6, chrono.tours[i]);
    }
}

//Sintillement de la barre d'etoile.
void afficher_flash(){
    int random = rand() % 5; 
    attron(COLOR_PAIR(random));
    for(int i = 0; i < COLS; i++){
        mvprintw(LINES - 8, i, "*");
    }
    attroff(COLOR_PAIR(random));
}

//Affiche sous la forme h:m:s:c un temps en ms.
 void afficher_duree(int y, int x, int nb_ms) {
    int h = nb_ms_vers_heures(nb_ms);
    int m = nb_ms_vers_minutes(nb_ms);
    int s = nb_ms_vers_secondes(nb_ms);
    int c = nb_ms_vers_centiemes(nb_ms);
    mvprintw(y, x, "%d : %d : %d : %d", h,m,s,c);
}


//Intéraction celon la touche pressé.
void interaction_clavier(int touche, Chronometre * chrono, struct timeval * debut, struct timeval * fin, int * play){
    int temp;
    if (touche != ERR) {
            switch (touche)
            {
            case 'q':
                *play = 0;
                break;//fermer la fenetre et rentre dans la terminal
            case 'r':
                chrono->duration = 0;
                chrono->indice_tour = 0;
                chrono->total_tour = 0;
                chrono->etat = 0;
                for(int i = 0; i < 6; i++){
                	chrono->tours[i] = 0; 
                    /*Permet de supprimer les tours graphiquement*/
                    mvprintw(LINES - 11 - i, (COLS / 2) - 27, "                                          ");
                }
                mvprintw(LINES - 10, (COLS / 2) - 10, "                                                             "); 
                break; // reinitialiser            
                
            case 't':
                ajouter_tour(chrono);
                break;// enrejistrer la nouvelle tour

            case KEY_F(2):// 'F2'diminuer l'heure
                temp = chrono->avert - 3600000;
                chrono->avert  = temp > 0 ? temp : 0;
                break;
            
            case KEY_F(1):// 'F1'augement l'heure
                chrono->avert += 3600000;
                break;

            case KEY_F(4):// 'F4'diminuer la minute
                temp = chrono->avert - 60000;
                chrono->avert = temp > 0 ? temp : 0;
                break;

            case KEY_F(3):// 'F3'augement la minute
                chrono->avert += 60000;
                break;

            case KEY_F(6):// 'F6'diminuer la seconde
                temp = chrono->avert - 1000;
                chrono->avert = temp > 0 ? temp : 0;
                break;

            case KEY_F(5)://'F5' augement la seconde
                chrono->avert += 1000;
                break;
                     
            case ' ':
                if(!chrono->etat) {
                    gettimeofday(debut, NULL);
                    chrono->etat = 1;
                }// si il etait en pause, quand on enpuye espace, le temp commence aa calculer, et on met l'etat active
                else {
                    gettimeofday(fin, NULL);
                    chrono->etat = 0;
                }// sinon on enregistrer le temp final, et met en pause
                break;

            default:
                break;
            }    
        }
}