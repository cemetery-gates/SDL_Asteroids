/*
 * Asteroid.cpp
 *
 *  Created on: Jul 1, 2023
 *      Author: logan
 */

#include "Asteroid.h"

Asteroid::Asteroid(double direction) {

	// 5 different shapes of asteroids that can spawn
    shapes = {
    		{
    		    point_t(-10, -20),
    		    point_t(10, -10),
    		    point_t(20, 0),
    		    point_t(10, 10),
    		    point_t(-10, 20),
    		    point_t(-20, 0)
    		},
			{
			    point_t(0, -20),
			    point_t(10, -10),
			    point_t(20, -5),
			    point_t(15, 5),
			    point_t(10, 15),
			    point_t(0, 20),
			    point_t(-10, 10),
			    point_t(-20, 0)
			},
			{
			    point_t(-10, -20),
			    point_t(0, -15),
			    point_t(10, -10),
			    point_t(20, 0),
			    point_t(10, 10),
			    point_t(0, 20),
			    point_t(-20, 15)
			},
			{
			    point_t(-10, -20),
			    point_t(10, -15),
			    point_t(20, 0),
			    point_t(0, 15),
			    point_t(-20, 10)
			},
			{
			    point_t(-10, -20),
			    point_t(0, -15),
			    point_t(10, -10),
			    point_t(15, 0),
			    point_t(10, 10),
			    point_t(0, 20),
			    point_t(-10, 15),
			    point_t(-15, 5),
			    point_t(-20, -5)
			}
    };

    // Pick random shape when spawn
    shape = shapes[rand() % 5];
    //Color set to white
    c = color(255, 255, 255);
    // Spawn in a random loc on screen
    loc.setX(rand() % (COL - 20) + 10);
    loc.setY(rand() % (ROW - 20) + 10);

    this->direction = direction;

    f = force(0.02, getDirection());

    //FIXME CIRCLE NOT IN RIGHT SPOT
    bounds = Boundary(this->loc, 10.0);

}
// Draws an asteroid on the screen
void Asteroid::draw(SDL_Plotter& g){
	drawPoly(loc, shape, c, g);
}

// Erases the asteroid on the screen
void Asteroid::erase(SDL_Plotter& g){
	drawPoly(loc, shape, BG, g);
}

// Move an asteroid in a fixed direction and speed
void Asteroid::move() {
	double newX = loc.getX() + f.getMagnitude() * cos(f.getDirection());
	double newY = loc.getY() + f.getMagnitude() * sin(f.getDirection());


	// Wrap screen if it falls off the screen
	if(newX < 0) {
		newX += COL;
	}
	else if(newX >= COL) {
		newX -= COL;
	}

	if(newY < 0) {
		newY += ROW;
	}
	else if(newY >= ROW){
		newY -= ROW;
	}

	loc.setX(newX);
	loc.setY(newY);
	bounds.setCenter(newX, newY);
}
// Set the direction of the asteroid
void Asteroid::setDirection(double d){
	direction = d;
}

// Get the direction of the asteroid
double Asteroid::getDirection() const{
	return direction;
}

Boundary Asteroid::getBoundary(){
	return bounds;
}

