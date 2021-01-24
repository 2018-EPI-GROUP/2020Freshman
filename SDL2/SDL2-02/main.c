#include <stdio.h>
#include <SDL2/SDL.h>

#define  WIDTH 800
#define HEIGHT 600


void event_loop() {
    while(1){
        SDL_Event event;
        if (SDL_PollEvent(&event)) {//Have Event
            switch (event.type) {
                case SDL_QUIT://Closing Window
                    return;
                default:
                    break;
            }
        }
    }
}

int main() {
    //Init
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("Error,%s",SDL_GetError());
    }
    //Create Window
    SDL_Window *win=SDL_CreateWindow("HelloWorld",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    //Get Surface Filled by White(ARGB)
    SDL_Surface *screen=SDL_GetWindowSurface(win);
    SDL_Rect r={0,0,WIDTH,HEIGHT};
    SDL_FillRect(screen,&r,0xffffffff);
    SDL_UpdateWindowSurface(win);
    //Show Window EventLoop
    SDL_ShowWindow(win);
    event_loop();
    //DestoryWindow
    SDL_DestroyWindow(win);
    return 0;
}
