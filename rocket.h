/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the rocket.h file which contains the rocket class
*       and the following function prototypes, related to the rocket's
*       direction, the rocket's ability to move in different directions,
*       to accelerate, and to rotate.
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 6/30/2023
*/

#ifndef ROCKET_H_INCLUDED
#define ROCKET_H_INCLUDED

#include <vector>

using namespace std;

#include "force.h"
#include "point.h"
#include "SDL_Plotter.h"
#include "constants.h"
#include "graphics.h"


class Rocket{
    private:
        point_t loc, center;
        force f;
        color c;
        vector<point_t> shape;
        double direction = 0;

    public:
        Rocket();
        //void setLocation(const point&);
        //point getLocation() const;

       /*
        * description: Draws the shape of the rocket by calling the draw polygon function which uses the
	*              locations, shape, color, and graphics to draw the rocket
        * return: None
        * precondition: Correct graphics
        * postcondition: The rocket is drawn
        */
        void draw(SDL_Plotter& g);

       /*
        * description: Erases the rocket as the rocket moves so so it doesn't leave a trail on the screen
        * return: None
        * precondition: Valid graphics
        * postcondition: The rocket won't leave a trail on the screen
	*/
        void erase(SDL_Plotter& g);

       /*
        * description: Assigns private data member direction to d.
        * return: None
        * precondition: Valid direction
        * postcondition: Direction is assigned and class user can access private data member
	*/
        void setDirection(double d);

       /*
        * description: Returns the direction when called
        * return: Direction
        * precondition: Function is constant becuase retrieving the direction should not change its value
        * postcondition: Returns direction as a double
	*/
        double getDirection() const;

       /*
        * description: Calculates the force/thrust which allows the rocket to accelerate based on the rocket's
        *              direction
        * return: None
        * precondition: Valid function call of thrust force in definition
        * postcondition: Calculates the force applied to the rocket
	*/
        void thrust();

       /*
        * description: Sets the new location (x and y coordinates) of the rocket based on its current location,
	*              its maginitude, and it's angular vector direction.
        * return: None
        * precondition: The new x and y coordinates are held in variables which are declared in within the function
	*               definition.
        * postcondition: The new x and y coordinates of the rocket are set
        */
        void move();

       /*
        * description: Calculates the rocket's rotation at its origin (rocket's center)
        * return: None
        * precondition: theta is valid
        * postcondition: The rocket will rotate
        */
        void rotatePolygonAtDistance(double theta);

        /*
        * description: Sets the determines the translation of the rocket as it rotates
        * return: None
        * precondition: Valid horizontal and vertical direction
        * postcondition: The rocket's shape is set as it moves/rotates
        */
	void translatePolygon(double dx, double dy);

        /*
        * description: Calculates the rotation for the all the points which plot the rocket which rotate around
	*              the rocket's origin.
        * return: None
        * precondition: theta is valid
        * postcondition: the x and y coordinates for all of the rocket's points are calculated as the rocket rotates
        */
	void rotatePolygon(double theta);
};

#endif // ROCKET_H_INCLUDED
