#include "Game.h"
#include "TextureManager.h"
#include "ECS/Components.h"
#include "ECS/SpriteComponent.h"

Manager manager;
auto& player(manager.AddEntity());

SDL_Renderer* Game::renderer_{ nullptr };

Game::Game(bool isRunning, SDL_Window *window) 
				: isRunning_(isRunning), window_(window), cnt_(0) {};

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
	int flags{0};
	if (fullScreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "System successfully initialized..." << std::endl;

		window_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window_) {
			std::cout << "Window created successfully!" << std::endl;
		}

		renderer_ = SDL_CreateRenderer(window_, -1, 0);
		if (renderer_) {
			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
			std::cout << "Renderer created successfully!" << std::endl;
		}

		isRunning_ = true;
	}
	else isRunning_ = false;

	player.AddComponent<PositionComponent>();
	player.AddComponent<SpriteComponent>("assets/knight.png");
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning_ = false;
			break;
		default:
			break;
	}
}

void Game::update() {
	manager.refresh();
	manager.update();
	std::cout << player.GetComponent<PositionComponent>().x() << ", " <<
		player.GetComponent<PositionComponent>().y() << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer_);
	manager.draw();
	SDL_RenderPresent(renderer_);
}

void Game::clean() {
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
	SDL_Quit();
	std::cout << "Game cleaned up successfully!";
}

bool Game::running() {
	return isRunning_;
}