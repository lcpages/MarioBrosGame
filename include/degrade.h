#ifndef __DEGRADE_H_
#define __DEGRADE_H_

#define taille_bloc 34
#define nb_bloc_largeur 12
#define nb_bloc_hauteur 12

#define SIZEX taille_bloc * nb_bloc_largeur
#define SIZEY taille_bloc * nb_bloc_hauteur


enum {VIDE, MUR, CAISSE, OBJECTIF, MARIO, CAISSE_OK};
enum {HAUT, BAS, GAUCHE, DROITE};

void pause();

void loadMap(int tab [nb_bloc_largeur][nb_bloc_hauteur], SDL_Surface * ecran);

void evolue(SDL_Rect * ecran, int tab [nb_bloc_largeur][nb_bloc_hauteur]);

void mario_move(SDL_Rect  * position, int direction, int tab [nb_bloc_largeur][nb_bloc_hauteur]);

int erase_double_mario( int tab [nb_bloc_largeur][nb_bloc_hauteur]);

int counting( int tab [nb_bloc_largeur][nb_bloc_hauteur]);


#endif
