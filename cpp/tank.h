#ifndef tank_h
#define tank_h

class tank {
	private:
		struct item {
			SDL_Texture* img;
			int spr = 0, x = 0, y = 0, w, h;
		};
		item tanke;
	
	public:
		void loadTank(render _render) {
			std::string _img = "../img/tank.png";
			SDL_Surface *img = IMG_Load(_img.c_str());
            SDL_Texture *texture = SDL_CreateTextureFromSurface(_render.ren, img);
            SDL_FreeSurface(img);
		}
	
		void renderTank(render _render, tank _tank) {
			SDL_Rect spr = {0,0,200,200};
			SDL_Rect dst = {0,0,200,200};
			SDL_RenderCopy(_render.ren, _tank.tanke.img, &spr, &dst);
		}
};

#endif
