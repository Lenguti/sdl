//
// Created by Lennie Gutierrez on 2/10/21.
//

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "../include/renderWindow.h"

RenderWindow::RenderWindow(const char *title, int w, int h) : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        std::cout << "UNABLE TO CREATE WINDOW: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);
    return mode.refresh_rate;
}

SDL_Texture* RenderWindow::loadTexture(const char *file)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, file);
    if (texture == nullptr)
        std::cout << "UNABLE TO LOAD TEXTURE: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity)
{
    Vector2 position = entity.getPosition();
    SDL_Rect src = {static_cast<int>(entity.getCurrentFrame().x), static_cast<int>(entity.getCurrentFrame().y), static_cast<int>(entity.getCurrentFrame().h), static_cast<int>(entity.getCurrentFrame().w)};
    SDL_FRect dst = {position.x, position.y, 128, 128};
    SDL_RenderCopyF(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanup()
{
    SDL_DestroyWindow(window);
}