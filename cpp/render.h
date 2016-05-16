#ifndef render_h
#define render_h

class render {
	private:
		int SCREEN_W = 1500, SCREEN_H = 800;
	
		SDL_Window *screen;
	
	public:
		SDL_Renderer *ren;
	
		void createWindow() {
			screen = SDL_CreateWindow("Commandos", 200, 200, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
            ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            
            loadBack();
		}
		
		void renderBack(render _render) {
			SDL_Rect spr = {_render.camboya.x,_render.camboya.y,_render.SCREEN_W,_render.SCREEN_H};
			SDL_Rect dst = {0,0,_render.SCREEN_W,_render.SCREEN_H};
			SDL_RenderCopy(_render.ren, _render.camboya.img, &spr, &dst);
		}
		void moveBack(render &_render, int x, int y) {
			_render.camboya.x = x;
			_render.camboya.y = y;
		}
		
		
		
		void maximizeScreen(render _render) {
			SDL_MaximizeWindow(_render.screen);
		}
		
		void destroyRender(render _render) {
            SDL_DestroyRenderer(_render.ren);
            SDL_DestroyWindow(_render.screen);

            IMG_Quit();
            SDL_Quit();
        }
       
	private:
		struct background {
			SDL_Texture* img;
			int x = 0, y = 0, w, h;
		} camboya;
		void loadBack() {
			int w,h;
			std::string _img = "../img/camboya.jpg";
			SDL_Surface *img = IMG_Load(_img.c_str());
            SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, img);
            SDL_QueryTexture(texture, NULL, NULL, &w, &h);
            SDL_FreeSurface(img);
            camboya.img = texture;
            camboya.w = w;
            camboya.h = h;
		}
};

#endif
