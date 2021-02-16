//
// Created by Lennie Gutierrez on 2/10/21.
//

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "../include/renderWindow.h"
#include "../include/utils.h"

int main(int argc, char* args[]) {
    std::cout << "Hello, World!" << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL INIT HAS FAILED: SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG INIT HAD FAILED: IMG_ERROR: " << SDL_GetError() << std::endl;

    std::cout << "It worked bois!!" << std::endl;

    RenderWindow window("len/carl/peter Game v1", 1280, 720);

    SDL_Texture* ground = window.loadTexture("../assets/images/upperGround.png");

    std::vector<Entity> entities = {
        Entity(Vector2(0, 600), ground),
        Entity(Vector2(128, 600), ground),
        Entity(Vector2(256, 600), ground),
        Entity(Vector2(384, 600), ground),
        Entity(Vector2(512, 600), ground),
        Entity(Vector2(640, 600), ground),
        Entity(Vector2(768, 600), ground),
        Entity(Vector2(896, 600), ground),
        Entity(Vector2(1024, 600), ground),
        Entity(Vector2(1152, 600), ground),
    };

    bool gameRunning = true;
    SDL_Event event;
    while (gameRunning)
    {
        std::cout << "Time passed: " << utils::hireTimeInSecond() << std::endl;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }
        window.clear();
        for (Entity& entity : entities) {
            window.render(entity);
        }
        window.display();
    }

    window.cleanup();
    SDL_Quit();

    return 0;
}
