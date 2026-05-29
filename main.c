#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL initialization failed!\n");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Pong Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Paddle leftPaddle = {30, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                         PADDLE_WIDTH, PADDLE_HEIGHT};

    Paddle rightPaddle = {WINDOW_WIDTH - 45,
                          WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2,
                          PADDLE_WIDTH, PADDLE_HEIGHT};
    Ball ball =
{
    WINDOW_WIDTH / 2,
    WINDOW_HEIGHT / 2,
    5,
    5,
    15
};

    int running = 1;
    SDL_Event event;

    while (running)
{
    handleInput(&event, &leftPaddle, &rightPaddle, &running);

    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

    updatePaddles(keyboardState,
                  &leftPaddle,
                  &rightPaddle);

    updateBall(&ball,
               &leftPaddle,
               &rightPaddle);

    render(renderer,
           &leftPaddle,
           &rightPaddle,
           &ball);

    SDL_Delay(16);
}

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
