#include"display.h"


void display::OnRender(){
    if(game->running == false)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    
    else if(game->gameover == true)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
    }

    else 
    {
        SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
    }
        SDL_RenderClear(renderer);

        
        game->render(renderer);

        
        SDL_RenderPresent(renderer);
    
}


