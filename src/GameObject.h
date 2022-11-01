#pragma once
#include "Game.h"

namespace DungeonDelvers {
	class GameObject {
	public:
		GameObject(const char* textureSheet, int x, int y);
		virtual ~GameObject() = default;

		void Update();
		void Render();

	private:
		int xpos_;
		int ypos_;
		SDL_Texture* texture_;
		SDL_Rect srcRect_, destinationRect_;
	};
}