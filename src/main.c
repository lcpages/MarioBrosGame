#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "degrade.h"
#include <SDL/SDL_image.h>


int main(int argc, char *argv[])

{
      SDL_Surface * ecran = NULL,* zozor = NULL, * mario[3] = {NULL};
      SDL_Rect position_zozor, position_mur;
      int next = 1, i, j;
      int move = 0;
      SDL_Event event;

      mario[0] = IMG_Load("pack_images_sdz/mario_bas.gif");
        mario[1] = IMG_Load("pack_images_sdz/mario_haut.gif");
          mario[2] = IMG_Load("pack_images_sdz/mario_gauche.gif");
            mario[3] = IMG_Load("pack_images_sdz/mario_droite.gif");



    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"), NULL);

    ecran =SDL_SetVideoMode(SIZEX,SIZEY, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    SDL_WM_SetCaption("Mario Game", NULL);

    zozor = mario[0];

    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 255, 255, 255));

    SDL_EnableKeyRepeat(100, 100);
    SDL_ShowCursor(SDL_ENABLE);

    int map1[nb_bloc_largeur][nb_bloc_hauteur] = {{1,1,1,0,0,1,1,1,1,1,1,1},{1,1,1,3,0,0,1,1,1,1,1,1},
    {1,1,1,3,0,0,1,1,1,1,1,1},{1,1,1,1,0,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,1,3,1,1,1},{0,4,0,1,2,1,0,1,0,1,1,1},
    {0,0,0,0,0,0,0,1,0,1,1,1},{1,0,1,1,0,0,0,1,0,1,1,1},
    {1,0,1,1,1,0,1,1,0,1,1,1},{1,0,0,0,2,0,2,0,0,1,1,1},
    {1,0,0,0,1,1,1,0,0,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1}};
    loadMap(map1, ecran);


    evolue(&position_zozor, map1);
        printf("%d %d\n", position_zozor.x, position_zozor.y );

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
                        }

      }
      SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 255, 255, 255));

      loadMap(map1, ecran);
      evolue(&position_zozor, map1);
      SDL_BlitSurface(zozor,NULL,ecran, &position_zozor);
      SDL_Flip(ecran);
    }

    SDL_FreeSurface(zozor);
    SDL_FreeSurface(ecran);
    SDL_Quit();


    return EXIT_SUCCESS;
}
