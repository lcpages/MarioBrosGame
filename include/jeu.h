#ifndef _JEU_H_
#define _JEU_H_

#include "degrade.h"


int jeu(SDL_Surface * ecran);


int chargerNiveau(int niveau[nb_bloc_largeur][nb_bloc_hauteur]);

int sauvegarderNiveau(int niveau[nb_bloc_largeur][nb_bloc_hauteur]);

void editeur(SDL_Surface * ecran);
#endif
