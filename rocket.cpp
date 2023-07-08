#include "rocket.h"
#include "bullets.h"
#include "collision.h"
#include "Asteroid.h"
using namespace std;

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
            bounds = Boundary(this->center, 15.0);
}

void Rocket::draw(SDL_Plotter& g){
	drawPoly(loc, shape, c, g);
	// DEBUGGING ONLY DELETE BEFORE GAME RELEASE
}

void Rocket::setDirection(double d){
	direction = d;
}

double Rocket::getDirection() const{
	return direction;
}

//fire bullets function
void Rocket::fireBullet(SDL_Plotter& g) {
        if (bullets.size() < 10) {    //load 10 bullets max.
                Bullet newBullet(loc, this->getDirection());
                bullets.push_back(newBullet);
	}
        //draw bullets
        for (size_t i = 0; i < bullets.size(); i++) {
                bullets[i].draw(g);
	}
        g.update();
}

//update bullets function
void Rocket::updateBullets(SDL_Plotter& g) {
    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].move();
        if (bullets[i].isOffScreen()) {
            bullets.erase(bullets.begin() + i);
            i--;
        } else {
            // Check for collision with asteroids
            for (size_t j = 0; j < asteroids.size(); j++) {
                if (isColliding(bullets[i].getBoundary(), asteroids[j].getBoundary())) {
                    // Bullet has collided with an asteroid
                    bullets[i].isColliding();
                    asteroids.erase(asteroids.begin() + j);
                    break; // Exit the loop since the bullet can only collide with one asteroid at a time
                }
            }
        }
    }

    // Draw the bullets
    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].draw(g);
    }

    // Draw the asteroids
    for (size_t i = 0; i < asteroids.size(); i++) {
        asteroids[i].draw(g);
    }

    // Remove bullets that have collided with asteroids
    bullets.erase(remove_if(bullets.begin(), bullets.end(), [](const Bullet& bullet) {
        return bullet.isColliding();
    }), bullets.end());

    g.update();
}

//erase bullets and rocket?
void Rocket::erase(SDL_Plotter& g){
	drawPoly(loc, shape, BG, g);
	for (size_t i = 0; i < bullets.size(); i++) {
		bullets[i].erase(g);
	}
}

void Rocket::thrust(){
	force tForce(STEP_SIZE, getDirection());
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
	bounds.setCenter(newX + center.getX(), newY + center.getY());
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

Boundary Rocket::getBoundary(){
	return bounds;
}
