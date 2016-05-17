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
		void moveTank(tank &_tank,  int px, int py) {
			//_tank.tanke.x += _tank.tanke.v;
			int vx 		= px - _tank.tanke.x;
			int vy 		= py - _tank.tanke.y;
			if(vx==0) vx+=1; if(vy==0) vy+=1; //float core dumperra arreglateko
			double alfa	= atan2(vy,vx) * 180 / M_PI;
			
			float v 	= sqrt(vx*vx + vy*vy);
			float vx2 = v * sin(alfa*( M_PI / 180));
			float vy2 = v * cos(alfa*( M_PI / 180));
			
			_tank.tanke.x = (int)vx2;
			_tank.tanke.y = (int)vy2;
			
			std::cout << vx << "-" << vy << "-" << alfa << std::endl;
			
			//tag alfa = x/y
			/*vFire[i].v = sqrt(vFire[i].vx*vFire[i].vx + vFire[i].vy*vFire[i].vy);
			vFire[i].vy = vFire[i].v * sin(vFire[i].angle*( M_PI / 180));
			vFire[i].vx = vFire[i].v * cos(vFire[i].angle*( M_PI / 180));*/
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
