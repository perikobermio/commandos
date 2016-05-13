    #include <iostream>
    #include <vector>
    #include <math.h>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"

    int main() {
		bool running = true;
		int frametime;
		
        render _render;
        SDL_Event event;
        
        _render.createWindow();
        
        while(running) {
			frametime = SDL_GetTicks();
			while(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT) running  = false;
			}
			frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));
		}
		
		_render.destroyRender(_render);
	}
