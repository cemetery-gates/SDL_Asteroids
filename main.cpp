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

int main(int argc, char** argv) {
    srand(time(0));
    SDL_Plotter g(COL, ROW);
    point p;
    color c;
    Rocket ship;
    // Initialize vector with 5 Large asteroids to start
    vector<Asteroid> asteroids{
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
    };

    g.clear();

    while (!g.getQuit()) {
        const Uint8* state = SDL_GetKeyboardState(NULL);

        if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
            ship.thrust();
        }

        if (state[SDL_SCANCODE_SPACE]) {
            ship.fireBullet(g);
        }

        ship.updateBullets(g);

        if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
            ship.rotatePolygonAtDistance(-0.031415);
        }

        if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
            ship.rotatePolygonAtDistance(0.031415);
        }

        if (state[SDL_SCANCODE_C]) {
            g.clear();
        }

        g.clear();

        vector<pair<AsteroidSize, point_t>> toMake;

        //Bullet hits an asteroid
        for (Bullet& bullet : ship.bullets) {
            for (auto it = asteroids.begin(); it != asteroids.end();) {
                if (isColliding(bullet.getBoundary(), it->getBoundary())) {
                    bullet.isColliding();
                    toMake.push_back({it->getSize(), it->getPosition()});
                    it = asteroids.erase(it);
                } else {
                    ++it;
                }
            }
        }

        for (auto const& [size, pos] : toMake) {
            if (size == AsteroidSize::LARGE) {
                asteroids.push_back(Asteroid(AsteroidSize::MEDIUM, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::MEDIUM, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
            } else if (size == AsteroidSize::MEDIUM) {
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
            }
        }

        //Game over if ship hits an asteroid
        for (const Asteroid& asteroid : asteroids) {
            if (isColliding(asteroid.getBoundary(), ship.getBoundary())) {
                g.clear();
                g.update();
                SDL_Delay(500);  // Pause for 0.5 seconds before exiting
                g.setQuit(true);
                return 0;
            }
        }

        //If all asteroids are destroyed
        if (asteroids.empty()) {
            // Spawn new asteroids
            for (int i = 0; i < 5; i++) {
                point_t position(rand() % COL + 10, rand() % ROW + 10);
                asteroids.push_back(Asteroid(AsteroidSize::LARGE, position, (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))));
            }
        }


        ship.move();
        ship.erase(g);
        ship.draw(g);

        for (Asteroid& asteroid : asteroids) {
            asteroid.erase(g);
            asteroid.move();
            asteroid.draw(g);
        }

        for (Bullet& bullet : ship.bullets) {
            bullet.move();
            bullet.draw(g);
        }

        g.update();
    }

    return 0;
}
