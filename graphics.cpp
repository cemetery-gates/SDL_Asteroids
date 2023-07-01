/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the graphics.cpp file which contains the graphics member
*       function definitions and these functions determine the graphics
*       of the rocket and the other elements of the game.
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 7/1/2023
*/

#include "graphics.h"
#include "point.h"

/*
* description: Draws the lines of the rocket by plotting the points that shape
*              the rocket, by first determining if there the point coordinates
*              have a slope and then the lines are drawn according to the slope
*              of the distance betewen the first and second points
* return: None
* precondition: x1, y1, x2, and y2 are valid
* postcondition: The lines of the rocket will be drawn
*/
void drawLine(int x1, int y1, int x2, int y2, color c, SDL_Plotter& g){
    double m, b, y;
    if(hasSlope(x1,y1,x2,y2)){
        m = slope(x1,y1,x2,y2);
        b = yIntercept(x1,y1,x2,y2);
        for(double x = min(x1,x2); x <= max(x1,x2); x += STEP_SIZE){
            y = m * x + b;
            g.plotPixel(round(x),round(y),c);
        }
    }
    else{
        for(double y = min(y1,y2); y < max(y1,y2); y+= STEP_SIZE){
            g.plotPixel(x1,y,c);
        }
    }
}

/*
* description: The function draws the shapes for the graphics on the screen
* return: None
* precondition: point location, shape vector, color and graphics are valid
* postcondition: The shape is drawn
*/
void drawPoly(const point_t& loc, const vector<point_t>& shape, color c, SDL_Plotter& g) {
    for (size_t i = 0; i < shape.size(); i++) {
        int x1 = static_cast<int>(loc.getX() + shape[i].getX());
        int y1 = static_cast<int>(loc.getY() + shape[i].getY());
        int x2 = static_cast<int>(loc.getX() + shape[(i + 1) % shape.size()].getX());
        int y2 = static_cast<int>(loc.getY() + shape[(i + 1) % shape.size()].getY());

        drawLine(x1, y1, x2, y2, c, g);
    }
}

/*
* description: The function moves the shape based on the x and y values of the
*              shape's points
* return: None
* precondition: vector x, vector y, and the x-value for the point is valid
* postcondition: Moves the shape
*/
void movePoly(vector<int>& x, vector<int>& y, int px){
    for(int i=0; i < x.size(); i++){
        x[i] += px;
        y[i] += px;
    }
}

/*
* description: The functions draws the bullet shape which is a circular shape,
*              using the location, size, and color to plot the circle
* return: None
* precondition: loc, size, c, and g are valid
* postcondition: Plots a circular shape
*/
void drawCircle(point loc, int size, color c, SDL_Plotter& g){
	for(double i = -size; i <= size;i+=0.1){
		for(double j = -size; j <= size; j+=0.1){
			if(i*i + j*j <= size*size){
				g.plotPixel(round(loc.x+i),round(loc.y+j),c);
			}
		}
	}

}

/*
* description: Determines if a line has slope
* return: x1 != x2;
* precondition: x1, y1, x2, and y2 are valid
* postcondition: The slope exists if the x values of two points are not equal
*/
bool hasSlope(int x1, int y1, int x2, int y2){
    return x1 != x2;
}

/*
* description: Calculates the slope of the point based on the x and y
*              coordinates of two points
* return: slope
* precondition: x1, y1, x2, and y2 are valid
* postcondition: Returns the slope
*/
double slope(int x1, int y1, int x2, int y2){
    return static_cast<double>(y1 - y2)/(x1 - x2);
}

/*
* description: Calculates the y-intercerpt of the point based on the first y
*              coordinate and the slope of the point.
* return: y-intercept
* precondition: x1, y1, x2, and y2 are valid
* postcondition: Returns y-intercept
*/
double yIntercept(int x1, int y1, int x2, int y2){
    return y1 - slope(x1,y1,x2,y2) *  x1;
}
