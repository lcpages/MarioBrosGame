#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

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
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Mon projet intitial",NULL);
    SDL_SetVideoMode(1020, 720, 32, SDL_HWSURFACE);


    pause();
    SDL_Quit();

    return EXIT_SUCCESS;

}
