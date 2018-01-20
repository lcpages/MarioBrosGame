#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "degrade.h"
#include "jeu.h"


int main(int argc, char *argv[])
{
    SDL_Surface * ecran = NULL, * menu = NULL;
    SDL_Rect position_menu;
    int continuer = 1;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"), NULL);

    ecran =SDL_SetVideoMode(SIZEX,SIZEY, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Mario Game", NULL);

    menu = IMG_Load("pack_images_sdz/10121.jpg");
    position_menu.x = 0;
    position_menu.y = 0;
    SDL_BlitSurface(menu, NULL, ecran, &position_menu );

    while (continuer)
     {
         SDL_WaitEvent(&event);
         switch(event.type)
         {
             case SDL_QUIT:
                 continuer = 0;
                 break;
             case SDL_KEYDOWN:
                 switch(event.key.keysym.sym)
                 {
                     case SDLK_ESCAPE: // Veut arrêter le jeu
                         continuer = 0;
                         break;
                     case SDLK_KP1: // Demande à jouer
                          jeu(ecran);
                         break;
                     case SDLK_KP2: // Demande l'éditeur de niveaux
                         editeur(ecran);
                         break;
                 }
                 break;
         }

         SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 255, 255, 255));
         SDL_BlitSurface(menu, NULL, ecran, &position_menu );
         SDL_Flip(ecran);
       }

    SDL_Quit();

    return EXIT_SUCCESS;
}
