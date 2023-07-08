#include "collision.h"
#include <cmath>

Boundary::Boundary(point_t loc, double r) {
    center = loc;
    radius = r;
}

void Boundary::setCenter(double x, double y){
	this->center.setX(x);
	this->center.setY(y);
}
void Boundary::setRadius(double r){
	radius = r;
}

point_t Boundary::getCenter(){
	return center;
}

double Boundary::getRadius(){
	return radius;
}

bool isColliding(const Boundary b1, const Boundary b2){
	double squareDistance = pow(b1.center.getX() - b2.center.getX(), 2) +
	                        pow(b1.center.getY() - b2.center.getY(), 2);


	double squareSumRadius = pow((b1.radius + b2.radius), 2);

	return squareDistance < squareSumRadius;
}
