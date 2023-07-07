#include "Scoreboard.h"
#include "SDL_Plotter.h"
#include "constants.h"

Scoreboard::Scoreboard(SDL_Plotter& g) : score(0), plotter(g) {}

void Scoreboard::updateScore(int newScore) {
    score = newScore;
}

void Scoreboard::render(SDL_Plotter& g) const {
    g.plotPixel(10, 10, ASCII_S, color(255, 255, 255));
    g.plotPixel(11, 10, ASCII_C, color(255, 255, 255));
    g.plotPixel(12, 10, ASCII_O, color(255, 255, 255));
    g.plotPixel(13, 10, ASCII_R, color(255, 255, 255));
    g.plotPixel(14, 10, ASCII_E, color(255, 255, 255));
    g.plotPixel(15, 10, ASCII_B, color(255, 255, 255));
    g.plotPixel(16, 10, ASCII_O, color(255, 255, 255));
    g.plotPixel(17, 10, ASCII_A, color(255, 255, 255));
    g.plotPixel(18, 10, ASCII_R, color(255, 255, 255));
    g.plotPixel(19, 10, ASCII_D, color(255, 255, 255));
    g.plotPixel(20, 10, ASCII_COLON, color(255, 255, 255));
}

