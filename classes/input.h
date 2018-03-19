//
// Created by Raster on 2/20/2018.
//

#ifndef PROJECTX_INPUT_H
#define PROJECTX_INPUT_H

#include <map>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_events.h>

/*
 *  Input class keeps track of key events
 */

class Input {
public:
    //This function is called at the beginning of each key frame
    //to reset the keys that are no longer relevant.
    void beginNewFrame();

    //Called when key is releaesd.
    void keyUpEvent(const SDL_Event& event);

    //Called when key is pressed.
    void keyDownEvent(const SDL_Event& event);

    //Checks if a certain key was pressed during the current frame.
    bool wasKeyPressed(SDL_Scancode key);

    //Checks if a certain key was released during the current frame.
    bool wasKeyReleased(SDL_Scancode key);

    //Checck if key is held/
    bool isKeyHeld(SDL_Scancode key);
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
};


#endif //PROJECTX_INPUT_H
