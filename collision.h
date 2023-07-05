#ifndef COLLISION_H
#define COLLISION_H

#include "point.h"

struct Boundary{
    	point_t center;
    	double radius;

    	Boundary(point_t loc = {0, 0}, double r = 0.0);

    	void setCenter(double x, double y);
    	void setRadius(double r);
    	point_t getCenter();
    	double getRadius();
};

bool isColliding(Boundary, Boundary);

#endif // COLLISION_H
