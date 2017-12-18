#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#define SIZEX 1024
#define SIZEY 512

void pause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}


int main(int argc, char *argv[])

{
    SDL_Surface * ecran = NULL;

    SDL_Surface * tab_ligne[SIZEY] = {NULL};
    SDL_Rect position;

    int i,j;
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<SIZEY; i++)
        tab_ligne[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,SIZEX,1, 32,0,0,0,0);

    SDL_WM_SetCaption("Mon projet intitial",NULL);
    ecran = SDL_SetVideoMode(SIZEX, SIZEY, 32, SDL_HWSURFACE);

    Uint32 Redcolor = SDL_MapRGB(ecran->format, 0, 0, 0);
    SDL_FillRect(ecran, NULL, Redcolor);


    for(i=0; i<SIZEY; i++){
      j = i/2;
      position.x=0;
      position.y = i;
      SDL_FillRect(tab_ligne[i],NULL,SDL_MapRGB(ecran->format, j, j, j));
      SDL_BlitSurface(tab_ligne[i], NULL, ecran, &position);
    }
    SDL_Flip(ecran);

    pause();

      for(i=0;i<SIZEY; i++){
        SDL_FreeSurface(tab_ligne[i]);
      }
    SDL_Quit();

    return EXIT_SUCCESS;

}
