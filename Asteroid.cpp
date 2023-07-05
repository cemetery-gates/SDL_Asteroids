/*
 * Asteroid.cpp
 *
 *  Created on: Jul 1, 2023
 *      Author: logan
 */

#include "Asteroid.h"

Asteroid::Asteroid(AsteroidSize size, point_t loc, double direction) {

	this->size = size;
	this->direction = direction;
	this->loc = loc;
	isDestroyed = false;

	shape = generateAsteroidShape(size);

    switch(size) {
        case AsteroidSize::LARGE:
            f = force(0.05, getDirection());
            c = color(255, 255, 255);
            bounds = Boundary(loc, 30.0);
            break;
        case AsteroidSize::MEDIUM:
            f = force(0.1, getDirection());
            c = color(255, 255, 255);
            bounds = Boundary(loc, 15.0);
            break;
        case AsteroidSize::SMALL:
            f = force(0.15, getDirection());
            c = color(255, 255, 255);
            bounds = Boundary(loc, 7.5);
            break;
    }

}
// Draws an asteroid on the screen
void Asteroid::draw(SDL_Plotter& g){
	drawPoly(loc, shape, c, g);
	// DEBUGGING ONLY DELETE BEFORE GAME RELEASE
	 g.drawCircle(bounds.getCenter().getX(), bounds.getCenter().getY(),
			 bounds.getRadius(), color(255, 0, 0));
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

point_t Asteroid::getPosition(){
	return loc;
}
AsteroidSize Asteroid::getSize(){
	return size;
}

vector<point_t> generateAsteroidShape(AsteroidSize size){
    vector<point_t> shape;
    double radius;
    int numPoints;

    switch (size) {
    case AsteroidSize::SMALL:
        radius = 7.5;
        numPoints = 5 + rand() % 3;
        break;
    case AsteroidSize::MEDIUM:
        radius = 15.0;
        numPoints = 7 + rand() % 4;
        break;
    case AsteroidSize::LARGE:
        radius = 30.0;
        numPoints = 10 + rand() % 6;
        break;
    }

    //Generate random asteroid shapes
    for (int i = 0; i < numPoints; ++i) {
        double theta = (i * 2.0 * PI) / numPoints;
        double newRadius = radius * (0.75 + ((rand() % 50) / 100.0));
        shape.push_back(point_t(newRadius * cos(theta), newRadius * sin(theta)));
    }

    return shape;
}

