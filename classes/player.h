//
// Created by Raster on 3/19/2018.
//

#ifndef PROJECTX_PLAYER_H
#define PROJECTX_PLAYER_H

#include <c++/string>
#include "animatedsprite.h"

class Graphics;

class Player : public AnimatedSprite {
public:
    Player();
    Player(Graphics &graphics, float x, float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    virtual void animationDone(std::string currenAanimation);
    virtual void setupAnimation();
private:
};


#endif //PROJECTX_PLAYER_H
