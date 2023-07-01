/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the rocket.cpp file which contains the rocket member
*       function definitions, related to the rocket's direction, the
*       rocket's ability to move in different directions, to accelerate,
*       and to rotate.
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 6/30/2023
*/

#include "rocket.h"

/*
* description: The rocket's initial, shape, location, and color are set
* return: None
* precondition: None
* postcondition: None
*/
Rocket::Rocket(){
            shape.push_back(point_t(0,0));
            shape.push_back(point_t(40,10));
            shape.push_back(point_t(0,20));
            shape.push_back(point_t(20,10));
            center.setX(20);
            center.setY(10);
            loc.setX(100);
            loc.setY(100);
            c = color(255,255,255);
}

//void Rocket::setLocation(const point&);
//point getLocation() const;

/*
* description: Draws the shape of the rocket by calling the draw polygon function which uses the
*              locations, shape, color, and graphics to draw the rocket
* return: None
* precondition: Correct graphics
* postcondition: The rocket is drawn
*/
void Rocket::draw(SDL_Plotter& g){
	drawPoly(loc, shape, c, g);
}

/*
* description: Erases the rocket as the rocket moves so so it doesn't leave a trail on the screen
* return: None
* precondition: Valid graphics
* postcondition: The rocket won't leave a trail on the screen
*/
void Rocket::erase(SDL_Plotter& g){
	drawPoly(loc, shape, BG, g);
}

/*
* description: Assigns private data member direction to d.
* return: None
* precondition: Valid direction
* postcondition: Direction is assigned and class user can access private data member
*/
void Rocket::setDirection(double d){
	direction = d;
	//rotatePolygonAtDistance(direction);
}

/*
* description: Returns the direction when called
* return: Direction
* precondition: Function is constant becuase retrieving the direction should not change its value
* postcondition: Returns direction as a double
*/
double Rocket::getDirection() const{
	return direction;
}

/*
* description: Calculates the force/thrust which allows the rocket to accelerate based on the rocket's
*              direction
* return: None
* precondition: Valid function call of thrust force in definition
* postcondition: Calculates the force applied to the rocket
*/
void Rocket::thrust(){
	force tForce(0.01, getDirection());
	f.apply(tForce);
}

/*
* description: Sets the new location (x and y coordinates) of the rocket based on its current location,
*              its maginitude, and it's angular vector direction.
* return: None
* precondition: The new x and y coordinates are held in variables which are declared in within the function
*               definition.
* postcondition: The new x and y coordinates of the rocket are set
*/
void Rocket::move(){
	double newX = loc.getX() + f.getMagnitude() * cos(f.getDirection());
	double newY = loc.getY() + f.getMagnitude() * sin(f.getDirection());

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
}

/*
* description: Calculates the rocket's rotation at its origin (rocket's center)
* return: None
* precondition: theta is valid
* postcondition: The rocket will rotate
*/
void Rocket::rotatePolygonAtDistance(double theta) {

			// Translate the polygon by (-cx, -cy) to bring the center to the origin
			double cx = center.getX();
			double cy = center.getY();

			translatePolygon(-cx, -cy);
			// Rotate the polygon at the origin
			rotatePolygon(theta);
			// Translate the polygon back to its original position
			translatePolygon(cx, cy);
			setDirection(getDirection() + theta);
}

/*
* description: Sets the determines the translation of the rocket as it rotates
* return: None
* precondition: Valid horizontal and vertical direction
* postcondition: The rocket's shape is set as it moves/rotates
*/
void Rocket::translatePolygon(double dx, double dy) {
	for (size_t i = 0; i < shape.size(); i++) {
		shape[i].setX(shape[i].getX() + dx);
		shape[i].setY(shape[i].getY() + dy);
	}
}

/*
* description: Calculates the rotation for the all the points which plot the rocket which rotate around
*              the rocket's origin.
* return: None
* precondition: theta is valid
* postcondition: The x and y coordinates for all of the rocket's points are calculated as the rocket rotates
*/
void Rocket::rotatePolygon(double theta) {

	for (size_t i = 0; i < shape.size(); i++) {
		double x = shape[i].getX();
		double y = shape[i].getY();

		shape[i].setX(x * cos(theta) - y * sin(theta));
		shape[i].setY(x * sin(theta) + y * cos(theta));

	}
}
