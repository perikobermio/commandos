#ifndef render_h
#define render_h

class render {
	private:
		int SCREEN_W = 500, SCREEN_H = 500;
	
		SDL_Renderer *ren;
		SDL_Window *screen;
	
	public:
		void createWindow() {
			screen = SDL_CreateWindow("Commandos", 0, 0, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
            ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}
};

#endif
