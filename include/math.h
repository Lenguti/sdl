//
// Created by Lennie Gutierrez on 2/13/21.
//

#ifndef SDL_MATH_H
#define SDL_MATH_H

#endif //SDL_MATH_H

#pragma once

struct Vector2
{
    Vector2() : x(0.0f), y(0.0f) {};
    Vector2(float x, float y) : x(x), y(y) {};

    void print();

    float x, y;
};