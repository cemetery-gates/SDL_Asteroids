#include <iostream>
#include <cmath>
#include <utility>
#include "point.h"
#include "collision.h"
#include "rocket.h"
#include "SDL_Plotter.h"
#include "graphics.h"
#include "constants.h"
#include "Asteroid.h"
#include "force.h"
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL_mixer.h>

using namespace std;

bool initializeAudio() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        return false;
    }

    return true;
}

// Function to load a sound effect
Mix_Chunk* loadSound(const string& filename) {
    Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
    if (sound == nullptr) {
        cout << "Failed to load sound effect: " << filename << ", SDL_mixer Error: " << Mix_GetError() << endl;
    }

    return sound;
}

// Function to free a loaded sound effect
void freeSound(Mix_Chunk* sound) {
    Mix_FreeChunk(sound);
}

// Function to play a sound effect
void playSound(Mix_Chunk* sound) {
    Mix_PlayChannel(-1, sound, 0);
}

int main(int argc, char** argv) {
    srand(time(0));
    SDL_Plotter g(COL, ROW);
    point p;
    color c;
    Rocket ship;
    bool spacePressed = false;

    // Initialize SDL_mixer
    if (!initializeAudio()) {
        return 1;
    }

    // Load the bullet sound effect
    Mix_Chunk* bulletSound = loadSound("bullet_sound.wav");
    Mix_Chunk* asteroidHitSound = loadSound("asteroid_hit_sound.wav");

    // Initialize vector with 5 Large asteroids to start
    vector<Asteroid> asteroids{
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
        Asteroid(AsteroidSize::LARGE, point_t(rand() % COL + 10, rand() % ROW + 10),
                 (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))),
    };

    g.clear();

    while (!g.getQuit()) {
        const Uint8* state = SDL_GetKeyboardState(NULL);

        if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
            ship.thrust();
        }

        if (state[SDL_SCANCODE_SPACE] && !spacePressed) {
            ship.fireBullet(g);
            spacePressed = true;
            // Play the bullet sound effect
            playSound(bulletSound);
        }

        if (!state[SDL_SCANCODE_SPACE]) {
            spacePressed = false;
        }

        ship.updateBullets(g);

        if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
            ship.rotatePolygonAtDistance(-0.031415);
        }

        if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
            ship.rotatePolygonAtDistance(0.031415);
        }

        if (state[SDL_SCANCODE_C]) {
            g.clear();
        }

        g.clear();

        vector<pair<AsteroidSize, point_t>> toMake;

        // Bullet hits an asteroid
        for (auto it = ship.bullets.begin(); it != ship.bullets.end();) {
            bool bulletDeleted = false;

            for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();) {
                if (isColliding(it->getBoundary(), asteroid->getBoundary())) {
                    it = ship.bullets.erase(it);
                    bulletDeleted = true;
                    toMake.push_back({asteroid->getSize(), asteroid->getPosition()});
                    asteroid = asteroids.erase(asteroid);
                    playSound(asteroidHitSound); // Play asteroid hit sound effect+
                    break;
                } else {
                    ++asteroid;
                }
            }

            if (!bulletDeleted) {
                ++it;
            }
        }

        for (auto const& [size, pos] : toMake) {
            if (size == AsteroidSize::LARGE) {
                asteroids.push_back(Asteroid(AsteroidSize::MEDIUM, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::MEDIUM, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
            } else if (size == AsteroidSize::MEDIUM) {
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
                asteroids.push_back(Asteroid(AsteroidSize::SMALL, pos,
                                             (2 * PI) * (rand() / static_cast<double>(RAND_MAX))));
            }
        }

        // Game over if ship hits an asteroid
        for (const Asteroid& asteroid : asteroids) {
            if (isColliding(asteroid.getBoundary(), ship.getBoundary())) {
                g.clear();
                g.update();
                SDL_Delay(500);  // Pause for 0.5 seconds before exiting
                g.setQuit(true);
                return 0;
            }
        }

        // If all asteroids are destroyed
        if (asteroids.empty()) {
            // Spawn new asteroids
            for (int i = 0; i < 5; i++) {
                point_t position(rand() % COL + 10, rand() % ROW + 10);
                asteroids.push_back(Asteroid(AsteroidSize::LARGE, position, (2 * M_PI) * (rand() / static_cast<double>(RAND_MAX))));
            }
        }


        ship.move();
        ship.erase(g);
        ship.draw(g);

        for (Asteroid& asteroid : asteroids) {
            asteroid.erase(g);
            asteroid.move();
            asteroid.draw(g);
        }

        for (Bullet& bullet : ship.bullets) {
            bullet.move();
            bullet.draw(g);
        }

        g.update();
    }

    // Free the loaded sound effect
    freeSound(bulletSound);
    freeSound(asteroidHitSound);

    // Quit SDL_mixer
    Mix_CloseAudio();
    Mix_Quit();

    return 0;
}
