#include <iostream>
#include <cmath>

#include "point.h"
#include "collision.h"
#include "rocket.h"
#include "SDL_Plotter.h"
#include "graphics.h"
#include "constants.h"
#include "Asteroid.h"
#include "force.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char ** argv){
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

    while (!g.getQuit()) {

    	// Utilize SDL2 directly as there is no method in plotter
    	// For detecting a key being held but rather only when
    	// it's hit
        const Uint8* state = SDL_GetKeyboardState(NULL);

        if(state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
            ship.thrust();
        }

        if(state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
            ship.rotatePolygonAtDistance(-0.031415);
        }

        if(state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
            ship.rotatePolygonAtDistance(0.031415);
        }

        if(state[SDL_SCANCODE_C]) {
            g.clear();
        }

		g.clear();
	    for (Asteroid& asteroid : asteroids) {
	    	asteroid.erase(g);
	        asteroid.move();
	        asteroid.draw(g);
	    }

	    //Check collisions
	    for(Asteroid& asteroid : asteroids) {
	    	if(isColliding(ship.getBoundary(), asteroid.getBoundary())){
	    		cout << "Collision DETECTED!" << endl;
	    	}

	    	//Another loop will be needed here once bullets work!
	    }

	    ship.move();
	    ship.draw(g);
	    g.update();

    	}

    return 0;
}
