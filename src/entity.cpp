//
// Created by Lennie Gutierrez on 2/12/21.
//

#include <SDL.h>

#include "../include/entity.h"

Entity::Entity(Vector2 position, SDL_Texture *texture) : position(position), texture(texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.h = 128;
    currentFrame.w = 128;
}
