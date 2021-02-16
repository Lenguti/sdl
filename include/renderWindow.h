//
// Created by Lennie Gutierrez on 2/10/21.
//

#ifndef SDL_RENDERWINDOW_H
#define SDL_RENDERWINDOW_H

#endif //SDL_RENDERWINDOW_H

#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"

class RenderWindow
{
public:
    RenderWindow(const char* title, int w, int h);

    int getRefreshRate();

    SDL_Texture* loadTexture(const char* file);

    void cleanup();
    void clear();
    void render(Entity& entity);
    void display();

private:
    SDL_Window*   window;
    SDL_Renderer* renderer;
};
