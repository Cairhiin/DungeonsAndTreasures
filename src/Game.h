#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#undef main

class Game {
public:
	Game(bool isRunning = false, SDL_Window *window = nullptr);
	~Game() = default;
	Game(const Game&) = delete; // disallow copying
	Game& operator=(const Game&) = delete; // disallow assign
	

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

	static SDL_Renderer* renderer_;

private:
	bool isRunning_;
	SDL_Window* window_;
	int cnt_;
};

