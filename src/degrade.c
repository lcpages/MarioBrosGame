#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "degrade.h"




void loadMap(int tab[nb_bloc_largeur][nb_bloc_hauteur], SDL_Surface * ecran){

  int i, j;
  SDL_Surface * index = NULL;
  SDL_Rect position_index ;

      for(j=0;j<nb_bloc_largeur;j++){
        for(i=0; i<nb_bloc_hauteur;i++){

          switch (tab[i][j]) {
            case MUR:
            index = IMG_Load("pack_images_sdz/mur.jpg");
            position_index.x = i * taille_bloc;
            position_index.y = j * taille_bloc;
            SDL_BlitSurface(index,NULL,ecran, &position_index);
            break;

            case CAISSE:
            index = IMG_Load("pack_images_sdz/caisse.jpg");
            position_index.x = i * taille_bloc;
            position_index.y = j * taille_bloc;
            SDL_BlitSurface(index,NULL,ecran, &position_index);
            break;

            case OBJECTIF:
            index = IMG_Load("pack_images_sdz/objectif.png");
            position_index.x = i * taille_bloc;
            position_index.y = j * taille_bloc;
            SDL_BlitSurface(index,NULL,ecran, &position_index);
            break;

            case CAISSE_OK:
            index = IMG_Load("pack_images_sdz/caisse_ok.jpg");
            position_index.x = i * taille_bloc;
            position_index.y = j * taille_bloc;
            SDL_BlitSurface(index,NULL,ecran, &position_index);
            break;

        /*    case MARIO:
            switch (move) {
              case 0:
              index = IMG_Load("pack_images_sdz/mario_bas.gif");
              break;
              case 1:
              index = IMG_Load("pack_images_sdz/mario_haut.gif");
              break;
              case 2:
              index = IMG_Load("pack_images_sdz/mario_gauche.gif");
              break;
              case 3:
              index = IMG_Load("pack_images_sdz/mario_droite.gif");
              break;
            }
            position_index.x = i * taille_bloc;
            position_index.y = j * taille_bloc;
            SDL_BlitSurface(index,NULL,ecran, &position_index);
            break;*/
          }
        }
      }
}
void evolue(SDL_Rect * mario_pos, int tab [nb_bloc_largeur][nb_bloc_hauteur]){
  int i, j;
  for(j=0;j<nb_bloc_largeur;j++){
    for(i=0; i<nb_bloc_hauteur;i++){
        if(tab[i][j] == MARIO){
            mario_pos->x = i * taille_bloc;
            mario_pos->y = j * taille_bloc;
        }
  }
}}

void mario_move(SDL_Rect * position, int direction, int tab[nb_bloc_largeur][nb_bloc_hauteur] ){

    switch(direction){
        case HAUT:
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
          position-> y = position-> y - taille_bloc;
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
          break;
        case BAS:
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
          position-> y = position-> y + taille_bloc;
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
          break;
        case GAUCHE:
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
          position-> x  = position-> x - taille_bloc;
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
          break;
        case DROITE:
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
          position-> x  = position-> x + taille_bloc;
          tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
          break;
        }
}
void pause()
{
    int continuer = 1;
    SDL_Event event;
    while(continuer){
            SDL_WaitEvent(&event);
             switch(event.type){
                  case SDL_QUIT:
                             continuer = 0;
                             break;
                  case SDL_KEYDOWN:
                            switch (event.key.keysym.sym) {
                              break;
                            }
                            break;
             }
    }
}
