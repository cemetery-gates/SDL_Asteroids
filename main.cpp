#include <iostream>
#include <cmath>

#include "point.h"
#include "rocket.h"
#include "SDL_Plotter.h"
#include "graphics.h"
#include "constants.h"

using namespace std;

int main(int argc, char ** argv)
{
    int speed = 0;
    SDL_Plotter g(COL,ROW);
    point p;
    color c;
    int size;
    Uint32 RGB;
    Rocket ship;


    vector<int> rocket_x(4), rocket_y(4);
    rocket_x[0] = 0;
    rocket_x[1] = 40;
    rocket_x[2] = 0;
    rocket_x[3] = 20;

    rocket_y[0] = 0;
    rocket_y[1] = 10;
    rocket_y[2] = 20;
    rocket_y[3] = 10;

    g.clear();

    while (!g.getQuit())
    {

		if(g.kbhit()){
			switch(toupper(g.getKey())){
				case 'C': g.clear();
				          break;
				case 'W':
                case UP_ARROW: ship.thrust();
                               break;
                case 'A':
                case LEFT_ARROW: ship.rotatePolygonAtDistance(-0.0628);
                               break;
                case 'D':
                case RIGHT_ARROW: ship.rotatePolygonAtDistance(0.0628);
                                break;
			}
		}
    	//cout << "Hello WOrld" << endl;

		c.R = rand()%256;
		c.G = rand()%256;
		c.B = rand()%256;
		//drawLine(rand()%COL, rand()%ROW, rand()%COL, rand()%ROW, c, g);

		//drawPoly(rocket_x, rocket_y, c, g);

		//movePoly(rocket_x, rocket_y, speed);

		//drawPoly(rocket_x, rocket_y, c, g);
		/*if(g.mouseClick()){
			p = g.getMouseClick();
			size = rand()%50;
			c.R  = rand()%256;
			c.G  = rand()%256;
			c.B  = rand()%256;
			//drawCircle(p, size, c, g);
		}*/

		ship.draw(g);
		g.update();
		ship.erase(g);
        ship.move();

    }
}
