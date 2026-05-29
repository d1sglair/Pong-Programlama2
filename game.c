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

void updateBall(Ball *ball,
                Paddle *leftPaddle,
                Paddle *rightPaddle)
{
    ball->x += ball->velX;
    ball->y += ball->velY;

    if (ball->y <= 0)
    {
        ball->velY *= -1;
    }

    if (ball->y + ball->size >= WINDOW_HEIGHT)
    {
        ball->velY *= -1;
    }

    if (ball->x <= leftPaddle->x + leftPaddle->width &&
        ball->y + ball->size >= leftPaddle->y &&
        ball->y <= leftPaddle->y + leftPaddle->height)
    {
        ball->velX *= -1;
    }

    if (ball->x + ball->size >= rightPaddle->x &&
        ball->y + ball->size >= rightPaddle->y &&
        ball->y <= rightPaddle->y + rightPaddle->height)
    {
        ball->velX *= -1;
    }
}

void render(SDL_Renderer *renderer,
            Paddle *leftPaddle,
            Paddle *rightPaddle,
            Ball *ball)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect leftRect = {
        (int)leftPaddle->x,
        (int)leftPaddle->y,
        leftPaddle->width,
        leftPaddle->height
    };

    SDL_Rect rightRect = {
        (int)rightPaddle->x,
        (int)rightPaddle->y,
        rightPaddle->width,
        rightPaddle->height
    };

    SDL_Rect ballRect = {
        (int)ball->x,
        (int)ball->y,
        ball->size,
        ball->size
    };

    SDL_RenderFillRect(renderer, &leftRect);
    SDL_RenderFillRect(renderer, &rightRect);
    SDL_RenderFillRect(renderer, &ballRect);

    SDL_RenderPresent(renderer);
}
