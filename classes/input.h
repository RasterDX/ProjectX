//
// Created by Raster on 2/20/2018.
//

#ifndef PROJECTX_INPUT_H
#define PROJECTX_INPUT_H

#include <map>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_events.h>

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
};


#endif //PROJECTX_INPUT_H
