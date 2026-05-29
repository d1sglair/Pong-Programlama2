#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define PADDLE_WIDTH 15
#define PADDLE_HEIGHT 100
#define PADDLE_SPEED 8

typedef struct
{
    float x;
    float y;
    int width;
    int height;
} Paddle;

void handleInput(SDL_Event *event,
                 Paddle *leftPaddle,
                 Paddle *rightPaddle,
                 int *running);

void updatePaddles(const Uint8 *keyboardState,
                   Paddle *leftPaddle,
                   Paddle *rightPaddle);
                   typedef struct
{
    float x;
    float y;
    float velX;
    float velY;
    int size;

} Ball;




void updateBall(Ball *ball,
                Paddle *leftPaddle,
                Paddle *rightPaddle);

void render(SDL_Renderer *renderer,
            Paddle *leftPaddle,
            Paddle *rightPaddle,
            Ball *ball);

#endif
