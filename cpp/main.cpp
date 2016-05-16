    #include <iostream>
    #include <vector>
    #include <math.h>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"
    #include "tank.h"

    int main() {
		bool running = true;
		int frametime;
		
        render _render;
        tank _tank;
        SDL_Event event;
        
        _render.createWindow();
        _tank.loadTank(_render);
        
        while(running) {
			frametime = SDL_GetTicks();
			while(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT) running  = false;
				if(event.type == SDL_KEYDOWN) {
					switch(event.key.keysym.sym) {
						case SDLK_ESCAPE: running  = false; break;
					}
				}
				/*if(event.type == SDL_MOUSEMOTION) {
					switch(event.button.button) {
						case SDL_BUTTON_MIDDLE: running  = false; break;
					}
				}*/
				if(event.type == SDL_MOUSEBUTTONDOWN) {
					switch(event.button.button) {
						case SDL_BUTTON_RIGHT: _render.moveBack(_render, event.button.x, event.button.y); break;
					}
				}
				//if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_MAXIMIZED)  maximizekeran mobidek itzeko
				
			}
			
			SDL_RenderClear(_render.ren);
            _render.renderBack(_render);
            _tank.renderTank(_render, _tank);
            SDL_RenderPresent(_render.ren);
			
			
			frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));
		}
		
		_render.destroyRender(_render);
	}
