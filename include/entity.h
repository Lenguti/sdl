//
// Created by Lennie Gutierrez on 2/12/21.
//

#ifndef SDL_ENTITY_H
#define SDL_ENTITY_H

#endif //SDL_ENTITY_H

#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "math.h"

class Entity
{
public:
    Entity(Vector2 position, SDL_Texture* texture);

    Vector2& getPosition() { return position; };
    SDL_Texture* getTexture() { return texture; };
    SDL_FRect getCurrentFrame() { return currentFrame; };

private:
    Vector2 position;

    SDL_FRect currentFrame;
    SDL_Texture* texture;
};