//
// Created by Lennie Gutierrez on 2/13/21.
//

#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#endif //SDL_UTILS_H

#pragma once

#include <SDL.h>

namespace utils
{
    inline float hireTimeInSecond()
    {
        float t = SDL_GetTicks();
        t *= 0.001f; // Convert milliseconds to seconds.

        return t;
    }
}