/*
 * Asteroid.h
 *
 *  Created on: Jul 1, 2023
 *      Author: logan
 */


#ifndef ASTEROID_H_
#define ASTEROID_H_
#include "point.h"
#include "graphics.h"
#include "force.h"
#include "collision.h"

enum class AsteroidSize {
    SMALL,
    MEDIUM,
    LARGE
};

class Asteroid {
private:
    point_t loc;
    color c;
    vector<vector<point_t>> shapes;
    vector<point_t> shape;
    force f;
    Boundary bounds;
    bool isDestroyed;
    double direction;
    AsteroidSize size;

public:
    Asteroid(AsteroidSize size, point_t loc, double direction = 0.0);
    void draw(SDL_Plotter& g);
    void move();
    void erase(SDL_Plotter& g);
    void setDirection(double d);
    double getDirection() const;
    point_t getPosition();
    AsteroidSize getSize();
    Boundary getBoundary() const;
    bool checkDestroyed();


};

vector<point_t> generateAsteroidShape(AsteroidSize size);

#endif /* ASTEROID_H_ */
