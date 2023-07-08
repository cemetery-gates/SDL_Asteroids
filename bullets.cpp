#include "bullets.h"
#include "constants.h"

// Takes location, the color, direction,
Bullet::Bullet(point_t location, double direction) {
    loc = location;
    f = force(6, direction); //changed if bullets are going to fast/slow
    c = color(255, 0, 0);
    offScreen = false;
    hasCollided = false;
}

void Bullet::draw(SDL_Plotter& g) {
    g.plotPixel(loc.getX(), loc.getY(), 255,255,255);
}

void Bullet::erase(SDL_Plotter& g) {
    g.plotPixel(loc.getX(), loc.getY(), BG.R, BG.G, BG.B);
}

void Bullet::move() {
    double newX = loc.getX() + f.getMagnitude() * cos(f.getDirection());
    double newY = loc.getY() + f.getMagnitude() * sin(f.getDirection());


    if (newX < 0 || newX > COL || newY < 0 || newY > ROW) {
        offScreen = true;
        return;
    }

    //FINISH COLLISION
    //if hit asteroid, set hasCollided to true, and have return statement
    loc.setX(newX);
    loc.setY(newY);


}

bool Bullet::isOffScreen() const {
    return offScreen;
}

bool Bullet::isColliding() const {
    return hasCollided;
}

Boundary Bullet::getBoundary() const{
    return Boundary(loc, 2);
}
