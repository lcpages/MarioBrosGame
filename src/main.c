#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "degrade.h"


#define SIZEX 1024
#define SIZEY 512


int main(int argc, char *argv[])

{
   SDL_Surface * ecran = NULL, * image_de_fond = NULL, * zozor = NULL;
    SDL_Rect position_fond, position_zozor;
    position_zozor.x = 512;
    position_zozor.y = 256;
    position_fond.x = 0;
    position_fond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"), NULL);

    ecran =SDL_SetVideoMode(SIZEX,SIZEY, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Affichage d'image :", NULL);

    image_de_fond = SDL_LoadBMP("pack_images_sdz/lac_en_montagne.bmp");
    SDL_BlitSurface(image_de_fond,NULL, ecran, &position_fond);

    zozor =SDL_LoadBMP("pack_images_sdz/zozor.bmp");

    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    SDL_BlitSurface(zozor, NULL, ecran, &position_zozor);

    SDL_Flip(ecran);
    pause();
    SDL_FreeSurface(image_de_fond);

   SDL_Quit();


    return EXIT_SUCCESS;
}
/*#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Window *window = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              500, 500, SDL_WINDOW_SHOWN);
    if(NULL == window)
        fprintf(stderr, "Erreur de creation de la fenetre : %s\n", SDL_GetError());
    else
    {
        SDL_Delay(500);
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
    return 0;
}
#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Window *window = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              500, 500, SDL_WINDOW_SHOWN);
    if(NULL == window)
        fprintf(stderr, "Erreur de creation de la fenetre : %s\n", SDL_GetError());
    else
    {
        SDL_Delay(500);
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
    return 0;
}*/
