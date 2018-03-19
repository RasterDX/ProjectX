//
// Created by Raster on 2/20/2018.
//

#ifndef PROJECTX_GAME_H
#define PROJECTX_GAME_H


#include "graphics.h"
#include "player.h"

class Game {
public:
    Game();
    ~Game();
    void draw(Graphics &graphics);
private:
    void gameLoop();
    void update(float elapsedTime);
    Player _player;
};


#endif //PROJECTX_GAME_H