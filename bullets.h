#ifndef BULLETS_H_INCLUDED
#define BULLETS_H_INCLUDED

#include "point.h"
#include "SDL_Plotter.h"
#include "constants.h"
#include "graphics.h"
#include "rocket.h"
#include "Asteroid.h"

class Bullet {
    private:
        point_t loc;
        force f;
        color c;
        bool offScreen;
        bool hasCollided;

    public:
        Bullet(point_t location, double direction);
        void draw(SDL_Plotter& g);
        void erase(SDL_Plotter& g);
        void move();
        bool isOffScreen() const;
        bool isColliding() const;
        Boundary getBoundary() const;
};


#endif // BULLETS_H_INCLUDED
