#include <iostream>
#include <cmath>
#include <utility>
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
    //Initialize vector with 5 Large asteroids to start
    vector<Asteroid> asteroids {
        Asteroid(AsteroidSize::LARGE, point_t(rand()%COL+10,rand()%ROW+10),
        		(2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
		Asteroid(AsteroidSize::LARGE, point_t(rand()%COL+10,rand()%ROW+10),
				(2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
		Asteroid(AsteroidSize::LARGE, point_t(rand()%COL+10,rand()%ROW+10),
				(2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
		Asteroid(AsteroidSize::LARGE, point_t(rand()%COL+10,rand()%ROW+10),
				(2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
		Asteroid(AsteroidSize::LARGE, point_t(rand()%COL+10,rand()%ROW+10),
				(2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),

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
	//FIXME: add collision mechanic for bullets
        //press space key to shoot bullets
	if (state[SDL_SCANCODE_SPACE]) {
	    ship.fireBullet(g);
	}
	ship.updateBullets(g);

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

        // Move and draw asteroids
        for (Asteroid& asteroid : asteroids) {
            asteroid.erase(g);
            asteroid.move();
            asteroid.draw(g);
        }

        // Check for collisions and erase asteroid
        vector<pair<AsteroidSize, point_t>> toMake;

        for (auto it = asteroids.begin(); it != asteroids.end(); ) {
        	//SHIP WILL BE REPLACED WITH A BULLET
            if(isColliding(ship.getBoundary(), it->getBoundary())) {
                toMake.push_back({it->getSize(), it->getPosition()});
                it = asteroids.erase(it);
            } else {
                ++it;
            }
        }

        for (auto const& [size, pos] : toMake) {
            if(size == AsteroidSize::LARGE) {
                asteroids.push_back(Asteroid(AsteroidSize::MEDIUM, pos,
                		(2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::MEDIUM, pos,
                		(2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
            } else if(size == AsteroidSize::MEDIUM) {
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                		(2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                		(2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                		(2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
            }
        }

        ship.move();
        ship.draw(g);
        g.update();
    }

    return 0;
}
