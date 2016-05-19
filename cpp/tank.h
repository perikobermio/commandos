#ifndef tank_h
#define tank_h

class tank {
	private:
		struct sprItem {
			SDL_Rect 	spr_l = {0,32,134,77}, 			spr_lt1 = {135,21,146,88}, 		spr_lt2 = {282,10,147,99}, 
						spr_lt3 = {430,3,141,106},		spr_lt4 = {571,0,123,109},		spr_lt5 = {695,1,98,108},
						spr_t = {794,7,72,102},			spr_tr1 = {867,1,97,108},		spr_tr2 = {965,0,123,109},
						spr_tr3 = {1089,3,140,106},		spr_tr4 = {1230,9,147,100},		spr_tr5 = {1378,15,145,94},
						spr_r = {1524,13,134,96},		spr_rb1 = {1378,129,145,90},	spr_rb2 = {1230,132,147,99},
						spr_rb3 = {1089,134,140,104},	spr_rb4 = {965,133,123,106},	spr_rb5 = {867,134,97,106},
						spr_b = {794,133,72,98},		spr_bl1 = {696,127,97,105},		spr_bl2 = {572,116,123,109},
						spr_bl3 = {431,110,140,105},	spr_bl4 = {282,110,147,99},		spr_bl5 = {135,110,146,88};
		} sprTanke; //15º-ko inbide kanbijue
		
		struct item {
			SDL_Texture* img;
			SDL_Rect spr;
			int x = 200, y = 200, w, h, vx, vy;
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
            tanke.spr = sprTanke.spr_bl1;
		}
		
		void setMoveTank(tank &_tank, int x, int y) {
			_tank.tanke.moving = true;
			_tank.tanke.x2 = x;
			_tank.tanke.y2 = y;
			
			int vx 		= _tank.tanke.x2 - _tank.tanke.x;
			int vy 		= _tank.tanke.y2 - _tank.tanke.y;
			if(vx==0) vx+=1; if(vy==0) vy+=1; //float core dumperra arreglateko
			double alfa	= atan2(vy,vx) * 180 / M_PI;
			
			_tank.tanke.vx = (int)(2*cos(alfa*( M_PI / 180)));
			_tank.tanke.vy = (int)(2*sin(alfa*( M_PI / 180)));
			
			_tank.tanke.spr = _tank.setSpr(alfa);
		}
	
		void renderTank(render _render, tank &_tank) {
			//if(_tank.tanke.moving) _tank.moveTank(_tank);
			if(_tank.tanke.moving) {
				_tank.tanke.x += _tank.tanke.vx;
				_tank.tanke.y += _tank.tanke.vy;
			}
			
			SDL_Rect dst = {_tank.tanke.x,_tank.tanke.y,_tank.tanke.spr.w,_tank.tanke.spr.h};
			SDL_RenderCopy(_render.ren, _tank.tanke.img, &_tank.tanke.spr, &dst);
		}
		
		private:
			void moveTank(tank &_tank) {
				int vx 		= _tank.tanke.x2 - _tank.tanke.x;
				int vy 		= _tank.tanke.y2 - _tank.tanke.y;
				if(vx==0) vx+=1; if(vy==0) vy+=1; //float core dumperra arreglateko
				double alfa	= atan2(vy,vx) * 180 / M_PI;
				
				_tank.tanke.x += (int)(2*cos(alfa*( M_PI / 180)));
				_tank.tanke.y += (int)(2*sin(alfa*( M_PI / 180)));
				
				_tank.tanke.spr = _tank.setSpr(alfa);
			}
			
			SDL_Rect setSpr(double alfa) {
				if(alfa>=-10 	&& alfa<5) 		return sprTanke.spr_r;
				if(alfa>=5 		&& alfa<20) 	return sprTanke.spr_rb1;
				if(alfa>=20 	&& alfa<35) 	return sprTanke.spr_rb2;
				if(alfa>=35 	&& alfa<50) 	return sprTanke.spr_rb3;
				if(alfa>=50 	&& alfa<65) 	return sprTanke.spr_rb4;
				if(alfa>=65 	&& alfa<80) 	return sprTanke.spr_rb5;
				
				if(alfa>=80 	&& alfa<95) 	return sprTanke.spr_b;
				if(alfa>=95 	&& alfa<110) 	return sprTanke.spr_bl1;
				if(alfa>=110 	&& alfa<125) 	return sprTanke.spr_bl2;
				if(alfa>=125 	&& alfa<140) 	return sprTanke.spr_bl3;
				if(alfa>=140 	&& alfa<155) 	return sprTanke.spr_bl4;
				if(alfa>=155 	&& alfa<170) 	return sprTanke.spr_bl5;
				
				if(alfa>=170 	|| alfa< -175) 	return sprTanke.spr_l;
				if(alfa>= -175 	&& alfa< -160) 	return sprTanke.spr_lt1;
				if(alfa>= -160 	&& alfa< -145) 	return sprTanke.spr_lt2;
				if(alfa>= -145 	&& alfa< -130) 	return sprTanke.spr_lt3;
				if(alfa>= -130 	&& alfa< -115) 	return sprTanke.spr_lt4;
				if(alfa>= -115 	&& alfa< -100) 	return sprTanke.spr_lt5;
				
				if(alfa>= -100 	&& alfa< -85) 	return sprTanke.spr_t;
				if(alfa>= -85 	&& alfa< -70) 	return sprTanke.spr_tr1;
				if(alfa>= -70 	&& alfa< -55) 	return sprTanke.spr_tr2;
				if(alfa>= -55 	&& alfa< -40) 	return sprTanke.spr_tr3;
				if(alfa>= -40 	&& alfa< -25) 	return sprTanke.spr_tr4;
				if(alfa>= -25 	&& alfa< -10) 	return sprTanke.spr_tr5;
				
				return sprTanke.spr_rb5;
			}
};

#endif
