//
// Created by Raster on 3/19/2018.
//

#ifndef PROJECTX_ANIMATEDSPRITE_H
#define PROJECTX_ANIMATEDSPRITE_H

#include <c++/map>
#include <c++/string>
#include <c++/vector>

#include "globals.h"
#include "sprite.h"

class Graphics;

/*  AnimatedSprite class
 *  Holds logic for animating sprites.
 */

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
            float posX, float posY, float timeToUpdate);

    /*  void playAnimation
     *  Plays an animation (if its not already playing.)
     */
    void playAnimation(std::string animation, bool once = false);

    /*
     *  Updates the animated sprite (timer)
     */
    void update(int elapsedTime);

    /*
     *  Draws the sprite to the screen.
     */
    void draw(Graphics &graphics, int x, int y);

    /*
     *  Required function that sets up all animations for a sprite.
     */
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    /*
     *  Adds an animation to the map of animations of the sprite.
     */
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

    /*
     *  Resets all animations associated with this sprite.
     */
    void resetAnimation();

    /*
     *  Stops the current animation.
     */
    void stopAnimation();

    /*
     *  Changes the visibility of the animated sprite.
     */
    void setVisible(bool visible);

    /*
     *  Happens when an animation ends.
     */
    virtual void animationDone(std::string currentAnimation) = 0;

    virtual void setupAnimation() = 0;


private:
    std::map<std::string, std::vector<SDL_Rect> > _animations;
    std::map<std::string, Vector2> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};


#endif //PROJECTX_ANIMATEDSPRITE_H
