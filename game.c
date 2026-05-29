#include "game.h"

void handleInput(SDL_Event *event,
                 Paddle *leftPaddle,
                 Paddle *rightPaddle,
                 int *running)
{
    (void)leftPaddle;
    (void)rightPaddle;

    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            *running = 0;
        }
    }
}

void updatePaddles(const Uint8 *keyboardState,
                   Paddle *leftPaddle,
                   Paddle *rightPaddle)
{
    if (keyboardState[SDL_SCANCODE_W] && leftPaddle->y > 0)
        leftPaddle->y -= PADDLE_SPEED;

    if (keyboardState[SDL_SCANCODE_S] &&
        leftPaddle->y < WINDOW_HEIGHT - leftPaddle->height)
        leftPaddle->y += PADDLE_SPEED;

    if (keyboardState[SDL_SCANCODE_UP] && rightPaddle->y > 0)
        rightPaddle->y -= PADDLE_SPEED;

    if (keyboardState[SDL_SCANCODE_DOWN] &&
        rightPaddle->y < WINDOW_HEIGHT - rightPaddle->height)
        rightPaddle->y += PADDLE_SPEED;
}

void render(SDL_Renderer *renderer,
            Paddle *leftPaddle,
            Paddle *rightPaddle)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect leftRect = {(int)leftPaddle->x, (int)leftPaddle->y,
                         leftPaddle->width, leftPaddle->height};

    SDL_Rect rightRect = {(int)rightPaddle->x, (int)rightPaddle->y,
                          rightPaddle->width, rightPaddle->height};

    SDL_RenderFillRect(renderer, &leftRect);
    SDL_RenderFillRect(renderer, &rightRect);

    SDL_RenderPresent(renderer);
}
