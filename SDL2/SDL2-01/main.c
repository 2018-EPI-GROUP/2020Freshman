#include <stdio.h>
#include <SDL2/SDL.h>

#define  WIDTH 400
#define HEIGHT 300
int main() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("Error,%s",SDL_GetError());
    }
    SDL_Window *win=SDL_CreateWindow("HelloWorld",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    SDL_ShowWindow(win);
    SDL_Delay(5000);
    return 0;
}
