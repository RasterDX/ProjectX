//
// Created by Raster on 3/19/2018.
//

#ifndef PROJECTX_PLAYER_H
#define PROJECTX_PLAYER_H

#include <c++/string>
#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite {
public:
    Player();
    Player(Graphics &graphics, float x, float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    /*
     *  Pretty self-explanatory what the functions below do.
     */

    //  Moves the player left by _dx.
    void moveLeft();

    //  Move the player right by _dx.
    void moveRight();

    //  Stop moving the player.
    void stopMoving();

    virtual void animationDone(std::string currenAanimation);
    virtual void setupAnimation();
private:
    float _dx, _dy;
};


#endif //PROJECTX_PLAYER_H
