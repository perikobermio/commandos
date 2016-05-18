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
			int x = 0, y = 0, w, h;
			bool moving = false;
			int x2,y2; 
		} tanke;
	
	public:
		void loadTank(render _render) {
			std::string _img = "../img/tank.png";
			SDL_Surface *img = IMG_Load(_img.c_str());
            SDL_Texture *texture = SDL_CreateTextureFromSurface(_render.ren, img);
            SDL_FreeSurface(img);
            tanke.img = texture;
            tanke.spr = sprTanke.spr_10;
		}
		
		void setMoveTank(tank &_tank, int x, int y) {
			_tank.tanke.moving = true;
			_tank.tanke.x2 = x;
			_tank.tanke.y2 = y;
		}
		
		void moveTank(tank &_tank) {
			int vx 		= _tank.tanke.x2 - _tank.tanke.x;
			int vy 		= _tank.tanke.y2 - _tank.tanke.y;
			if(vx==0) vx+=1; if(vy==0) vy+=1; //float core dumperra arreglateko
			double alfa	= atan2(vy,vx) * 180 / M_PI;
			
			_tank.tanke.x += (int)(2*cos(alfa*( M_PI / 180)));
			_tank.tanke.y += (int)(2*sin(alfa*( M_PI / 180)));
		}
	
		void renderTank(render _render, tank &_tank) {
			if(_tank.tanke.moving) _tank.moveTank(_tank);
			
			SDL_Rect dst = {_tank.tanke.x,_tank.tanke.y,134,77};
			SDL_RenderCopy(_render.ren, _tank.tanke.img, &_tank.tanke.spr, &dst);
		}
};

#endif
