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

            case MARIO:
            index = IMG_Load("pack_images_sdz/mario_bas.gif");
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
int erase_double_mario( int tab [nb_bloc_largeur][nb_bloc_hauteur]){
  int i, j;
  for(i=0;i<nb_bloc_largeur;i++){
    for(j=0; j<nb_bloc_hauteur;j++){
        if(tab[i][j] == MARIO){
            tab[i][j] = VIDE;
            return 1;
        }
      }
  }
  return 0;
}
int counting( int tab [nb_bloc_largeur][nb_bloc_hauteur]){

  int i, j;
  int count = 0;
  for(i=0;i<nb_bloc_largeur;i++){
    for(j=0; j<nb_bloc_hauteur;j++){
        if(tab[i][j] == OBJECTIF){
          count = count + 1;
        }
      }
    }
    return count;
}

void mario_move(SDL_Rect * position, int direction, int tab[nb_bloc_largeur][nb_bloc_hauteur] ){

    switch(direction){
        case HAUT:
            switch (tab[position-> x / taille_bloc][(position-> y - taille_bloc) / taille_bloc]) {
              case VIDE:
              tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
              position-> y = position-> y - taille_bloc;
              tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
              break;
              case CAISSE:
              if(tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] == MUR || tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] == CAISSE ||
              tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] == CAISSE_OK)
                break;
              else if(tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] == OBJECTIF){
                tab[position-> x / taille_bloc][(position-> y - taille_bloc) / taille_bloc] = MARIO;
                tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] = CAISSE_OK;
                tab[position-> x / taille_bloc][(position-> y) / taille_bloc] = VIDE;
                break;
              } else{
                tab[position-> x / taille_bloc][(position-> y - taille_bloc) / taille_bloc] = MARIO;
                tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] = CAISSE;
                tab[position-> x / taille_bloc][(position-> y) / taille_bloc] = VIDE;
                break;
              }
              case CAISSE_OK:
              if(tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] == MUR || tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] == CAISSE)
                break;
                else if(tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] == OBJECTIF){
                  tab[position-> x / taille_bloc][(position-> y - taille_bloc) / taille_bloc] = OBJECTIF;
                  tab[position-> x / taille_bloc][(position-> y - 2*taille_bloc) / taille_bloc] = CAISSE_OK;
                  tab[position-> x / taille_bloc][(position-> y) / taille_bloc] = MARIO;
                  break;
                }
              default :
              break;
            }
          break;
          case BAS:
              switch (tab[position-> x / taille_bloc][(position-> y + taille_bloc) / taille_bloc]) {
                case VIDE:
                tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
                position-> y = position-> y + taille_bloc;
                tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
                break;
                case CAISSE:
                if(tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] == MUR || tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] == CAISSE
                || tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] == CAISSE_OK)
                  break;
                else if(tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] == OBJECTIF){
                    tab[position-> x / taille_bloc][(position-> y + taille_bloc) / taille_bloc] = MARIO;
                    tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] = CAISSE_OK;
                    tab[position-> x / taille_bloc][(position-> y) / taille_bloc] = VIDE;
                    break;
                  }else{
                    tab[position-> x / taille_bloc][(position-> y + taille_bloc) / taille_bloc] = MARIO;
                    tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] = CAISSE;
                    tab[position-> x / taille_bloc][(position-> y) / taille_bloc] = VIDE;
                    break;}
            case CAISSE_OK:
                  if(tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] == MUR || tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] == CAISSE)
                    break;
                  else if(tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] == OBJECTIF){
                      tab[position-> x / taille_bloc][(position-> y + taille_bloc) / taille_bloc] = OBJECTIF;
                      tab[position-> x / taille_bloc][(position-> y + 2*taille_bloc) / taille_bloc] = CAISSE_OK;
                      tab[position-> x / taille_bloc][(position-> y) / taille_bloc] = MARIO;
                      break;
                    }
                default :
                break;
              }
            break;
          case GAUCHE:
              switch(tab[(position-> x - taille_bloc)/ taille_bloc][(position-> y)/taille_bloc]) {
                case VIDE:
                tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
                position-> x = position-> x - taille_bloc;
                tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
                break;
                case CAISSE:
                if(tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == MUR || tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y) / taille_bloc] == CAISSE
                || tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y) / taille_bloc] == CAISSE_OK)
                  break;
                else if(tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == OBJECTIF){
                  tab[(position-> x - taille_bloc)/ taille_bloc][(position-> y)/taille_bloc] = MARIO;
                  tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y)/ taille_bloc] = CAISSE_OK;
                  tab[position-> x / taille_bloc][(position-> y)/ taille_bloc] = VIDE;
                  break;
                } else {
                  tab[(position-> x - taille_bloc)/ taille_bloc][(position-> y)/taille_bloc] = MARIO;
                  tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y)/ taille_bloc] = CAISSE;
                  tab[position-> x / taille_bloc][(position-> y)/ taille_bloc] = VIDE;
                  break;
                }
                case CAISSE_OK:
                  if(tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == MUR || tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y) / taille_bloc] == CAISSE)
                    break;
                  else if(tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == OBJECTIF){
                    tab[(position-> x - taille_bloc)/ taille_bloc][(position-> y)/taille_bloc] = OBJECTIF;
                    tab[(position-> x - 2*taille_bloc) / taille_bloc][(position-> y)/ taille_bloc] = CAISSE_OK;
                    tab[position-> x / taille_bloc][(position-> y)/ taille_bloc] = MARIO;
                      break;
                    }
                default :
                break;
              }
            break;
          case DROITE:
                switch(tab[(position-> x + taille_bloc)/ taille_bloc][(position-> y)/taille_bloc]) {
                  case VIDE:
                  tab[position-> x / taille_bloc][position-> y / taille_bloc] = VIDE;
                  position-> x = position-> x + taille_bloc;
                  tab[position-> x / taille_bloc][position-> y / taille_bloc] = MARIO;
                  break;
                  case CAISSE:
                  if(tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == MUR || tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y) / taille_bloc] == CAISSE
                  || tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y) / taille_bloc] == CAISSE_OK)
                    break;
                  else if(tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == OBJECTIF){
                      tab[(position-> x + taille_bloc)/ taille_bloc][(position-> y)/taille_bloc] = MARIO;
                      tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y)/ taille_bloc] = CAISSE_OK;
                      tab[position-> x / taille_bloc][(position-> y)/ taille_bloc] = VIDE;
                        break;
                      } else {
                      tab[(position-> x + taille_bloc)/ taille_bloc][(position-> y)/taille_bloc] = MARIO;
                      tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y)/ taille_bloc] = CAISSE;
                      tab[position-> x / taille_bloc][(position-> y)/ taille_bloc] = VIDE;
                      break; }
                  case CAISSE_OK:
                  if(tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == MUR || tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y) / taille_bloc] == CAISSE)
                  break;
                  else if(tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y ) / taille_bloc] == OBJECTIF){
                    tab[(position-> x + taille_bloc)/ taille_bloc][(position-> y)/taille_bloc] = OBJECTIF;
                    tab[(position-> x + 2*taille_bloc) / taille_bloc][(position-> y)/ taille_bloc] = CAISSE_OK;
                    tab[position-> x / taille_bloc][(position-> y)/ taille_bloc] = MARIO;
                    break;
                      }
                  default :
                  break;
                }
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
