#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "degrade.h"
#include "jeu.h"


int main(int argc, char *argv[])
{
    SDL_Surface * ecran = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"), NULL);

    ecran =SDL_SetVideoMode(SIZEX,SIZEY, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Mario Game", NULL);


    jeu(ecran);
    SDL_Quit();

    return EXIT_SUCCESS;
}
