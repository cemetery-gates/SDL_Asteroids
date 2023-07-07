#include "LivesCounter.h"
#include "SDL_Plotter.h"

LivesCounter::LivesCounter(SDL_Plotter& g) : lives(0), plotter(g) {}

void LivesCounter::updateLives(int newLives) {
    lives = newLives;
}

void LivesCounter::render(SDL_Plotter& g) const {
    g.plotPixel(10, 30, color(255,255,255));
    g.plotPixel(11, 30, color(255,255,255));
    g.plotPixel(12, 30, color(255,255,255));
    g.plotPixel(10, 31, color(255,255,255));
    g.plotPixel(10, 32, color(255,255,255));
    g.plotPixel(10, 33, color(255,255,255));
    g.plotPixel(10, 34, color(255,255,255));
    g.plotPixel(10, 35, color(255,255,255));
    g.plotPixel(11, 32, color(255,255,255));
    g.plotPixel(12, 31, color(255,255,255));
    g.plotPixel(12, 32, color(255,255,255));
    g.plotPixel(12, 33, color(255,255,255));
    g.plotPixel(12, 34, color(255,255,255));
    g.plotPixel(12, 35, color(255,255,255));
    g.plotPixel(13, 30, color(255,255,255));
    g.plotPixel(13, 32, color(255,255,255));
    g.plotPixel(13, 34, color(255,255,255));
    g.plotPixel(14, 30, color(255,255,255));
    g.plotPixel(14, 32, color(255,255,255));
    g.plotPixel(14, 34, color(255,255,255));
    g.plotPixel(15, 30, color(255,255,255));
    g.plotPixel(15, 32, color(255,255,255));
    g.plotPixel(15, 34, color(255,255,255));
    g.plotPixel(16, 30, color(255,255,255));
    g.plotPixel(16, 32, color(255,255,255));
    g.plotPixel(16, 34, color(255,255,255));
    g.plotPixel(17, 31, color(255,255,255));
    g.plotPixel(17, 32, color(255,255,255));
    g.plotPixel(17, 33, color(255,255,255));
    g.plotPixel(17, 34, color(255,255,255));
    g.plotPixel(17, 35, color(255,255,255));
    g.plotPixel(17, 36, color(255,255,255));
    g.plotPixel(17, 37, color(255,255,255));
    g.plotPixel(17, 38, color(255,255,255));
    g.plotPixel(17, 39, color(255,255,255));
}
