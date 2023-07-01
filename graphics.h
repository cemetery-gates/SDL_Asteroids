/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the graphics.h file which contains the function prototypes
*       that determines the graphics of the rocket and the other elements 
*       of the game
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 7/1/2023
*/

#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <cmath>
#include "constants.h"
#include "point.h"
#include "SDL_Plotter.h"

using namespace std;

/*
* description: The functions draws the bullet shape which is a circular shape,
*              using the location, size, and color to plot the circle
* return: None
* precondition: loc, size, c, and g are valid
* postcondition: Plots a circular shape
*/
void drawCircle(point loc, int size, color c, SDL_Plotter& g);

/*
* description: Draws the lines of the rocket by plotting the points that shape
*              the rocket, by first determining if there the point coordinates
*              have a slope and then the lines are drawn according to the slope
*              of the distance betewen the first and second points
* return: None
* precondition: x1, y1, x2, and y2 are valid
* postcondition: The lines of the rocket will be drawn
*/
void drawLine(int, int, int, int, color c, SDL_Plotter& g);

/*
* description: The function draws the shapes for the graphics on the screen
* return: None
* precondition: point location, shape vector, color and graphics are valid
* postcondition: The shape is drawn
*/
void drawPoly(const point_t&, const vector<point_t>&, color, SDL_Plotter&);

/*
* description: The function moves the shape based on the x and y values of the
*              shape's points
* return: None
* precondition: vector x, vector y, and the x-value for the point is valid
* postcondition: Moves the shape
*/
void movePoly(vector<int>& x, vector<int>& y, int px);

/*
* description: Determines if a line has slope
* return: x1 != x2;
* precondition: x1, y1, x2, and y2 are valid
* postcondition: The slope exists if the x values of two points are not equal
*/
bool hasSlope(int, int, int, int);

/*
* description: Calculates the slope of the point based on the x and y
*              coordinates of two points
* return: slope
* precondition: x1, y1, x2, and y2 are valid
* postcondition: Returns the slope
*/
double slope(int, int, int, int);

/*
* description: Calculates the y-intercerpt of the point based on the first y
*              coordinate and the slope of the point.
* return: y-intercept
* precondition: x1, y1, x2, and y2 are valid
* postcondition: Returns y-intercept
*/
double yIntercept(int, int, int, int);

#endif // GRAPHICS_H_INCLUDED
