#ifndef tank_h
#define tank_h

class tank {
	private:
		struct sprItem {
			SDL_Rect spr_10 = {0,32,134,77};
		} sprTanke;
		
		struct item {
			SDL_Texture* img;
			SDL_Rect spr;
			int x = 0, y = 0, w, h, v = 1;
		} tanke;
	
	public:
		void moveTank(tank &_tank,  int x, int y) {
			_tank.tanke.x += _tank.tanke.v;
		}
	
	
		void loadTank(render _render) {
			std::string _img = "../img/tank.png";
			SDL_Surface *img = IMG_Load(_img.c_str());
            SDL_Texture *texture = SDL_CreateTextureFromSurface(_render.ren, img);
            SDL_FreeSurface(img);
            tanke.img = texture;
            tanke.spr = sprTanke.spr_10;
		}
	
		void renderTank(render _render, tank _tank) {
			SDL_Rect dst = {_tank.tanke.x,_tank.tanke.y,134,77};
			SDL_RenderCopy(_render.ren, _tank.tanke.img, &_tank.tanke.spr, &dst);
		}
};

#endif
