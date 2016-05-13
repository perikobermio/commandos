    #include <iostream>
    #include <vector>
    #include <math.h>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"

    int main() {
		bool running = true;
        render _render;
        SDL_Event event;
        
        _render.createWindow();
        
        while(running) {
			while(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT) running  = false;
			}
		}
	}
