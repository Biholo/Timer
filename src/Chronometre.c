#include "../include/Chronometre.h"

//Initialisation du chronometre
Chronometre initialiser_chronometre() {
    Chronometre Chrono;
    Chrono.etat = 0;
    Chrono.duration = 0;
    Chrono.avert = 25000;
    Chrono.indice_tour = 0;
    Chrono.total_tour = 0;
    return Chrono;
}

//Ajouter un tour dans chrono à partir de chrono.duration
void ajouter_tour(Chronometre *chrono){ 
    if(chrono->indice_tour < 6)
    {
	    chrono->tours[chrono->indice_tour++] = chrono->duration;
	    chrono->total_tour++;
    }// si le tableu n'a pes ete remplie , on augment l'indice et tour_total
    else{
        for(int i = 0; i < 6; i++){
		    chrono->tours[i] = chrono->tours[i+1];
	    }
        chrono->tours[5] = chrono->duration;
        chrono->total_tour++;
    }//sinon on depllace les tour avant , renouvelle la derniere tour et augment le tour_total
    	
}