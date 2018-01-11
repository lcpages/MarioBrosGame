#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeu.h"
#include "degrade.h"


int chargerNiveau(int niveau[][nb_bloc_hauteur]){
    FILE* fichier = NULL;
    char ligneFichier[nb_bloc_largeur * nb_bloc_hauteur + 1] = {0};
    int i = 0, j = 0;
    fichier = fopen("include/niveaux.lvl", "r");
    if (fichier == NULL)
    return 0;

  fgets(ligneFichier, nb_bloc_largeur * nb_bloc_hauteur + 1, fichier);

  for (i = 0 ; i < nb_bloc_largeur ; i++)
{
    for (j = 0 ; j < nb_bloc_hauteur ; j++)
    {
        switch (ligneFichier[(i * nb_bloc_largeur) + j])
        {
            case '0':
                niveau[j][i] = 0;
                break;
            case '1':
                niveau[j][i] = 1;
                break;
            case '2':
                niveau[j][i] = 2;
                break;
            case '3':
                niveau[j][i] = 3;
                break;
            case '4':
                niveau[j][i] = 4;
                break;
              }

      }
  }
  fclose(fichier);
  return 1;
}



int sauvegarderNiveau(int niveau[][nb_bloc_hauteur])
{
    FILE* fichier = NULL;
    int i = 0, j = 0;
    fichier = fopen("niveaux.lvl", "w");
    if (fichier == NULL)
        return 0;
    for (i = 0 ; i < nb_bloc_largeur ; i++)
    {
        for (j = 0 ; j < nb_bloc_hauteur ; j++)
        {
            fprintf(fichier, "%d", niveau[j][i]);
        }
    }
    fclose(fichier);
    return 1;
}

int jeu(SDL_Surface * ecran){


  SDL_Surface * zozor = NULL, * mario[3] = {NULL};
  SDL_Rect position_zozor, position_mur;
  int next = 1, i, j;
  int move = 0;
  SDL_Event event;

  int result = 0;


  mario[0] = IMG_Load("pack_images_sdz/mario_bas.gif");
    mario[1] = IMG_Load("pack_images_sdz/mario_haut.gif");
      mario[2] = IMG_Load("pack_images_sdz/mario_gauche.gif");
        mario[3] = IMG_Load("pack_images_sdz/mario_droite.gif");

zozor = mario[0];

SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 255, 255, 255));

SDL_EnableKeyRepeat(100, 100);
SDL_ShowCursor(SDL_ENABLE);

int map1[nb_bloc_largeur][nb_bloc_hauteur];
 chargerNiveau(map1);


  loadMap(map1, ecran);

  evolue(&position_zozor, map1);


while(next){
  SDL_WaitEvent(&event);
  switch (event.type) {
            case SDL_QUIT:
              next = 0;
            break;
            case SDL_KEYDOWN:
               switch(event.key.keysym.sym){
                    case SDLK_UP:
                      mario_move(&position_zozor,HAUT,map1);
                      zozor = mario[1];
                      break;
                    case SDLK_DOWN:
                      mario_move(&position_zozor,BAS,map1);
                      zozor = mario[0];
                      break;
                    case SDLK_LEFT:
                      mario_move(&position_zozor,GAUCHE,map1);
                      zozor = mario[2];
                      break;
                    case SDLK_RIGHT:
                      mario_move(&position_zozor,DROITE,map1);
                      zozor = mario[3];
                      break;
                    case SDLK_ESCAPE:
                      next=0;
                      break;
                    }

                }
      SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 255, 255, 255));

      loadMap(map1, ecran);
      result =  counting( map1);
      evolue(&position_zozor, map1);
      SDL_BlitSurface(zozor,NULL,ecran, &position_zozor);
      SDL_Flip(ecran);
      if( result == 0) next = 0;
}

SDL_FreeSurface(zozor);
SDL_FreeSurface(ecran);
return 1;
}
