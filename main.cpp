#include <iostream>
#include <cmath>

#include "point.h"
#include "rocket.h"
#include "SDL_Plotter.h"
#include "graphics.h"
#include "constants.h"
#include "Asteroid.h"
#include "force.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char ** argv)
{
    srand(time(0));
    SDL_Plotter g(COL,ROW);
    point p;
    color c;
    Rocket ship;
    Asteroid a1, a2, a3, a4, a5;
    vector<Asteroid> asteroids{
        Asteroid((2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid((2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid((2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid((2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid((2 * M_PI) * (rand() / static_cast<double>(RAND_MAX)))
    };

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
                case LEFT_ARROW: ship.rotatePolygonAtDistance(-0.0628*2.5);
                               break;
                case 'D':
                case RIGHT_ARROW: ship.rotatePolygonAtDistance(0.0628*2.5);
                                break;
			}
		}

		g.clear();
	    for (Asteroid& asteroid : asteroids) {
	    	asteroid.erase(g);
	        asteroid.move();
	        asteroid.draw(g);
	    }
	    ship.move();
	    ship.draw(g);
        g.update();

    }
    return 0;

}
