#pragma once
#include "Game.h"

/**
 * @brief A helper class to load and draw an SDL texture
 *
 * Functions
 *
 * LoadTexture: A static function that takes a C style string
 * as argument for the filename, and returns a pointer to an
 * SDL_Texture object.
 *
 * Draw: A static method that takes a pointer to an SDL_Texture,
 * and two SDL_Rect objects: a source and destination rectangle.
 * The method returns nothing. Renders the texture to the
 * destination rectangle with the help of a static SDL_Render object.
 *
 */
namespace DungeonDelvers {
	class TextureManager {
	public:
		static SDL_Texture* LoadTexture(const char* fileName);
		static void Draw(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect);
	};
}
