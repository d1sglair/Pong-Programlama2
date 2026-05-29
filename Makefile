CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/main.c src/game.c
TARGET = pong

all:
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) `sdl2-config --cflags --libs`

clean:
	rm -f $(TARGET)
