/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the point.cpp file which contains the member function
*       definitions related to the points's x and y coordinates. Each
*       point is given a color, a size, and location to plot the rocket.
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 7/1/2023
*/

#include "point.h"

/*
* description: Defines the x and y coordinates of the point on the rocket
* return: None
* precondition: Valid x and y value
* postcondition: x and y coordinates are assigned
*/
point_t::point_t(double x, double y){
    this-> x = x;
    this-> y = y;
    size = 1;
}

/*
* description: Sets private data member x to x
* return: None
* precondition: x is valid
* postcondition: The x coordinate is set.
*/
void point_t::setX(double x){
    this-> x = x;
}

/*
* description: Sets private data member y to y
* return: None
* precondition: y is valid
* postcondition: The y coordinate is set.
*/
void point_t::setY(double y){
    this-> y = y;
}

/*
* description: Sets the point's color (private data member c is assigned
*              to c and is type color)
* return: None
* precondition: color c is valid
* postcondition: The color is set
*/
void point_t::setColor(color c){
    this-> c = c;
}

/*
* description: Sets private data member size to n which is an integer type.
* return: None
* precondition: n is valid
* postcondition: The point's size is set on the condition that it is greater
*                than 1.
*/
void point_t::setSize(int n){
    if(n >= 1){
        size = n;
    }
}

/*
* description: Gets the x coordinate and allows the class user to access x
* return: x
* precondition: None
* postcondition: Returns the x coordinate.
*/
double point_t::getX() const{
    return x;
}

/*
* description: Gets the y coordinate and allows the class user to access y.
* return: y
* precondition: None
* postcondition: Returns the y coordinate.
*/
double point_t::getY() const{
    return y;
}

/*
* description: Gets the color of the point and allows the user to access c.
* return: c
* precondition: None
* postcondition: Returns the color of the point.
*/
color point_t::getColor() const{
    return c;
}

/*
* description: Gets the size of the point and allows the user to access size.
* return: None
* precondition: None
* postcondition: Returns the size of the point.
*/
int point_t::getSize() const{
    return size;
}

/*
* description: Prints the point in the format "(x, y)"
* return: None
* precondition: None
* postcondition: The point is printed.
*/
void point_t::draw(ostream& output){
    output << "(" << x << ", " << y << ")";
}

/*
* description: Determines the graphics for the points on the rocket
* return: None
* precondition: g (graphics) is valid.
* postcondition: The points are drawn.
*/
void point_t::draw(SDL_Plotter& g){
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            g.plotPixel(x+c,y+r,this->c);
        }
    }
}

/*
* description: Point 3 of the rocket is assigned an x and y value
*              and is assigned to a color.
* return: p3
* precondition: point is valid
* postcondition: point 3 is returned with its assigned attributes.
*/
point_t point_t::add(const point_t& p) const{
    point_t p3;
    p3.setX(getX() + p.getX());
    p3.setY(getY() + p.getY());

    p3.setSize(getSize() + p.getSize());
    p3.setColor(color(c.R + p.c.R, c.G + p.c.G, c.B + p.c.B));

    return p3;
}
