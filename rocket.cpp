#include "rocket.h"

Rocket::Rocket(){
            shape.push_back(point_t(0,0));
            shape.push_back(point_t(40,10));
            shape.push_back(point_t(0,20));
            shape.push_back(point_t(20,10));
            center.setX(20);
            center.setY(10);
            loc.setX(ROW/2);
            loc.setY(COL/2);
            c = color(255,255,255);
}

void Rocket::draw(SDL_Plotter& g){
	drawPoly(loc, shape, c, g);
}

void Rocket::erase(SDL_Plotter& g){
	drawPoly(loc, shape, BG, g);
}

void Rocket::setDirection(double d){
	direction = d;
	//rotatePolygonAtDistance(direction);
}

double Rocket::getDirection() const{
	return direction;
}

void Rocket::thrust(){
	force tForce(0.01, getDirection());
	f.apply(tForce);
}

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

void Rocket::rotatePolygonAtDistance(double theta) {

			// Translate the polygon by (-cx, -cy) to bring the center
			// to the origin
			double cx = center.getX();
			double cy = center.getY();

			translatePolygon(-cx, -cy);
			// Rotate the polygon at the origin
			rotatePolygon(theta);
			// Translate the polygon back to its original position
			translatePolygon(cx, cy);
			setDirection(getDirection() + theta);
}

void Rocket::translatePolygon(double dx, double dy) {
	for (size_t i = 0; i < shape.size(); i++) {
		shape[i].setX(shape[i].getX() + dx);
		shape[i].setY(shape[i].getY() + dy);
	}
}

void Rocket::rotatePolygon(double theta) {

	for (size_t i = 0; i < shape.size(); i++) {
		double x = shape[i].getX();
		double y = shape[i].getY();

		shape[i].setX(x * cos(theta) - y * sin(theta));
		shape[i].setY(x * sin(theta) + y * cos(theta));

	}
}
