//
// Created by Raster on 2/20/2018.
//

#ifndef PROJECTX_GRAPHICS_H
#define PROJECTX_GRAPHICS_H

#include <map>
#include <c++/string>

#include <SDL2/SDL_image.h>

/*  Graphics class
 *  Holds information dealing with graphics for the game.
 */

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
//    constructor
    Graphics();

//    destructor
    ~Graphics();

    /*  SDL_Surface* loadImage
     *  Loads an image into the spritesheet map if it doesn't already exist.
     *  Each image will only be loaded once.
     *  Returns the image from the map regardless of whether or not it was just loaded.
     */

    SDL_Surface* loadImage(const std::string&filePath);

    /*  void blitSurface.
     *  Draws a texture to a certain part of the screen.
     */
    void blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle);

    /*
     *  bligSurfaceL simply flips the sprite when rendering. THis is used for animated sprites so we don't have to
     *  duplicate sprites or the entire sprite sheet and flip them.
     */

    void blitSurfaceL(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle);

    /* void flip
     * renders everything to the screen.
     */
    void flip();

    /*  void clear
     *  Clears the screen.
     */
    void clear();

    /*  SDL_Renderer* getRenderer
     *  Returns the renderer.
     */
    SDL_Renderer* getRenderer() const;

    /*  SDL_Window* getWindow
    *   Returns the window.
    */
    SDL_Window* getWindow() const;

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*>_spriteSheets; };


#endif //PROJECTX_GRAPHICS_H