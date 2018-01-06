#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "degrade.h"
#include <SDL/SDL_image.h>


#define SIZEX 1024
#define SIZEY 512


int main(int argc, char *argv[])

{
      SDL_Surface * ecran = NULL, * zozor = NULL;
      SDL_Rect position_zozor;
      int next = 1;
      SDL_Event event;


    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"), NULL);

    ecran =SDL_SetVideoMode(SIZEX,SIZEY, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Affichage d'image :", NULL);


    zozor =SDL_LoadBMP("pack_images_sdz/zozor.bmp");

    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    position_zozor.x = ecran->w / 2 - zozor->w / 2;
    position_zozor.y = ecran->h / 2 - zozor->h / 2;

    SDL_EnableKeyRepeat(10, 10);
    SDL_ShowCursor(SDL_ENABLE);

    while(next){
      SDL_WaitEvent(&event);
      switch (event.type) {
        case SDL_QUIT:
          next = 0;
          break;
        case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_RIGHT){next = 0 ;}
                if(event.button.button == SDL_BUTTON_LEFT){
                  position_zozor.x = event.button.x;
                  position_zozor.y = event.button.y;
                }
          break;
        /* case SDL_MOUSEMOTION:
            position_zozor.x = event.motion.x;
            position_zozor.y = event.motion.y;
          break; */
        case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_UP:
                      position_zozor.y--;
                      break;
                    case SDLK_DOWN:
                      position_zozor.y++;
                      break;
                    case SDLK_LEFT:
                      position_zozor.x--;
                      break;
                    case SDLK_RIGHT:
                      position_zozor.x++;
                      break;
                    case SDLK_ESCAPE:
                      next = 0;
                      break;
                }
            break;
      }
      SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 0, 0, 0));
      SDL_BlitSurface(zozor,NULL,ecran, &position_zozor);
      SDL_Flip(ecran);
    }

  //  pause();
    SDL_FreeSurface(zozor);
    SDL_Quit();


    return EXIT_SUCCESS;
}
