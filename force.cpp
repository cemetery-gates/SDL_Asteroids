/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the force.cpp file which contains member function definitions
*       that determine the forces acted on the rocket (magnitude and direction)
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 7/1/2023
*/

#include "force.h"

/*
* description: The default constructor sets the magnitude and direction to its
*              initial values of 0
* return: None
* precondition: None
* postcondition: Initializes magnitude and direction
*/
force::force(){
    magnitude = 0;
    direction = 0;
}

/*
* description: The second constructor assigns private data member magnitude to
*              m, and private data member direction to d;
* return: None
* precondition: m and d are valid
* postcondition: magnitude is m and direction is d
*/
force::force(double m, double d){
    magnitude = m;
    direction = d;
}

/*
* description: Sets private data member magnitude to m
* return: None
* precondition: m is valid
* postcondition: magnitude is assigned to m
*/
void force::setMagnitude(double m){
    magnitude = m;
}

/*
* description: Sets private data member direction to d
* return: None
* precondition: d is valid
* postcondition: direction is assigned to d
*/
void force::setDirection(double d){
    direction = d;
}

/*
* description: Gets magnitude and allows class user to access magnitude
* return: magnitude
* precondition: None
* postcondition: Returns magnitude
*/
double force::getMagnitude() const{
    return magnitude;
}

/*
* description: Gets direction and allows class user to access direction
* return: direction
* precondition: None
* postcondition: Returns directions
*/
double force::getDirection() const{
    return direction;
}

/*
* description: Calculates the rocket's velocity using magnitude and force
* return: v
* precondition: f (force) is valid
* postcondition: Returns v (velocity)
*/
force force::add(const force& f) const{
    force v;

    double ax, ay, bx, by;
    double theta, mag;

    ax = getMagnitude() * cos(getDirection());
    ay = getMagnitude() * sin(getDirection());

    bx = f.getMagnitude() * cos(f.getDirection());
    by = f.getMagnitude() * sin(f.getDirection());

    theta = atan((ay + by)/(ax + bx));

    if((ay + by) < 0 && theta > 0) theta += PI;
    if((ay + by) > 0 && theta < 0) theta += PI;

    mag = sqrt(pow(ax + bx, 2) + pow(ay + by, 2));

    v.setMagnitude(mag);
    v.setDirection(theta);

    return v;
}

/*
* description: The overloaded addition operator function will add force.
* return: Returns add(f)
* precondition: f (force) is valid
* postcondition: Returns addition of f (force)
*/
force force::operator+ (const force& f) const{
    return add(f);
}

/*
* description: The overloaded equality operator function sets magnitude and
*              direction to force.
* return: None
* precondition: f (force) is valid
* postcondition: magnitude and direction are set
*/
force force::operator= (const force& f){
    setMagnitude(f.getMagnitude());
    setDirection(f.getDirection());
}

/*
* description: Assigns applied force to force
* return: None
* precondition: f (force) is valid
* postcondition: applied force is assigned
*/
void force::apply(const force& f){
    *this = add(f);
}

/*
* description: Prints magnitude and direction
* return: None
* precondition: output is valid
* postcondition: magnitude and direction are printed
*/
void force::display(ostream& output) const{
    output << getMagnitude() << " " << getDirection() << endl;
}
