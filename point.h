/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the point.h file which contains the function prototypes
*       and two function members related to the point's x and y coordinates.
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 7/1/2023
*/

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <ostream>
#include <cmath>

#include "SDL_Plotter.h"

class point_t{
    private:
        double x, y;
        color c;
        int size;

    public:

        /*
        * description: Defines the x and y coordinates of the point on the rocket
        * return: None
        * precondition: Valid x and y value
        * postcondition: x and y coordinates are assigned
        */
        point_t(double=0, double=0);

        /*
        * description: Sets private data member x to x
        * return: None
        * precondition: x is valid
        * postcondition: The x coordinate is set.
        */
        void setX(double);

        /*
        * description: Sets private data member y to y
        * return: None
        * precondition: y is valid
        * postcondition: The y coordinate is set.
        */
        void setY(double);

        /*
        * description: Sets the point's color (private data member c is assigned
        *              to c and is type color)
        * return: None
        * precondition: color c is valid
        * postcondition: The color is set
        */
        void setColor(color);

        /*
        * description: Sets private data member size to n which is an integer type.
        * return: None
        * precondition: n is valid
        * postcondition: The point's size is set on the condition that it is greater
        *                than 1.
        */
        void setSize(int);

        /*
        * description: Gets the x coordinate and allows the class user to access x
        * return: x
        * precondition: None
        * postcondition: Returns the x coordinate.
        */
        double getX() const;

        /*
        * description: Gets the y coordinate and allows the class user to access y.
        * return: y
        * precondition: None
        * postcondition: Returns the y coordinate.
        */
        double getY() const;

        /*
        * description: Gets the color of the point and allows the user to access c.
        * return: c
        * precondition: None
        * postcondition: Returns the color of the point.
        */
        color getColor() const;

        /*
        * description: Gets the size of the point and allows the user to access size.
        * return: None
        * precondition: None
        * postcondition: Returns the size of the point.
        */
        int getSize() const;

        /*
        * description: Prints the point in the format "(x, y)"
        * return: None
        * precondition: None
        * postcondition: The point is printed.
        */
        void draw(ostream&);

        /*
        * description: Determines the graphics for the points on the rocket
        * return: None
        * precondition: g (graphics) is valid.
        * postcondition: The points are drawn.
        */
        void draw(SDL_Plotter&);

        /*
        * description: Point 3 of the rocket is assigned an x and y value
        *              and is assigned to a color.
        * return: p3
        * precondition: point is valid
        * postcondition: point 3 is returned with its assigned attributes.
        */
        point_t add(const point_t&) const;

        /*
        * description: The overloaded operator allows the addition of other
        *              points that will draw the rocket.
        * return: addition of another point
        * precondition: point is valid
        * postcondition: Another point is addded.
        */
        point_t operator+(const point_t& p) const{
            return add(p);
        }

        /*
        * description: Calculates the distance between x and y coordinates
        *              of two points using the distance formula
        * return: distance
        * precondition: point is valid
        * postcondition: Returns the distance between two points
        */
        double distance(point_t p){
            return sqrt(pow(x- p.x,2) + pow(y - p.y, 2));
        }

};

#endif // POINT_H_INCLUDED
