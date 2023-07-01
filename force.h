/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the force.h file which contains the function prototypes
*       for the forces acted on the rocket (magnitude and direction)
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 7/1/2023
*/

#ifndef FORCE_H_INCLUDED
#define FORCE_H_INCLUDED

#include <cmath>
#include <ostream>
#include "constants.h"

using namespace std;

class force{
    private:
        double magnitude;
        double direction; //radians
    public:

        /*
        * description: The default constructor sets the magnitude and direction to its
        *              initial values of 0
        * return: None
        * precondition: None
        * postcondition: Initializes magnitude and direction
        */
        force();

        /*
        * description: The second constructor assigns private data member magnitude to
        *              m, and private data member direction to d;
        * return: None
        * precondition: m and d are valid
        * postcondition: magnitude is m and direction is d
        */
        force(double m, double d);

        /*
        * description: Sets private data member magnitude to m
        * return: None
        * precondition: m is valid
        * postcondition: magnitude is assigned to m
        */
        void setMagnitude(double);

        /*
        * description: Sets private data member direction to d
        * return: None
        * precondition: d is valid
        * postcondition: direction is assigned to d
        */
        void setDirection(double);

        /*
        * description: Gets magnitude and allows class user to access magnitude
        * return: magnitude
        * precondition: None
        * postcondition: Returns magnitude
        */
        double getMagnitude() const;

        /*
        * description: Gets direction and allows class user to access direction
        * return: direction
        * precondition: None
        * postcondition: Returns directions
        */
        double getDirection() const;

        /*
        * description: Calculates the rocket's velocity using magnitude and force
        * return: v
        * precondition: f (force) is valid
        * postcondition: Returns v (velocity)
        */
        force add(const force&) const;

        /*
        * description: The overloaded addition operator function will add force.
        * return: Returns add(f)
        * precondition: f (force) is valid
        * postcondition: Returns addition of f (force)
        */
        force operator+ (const force& f) const;

        /*
        * description: The overloaded equality operator function sets magnitude and
        *              direction to force.
        * return: None
        * precondition: f (force) is valid
        * postcondition: magnitude and direction are set
        */
        force operator= (const force&);

        /*
        * description: Assigns applied force to force
        * return: None
        * precondition: f (force) is valid
        * postcondition: applied force is assigned
        */
        void apply(const force&);

        /*
        * description: Prints magnitude and direction
        * return: None
        * precondition: output is valid
        * postcondition: magnitude and direction are printed
        */
        void display(ostream&) const;

};

#endif // FORCE_H_INCLUDED
