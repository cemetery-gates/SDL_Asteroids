#ifndef ROCKET_H_INCLUDED
#define ROCKET_H_INCLUDED

#include "force.h"
#include "point.h"
#include "SDL_Plotter.h"
#include "constants.h"
#include "graphics.h"
#include "collision.h"
#include "bullets.h"
#include "Asteroid.h"
#include <vector>
#include <algorithm>
using namespace std;

class Bullet;

class Rocket{
    private:
        point_t loc, center;
        force f;
        color c;
        vector<point_t> shape;
        Boundary bounds;
        double direction = 0;


    public:
        Rocket();
        //void setLocation(const point&);
        //point getLocation() const;
        void draw(SDL_Plotter& g);
        void erase(SDL_Plotter& g);
        void setDirection(double d);
        double getDirection() const;
        void thrust();
        void decelerate();
        void move();
        void rotatePolygonAtDistance(double theta);
        void translatePolygon(double dx, double dy);
        void rotatePolygon(double theta);
        Boundary getBoundary();
        void fireBullet(SDL_Plotter& g);
        void updateBullets(SDL_Plotter& g);
        vector<Bullet> bullets;
        vector<Asteroid> asteroids;

};

#endif // ROCKET_H_INCLUDED
